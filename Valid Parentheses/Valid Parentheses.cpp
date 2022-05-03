class Solution {
public:
     bool isValid(string s) {
        std::vector<char> closingChars ;
        int size = s.size();
        if (size < 2){
            return false ;
        }
        for (int i = 0 ; i < s.size() ; i++){
            switch (s[i]){
                case '(':
                    closingChars.push_back(')');
                    break;
                case '[':
                    closingChars.push_back(']');
                    break;
                case '{':
                    closingChars.push_back('}');
                    break;
                default :
                    if (closingChars.size() ==0){
                        return false;
                    }
                    char cloasingBracket = closingChars.back() ;
                    closingChars.pop_back();
                    if (s[i] != cloasingBracket){
                        return false ;
                    }
                    break ;
            }
    }
        if (closingChars.size() ==0){
            return true ;
        }
        return false ;
    }
};

int main(){
    cout<<isValid("{()}")<<isValid("(]")<<isValid(")(");
}
