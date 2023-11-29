#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int M = nums.size();
      if (M == 1){
        return 1;
      }
      vector<int> output ;
      output.push_back(nums[0]);
      output.push_back(nums[1]);

    for (int i = 2 ; i < M; i = i+2){
       if (nums[i] != nums[i-2]){ //[ 0 0 0 1 1 2 2 3]
            output.push_back(nums[i]);
       }
    }
    int k = output.size();
     nums = output ;  
     return k ;
    }
};

