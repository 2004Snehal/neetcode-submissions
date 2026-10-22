class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        queue<pair<int,int>>q;

        int fresh=0;
        int min=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        while(fresh>0 && !q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int j=0;j<4;j++){        // renamed i -> j
                    int nr=r+dr[j];
                    int nc=c+dc[j];
                    if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            min++;
        }
        return fresh==0 ? min : -1;}
};
