# 2178 / 미로 탐색 / boj
# 64ms
# 25분 소요

import sys
import itertools as it
readline = sys.stdin.readline


height, width = map(int, readline().split())

visit = []
for _ in range(height):
    visit.append(list(map(int, readline().rstrip())))

def get_nexts(tup):
    y, x = tup
    def is_valid_range(tup):
        y, x = tup
        if (0 <= x < width) and (0 <= y < height) and (visit[y][x] != 0):
            visit[y][x] = 0
            return True
        else:
            return False
    
    nexts = [(y + 1, x), (y - 1, x), (y, x + 1), (y, x - 1)]
    return filter(is_valid_range, nexts)

visit[0][0] = 0
queue = [(0, 0)]

cnt = 0
while queue != []:
    cnt += 1
    for pos in queue:
        if pos == (height - 1, width - 1):
            print(cnt)
            exit(0)
    queue = list(it.chain.from_iterable(map(get_nexts, queue)))

