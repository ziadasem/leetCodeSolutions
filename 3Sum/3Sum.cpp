#include <vector>
#include <algorithm>
#include <set>
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& numbers) {
        std::set<std::vector<int>> result ;
        int sum ;
        //sort
        std::sort(numbers.begin(), numbers.end());
        for (int corner =0; corner < numbers.size()-2; corner ++ ){
            for (int start =corner + 1 , end = numbers.size()-1 ; start < end ; ) {
                sum = numbers[corner] +  numbers[start] + numbers[end] ;
                if (sum == 0){
                    result.insert({numbers[corner], numbers[start], numbers[end] });
                    start++ ;
                    end -- ;
                }else if (sum > 0){
                    end -- ;
                }else{
                    start ++ ;
                }
            }
        }
        std::vector<std::vector<int>> vectorizedSet = std::vector<std::vector<int>>(result.begin(), result.end()); 
        return vectorizedSet ; 
    }
};

int main(){
    Solution s;
    std::vector<int> v = {-1,0,1,2,-1,-4};
    s.threeSum(v);
}