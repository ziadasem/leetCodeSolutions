#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int max_length = 1 ;
        int start = 0 ;
        int length = s.length();
        for (int i = 0 ; i < length ; i++){
            //try even and odd length
            for (int j = 0 ; j <= 1; j++) {
                int left = i ;
                int right = i + j ;
                while (left >= 0 && right < length && s[left] == s[right]) {
                    int new_length = right - left + 1 ;
                    if (new_length > max_length) {
                        max_length = new_length ;
                        start = left ;
                    }
                    left-- ;
                    right++ ;
                }
            }
        }
        return s.substr(start, max_length) ;
    }
};