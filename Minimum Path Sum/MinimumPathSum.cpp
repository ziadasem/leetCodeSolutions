#include <string>
#include <vector>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       vector<vector<int>> dp = vector<vector<int>>(grid.size());
       for (int i = 0 ; i < dp.size(); ++ i){
           dp[i] = vector<int>(grid[i].size());
       }
       dp[0][0] = grid[0][0]; 
       for (int i = 0; i < grid.size(); ++i) {
           for (int j = 0; j < grid[i].size(); ++j) {
                if ( i > 0 && j > 0){
                    dp[i][j] = grid[i][j] + MIN(dp[i-1][j], dp[i][j-1]);
                }else if ( i > 0){
                    dp[i][j] = grid[i][j] + dp[i- 1][j];
                }else if (j > 0){
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];  
    }

};