#include <map>
#include <string>
class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int len = s.length();
        std::map<char, char> sMapper, tMapper;
        
        for (int i{0}; i <len; ++i )
        {
            char sKey = s[i];
            char tKey = t[i];
            bool sKeyFound = sMapper.find(sKey) != sMapper.end();
            bool tKeyFound = tMapper.find(tKey) != tMapper.end();
            if ( (sKeyFound ^ tKeyFound) ||  (sKeyFound == true && (sMapper[sKey] != tKey || tMapper[tKey] != sKey)))
            {
                return false;
            }else if (sKeyFound == false)
            {
                sMapper[sKey] = tKey;
                tMapper[tKey] = sKey;

            }
        }
        return true;
    }
};