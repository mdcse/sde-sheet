#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {

private:

    void setRow(vector< vector<int> >& v, int row) {
        for(int i = 0; i < v[row].size(); i++) {
            if(v[row][i] != -1)
                v[row][i] = 0;
        }
    }
    void setColumn(vector< vector<int> >& v, int col) {
        for(int i = 0; i < v.size(); i++) {
            if(v[i][col] != -1)
                v[i][col] = 0;
        }
    }
public:
    
    // Solution 2

    void setZeroes(vector< vector<int> >& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][j] = -1;
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == -1) {
                    setRow(matrix, i);
                    setColumn(matrix, j);
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
     }

    // solution 1
    // void setZeroes(vector<vector<int> >& matrix) {
    //     // make a alias of the matrix
    //     vector<vector<int> > temp(matrix);

    //     for(int i = 0; i < temp.size(); i++) {
    //         for(int j = 0; j < temp[i].size(); j++) {
    //             if(temp[i][j] == 0) {
    //                 setRow(matrix, i);
    //                 setColumn(matrix, j);
    //             }
    //         }
    //     }
    // }

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