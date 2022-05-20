# avg_x_{n + 1} = 1 / (n + 1) [n * avg_x_{n} + x_{n + 1}]
#               = 1 / (n + 1) [(n+1) * avg_x_{n} + x_{n + 1} - avg_x_{n} ]
#               = avg_x_{n} + 1 / (n + 1) [x_{n + 1} - avg_x_{n} ]

import time
import numpy as np


def sum1(nums):
    x_avg = nums[0]
    for i in range(len(nums)):
        x_avg = x_avg + (nums[i] - x_avg) / (i + 1)
    return x_avg

def sum2(nums):
    sum = 0
    for i in range(len(nums)):
        sum += nums[i]
    return sum / len(nums)

if __name__=="__main__":

    nums = [1, 2, 3, 4, 5]
    x_avg = nums[0]
    for i in range(len(nums)):
        x_avg = x_avg + (nums[i] - x_avg) / (i + 1)

    print("input:", nums)
    print("average:", x_avg)


    # nums = np.random.randint(low=1e8, high=2e8, size=(100))
    # t0 = time.time()
    # print(sum1(nums))
    # t1 = time.time()
    # print(sum2(nums))
    # t2 = time.time()
    #
    #
    # print("iteration:", t1 - t0,"traverse:", t2 - t1)