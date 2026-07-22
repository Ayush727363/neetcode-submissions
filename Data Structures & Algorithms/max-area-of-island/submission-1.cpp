class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int& area){
        grid[i][j] = 0;
        area++;
        if(i < n-1 && grid[i+1][j] == 1){
            dfs(grid, i+1, j, n, m, area);
        }
        if(j < m-1 && grid[i][j+1] == 1){
            dfs(grid, i, j+1, n, m, area);
        }
        if(i > 0 && grid[i-1][j] == 1){
            dfs(grid, i-1, j, n, m, area);
        }
        if(j > 0 && grid[i][j-1] == 1){
            dfs(grid, i, j-1, n, m, area);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int marea = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, i, j, n, m, area);
                    marea = max(marea, area);
                }
            }
        }
        return marea;
    }
};
