class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int>freq(128,0);
        vector<int>win(128,0);
        int k=s1.size();
        for (int i = 0; i < k; i++) {
            freq[s1[i]]++;
            win[s2[i]]++;
        }
        if (win == freq) return true;
        //window size and condition
        //if condition remains true size can be expanded atmost k
        //when size is k and condition is true answer is true
        int n=s2.size();
        int left = 0, right = 0;
        for (int right = k; right < s2.size(); right++) {
            win[s2[right]]++;          
            win[s2[left]]--;
            left++;

            if (win == freq) return true;
        }
        return false;

    }
};
