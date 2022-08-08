#include<iostream>
#include<vector>
using namespace std;

class node {
public:
    node(int _row, int _col, int _val) {
        row = _row;
        col = _col;
        val = _val;
    }
    int row;
    int col;
    int val;
};
class SparseMatrix {
public:
    vector<node> getSparseMatrix(vector<vector<int>>& matrix) {
        vector<node> sparse_matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    sparse_matrix.push_back(node(i, j, matrix[i][j]));
                }
            }
        }
        return sparse_matrix;
    }

    void showSparseMatrix(vector<node> sparse_matrix) {
        int n = sparse_matrix.size();
        for (int i = 0; i < n; i++) {
            int row = sparse_matrix[i].row;
            int col = sparse_matrix[i].col;
            int val = sparse_matrix[i].val;
            cout << "[" << row << "," << col << "]:" << val << endl;

        }
        cout << endl;
    }

    void showMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

    }

    vector<vector<int>> multiply(vector<vector<int>>& m1, vector<vector<int>>& m2) {
        vector<vector<int>> res(m1.size(), vector<int>(m2[0].size()));
        vector<node> s1 = getSparseMatrix(m1);
        vector<node> s2 = getSparseMatrix(m2);
        for (node p1 : s1) {
            for (node p2 : s2) {
                // 3 * 5   5 * 4，以第一个矩阵为基础遍历第二个是否非零
                if (p1.col == p2.row) {
                    res[p1.row][p2.col] += p1.val * p2.val;
                }
            }
        }
        return res;
    }
};



int main() {

    vector<vector<int>> matrix = { 
        {0,0,2,0,0},
        {1,0,0,0,0},
        {0,0,0,0,0},
        {0,0,4,0,0},
        {0,0,0,0,0}
    };
    SparseMatrix s;
    s.showSparseMatrix(s.getSparseMatrix(matrix));


    vector<vector<int>> m1 = {
    {0,0,2},
    {1,0,0},
    };

    vector<vector<int>> m2 = {
    {0,1},
    {2,0},
    {0,1}
    };



    vector<vector<int>> res = s.multiply(m1, m2);
    s.showSparseMatrix(s.getSparseMatrix(res));
    s.showMatrix(res);




    return 0;
}
