import time

def fib( n ):
    if n == 0 or n == 1:
        return n
    else:
        return fib( n - 1 ) + fib( n - 2 )

t = time.time()
for i in range(1, 51):
    print('F(' + str(i) + ')=' + str(fib(i)))
print(f'Time run: {time.time() - t:.4f}s')