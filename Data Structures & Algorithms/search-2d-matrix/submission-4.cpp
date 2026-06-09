class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        //i*n+j flattens
        //t=i*n+j
        //i=t/n, j=t%n
        //just move t from 0 to m*n-1
        return bin(0,m*n-1,matrix,target);
    }
    bool check(int mid,vector<vector<int>>& matrix,int target){
        int n=matrix[0].size();
        int i=mid/n;
        int j=mid%n;

        return matrix[i][j]>=target;
    }

    int bin(int lo,int hi,vector<vector<int>>& matrix,int target){
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,matrix,target))
                hi=mid;
            else
                lo=mid+1;
        }
        int n=matrix[0].size();
        int i=lo/n;
        int j=lo%n;

        if(matrix[i][j]==target)
            return true;
        return false;
    }
};
