#include <vector>
#include <stack>
class Solution {
public:
std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
std::vector<int> result = std::vector<int>(temperatures.size(), 0);
        std::stack<std::pair<int, int>> backtrack ;

        for (int i = 0 ; i < temperatures.size(); i++ ){
           int temp = temperatures[i];
           while(! backtrack.empty() && temp > backtrack.top().first ){
                int resIndex =  backtrack.top().second ; 
                result[resIndex] = i -  backtrack.top().second ;
                backtrack.pop();
           }
           backtrack.push({temp, i});
        }

        return result;
    }
};