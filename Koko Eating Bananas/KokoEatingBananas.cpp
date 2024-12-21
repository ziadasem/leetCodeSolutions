#include <vector>
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        long maxPilevalue = piles[0];
        long pilesSize = piles.size();
        for (int i {1}; i < pilesSize; i++) {
            if (piles[i] > maxPilevalue){
                maxPilevalue = piles[i];
            }
        }
        long minimumK = maxPilevalue ;
        long l = 1 ;
        long r = maxPilevalue ;
        long mid ;
        long hoursToEmptyPile ;
        while (l <= r) {
            mid = (l + r) / 2;
            hoursToEmptyPile = 0 ;
            for (int i =0 ; i <pilesSize ; i++ ){
                hoursToEmptyPile+= ( (piles[i] / mid)) ;
                if ((piles[i] % mid != 0)){
                    hoursToEmptyPile++ ;
                }
            }
            if (hoursToEmptyPile > h){
                l = mid + 1;
            } else {
                if (mid < minimumK){
                    minimumK = mid;
                }
                r = mid - 1;
            }
            
        }
        return  minimumK;
    }
};
