import numpy as np

N = 2
C = 3


def entropy(pa, pb):
    return -pa * np.log(pb)


Output = np.random.random(size=(N, C))
GT = np.random.random(size=(N, C))

cross_entropy = -entropy(Output, Output) + entropy(Output, GT)

print(cross_entropy)
