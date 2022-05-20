# avg_x_{n + 1} = 1 / (n + 1) [n * avg_x_{n} + x_{n + 1}]
#               = 1 / (n + 1) [(n+1) * avg_x_{n} + x_{n + 1} - avg_x_{n} ]
#               = avg_x_{n} + 1 / (n + 1) [x_{n + 1} - avg_x_{n} ]
nums = [1, 2, 3, 4, 5]
x_avg = nums[0]
for i in range(len(nums)):
    x_avg = x_avg + (nums[i] - x_avg) / (i + 1)

print("input:", nums)
print("average:", x_avg)