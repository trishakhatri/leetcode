class Solution {
public:
    int GCD(int a , int b){
        while(b != 0){
            int temp = b;
            b = a%b;
            a= temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int low = INT_MAX;
        int high = INT_MIN;
        for(int num: nums){
            low = min(low , num);
            high = max(high, num);
        }
        return GCD(low, high);
    }
};