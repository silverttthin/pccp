// 문제 번호/제목/출처 - 1012번/유기농 배추/백준 온라인 저지
// 실행 시간 - 0ms
// 해결하는데 걸린 시간 - 10분 이내

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> dy{1, 0, -1, 0}, dx{0, 1, 0, -1};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  while (T--) {
    int M, N, K; // 가로 M 세로 N
    cin >> M >> N >> K;
    vector<vector<int>> brd(N, vector<int>(M)), vst(N, vector<int>(M));
    while (K--) {
      int x, y;
      cin >> x >> y;
      brd[y][x] = 1;
    }

    int ans = 0;

    for (int a = 0; a < N; a++) {
      for (int b = 0; b < M; b++) {
        if (!brd[a][b] || vst[a][b]) continue;
        queue<pair<int, int>> q;
        q.push({a, b});
        vst[a][b] = 1;
        ans++;
        while (!q.empty()) {
          auto [y, x] = q.front(); q.pop();
          for (int i = 0; i < 4; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if (ny >= 0 && nx >= 0 && ny < N && nx < M && brd[ny][nx] && !vst[ny][nx]) {
              q.push({ny, nx});
              vst[ny][nx] = 1;
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }
}
