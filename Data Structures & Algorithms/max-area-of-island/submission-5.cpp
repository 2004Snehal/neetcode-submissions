class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        int count=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
                if(grid[i][j]){
                    count=max(count,dfs(grid,i,j,row,col));
                    
                }
            }
        }
        return count;

    }
    int dfs(vector<vector<int>>&grid,int r,int c,int row,int col){
        if(r<0||r>row-1||c<0||c>col-1||!grid[r][c]){
            return 0;
        }
        int area=1;
        if(grid[r][c]){
            grid[r][c]=0;
            int dr[]={1,-1,0,0};
            int dc[]={0,0,1,-1};

            for(int i=0;i<4;i++){
                area+=dfs(grid,r+dr[i],c+dc[i],row,col);
            }
        }
        return area;
    }
};
