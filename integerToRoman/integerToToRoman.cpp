#include <iostream>
#include<string>

using namespace std;

int countDigits(int number);
int powOf10(int power) ;
string baseToRomanChar(int base) ;
string digitToRoman(int num, int base) ;
string intToRoman(int num);


string intToRoman(int num) {
    int numLength = countDigits(num);
    string result = "" ;

    for(int base = numLength -1  ; base >= 0 ; base --){
            result += digitToRoman(num/ powOf10(base) , powOf10(base));
            num = num - ((num/ powOf10(base)) * powOf10(base)); //remove leading digit
        }

    return result ;
}

string digitToRoman(int num, int base){

    string result = "";
    if (num == 4 || num == 9){ //special case
        result = baseToRomanChar(base) + baseToRomanChar( (num + 1) * base);
    }else{
        if (num >= 5){
            result += baseToRomanChar(5 * base);
            num = num -5 ;
        }
        for (int i = 0 ; i < num  ; i++){
            result += baseToRomanChar(base); //repeat char with digit value
        }

    }
    return result ;

}

string baseToRomanChar(int base){
    switch (base){
            case 1 :
                return  "I"  ;
            case 5 :
                return "V" ;
            case 10 :
                return "X"  ;
            case 50 :
                return "L"  ;
            case 100 :
                return "C" ;
            case 500 :
                return "D"  ;
            case 1000 :
                return "M"  ;
            default :
                return "-" ;
           }
}

int countDigits(int number){
    int counter = 0 ;
    while(number != 0){
        number = number  / 10;
        counter ++ ;
    }
    return counter;
}

int powOf10(int power){
    int base = 1 ;
    for (int i =0 ; i < power ; i++ ){
        base = base * 10 ;
    }
    return base ;
}


int main()
{
    cout << intToRoman(1994) << endl;
    cout << intToRoman(58) << endl;
    cout << intToRoman(37) << endl;
    cout << intToRoman(435) << endl;

    return 0;
}
