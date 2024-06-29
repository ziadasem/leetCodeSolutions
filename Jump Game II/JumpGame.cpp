#include<vector>
#define MAX(A,B) ((A>B) ? (A) : (B))
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0 ;
             int j = 1 ;
             int nI = nums[0];
             int fI = 0 ;

             for (int i = 1 ; i < nums.size() - 1 ; i++){
              fI = max(fI, nums[i] + i );
              if (i == nI){
                j++;
                nI = fI;
              }
            }
            return j ;
    }
};