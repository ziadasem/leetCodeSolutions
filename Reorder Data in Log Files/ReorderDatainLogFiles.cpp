#include<string>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
     vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters ;  
        vector<string> nums ;  
        for (vector<string>::iterator it = logs.begin(); it != logs.end(); ++it) {
            if (!isDigitWord(*it)){
                letters.push_back(*it);
            }else {
                nums.push_back(*it);
            }
        }
        sort(letters.begin(), letters.end(), sortFunc );

        for (int i = 0; i < nums.size(); i++){
            letters.push_back(nums[i]);
        }
        return letters ;

    }

    bool isDigitWord(string& str) {
        int index = str.find(" ") ;
        return isdigit(str[index +1]) ;
    }

    static bool sortFunc(const string& a, const string& b) {
        int firstSpaceIndex = a.find(" ");
        string a_id = a.substr(0, firstSpaceIndex);
        string a_content = a.substr(firstSpaceIndex +1, a.length());

        firstSpaceIndex = b.find(" ");
        string b_id = b.substr(0, firstSpaceIndex);
        string b_content = b.substr(firstSpaceIndex + 1, b.length());

        if (a_content == b_content){
            return a_id < b_id ;
        }else{
             return a_content < b_content ;
        }
    }
};