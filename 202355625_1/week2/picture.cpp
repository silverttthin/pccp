// 1926/그림 /baekjoon 
// 72ms
// 1.5h
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int x, int y, vector<vector<int>>& paper, vector<vector<bool>>& visited, int n, int m) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int area = 1;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (paper[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    area++;
                }
            }
        }
    }

    return area;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> paper(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> paper[i][j];
    int pictureCount = 0;
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && paper[i][j] == 1) {
                int area = bfs(i, j, paper, visited, n, m);
                pictureCount++;                    
                maxArea = max(maxArea, area);      
            }
        }
    }
    cout << pictureCount << "\n" << maxArea << "\n";
    return 0;
}
