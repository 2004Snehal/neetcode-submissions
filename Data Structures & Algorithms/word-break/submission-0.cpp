class Solution {
public:
    string s;
    unordered_set<string> wordSet;
    vector<int> dp; 

    int rec(int i){
        // pruning // matlab ki agar ye invalid hai to return 0 karo
        // (koi pruning nahi chahiye yaha, kyunki i hamesha 0..n ke beech hi rahega)

        // basecase
        if(i == s.size()){
            // poora string consume ho gaya, matlab valid segmentation mil gaya
            return 1;
        }

        // cache check
        if(dp[i] != -1){ // dekh liya ki ye pehle calculate hua hai ki nahi
            return dp[i];
        }

        // transition
        int ans = 0;
        for(int j = i+1; j <= s.size(); j++){
            
            string chunk = s.substr(i, j - i);
            if(wordSet.count(chunk)){
                // agar ye chunk valid word hai, to baaki string (j se aage) bhi valid hona chahiye
                if(rec(j)){
                    ans = 1;
                    break; 
                }
            }
        }

        // save and return
        dp[i] = ans;
        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        dp.assign(s.size() + 1, -1);

        return rec(0) == 1;
    }
};