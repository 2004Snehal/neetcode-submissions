class Solution {
public:
    // hours is fixed
    // it is a search problem 
    // we need to find k
    // k minimum 
    // any large value of k will return true obv
    //chek function 
    //k ranges 0 to 1,000,000,000
    // complexity of check function can be challenge eklse its a easy problem
    //sort the array atleast
    bool check(int k,int h, vector<int>&a){
        int n=a.size();
        for(int i=n-1;i>=0;i--){
            h-=(a[i]/k+bool(a[i]%k));
            if(h<0)
                break;
        }
        return (h>=0);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int l=1;
        int hi=1000000000+1;
        int mid=l+(h-l)/2;

        while(l<hi){
            mid=l+(hi-l)/2;
            if(check(mid,h,piles)){
                hi=mid;
            }
            else
                l=mid+1;
        }
        return l;
    }
}; 
