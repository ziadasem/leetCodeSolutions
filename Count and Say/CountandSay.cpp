#include <iostream>
#include <string>

using namespace std ;
class Solution {
public:
    string countAndSay(int n) {
        string inital = "1";
        for (int i = 2; i <= n; i++){
            inital = rlc(inital);
        }
        return inital;
    }
    string rlc(string s){
        if (s.length() == 1){
            return "1" + s ;
        }
        int count = 1;
        char inital_char = s[0];
        string encoded = "";
        for (int i = 1; i <s.length(); i++){
            if (s[i] == inital_char){
                count ++ ;
            } else{
                encoded += to_string(count) + inital_char;
                inital_char = s[i];
                count = 1;
            }
        }
        encoded += to_string(count) + inital_char;
        return encoded;
    }
};