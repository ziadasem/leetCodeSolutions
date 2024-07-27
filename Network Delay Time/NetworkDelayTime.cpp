#include<vector>
#include <map>
using namespace std;
class Solution {
public:

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<int>> path =  vector<vector<int>>(n + 1);
        for (int i = 0 ; i < n+1 ; i++){
            path[i] =  vector<int>(n + 1);
            for (int j =  1 ; j < n+1 ; j++){
                path[i][j] = 2147483647 ;
            }
            path[i][i] = 0 ;
        }
        

        //filling paths
        for (int i = 0 ; i < times.size(); i++){
            path[ times[i][0]  ][times[i][0]] = 0;
            path[ times[i][0]  ][times[i][1]] = times[i][2];
        }
        
        //update and find min path
        int count;
        do{
            count = 0 ;
            for (int src = 1 ; src< n + 1 ; src ++){
                for (int dest = 1 ; dest < n+1 ; dest ++){
                    if (path[src][dest] != 0){
                        int min = path[src][dest]  ;
                        for (int k =  1; k <  n+1 ; k++){
                            if (path[src][k] != 2147483647 &&  path[k][dest] != 2147483647 && src != k && dest != k){
                                if ( (path[src][k] + path[k][dest]) < min){
                                    min = path[src][k] + path[k][dest] ;
                                }
                            }
                        }
                        if (min !=  path[src][dest] ){
                            path[src][dest] = min ;
                            count ++ ;
                        }
                    }
                }
            }
        }while(count > 0);
        int sum  = 0 ;
        for (int i = 1 ; i < n+1 ; i++){
            if (path[k][i] == 2147483647 ){
                return -1 ;
            }else{
                sum += path[k][i] ;
            }
        }
        
        return sum ;
}
   
};