class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0, c20 = 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                c5++;
                continue;
            }else if(bills[i] == 10 && c5 > 0){
                c10++;
                c5--;
                continue;
            }else if(bills[i] == 20 && c5 > 0){
                if(c10 > 0){
                    c20++;
                    c10--;
                    c5--;
                    continue;
                }
                else if(c5 > 2){
                    c20++;
                    c5 = c5 - 3;
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};