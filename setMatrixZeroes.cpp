#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {

private:

    void setRow(vector< vector<int> >& v, int row) {
        for(int i = 0; i < v[row].size(); i++) {
            v[row][i] = 0;
        }
    }
    void setColumn(vector< vector<int> >& v, int col) {
        for(int i = 0; i < v.size(); i++) {
            v[i][col] = 0;
        }
    }
public:

    // solution 1
    void setZeroes(vector<vector<int> >& matrix) {
        // make a alias of the matrix
        vector<vector<int> > temp(matrix);

    for(int i = 0; i < temp.size(); i++) {
        for(int j = 0; j < temp[i].size(); j++) {
            if(temp[i][j] == 0) {
                setRow(matrix, i);
                setColumn(matrix, j);
            }
        }
    }

    }

    void print(vector<vector<int> >& v, int m, int n) {
        for(int i = 0; i < m; i++) {
            cout<<"\n";
            for(int j = 0; j < n; j++){
                cout<<v[i][j]<< ' ';
            }
        }
    }
};

int main() {
    int m, n;
    cin>>m>>n;
    vector<vector<int> > v(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            cin>>v[i][j];
        }
    }

    Solution obj = Solution();
    obj.setZeroes(v);
    obj.print(v, m, n);

}