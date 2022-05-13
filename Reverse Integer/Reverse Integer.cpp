class Solution {
public:
    int reverse(int x){
        long value = 0 ;
        while(x != 0){
            value =value * 10 + x%10;
            x /= 10;
        }
        if (value >= 2147483647 ||value <= - 2147483648){
            return 0;
        }
        return value ;
    }

};
