#include <unordered_map>
#include <vector>

class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        std::unordered_map<int, int> frequencyMap ;
        int arrSize = arr.size();
        for (int i{0}; i < arrSize; ++i)
        {
            int val = arr[i];
            frequencyMap[val] ++ ;
        }
        int maxLuckyNumber = -1 ;
        for (auto it: frequencyMap)
        {
            if (it.first == it.second)
            {
                if (maxLuckyNumber < it.first)
                {
                    maxLuckyNumber = it.first;
                }
            }
        }
        return maxLuckyNumber;
    }
};