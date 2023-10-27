import time

def fib( n ):
    return (1 / 5 ** 0.5) * (((1 + 5 ** 0.5) / 2) ** i - ((1 - 5 ** 0.5) / 2) ** i)

t = time.time()
for i in range(1, 51):
    print('F(' + str(i) + ')=' + str(int(fib(i))))
print(f'Time run: {time.time() - t:.4f}s')