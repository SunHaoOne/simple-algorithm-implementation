#include <iostream>
#include <vector>
using namespace std;

// kernal = [3, 3], stride = [1, 1], matrix_size = [m, m]
// Maxpool2D, Averagepool2D, Conv2D, MODE = SAME


template<typename elemType>
void showMatrix(vector<vector<elemType>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


float getAverage(vector<vector<int>>& X, int m, int n, int kernel_size, int strides) {
    float sum = 0;
    for (int i = m * strides; i < m * strides + kernel_size; i++) {
        for (int j = n * strides; j < n * strides + kernel_size; j++) {
            sum += X[i][j];
        }
    }
    return sum / (kernel_size * kernel_size);
}

float getMax(vector<vector<int>>& X, int m, int n, int kernel_size, int strides) {
    int maxVal = INT_MIN;
    for (int i = m * strides; i < m * strides + kernel_size; i++) {
        for (int j = n * strides; j < n * strides + kernel_size; j++) {
            maxVal = max(maxVal, X[i][j]);
        }
    }
    return maxVal;
}

float getConv(vector<vector<int>>& X, vector<vector<int>>& w, int m, int n, int kernel_size, int strides) {
    int sum = 0;
    for (int i = m * strides; i < m * strides + kernel_size; i++) {
        for (int j = n * strides; j < n * strides + kernel_size; j++) {
            sum += X[i][j] * w[i - m * strides][j - n * strides];
        }
    }
    return sum;
}


vector<vector<int>> padSame(vector<vector<int>>& X, int kernel_size, int strides) {
    int out = ceil( float (X.size()) / strides);
    int pad = (out - 1) * strides + kernel_size - X.size();
    int pad_l = floor(pad / 2);
    vector<vector<int>> res(X.size() + pad, vector<int>(X[0].size() + pad, 0));
    for (int i = pad_l; i < X.size() + pad_l; i++) {
        for (int j = pad_l; j < X[0].size() + pad_l; j++) {
            res[i][j] = X[i - pad_l][j - pad_l];
        }
    }
    return res;
}

vector<vector<int>> padValid(vector<vector<int>>& X, int kernel_size, int strides) {
    int out = ceil((X.size() - kernel_size + 1) / strides);
    int len = (out - 1) * strides + kernel_size;
    vector<vector<int>> res(len, vector<int>(len, 0));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            res[i][j] = X[i][j];
        }
    }
    return res;
}

vector<vector<float>> averagePooling2D(vector<vector<int>>& X, int kernel_size, int strides, string mode) {
    vector<vector<int>> padX;
    if (mode == "SAME") padX = padSame(X, kernel_size, strides);
    else if (mode == "VALID") padX = padValid(X, kernel_size, strides);
    int out = (padX.size() - kernel_size) / strides + 1;
    vector<vector<float>> res(out, vector<float>(out, 0));
    for (int i = 0; i < out; i++) {
        for (int j = 0; j < out; j++) {
            res[i][j] = getAverage(padX, i, j, kernel_size, strides);
        }
    }
    return res;
}

vector<vector<float>> maxPooling2D(vector<vector<int>>& X, int kernel_size, int strides, string mode) {
    vector<vector<int>> padX;
    if (mode == "SAME") padX = padSame(X, kernel_size, strides);
    else if (mode == "VALID") padX = padValid(X, kernel_size, strides);
    int out = (padX.size() - kernel_size) / strides + 1;
    vector<vector<float>> res(out, vector<float>(out, 0));
    for (int i = 0; i < out; i++) {
        for (int j = 0; j < out; j++) {
            res[i][j] = getMax(padX, i, j, kernel_size, strides);
        }
    }
    return res;
}

vector<vector<float>> conv2D(vector<vector<int>>& X, vector<vector<int>>& w, int kernel_size, int strides, string mode) {
    vector<vector<int>> padX;
    if (mode == "SAME") padX = padSame(X, kernel_size, strides);
    else if (mode == "VALID") padX = padValid(X, kernel_size, strides);
    int out = (padX.size() - kernel_size) / strides + 1;
    vector<vector<float>> res(out, vector<float>(out, 0));
    for (int i = 0; i < out; i++) {
        for (int j = 0; j < out; j++) {
            res[i][j] = getConv(padX, w, i, j, kernel_size, strides);
        }
    }
    return res;
}





int main(){
    cout << "========INPUT========" << endl;
    int kernel_size = 2;
    int stride = 2;
    cout << "kernel_size = "<< kernel_size << ", stride = " << stride << endl;
    cout << "Matrix X:" << endl;
    vector<vector<int>> X = {{1,2,3},{4,5,6},{7,8,9}};
    showMatrix(X);

    cout << "Matrix w:" << endl;
    // vector<vector<int>> w = {{1,1,1},{1,1,1},{1,1,1}};
    vector<vector<int>> w(3, vector<int>(3, 1));
    showMatrix(w);


    cout << "========PADDING========" << endl;

    cout << "Pad X, Same:" << endl;
    vector<vector<int>> padX = padSame(X, kernel_size, stride);
    showMatrix(padX);

    cout << "Pad X, Valid:" << endl;
    vector<vector<int>> padX2 = padValid(X, kernel_size, stride);
    showMatrix(padX2);

    cout << "========SAME========" << endl;

    cout << "AveragePooling2D:" << endl;
    vector<vector<float>> res = averagePooling2D(X, kernel_size, stride, "SAME");
    showMatrix(res);

    cout << "MaxPooling2D:" << endl;
    vector<vector<float>> res2 = maxPooling2D(X, kernel_size, stride, "SAME");
    showMatrix(res2);

    cout << "Conv2D:" << endl;
    vector<vector<float>> res3 = conv2D(X, w, kernel_size, stride, "SAME");
    showMatrix(res3);


    cout << "========VALID========" << endl;

    cout << "AveragePooling2D:" << endl;
    vector<vector<float>> res4 = averagePooling2D(X, kernel_size, stride, "VALID");
    showMatrix(res4);

    cout << "MaxPooling2D:" << endl;
    vector<vector<float>> res5 = maxPooling2D(X, kernel_size, stride, "VALID");
    showMatrix(res5);

    cout << "Conv2D:" << endl;
    vector<vector<float>> res6 = conv2D(X, w, kernel_size, stride, "VALID");
    showMatrix(res6);


}


