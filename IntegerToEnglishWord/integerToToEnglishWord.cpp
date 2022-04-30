#include <iostream>
#include<string>

using namespace std;


string numberToWords(int num);
string digitToEnglish(int num, int base);
string numberToEnglishWord(int num);
string baseTenthToEnglishWord(int num);
string tenthToEnglishWord(int base);
string baseToEnglishWord(int base);
int countDigits(int number);
int powOf10(int power);
string hundridsToDigit(int num);
string emptySpaces(string result);



string numberToWords(int num) {
    int numLength = countDigits(num);
    string result = "" ;
    if (num == 0){
        return "Zero";
    }
    for(int base = 0 ; base <numLength; base = base + 3){
            int powOf10Value = powOf10(base) ;
            int hundridsPart = num  ;
            hundridsPart = (hundridsPart / powOf10Value) %1000 ;
            if (hundridsPart !=0)
                result = hundridsToDigit(hundridsPart) +baseToEnglishWord(base)  + result;
        }

    return emptySpaces(result);
}


string hundridsToDigit(int num){
    string result ="";
    int hundrid = num /100;
    if (hundrid != 0){
       result = numberToEnglishWord(hundrid) + " Hundred "  ;
    }
    //isolate two numbers
    num = num - (hundrid * 100) ;
    int tenth = num / 10 ;
    int units = num - tenth*10;
    if (tenth == 1){//special case
       result += baseTenthToEnglishWord(units);
    }else{
        if(tenthToEnglishWord(tenth) != ""){
            result += tenthToEnglishWord(tenth) + " " + numberToEnglishWord(units);
        }else{
            result += numberToEnglishWord(units);
        }
    }
    return (result);

}




string numberToEnglishWord(int num){
    switch (num){
            case 1 :
                return  "One "  ;
            case 2 :
                return "Two " ;
            case 3 :
                return "Three "  ;
            case 4 :
                return "Four "  ;
            case 5 :
                return "Five " ;
            case 6 :
                return "Six "  ;
            case 7 :
                return "Seven "  ;
            case 8 :
                return "Eight "  ;
            case 9 :
                return "Nine "  ;
            default :
                return "" ;
           }
}

string baseTenthToEnglishWord(int num){
    switch (num){
            case 0 :
                return "Ten " ;
            case 1 :
                return "Eleven " ;
            case 2 :
                return "Twelve "  ;
            case 3 :
                return "Thirteen "  ;
            case 4 :
                return "Fourteen "  ;
            case 5 :
                return "Fifteen " ;
            case 6 :
                return "Sixteen "  ;
            case 7 :
                return "Seventeen "  ;
            case 8 :
                return "Eighteen "  ;
            case 9 :
                return "Nineteen "  ;
            default :
                return "" ;
           }
}

string tenthToEnglishWord(int base){
    switch (base){
            case 2 :
                return "Twenty " ;
            case 3 :
                return "Thirty "  ;
            case 4 :
                return "Forty "  ;
            case 5 :
                return "Fifty " ;
            case 6 :
                return "Sixty "  ;
            case 7 :
                return "Seventy "  ;
            case 8 :
                return "Eighty "  ;
            case 9 :
                return "Ninety "  ;
            default :
                return "" ;
           }
}



string baseToEnglishWord(int base){
    switch (base){
            case 3 :
                return "Thousand "  ;
            case 6 :
                return "Million "  ;
            case 9 :
                return "Billion " ;
            case 12 :
                return "Trillion "  ;
            case 15 :
                return "Quadrillion "  ;
            default :
                return "" ;
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

string emptySpaces(string result){
    int i  ;
    for (i = 0 ; result[i] != '\0'; i++){
        if (result[i] == result[i+1] && result[i] == ' '){
            result.erase(i, 1);
        }
    }

    if (result[i-1] == ' '){
         result.erase(i-1, 1);
    }
    return result;
}


int main()
{
    cout<<numberToWords(1234)<<endl;
    cout<<numberToWords(12345)<<endl;
    cout<<numberToWords(123456)<<endl;
    cout<<numberToWords(1000000);

    return 0;
}
