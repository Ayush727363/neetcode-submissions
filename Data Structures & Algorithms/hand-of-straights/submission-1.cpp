class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int n) {
        if(hand.size() % n != 0) return false;

        sort(hand.begin(), hand.end());
        map<int,int> mp;
        for(int i : hand){
            mp[i]++;
        }

        while(!mp.empty()){
            int prev = -1, c = n;
            for(auto& i : mp){
                if(c == 0) break;
                
                if(prev == -1) prev = i.first;
                else if(i.first != prev+1) return false;

                prev = i.first;
                i.second--;
                if(i.second == 0) mp.erase(i.first);
                c--;
            }
            if(c != 0) return false;
        }
        return true;
    }
};
