class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp ;
    if (n == 0){
        return;
    }
    int index2 = 0 ;
    int index1 = 0 ;

    while(index1<m ){
        if(nums1[index1] > nums2[index2]){
            temp.push_back(nums2[index2++]);
            if (index2 >= n){
                break ;
            }
        }else{
            temp.push_back( nums1[index1++]);
        }
    }

    for (int i = index2 ; i < n ; i++){
       temp.push_back(nums2[i]);
    }
    for (int k = index1 ; k < m ; k++){
        temp.push_back(nums1[k]);
    }
    nums1 = temp ;
    }
};