import time


t = time.time()

a, b, tmp = 1, 1, 0
n = 50
print("F(1)=1")
for i in range(1, 50):
	tmp = a
	a = b
	b = tmp + b
	print("F(" + str(i+1) + ")=" + str(a))

print(f'Time run: {time.time() - t:.4f}s')