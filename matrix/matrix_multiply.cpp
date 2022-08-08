#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;


// 实现矩阵乘法
vector<vector<int>> multiply(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
	// [m, k] * [k, n] = [m, n]
	int m = matrix1.size();
	int k = matrix1[0].size();

	int kk = matrix2.size();
	int n = matrix2[0].size();

	assert(k == kk);

	vector<vector<int>> res(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int u = 0; u < k; u++) {
				cout << matrix1[i][u] << " " << matrix2[u][j] << endl;
				res[i][j] += matrix1[i][u] * matrix2[u][j];
			}
		}
	}
	return res;
}


void printMatrix(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{	
	int m = 2;
	int k = 2;
	int kk = 2;
	int n = 2;
	vector<vector<int>> matrix1(m, vector<int>(k, 1));
	vector<vector<int>> matrix2(kk, vector<int>(n));

	matrix2 = { {1,2},{3,4} };

	vector<vector<int>> res = multiply(matrix1, matrix2);

	printMatrix(res);

	return 0;

}


