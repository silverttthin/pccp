/*
1012/유기농배추/BOG
0ms
30m
*/

#include <iostream>
#include <vector>
using namespace std;

int t, m, n, k, result = 0;
vector<vector<int>> adj;
vector<vector<bool>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (!visited[nx][ny] && adj[nx][ny] == 1)
            {
                dfs(nx, ny);
            }
        }
    }
}

void dfsAll()
{
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
        {
            if (!visited[i][j] && adj[i][j] == 1)
            {
                result += 1;
                dfs(i, j);
            }
        }
}
 
int main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> t;

    while (t--)
    {
        result = 0;
        cin >> m >> n >> k;

        adj = vector<vector<int>>(n, vector<int>(m, 0));
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        while (k--)
        {
            int x, y;
            cin >> y >> x;
            adj[x][y] = 1;
        }

        dfsAll();

        cout << result << '\n';
    }
}