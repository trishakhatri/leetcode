class Solution {
public:
    vector<string> ans;
    vector<string> key = {"", "", "abc","def","ghi", "jkl","mno","pqrs","tuv","wxyz"};
    string temp;
    void phone(string digits, int i){
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }
        string letters = key[digits[i] -'0'];
        for(char j: letters){
            temp.push_back(j);
            phone(digits , i+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        phone(digits , 0);
        return ans;
    }
};