class Solution {
public:
    vector<vector<int>> ans;
    vector<int> instore;
    void tt(vector<int>& candidates, int target , int index ){
        if(target== 0){
            ans.push_back(instore);
            return;
        }
        for(int i = index; i<candidates.size(); i++){
            if(i> index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]> target) break;
            instore.push_back(candidates[i]);
            tt(candidates , target - candidates[i], i+1);
            instore.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        tt(candidates , target , 0);
        return ans;
    }
};