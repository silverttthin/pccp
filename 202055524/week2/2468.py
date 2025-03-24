# 2468 / 안전 영역 / boj
# 1204
# 37m 소요
import sys
import itertools as it
readline = sys.stdin.readline


N = int(readline())
board  = []

min_height = 100
max_height = 0

for _ in range(N):
    board.append(list(map(int ,readline().split())))
    min_height = min(min_height, min(board[-1]))
    max_height = max(max_height, max(board[-1]))

def fill_board(sync_height):
  for y, line in enumerate(board):
      for x, height in enumerate(line):
          if height == sync_height:
                board[y][x] = -1

def get_nexts(pos):
    def is_valid(tup):
        y, x = tup
        return (0 <= x < N) and (0 <= y < N) and (board[y][x] > 0)
        
    y, x = pos
    nexts = [(y + 1, x), (y - 1, x), (y, x + 1), (y, x - 1)]

    return filter(is_valid, nexts)

    
def count_regions():
    cnt = 0
    
    visited = [[False for _ in range(N)] for _ in range(N)]
    
    def is_visited(tup):
        y, x = tup
        if visited[y][x] == False:
            visited[y][x] = True
            return True
        return False
    
    
    for y in range(N):
        for x in range(N):
            if visited[y][x] or board[y][x] < 0:
                continue
            queue = [(y, x)]
            visited[y][x] = True
            while queue != []:
                queue = list(filter(is_visited, it.chain.from_iterable(map(get_nexts, queue))))
            cnt += 1
    return cnt


def get_max_cnt():
    cnts = [count_regions()]
    for sync_height in range(1, max_height + 1):
        fill_board(sync_height)
        cnts.append(count_regions())
    return max(cnts)

print(get_max_cnt())
