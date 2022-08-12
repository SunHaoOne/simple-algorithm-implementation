#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

double PRECISION = 1.5;
int NUM_CLASS = 3;

double distance(vector<double>& p1, vector<double>& p2) {
    double dx = p2[0] - p1[0];
    double dy = p2[1] - p1[0];
    return sqrt(dx * dx + dy * dy);
}

vector<int> kmeans(vector<vector<double>>& data, vector<vector<double>>& centers) {

    double centerDiff = FLT_MAX;
    vector<vector<double>> newCenters(centers.size());
    vector<int> clusters;
    int nearestCenterIdx = 0;

    while (centerDiff >= PRECISION) {
        clusters.clear();
        newCenters.clear();
        // 根据最近的中心点来进行分类
        for (auto p : data) {
            double minCenterDist = FLT_MAX;
            for (int i = 0; i < NUM_CLASS; i++) {
                // 计算当前数据的点和中心点的距离
                double dist = distance(p, centers[i]);
                if (dist < minCenterDist) {
                    minCenterDist = dist;
                    nearestCenterIdx = i;
                }
            }
            // 遍历当前点和所有中心点的距离后，将最小的距离对应的中心点索引处处下来，作为当前点的类别
            clusters.push_back(nearestCenterIdx);
        }
        // 将每一个数据的坐标点更换为平均后的坐标点，存储下来
        for (int i = 0; i < NUM_CLASS; i++) {
            double avgX = 0;
            double avgY = 0;
            int countX = 0;
            int countY = 0;
            for (int j = 0; j < data.size(); j++) {
                // 由于已经存储了对应数据的类别，计算当前类别对应的中心点坐标
                if (clusters[j] == i) {
                    avgX += data[i][0];
                    avgY += data[i][1];
                    countX += 1;
                    countY += 1;
                }
            }
            // 如果该类别有数据，那么计算该类别的平均值作为新的中心点
            if (countX != 0) {
                cout << avgX << endl;
                avgX /= countX;
                avgY /= countY;
                cout << avgX << endl;
                newCenters.push_back({ avgX, avgY });
            }
            else {
                newCenters.push_back(centers[i]);
            }
        }
        // 计算新中心点和旧中心点的距离
        double maxCenterDiff = 0;
        for (int i = 0; i < centers.size(); i++) {
            double diff = distance(centers[i], newCenters[i]);
            cout << diff << endl;
            if (diff > maxCenterDiff) {
                maxCenterDiff = diff;
            }
        }
        centerDiff = maxCenterDiff;
        centers = newCenters;

        cout << "errors:" << centerDiff << endl;
    }
    return clusters;

}


int main() {

    vector<vector<double>> data = { {0,0},{0,1},{15,15},{15,16},{3,8},{3,7}};
    vector<vector<double>> center;

    center.push_back(data[0]);
    center.push_back(data[1]);
    center.push_back(data[5]);





    vector<int> res = kmeans(data, center);

    for (int i = 0; i < res.size(); i++) {
        cout << "[" << data[i][0] << "," << data[i][1] << "] :" << res[i] << endl;
    }


}
