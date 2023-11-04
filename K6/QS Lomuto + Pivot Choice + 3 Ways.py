import random
import time

def quicksort(A, lo, hi):
    if lo < hi:
        p = pivot(A, lo, hi)
        left, right = partition(A, p, lo, hi) # 三路混合
        quicksort(A, lo, left - 1)
        quicksort(A, right + 1, hi)

def partition(A, p, lo, hi):
    left = lo
    right = hi
    i = lo

    while i <= right:
        if A[i] < p:
            A[i], A[left] = A[left], A[i]
            left += 1
            i += 1
        elif A[i] > p:
            A[i], A[right] = A[right], A[i]
            right -= 1
        else:
            i += 1
    return left, right

def pivot(A, lo, hi): # 三数取中
    mid = (hi - lo) // 2 + lo
    if A[mid] < A[lo]:
        A[lo], A[mid] = A[mid], A[lo]
    if A[hi] < A[lo]:
        A[lo], A[hi] = A[hi], A[lo]
    if A[mid] < A[hi]:
        A[hi], A[mid] = A[mid], A[hi]
    return A[hi]

A = []
for i in range(0, 100000):
    A.append(random.uniform(0, 100000))

t = time.time()
quicksort(A, 0, len(A) - 1)
timeCost = time.time() - t
f = open('log_py.txt','w')
print(A)
print(A, file=f)
f.close()
print("\nTime Cost of QS Func: " + str(timeCost) + " s")