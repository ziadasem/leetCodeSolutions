#include <string>
#include <vector>
class Solution {
public:
    std::string firstPalindrome(std::vector<std::string>& words) {
        int wordsSize = words.size();
        for (int i{0} ; i < wordsSize ; ++i)
        {
             bool fIsPalindromic = true;
            int wordLength = words[i].size();
            for (int s{0}, e{wordLength - 1}; e > s;  e-- , s++)
            {
                if (words[i][s] !=  words[i][e])
                {
                    fIsPalindromic = false;
                    break;
                }
            }
            if (fIsPalindromic)
            {
                return words[i];
            }
        }
        return "";
    }
};