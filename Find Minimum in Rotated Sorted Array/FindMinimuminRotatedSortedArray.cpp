#include <vector>
#include <iostream>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int l = 0 ;
        int r = nums.size() - 1 ;
        int res = nums[l] ;
        
        while (l <= r){
            if (nums[l] < nums[r]){
                return MIN(res, nums[l]);
            }
            int mid = l + (r - l) / 2 ;
            res = MIN(res, nums[mid]);
            if (nums[mid] >= nums[l]) {
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }

        return res ;
    }
};


int main(){
    Solution solution ;
    std::vector<std::vector<int>> nums = 
    {
        {4,5,6,7,0,1,2},
        {4,5,6},
        {7,0,2}
    };
    for (int i = 0; i < nums.size(); i++){
        std::cout<<solution.findMin(nums[i])<<"\n";  // should return 0, 0, 0 respectively for each vector.
    }
    
    return 0;
 
}