import sys
input = sys.stdin.readline

S = list(input().rstrip("\n"))
T = list(input().rstrip("\n"))
s, t = len(S), len(T)
for i in range(t - s):
    if T.pop(-1) == 'B':
        T = list(reversed(T))
print(int(S == T))

