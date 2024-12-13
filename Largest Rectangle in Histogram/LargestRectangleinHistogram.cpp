#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int maxArea = -2147483647 - 1;
        int heightsSize = heights.size();
        std::stack<std::pair<int, int>> extendableRectangles ;
        
        std::pair<int, int> temp = {heights[0], 0}; //height, starting index 
        extendableRectangles.push(temp);
        int index;
        int popedIndex;
        for (index = 1; index < heightsSize; index++) {
            //check if the current rectangle can be extended
            #define CURRENT_RECT_CANNOT_EXTEND (extendableRectangles.top().first >  heights[index])
            popedIndex = index ;
            while (!extendableRectangles.empty() && CURRENT_RECT_CANNOT_EXTEND ) {
                popedIndex = extendableRectangles.top().second ;
                #define CURRENT_RECT_WIDTH (index - popedIndex)
                int currentArea = extendableRectangles.top().first * CURRENT_RECT_WIDTH  ;
                maxArea = std::max(currentArea, maxArea );
                extendableRectangles.pop();
            }
            temp = { heights[index], popedIndex};
            extendableRectangles.push(temp);
        }

        while (!extendableRectangles.empty()) {
                popedIndex = extendableRectangles.top().second ;
                #define CURRENT_RECT_WIDTH (index - popedIndex)
                int currentArea = extendableRectangles.top().first * CURRENT_RECT_WIDTH  ;
                maxArea = std::max(currentArea, maxArea );
                extendableRectangles.pop();
        }
        return maxArea ;
        
    }
   
};
