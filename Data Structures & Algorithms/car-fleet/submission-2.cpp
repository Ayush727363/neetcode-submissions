class Solution {
public:
    int carFleet(int t, vector<int>& position, vector<int>& speed) {
        vector<pair<double,int>> car;
        for(int i=0; i<speed.size(); i++){
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end());

        for(int i = 0; i<car.size(); i++){
            car[i].first = ((t-car[i].first) / car[i].second);
        }

        int c=0;
        double m = 0;
        for(int i = car.size()-1; i>=0; i--){
            if(car[i].first > m){
                m = car[i].first;
                c++;
            }
        }
        return c;
    }
};
