class Solution {
public:
    int findMin(vector<int> &nums) {
        // 3 4 5 6 1 2
        // 0 0 0 0 1 1
        // 1 2 3 4
        // 0 0 0 0
        //l=0 r=3, m=1
        //l=2 r=3
        //l=3 r=3//no looping here l==r
        //l=4
        // compare with first element
        // 
        

        int left =0; 
        int right = nums.size()-1;

        int mid=left + (right-left)/2;
        cout<<left<<right<<mid;

        while (left<right){
            mid=left + (right-left)/2;
            if(nums[0]>nums[mid]){
                right=mid;
            }
            else
                left=mid+1;
            cout<<left<<right<<mid;
        }
        // if(left>=nums.size()-1){
        //     return nums[0];
        // }
        // else 
        if(nums[0]>nums[left])
            return nums[left];
        else
            return nums[0];
    }
};
