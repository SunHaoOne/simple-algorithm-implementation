#include<iostream>
#include<vector>
/*
实现c++版本的kmeans，提升推理速度


*/
double distance(std::vector<double>& src, std::vector<double>& dst) {
    double sum = 0;
    for (int i = 0; i < src.size(); i++) {
        sum += (src[0] - dst[0]) * (src[0] - dst[0]) + (src[1] - dst[1]) * (src[1] - dst[1]);
    }
    return sum;
}

std::vector<int> kmeans(std::vector<std::vector<double>>& points, std::vector<std::vector<double>>& centers) {
    /*
    1. 计算每一个点到中心点的距离，记录最小的索引存下来
    2. 遍历每一个类别中所有的点，将他们的平均值作为新的中心点
    3. 计算新旧中心点的距离，用来计算终止条件，如果满足后直接用新中心点替换旧中心点的含义。
    */
    int n = points.size();
    int k = centers.size();
    std::vector<int> idx(n);
    double error = 0;


    double cur_error = 1e6;
    while (true) {
        if (cur_error < 1e-6) {
            std::cout << "cur_error = " << cur_error << std::endl;
            break;
        }

        for (int i = 0; i < n; i++) {
            double minDist = 1e6;
            int cur_idx = -1;
            for (int j = 0; j < k; j++) {
                double dist = distance(points[i], centers[j]);
                if (dist < minDist) {
                    minDist = dist;
                    cur_idx = j;
                }
            }
            idx[i] = cur_idx;
        }

        // 计算x上的平均和y上的平均

        std::vector<std::vector<double>> new_centers(k, std::vector<double>(n,0)); 
        for (int j = 0; j < k; j++) {
            double sum_x = 0;
            double sum_y = 0;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (idx[i] == j) {
                    sum_x += points[i][0];
                    sum_y += points[i][1];
                    count++;
                }
            }
            std::cout << "count = " << count << std::endl;
            if (count > 0) {
                double avg_x = sum_x / count;
                double avg_y = sum_y / count;
                new_centers[j][0] = avg_x;
                new_centers[j][1] = avg_y;
            }
            else {
                new_centers[j][0] = centers[j][0];
                new_centers[j][1] = centers[j][1];
            }

        }
        std::cout << std::endl;

        for (auto center : new_centers) {
            std::cout << "[" << center[0] << ", " << center[1] << "]";
        }
        std::cout << std::endl;

        // 计算新旧中心点的距离
        double minCenterDist = 1e6;
        double maxError = 0;
        for (int j = 0; j < k; j++) {
            double dist = distance(new_centers[j], centers[j]);
            if (dist > maxError) {
                maxError = dist;
            }
        }
        std::cout << "E = " << cur_error;

        cur_error = maxError;
        centers = new_centers;
        // std::cout << "--------------" << std::endl;
        // for (int i : idx) {
        //     std::cout << "idx[i] = " << i << " ";

  

    }
    return idx;
}

int main() {
    /*
    写一个简单的代码测试，4个点分成两个类别。
    除此之外的话还有随机的初始化中心点，希望是两个坐标点。
    输入维度: points [M,2]
    输出维度  class [M] ， valud from 1 - K, 表示当前点属于哪一个类别。
    0 0
    1 1
    3 3
    4 4
    */
    std::vector<std::vector<double>> points = {{0,0},{1,1},{3,3},{4,4}};
    int n = points.size();
    // 随机的中心点直接选取point里面的两个点就可以了。

    std::vector<std::vector<double>> centers(2, std::vector<double>(2,0));
    int k = centers.size();
    for (int i = 0; i < k; i++) {
        centers[i] = points[i];
    }

    // for (auto center : centers) {
    //     std::cout << center[0] << ", " << center[1] << std::endl;
    // }
    
    auto res = kmeans(points, centers);

    for (int c : res) {
        std::cout << "c = " << c << std::endl;
    }
    

}
