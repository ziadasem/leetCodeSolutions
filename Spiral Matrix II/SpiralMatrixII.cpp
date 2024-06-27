#include<vector>
using namespace std; 
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result = vector<vector<int>>(n);
        int dr[] = { 0, 1, 0, -1 };
        int dc[] = { 1, 0, -1, 0 };
 
        for (int i = 0 ; i < n ; i++){
            result[i] = vector<int>(n);
        }
        int count = 1 ;
        int directionIndex = 0;
        int i =0;
        int j = 0 ;
        while(count <= n*n){
            result[i][j] = count ++ ;
            int newI = (i + dr[directionIndex]);
            int newJ = (j + dc[directionIndex]);    
           if (newI >= 0 && newI < n && newJ >=0 && newJ < n && result[newI][newJ] == 0){
                i = newI ;
                j = newJ ;
            }else{
                directionIndex = (directionIndex + 1 )%4 ;
                i = (i + dr[directionIndex]);
                j = (j + dc[directionIndex]);    
                
            }
        }
    return result;
    }
};