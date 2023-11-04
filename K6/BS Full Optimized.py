import random
import time

def bubblesort(A):
    n = len(A)
    while n > 1:
        newn = 0
        for i in range(1, n):
            if A[i - 1] > A[i]:
                A[i - 1], A[i] = A[i], A[i - 1]
                newn = i
        n = newn
    return A

A = []
for i in range(0, 100000):
    A.append(random.uniform(0, 100000))

t = time.time()
bubblesort(A)
timeCost = time.time() - t
f = open('log_py.txt','w')
print(A)
print(A, file=f)
f.close()
print("\nTime Cost of BS Func: " + str(timeCost) + " s")