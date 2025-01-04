#include <vector>
#define MAX(a,b) (( (a) < (b )) ? (a) : (b))
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() == 1){ return 0;}
        int size = prices.size();
        int low = 0;
        int high = 1;
        int maxProfit = MAX(0, prices[1]- prices[0]) ;
        for (; high < size; high ++){
            if (prices[low] > prices[high]){
                low =high ;
            }else{
                maxProfit = MAX(maxProfit, prices[high] - prices[low]);
            }
        }
        return maxProfit;
    }
};