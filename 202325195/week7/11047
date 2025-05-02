//11047/동전0/BOJ
//44ms
//15m

N, K = map(int,input().split())
mo = []

for i in range(0,N):
	aa = int(input())
	mo.append(aa)
mo.sort(reverse=True)
count = 0
for i in mo:
	count += K//i
	K = K%i
print(count)
