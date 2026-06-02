class Solution {
public:

    int bs(int l, int r, vector<int>& piles, int h){
        int ans = r;
        while(l <= r){
            int res = 0;
            int k = (l+r)/2;
            for(int i : piles){
                res += ceil((double)i / k);
            }
            if(res <= h){
                ans = k;
                r = k-1;
            }
            else l = k+1;

        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = 0;
        for(int i =0; i<piles.size(); i++){
            mx = max(mx, piles[i]);
        }

        return bs(1, mx, piles, h);
    }
};
