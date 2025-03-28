#include <iostream>
#include <vector>
#include <utility>

// 백준 16234 인구이동
// 알고리즘 : 그래프, 구현, 시뮬레이션, BFS, DFS

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;

int N, L, R;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<pair<int, int>> alliance;

bool moved_atLeastOnce;
void search_alliance(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N) continue;
        if (ny < 0 || ny >= N) continue;
        if (visited[nx][ny] == true) continue;
        int populationDiff = abs(map[x][y] - map[nx][ny]);
        if (populationDiff < L || populationDiff > R) continue;
        visited[nx][ny] = true;
        moved_atLeastOnce = true;
        alliance.push_back({nx, ny});
        search_alliance(nx, ny);
    }
}

void move_people() {
    int sum = 0;
    for (auto [x, y] : alliance) sum += map[x][y];
    if (alliance.size() > 0) sum /= alliance.size();
    for (auto [x, y] : alliance) map[x][y] = sum;
}

void populationMovement() {
    int day = 0;
    while (true) {
        visited = vector<vector<bool>> (N, vector<bool> (N, false));
        moved_atLeastOnce = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == true) continue;
                search_alliance(i, j);
                move_people();
                alliance.clear();
            }
        }
        if (moved_atLeastOnce == false) break;
        day++;
    }
    cout << day << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    map.resize(N, vector<int> (N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    populationMovement();

    return 0;
}
