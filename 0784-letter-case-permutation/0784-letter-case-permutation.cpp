class Solution {
public:
    vector<string> ans;
    void str(string s, int i){
        if(i == s.length()){
            ans.push_back(s);
            return;
        }
        if(isdigit(s[i])){
            str(s, i+1); 
        }else{
            str(s,i+1);

            s[i] ^= 32;
            str(s, i+1);

            s[i] ^= 32;
        }
    }
    vector<string> letterCasePermutation(string s) {
        str(s, 0);
        return ans;
    }
};