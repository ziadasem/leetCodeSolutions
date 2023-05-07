class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int* arr = new int [size(nums) +1] ;
      int length= size(nums) +1;
      arr[0] = 1;
      for (int i =1; i < length; i++){
        arr[i] = 0;
     }
     for (int i =0; i < size(nums) ; i++){
         if (nums[i] < length && nums[i] > 0){
          arr[ nums[i]] = 1;
         }
     }
     for (int i =0; i < length; i++){
         if(arr[i] == 0){
             return (i);
         } 
     }
        return length;
    }
};