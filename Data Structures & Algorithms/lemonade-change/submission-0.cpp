class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        mp[0]=0;mp[10]=0;mp[20]=0;

        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                mp[5]++;
                continue;
            }else if(bills[i] == 10 && mp[5] > 0){
                mp[10]++;
                mp[5]--;
                continue;
            }else if(bills[i] == 20 && mp[5] > 0){
                if(mp[10] > 0){
                    mp[20]++;
                    mp[10]--;
                    mp[5]--;
                    continue;
                }
                else if(mp[5] > 2){
                    mp[20]++;
                    mp[5] = mp[5] - 3;
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};