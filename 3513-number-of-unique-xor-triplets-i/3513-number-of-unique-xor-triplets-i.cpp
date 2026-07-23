class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int temp = floor((double)log2((int)nums.size()));
        return 1<<(temp+1);
    }
};