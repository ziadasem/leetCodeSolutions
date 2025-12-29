#include <vector>
class Solution {
public:
int countNegatives(std::vector<std::vector<int>>& grid) {
        int count           = 0;
        int rowsCount       = grid.size();
        int columnsCount    = grid[0].size();
        int row             = rowsCount - 1;
        int column          = 0;

        while(row >= 0 && column < columnsCount)
        {
            // if negative
            if (grid[row][column] < 0)
            {
                // count and go up
                count += (columnsCount - column);
                row -- ;
            }else{
                // go right
                column ++ ;
            }
        }
        return count;
    }
};