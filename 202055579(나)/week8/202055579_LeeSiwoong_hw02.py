INF = int(1e9)
n = int(input())


adj_list = []
for _ in range(n):
    row = list(map(int, input().split()))
    for i in range(n):
        if row[i] == -1:
            row[i] = INF
    adj_list.append(row)

start, end = map(int, input().split())


next_node = []

for i in range(n):
    row = []
    for j in range(n):
        if adj_list[i][j] == INF or i == j:
            row.append(None)
        else:
            row.append(j)
    next_node.append(row) # next_node[i][j] = i->j을 가는 최단경로의 i 다음 노드를 저장


for k in range(n):
    for i in range(n):
        for j in range(n):
            if adj_list[i][k] + adj_list[k][j] < adj_list[i][j]:
                adj_list[i][j] = adj_list[i][k] + adj_list[k][j]
                next_node[i][j] = next_node[i][k] 
                # i->j 최단경로에서 i 다음 노드를 i -> k 노드로 가는 경로의 i 다음 노드로 갱신


shortest_path = []
cur = start 

if adj_list[start][end] != INF:
    shortest_path = [cur]
    while cur != end:
        next_cur = next_node[cur][end]
        if next_cur is None:
            shortest_path = []
            break
        shortest_path.append(next_cur) 
        cur = next_cur

print(f"Shortest cost from {start} to {end}: {adj_list[start][end]}")
if adj_list[start][end] == INF: print(f"Path from {start} to {end}: []")
else: print(f"Path from {start} to {end}: {shortest_path}")