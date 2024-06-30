#include <vector>
#include<string>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
       vector<int> boxesI(1); 
       for (int i = 0; i < boxes.size() ; i++){
            if (boxes[i] == '1'){
                boxesI.push_back(i);
            }
       }

       int on_right_ones = boxesI.size();
       int on_left_ones =  0 ;
       int splitI = 0 ;

       vector<int> ans(boxes.size());

       for (int i = 0; i < ans.size(); i++) {
            int on_right_sum = accumulate(boxesI.begin(), boxesI.end() - splitI, 0);
            int on_left_sum = accumulate(boxesI.end() - splitI, boxesI.end(), 0);
            if (i == boxesI[splitI]){ //move indices
                splitI++;
                on_left_ones ++;
                on_right_ones -- ;
            }

            int r = (on_right_sum - (on_right_ones * i)) + (on_left_ones * i) - on_left_sum;
            ans[i]  = r;
       }

        return ans ;
    }
};