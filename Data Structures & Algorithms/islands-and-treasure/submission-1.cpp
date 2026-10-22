class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        int INF=2147483647;

        queue<pair<int,int>>q;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0)
                q.push({i,j});
            }
        }

        int dist=0;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        while(!q.empty()){
            int k=q.size();
            for(int x=0;x<k;x++){//msbfs
                int r=q.front().first;
                int c=q.front().second;

                q.pop();

                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];

                    if(nr>=0&&nr<row&&nc>=0&&nc<col&&grid[nr][nc]==INF){
                        grid[nr][nc]=dist+1;
                        q.push({nr,nc});
                    }
                }
            }
            dist++;
        }

    }
};
