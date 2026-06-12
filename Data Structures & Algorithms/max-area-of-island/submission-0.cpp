class Solution {
public:

    int n, m;

    bool check(int i, int j){
        return i>=0&&i<n && j>=0&&j<m;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        int maxArea = 0;
        int currArea = 0;

        int row[4] = {-1,0,0,1};
        int col[4] = {0,-1,1,0};

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea, currArea);

                    currArea = 0;
                    grid[i][j] = 0;

                    q.push({i,j});

                    while(!q.empty()){
                        int temp_i = q.front().first, temp_j = q.front().second;
                        q.pop();

                        currArea++;

                        for(int k=0; k<4; k++){
                            int new_i = temp_i + row[k], new_j = temp_j + col[k];
                            if(check(new_i, new_j) && grid[new_i][new_j]==1){
                                grid[new_i][new_j] = 0;
                                q.push({new_i, new_j});
                            }
                        }
                    }
                }
            }
        }

        return max(maxArea, currArea);
    }
};
