class Solution {
public:
    vector<vector<string>> ans;
    vector<string> instore;
    bool ispalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void palindrome(string s, int index) {
        int n = s.size();
        if (index == n){
                ans.push_back(instore);
                return;
            }
        for (int i = index; i < n; i++) {
            if (ispalindrome(s, index , i)) {
                instore.push_back(s.substr(index, i - index + 1));
                palindrome(s, i+1);
                instore.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        palindrome(s, 0);
        return ans;
    }
};