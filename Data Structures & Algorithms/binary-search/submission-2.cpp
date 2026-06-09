class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi=nums.size();
        int lo=0;
        return bin(lo,hi,target,nums);//pass function by reference so as not to create a copy

    }
    bool check(int mid, int target,vector<int>&nums){
        // 0 0 0 1 1 
        //on index
        return nums[mid]>=target;
    }
    int bin(int lo,int hi, int target, vector<int>&nums){
        while(lo<hi){
            int mid= lo + (hi-lo)/2;
            if(check(mid,target,nums))
            hi=mid;
            else
            lo=mid+1;//if lo=mid then forever loop
        }
    
        if(nums[lo]==target)
            return lo;
        return -1;
    }
};
