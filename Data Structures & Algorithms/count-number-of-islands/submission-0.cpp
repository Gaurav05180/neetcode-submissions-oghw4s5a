class Solution {
public:

    int n, m;

    bool check(int i, int j){
        return i>=0&&i<n && j>=0&&j<m;
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();

        int count = 0;

        int row[4] = {-1,0,0,1};
        int col[4] = {0,-1,1,0};

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]=='1'){
                    count++;

                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while(!q.empty()){
                        int temp_i = q.front().first;
                        int temp_j = q.front().second;

                        q.pop();

                        for(int k=0; k<4; k++){
                            int new_i = temp_i + row[k], new_j = temp_j + col[k];

                            if(check(new_i, new_j) && grid[new_i][new_j]=='1'){
                                q.push({new_i, new_j});
                                grid[new_i][new_j]='0';
                            }
                        }                        
                    }
                }
            }
        }

        return count;        
    }
};
