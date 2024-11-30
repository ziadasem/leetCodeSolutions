#include <string>
class Solution {
public:
    bool isPalindrome(std::string s) {
        for (int i = 0, j = s.length() -1 ; i < j ;  ){
            char firstChar = s[i];
            if (firstChar >= 'A' && firstChar <= 'Z'){
                firstChar += 32 ;
            }else if ( 
                !(
                    (firstChar >= 'a' && firstChar <= 'z') 
                    || (firstChar >= '0' && firstChar <= '9') 
                 )
            ){
                i++ ;
                continue;
            }

            char lastChar = s[j];
            if (lastChar >= 'A' && lastChar <= 'Z'){
                lastChar += 32 ;
            }else if (
                !(
                (lastChar >='a' && lastChar <= 'z') ||
                (lastChar >='0' && lastChar <= '9')
                )
            ){
                j-- ;
                continue;
            }

            if (firstChar != lastChar){
                return false ;
            }else{
                i++; j-- ;
            }
        }
        return true; 
    }
};