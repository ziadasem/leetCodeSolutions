#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int capacity = 0 ;
    int l =0 ;
    int r = height.size() - 1 ;
    while(l < r){
        int currentCapacity = (r - l);
        if (height[l] < height[r]){
            currentCapacity *= height[l] ;
            l++;
        }else{
            currentCapacity *= height[r] ;
            r-- ;
        }
        if (currentCapacity > capacity){
            capacity = currentCapacity;
        }

    }
     return capacity;
}