#include<vector>
#define MIN(A,B) ((A>B) ? (A) : (B))

class Solution {
public:
   bool canJump(std::vector<int>& nums) {
       int steps = nums[0]; 
       if (steps == 0 && nums.size() != 1){
           return false ;
       }
       for (int i = 1; i < nums.size() - 1; i++) {
         steps = MIN(steps - 1, nums[i]);
         if (steps == 0 ) return false; // No further steps left, cannot reach the end of the array.
       }
       return true ;
    }
};