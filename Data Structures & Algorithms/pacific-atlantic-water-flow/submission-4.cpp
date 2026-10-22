class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();

        vector<vector<bool>>pac(row,vector<bool>(col,false));
        vector<vector<bool>>at(row,vector<bool>(col,false));
        //top
        for(int c=0;c<col;c++){
            dfs(heights,pac,0,c,row,col);
        }
        //right
        for(int r=0;r<row;r++){
            dfs(heights,at,r,col-1,row,col);
        }
        //bottom
        for(int c=0;c<col;c++)
            dfs(heights,at,row-1,c,row,col);
        //left
        for(int r=0;r<row;r++){
            dfs(heights,pac,r,0,row,col);
        }

        vector<vector<int>>list;

        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(pac[r][c]&&at[r][c])
                    list.push_back({r,c});
            }
        }
        return list;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& oc, int r, int c,int row, int col){
        oc[r][c]=true;

        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nc<0 || nc>=col || nr<0 || nr>=row){
                continue;
            }
            if(oc[nr][nc])
                continue;
            if(heights[r][c]>heights[nr][nc])
                continue;
            dfs(heights,oc,nr,nc,row,col);
        }
    }
};
