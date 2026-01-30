#include <string>
const int ALL_CHARS_MATCHE = 26;
class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) return false;
        int matches = 0;
        int s1FrequencyMap[26] = {0}, s2FrequencyMap[26] = {0}; //init all to zeros
        int windowLength = s1.size();
        int s1CharPosIndex, s2CharPosIndex;
        int popedCharFromWindowIndex;
        int pushedCharFromWindowIndex;

        //Fill the s1 and s2 frequency map
        for (int i{0}; i < windowLength; ++i)
        {
            // convert ascii char to position (97 -> 0)
            s1CharPosIndex = s1[i] - 'a';
            s2CharPosIndex = s2[i] - 'a';
            s1FrequencyMap[s1CharPosIndex] ++ ;
            s2FrequencyMap[s2CharPosIndex] ++ ;
        }

        //Find the inital matches for the window
        for (int i{0}; i < 26; ++i)
        {
            if (s1FrequencyMap[i] == s2FrequencyMap[i])
                matches ++ ;
        }

        if (matches == ALL_CHARS_MATCHE)
            return true;

        //Sliding Windows
        for (int i = windowLength; i < s2.size(); ++i)
        {
            popedCharFromWindowIndex  = s2[i - windowLength] - 'a'; 
            pushedCharFromWindowIndex = s2[i] - 'a'; 
            s2FrequencyMap[popedCharFromWindowIndex] --;
            if (s1FrequencyMap[popedCharFromWindowIndex] == s2FrequencyMap[popedCharFromWindowIndex])
                matches ++ ;
            else if (s1FrequencyMap[popedCharFromWindowIndex] == s2FrequencyMap[popedCharFromWindowIndex] + 1)
                matches -- ;
                
            s2FrequencyMap[pushedCharFromWindowIndex] ++ ;
            if (s1FrequencyMap[pushedCharFromWindowIndex] == s2FrequencyMap[pushedCharFromWindowIndex])
                matches ++ ;
            else if (s1FrequencyMap[pushedCharFromWindowIndex] == (s2FrequencyMap[pushedCharFromWindowIndex] - 1) )
                matches -- ;
            if (matches == ALL_CHARS_MATCHE)
                return true;
        }
        return false;
    }
};