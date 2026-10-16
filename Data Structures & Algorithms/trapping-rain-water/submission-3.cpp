class Solution {
public:
    int trap(vector<int>& height) {
        int w=0;
        int lmax=0, rmax=0;
        int i=0, j = height.size()-1;

        while(i<j){
            if(height[i] < height[j]){
                if(lmax < height[i]){
                    lmax = height[i];
                }else{
                    w += lmax - height[i];
                }
                i++;
            }else{
                if(rmax < height[j]){
                    rmax = height[j];
                }else{
                    w += rmax - height[j];
                }
                j--;
            }
        }
        return w;
    }
};
