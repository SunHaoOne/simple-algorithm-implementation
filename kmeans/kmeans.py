## 重构一下代码
import numpy as np
import matplotlib.pyplot as plt



# 生成更有特点的一些数据并且保存在data中
# data = []
# NUM_SUB_POINTS = int(NUM_POINTS/4)

# x_1 = np.random.uniform(low = 0, high = 20, size=(NUM_SUB_POINTS,))
# y_1 = np.random.uniform(low = 80, high = 100, size=(NUM_SUB_POINTS,))
# x_2 = np.random.uniform(low = 80, high = 100, size=(NUM_SUB_POINTS,))
# y_2 = np.random.uniform(low = 80, high = 100, size=(NUM_SUB_POINTS,))
# x_3 = np.random.uniform(low = 0, high = 20, size=(NUM_SUB_POINTS,))
# y_3 = np.random.uniform(low = 0, high = 20, size=(NUM_SUB_POINTS,))
# x_4 = np.random.uniform(low = 80, high = 100, size=(NUM_SUB_POINTS,))
# y_4 = np.random.uniform(low = 0, high = 20, size=(NUM_SUB_POINTS,))
# for i in range(NUM_SUB_POINTS):
#     data.append([x_1[i], y_1[i]])
#     data.append([x_2[i], y_2[i]])
#     data.append([x_3[i], y_3[i]])
#     data.append([x_4[i], y_4[i]])

# centers = []
# idx = np.random.randint(0, NUM_SUB_POINTS)
# centers.append([x_1[idx], y_1[idx]])
# centers.append([x_2[idx], y_2[idx]])
# centers.append([x_3[idx], y_3[idx]])
# centers.append([x_4[idx], y_4[idx]])


# 定义距离计算函数
def distance(p1, p2):
    dx = p2[0] - p1[0]
    dy = p2[1] - p1[1]
    return np.sqrt(dx ** 2 + dy ** 2)


def kmeans(data, centers):
    centerDiff = float('inf')
    while centerDiff >= PRECISION:
        clusters = []
        # 根据最近的中心点来进行分类q
        for p in data:
            minCenterDist = float('inf')
            nearestCenterIdx = None
            for i in range(NUM_CLASS):
                # 计算当前数据的点和中心点的距离
                dist = distance(p, centers[i])
                if dist < minCenterDist:
                    minCenterDist = dist
                    nearestCenterIdx = i
            # 遍历当前点和所有中心点的距离后，将最小的距离对应的中心点索引处处下来，作为当前点的类别
            clusters.append(nearestCenterIdx)

        # 将每一个数据的坐标点更换为平均后的坐标点，存储下来
        newCenters = []

        for i in range(NUM_CLASS):
            avgX = 0.0
            avgY = 0.0
            countX = 0
            countY = 0
            for j in range(len(data)):
                # 由于已经存储了对应数据的类别，计算当前类别对应的中心点坐标
                if clusters[j] == i:
                    avgX += data[i][0]
                    avgY += data[i][1]
                    countX += 1
                    countY += 1
            # 如果该类别有数据，那么计算该类别的平均值作为新的中心点
            if countX != 0:
                avgX /= countX
                avgY /= countY
                newCenters.append([avgX, avgY])
            else:
                newCenters.append(centers[i])

        # 计算这个新旧中心点的距离
        maxCenterDiff = 0.0
        for i in range(len(centers)):
            diff = distance(centers[i], newCenters[i])
            if diff > maxCenterDiff:
                maxCenterDiff = diff

        centerDiff = maxCenterDiff
        centers = newCenters
        print("errors:", centerDiff)
    return clusters


def visualize(data, cluster):
    markers = ['ro', 'bo', 'go', 'yo', 'mo', 'co', 'ko']

    for i in range(len(data)):
        x = data[i][0]
        y = data[i][1]
        marker = markers[clusters[i]]
        plt.plot(x, y, marker)
    plt.show()


if __name__=="__main__":
    # https://www.cnblogs.com/pinard/p/6164214.html

    # 定义超参数
    NUM_POINTS = 100  # 随机生成点的个数
    NUM_CLASS = 3  # 可视化最多支持7个类别
    PRECISION = 1e-6  # 迭代的精度设置

    # 随机生成一些数据保存在data中
    data = []
    x = np.random.uniform(low=0, high=100, size=(NUM_POINTS,))
    y = np.random.uniform(low=0, high=100, size=(NUM_POINTS,))
    for i in range(len(x)):
        data.append([x[i], y[i]])

    # 随机选择数据中的一些坐标点作为初始的中心坐标点
    centers = []
    for i in range(NUM_CLASS):
        idx = np.random.randint(0, NUM_POINTS)
        centers.append([data[idx][0], data[idx][1]])

    clusters = kmeans(data, centers)
    visualize(data, clusters)
