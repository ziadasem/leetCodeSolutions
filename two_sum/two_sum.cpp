#include <map>
class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mp;
    for (int i = 0 ; i < nums.size() ; i++){
        int difference = target - nums[i];
        if (mp[difference] != 0){
            return { i, mp[difference]-1};
        }else{
            mp[nums[i]] = i + 1 ;
        }
    }
    return {0,0};
}
};
