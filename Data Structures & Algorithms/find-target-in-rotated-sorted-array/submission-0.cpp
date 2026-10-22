class Solution {
public:
    bool check(vector<int>& nums, int mi) {
        if(nums[0]>nums[mi]){
            return true;
        }
        return false;
    }

    bool check2(vector<int>& nums, int mi,int t) {
        if(nums[mi]>=t){
            return true;
        }
        return false;
    }

    int search(vector<int>& nums, int target) {
        int rot=0;
        int n=nums.size();
        int lo=0;
        int hi=n-1;

        while(lo<=hi){
            int mi = lo + (hi-lo)/2;
            if (check(nums, mi)) {
                rot = mi;
                hi = mi-1;
            }
            else 
                lo = mi+1;
        }

        int ans=-1;
        lo=0;
        hi=n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int mi = (mid + rot) % n;
            if (check2(nums, mi, target)) {
                ans = mi;
                hi = mid - 1;
            }
            else 
                lo = mid + 1;
        }
        if(ans!=-1){
            if(nums[ans]!=target){
                ans=-1;
            }
        }
        return ans;
    }
};