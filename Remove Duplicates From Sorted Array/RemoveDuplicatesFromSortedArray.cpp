class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     if(nums.empty())
        return 0;
      int M = nums.size();
      vector<int> output ;
      output.push_back(nums[0]);
      for (int i = 1 ; i < M; i++){
       if (nums[i] != nums[i-1]){ //[ 0 0 0 1 1 2 2 3]
            output.push_back(nums[i]);
       }
    }
    int k = output.size();
     nums = output ;  
     return k ;
    }
};