#include <vector>
#include <algorithm>
#include <stack>
class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int,int>> carPairs =  std::vector<std::pair<int,int>>(position.size());
        for (int i =0; i < position.size(); i++){
            carPairs[i] = {position[i], speed[i]};
        }
        std::sort(carPairs.begin(), carPairs.end()); //sort cars
        std::stack<std::pair<int,int>> s ;

        s.push( carPairs[carPairs.size() - 1 ]);
        for (int i = carPairs.size() - 2 ; i >= 0; i-- ){
            std::pair<int, int> leadingCar = s.top();
            std::pair<int, int> latingCar = carPairs[i];
           
            double leadingTime = (target - leadingCar.first) / static_cast<double>(leadingCar.second) ;
            double latingTime = (target - latingCar.first) / static_cast<double>(latingCar.second);

            if (latingTime > leadingTime){ //car2 will catch car1
                s.push(latingCar);
            }
            
        }
        return s.size();
    }
};

int main(){
    Solution s ;
    std::vector v = std::vector<int>({6,8});
    std::vector v2 = std::vector<int>({3,2});

    int y = s.carFleet(10,v, v2);
    int x = 4 ;
}