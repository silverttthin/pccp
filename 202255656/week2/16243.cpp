#include <iostream>
#include <vector>

// 백준 16234 인구이동
// 알고리즘 : 그래프, 구현, 시뮬레이션, BFS

using namespace std;

void print(const vector<vector<int>>& vvi) {
    for (const vector<int>& vi : vvi) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print(const vector<pair<int, int>>& vpii) {
    for (auto [a, b] : vpii) {
        printf("{%d, %d} ", a, b);
    }
    printf("\n");
}

void print(const vector<vector<pair<int, int>>>& vvpii) {
    for (const vector<pair<int, int>>& vpii : vvpii) {
        print(vpii);
    }
    printf("\n");
}

vector<vector<int>> map;
vector<vector<int>> visited;

int N, L, R;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<vector<pair<int, int>>> alliances;

bool moved_atLeastOnce;
void search_map(int x, int y, int allianceCount) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N) continue;
        if (ny < 0 || ny >= N) continue;
        if (visited[nx][ny] > 0) continue;
        int populationDiff = abs(map[x][y] - map[nx][ny]);
        if (populationDiff < L || populationDiff > R) continue;
        visited[nx][ny] = allianceCount;
        moved_atLeastOnce = true;
        alliances[alliances.size() - 1].push_back({nx, ny});
        search_map(nx, ny, allianceCount);
    }
}

void move_people() {
    vector<pair<int, int>> nextPopulations (alliances.size(), {0, 0});
    for (int i = 0; i < alliances.size(); i++) {
        for (int j = 0; j < alliances[i].size(); j++) {
            auto [x, y] = alliances[i][j];
            nextPopulations[i].first += map[x][y];
            nextPopulations[i].second++;
        }
        nextPopulations[i].first /= nextPopulations[i].second;
    }

    for (int i = 0; i < alliances.size(); i++) {
        for (int j = 0; j < alliances[i].size(); j++) {
            auto [x, y] = alliances[i][j];
            map[x][y] = nextPopulations[i].first;   
        }
    }
}

void populationMovement() {
    int day = 0;
    while (true) {
        moved_atLeastOnce = false;
        int allianceCount = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == 0) {
                    alliances.push_back({});
                    search_map(i, j, allianceCount);
                    allianceCount++;
                    if (alliances[alliances.size() - 1].size() == 0) {
                        alliances.pop_back();
                        continue;
                    }
                    move_people();
                }
            }
        }
        alliances.clear();
        visited = vector<vector<int>> (N, vector<int> (N, 0));
        if (moved_atLeastOnce == false) break;
        day++;
    }
    cout << day << endl;
}

int main() {
    cin >> N >> L >> R;

    visited.resize(N, vector<int> (N, 0));
    map.resize(N, vector<int> (N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    populationMovement();

    return 0;
}
