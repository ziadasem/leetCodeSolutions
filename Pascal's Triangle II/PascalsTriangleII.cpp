#include<vector>
using namespace std ;
class Solution {
public:
    vector<int> getRow(int numRows) {
        numRows ++ ;
        vector<vector<int>> triangle =   vector<vector<int>>(numRows);
        for (int i = 0; i < numRows ; i++ ){
            triangle[i] = vector<int>(i + 1);
            triangle[i][0] = 1 ;
            triangle[i][i] = 1 ;
        }
        
        for (int i = 2; i < numRows ; i++ ){
            for (int j = 1 ; j <i  ; j++ ){
                triangle[i][j] =  triangle[i-1][j-1] +triangle[i-1][j] ;
            }
         
        }
        return triangle[numRows - 1];
    }
};

