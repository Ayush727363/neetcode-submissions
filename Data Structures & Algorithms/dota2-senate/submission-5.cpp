class Solution {
public:
    string predictPartyVictory(string s) {
        int sr=0, sd=0;
        int n = s.size();
        queue<char> q;
        for(char& c : s){
            if(c == 'R') sr++;
            else sd++;
            q.push(c);
        }
        if(sr == 0) return "Dire";
        else if(sd==0) return "Radiant";  
        int r=0, d=0;
        while(sr>0 && sd>0){
            char t = q.front();
            if(t == 'R'){
                if(d > 0){
                    d--;
                    sr--;
                    q.pop();
                }else{
                    r++;
                    q.pop();
                    q.push(t);
                }
            }else{
                if(r > 0){
                    r--;
                    sd--;
                    q.pop();
                }else{
                    d++;
                    q.pop();
                    q.push(t);
                }
            }
        }
        if(sr>0) return "Radiant";
        else return "Dire";
    }
};