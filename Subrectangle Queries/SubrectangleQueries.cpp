#include<vector>
using namespace std;

class SubrectangleQueries {
private:
    vector<vector<int>> m_rectangle;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        m_rectangle = rectangle ;
    }
    
    void updateSubrectangle(int r1, int c1, int r2, int c2, int val) {
        for(int i = r1 ; i <= r2 ; i++){
            for (int j = c1 ; j <= c2 ; j++){
                m_rectangle[i][j] = val ;
            }
        }
    }
    
    int getValue(int r, int c) {
        return  m_rectangle[r][c];
    }
    
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */