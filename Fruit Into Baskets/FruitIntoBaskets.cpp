#include<vector>
using namespace std; 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int currentCount = 1;
        int accumaltive = 1;
        int lastType = fruits[0];
        vector<int> fruitsCount = vector<int>(fruits.size());

        int basketsvector[2]= {fruits[0]};

        for (int i = 1 ; i < fruits.size(); i++){
            if (fruits[i] != lastType){
                basketsvector[1]  = fruits[i];
                break ;
            }
        }
        fruitsCount[0] = 1; 
        for (int i = 1 ; i < fruits.size(); i++){
            if (fruits[i] == basketsvector[0] || fruits[i] == basketsvector[1]){ //found
                if (lastType == fruits[i]){
                    accumaltive ++ ;
                }else{
                    accumaltive = 1 ;    
                }

                currentCount++ ;
            }else{
                currentCount = accumaltive + 1 ;
                accumaltive = 1 ; 

                if (basketsvector[0] ==lastType){
                    basketsvector[1] = fruits[i];
                }else{
                     basketsvector[0] = fruits[i];
                }
            }
            fruitsCount[i] = currentCount ;
            lastType = fruits[i];  
        }
        int max = fruitsCount[0];
        for (int i = 1 ; i < fruitsCount.size(); i++){
            if (fruitsCount[i] > max){
                max = fruitsCount[i];
            }
        }

        return max;
    }
};