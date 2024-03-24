#include <vector>
#include <cmath>
#include <iostream>

class Solution {
public:
    int maxDistToClosest(std::vector<int>& seats) {
        std::vector<int> places ;
        for (int i = 0 ; i < seats.size() ; i++) {
            if (seats[i] == 1) {
                places.push_back(i) ;
            }
        }
        int max = places[0] - 0;
        for (int i = 0 ; i < places.size() - 1; i++) {
            int difference = places[i + 1] - places[i] ; 
            double step = difference / 2;
            int distance = ceil(step);
            if (distance > max) {
                max = distance; 
            }
        }
        int _max = seats.size() -  places[places.size() - 1] - 1 ;
        if (_max > max) {
                max = _max; 
        }
        return max;
    }
};

int main(){
    Solution s = Solution();
    std::vector<int> seats{1,0,0,0,1,0,1};
    std::cout<<s.maxDistToClosest(seats)<<"\n";

    std::vector<int> seats2{1,0,0,0};
    std::cout<<s.maxDistToClosest(seats2)<<"\n";

    std::vector<int> seats3{0,1};
    std::cout<<s.maxDistToClosest(seats3)<<"\n";
}