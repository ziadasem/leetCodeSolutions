#include <map>
#include <iostream>
#include <set>

class Solution {
    private:
        std::map<int, int> rotator = { 
            {0,0},
            {1,1},
            {2,5},
            {3,-1},
            {4,-1},
            {5,2},
            {6,9},
            {7,-1},
            {8,8},
            {9,6},

        };
        bool canIncrement(int num, int divisor) {
            int reversed = 0 ;
            int digit ;
            int _num = num ;
            while (_num > 0) {
                digit = _num / divisor;
                digit = rotator[digit];
                if (digit < 0) {
                    return false;
                }
                reversed += (digit * divisor);
                _num %= divisor ;
                divisor /= 10;
            }

            return reversed != num ;
        }
    public:
        int rotatedDigits(int n) {
            int count = 0;
            for (int i = 0; i <= n && i < 10; i++){
                if (canIncrement(i, 1)){
                    count ++;
                }
            }
            for (int i = 10; i <= n && i <100; i++){
                if (canIncrement(i, 10)){ 
                    count ++;
                }
            }

            for (int i = 100; i <= n && i <1000; i++){
                if (canIncrement(i, 100)){
                    count ++;
                }
            }

            for (int i = 1000; i <= n && i <10000; i++){
                if (canIncrement(i, 1000)){
                    count ++;
                }
            }
            return count;
    }

};