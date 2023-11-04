import random
import time

def quicksort(A, lo, hi):
    if lo >= 0 and hi >= 0 and lo < hi:
        p = partition(A, lo, hi)
        quicksort(A, lo, p)
        quicksort(A, p + 1, hi)

def partition(A, lo, hi):

    i = lo
    j = hi

    mid = (hi - lo) // 2 + lo
    if A[mid] < A[lo]:
        A[lo], A[mid] = A[mid], A[lo]
    if A[hi] < A[lo]:
        A[lo], A[hi] = A[hi], A[lo]
    if A[mid] < A[hi]:
        A[hi], A[mid] = A[mid], A[hi]
    pivot = A[hi]

    while True:
        while A[i] < pivot:
            i += 1
        while A[j] > pivot:
            j -= 1
        if i >= j:
            return j
        A[i], A[j] = A[j], A[i]

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