class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ins;
    void powerset(vector<int>& nums , int index){
        ans.push_back(ins);
        for(int i = index; i< nums.size(); i++){
            if(i> index && nums[i] == nums[i-1]) continue;
            ins.push_back(nums[i]);
            powerset(nums, i+1);
            ins.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        powerset(nums, 0);
        return ans;
    }
};