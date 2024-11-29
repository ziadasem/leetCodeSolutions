#include <vector>
#include <string>
#include <stack>
class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> operands ;
        for (auto token: tokens){     
            if ( token == "*" || token == "/" || token == "+" || token == "-" ){
                int op2 = operands.top(); operands.pop();
                int op1 = operands.top(); operands.pop();
                int result;
                switch (token[0]) {
                    case '+' :
                        result = op1 + op2 ;
                        break;
                    case '-' :
                        result = op1 - op2 ;
                        break;
                    case '*' :
                        result = op1 * op2 ;
                        break;
                    case '/' :
                        result = op1 / op2 ;
                        break;
                }
                operands.push(result);
            }else{
                operands.push(std::stoi(token)); //cast to integer
            }
        }
        return operands.top() ;
        
    }
};
