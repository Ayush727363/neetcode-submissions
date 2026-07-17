class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=0;
        int n = gas.size();
        int tank=0;
        for(int i=0; i<n; i++) tank += (gas[i] - cost[i]);
        if(tank < 0) return -1;
        
        tank = 0;
        for(int i=0; i<n; i++){
            tank += (gas[i] - cost[i]);
            if(tank < 0){
                tank = 0;
                st = i+1;
            }
        }
        return st;
    }
};
