class Solution {
public:
    int carFleet(int t, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        for(int i=0; i<speed.size(); i++){
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end());
        vector<double> time;
        for(auto i : car){
            time.push_back((double)(t-i.first) / i.second);
        }

        int c=0;
        double m = 0;
        for(int i = time.size()-1; i>=0; i--){
            if(time[i] > m){
                m = time[i];
                c++;
            }
        }
        return c;
    }
};
