#include<vector>
#include <numeric>

using namespace std;

class Solution {
public:
     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> candidatePath;
        traverse(result, candidatePath, candidates, target, 0);
        return result; 
    }

    void traverse(vector<vector<int>>& result, vector<int>& candidatePath, vector<int>& candidates, int target, int startIndex) {
        int summation = accumulate(candidatePath.begin(), candidatePath.end(), 0);

        if(summation == target) {
            result.push_back(candidatePath);
            return;
        }

         if(summation > target) {
            return;
        }

        for (int i = startIndex; i <candidates.size(); i++) {
            candidatePath.push_back(candidates[i]);
            traverse(result, candidatePath, candidates, target, i);
            candidatePath.pop_back(); 
        }
    }
};