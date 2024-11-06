#include <string>
#include <queue>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1){
            return s ;          
        }
        std::string result ="";
        std::queue<int> indices ;
        int length = s.length();
        // init queue
        int step = numRows * 2 - 2 ;
        int i;
        for (i = 0 ; i < length; i +=step ){
            indices.push(i);
            indices.push(i + step);
        }
        //padding the string
        for (int j = 0; j < step ; j++){
             s += '}';
        }
        bool increment = true ;
        while(!indices.empty()){
            int index = indices.front();
            indices.pop();

            if (index < s.length() && s[index] != '*'){
                if (s[index] != '}'){
                    result += s[index];
                }
                s[index] = '*';
            }
            
            
            if (increment){
               index ++;
            }else{
                index -- ;
            }
            increment = !increment ;
            if (index < s.length() && s[index] != '*'){
                indices.push(index);
            }
        }
        
        return result ;
    }
};
