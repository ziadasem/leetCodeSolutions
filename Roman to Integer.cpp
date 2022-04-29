#include <iostream>
#include <string>
using namespace std;

int letterToInteger(char letter){
     switch (letter){
            case 'I' :
                return 1 ;
            case 'V' :
                return 5;
            case 'X' :
                return 10 ;
                break;
            case 'L' :
                return 50 ;
            case 'C' :
                return 100 ;
            case 'D' :
                return 500;
            case 'M' :
                return 1000 ;
            default :
                return -1; //error
            }
}

int romanToInt(string s) {
    int sum = 0 ;
    for (int i =0 ; s[i] != '\0'; i++){
        int num1= letterToInteger(s[i]) ;
        int num2 = letterToInteger(s[i + 1]);
        if (num1>= num2){
            sum += num1;
        }else {
            sum += (num2 - num1);
            i++ ;
        }

    }
    return sum ;
}

int main()
{
    cout<<romanToInt("III")<<endl;
    cout<<romanToInt("LVIII")<<endl;
    cout<<romanToInt("MCMXCIV")<<endl;

    return 0;
}
