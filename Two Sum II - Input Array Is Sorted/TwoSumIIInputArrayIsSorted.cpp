#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        for (int start =0, end = numbers.size()-1 ; start < end ; ) {
            int sum = numbers[start] + numbers[end] ;
            if (sum == target){
                return {start +1, end +1};
            }else if (sum > target){
                end -- ;
            }else{
                start ++ ;
            }
        }
        return {};
    }
};