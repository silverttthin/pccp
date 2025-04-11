#include <iostream>
#include <vector>
#include <algorithm>

// 백준 1149 RGB 거리 / DP

using namespace std;

void print_vector(const vector<vector<int>> vvi);

int main() {
    int N; cin >> N; // 2 <= N <= 1000

    vector<vector<int>> vvi;
    for (int i = 0; i < N; i++) {
        int R, G, B; cin >> R >> G >> B;
        vvi.push_back({R, G, B});
    }
    vector<vector<int>> dp(N, {0, 0, 0});
    dp[0] = vvi[0];
    for (int i = 1; i < N; i++) {
        dp[i][0] = vvi[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = vvi[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = vvi[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << *min_element(dp[N - 1].begin(), dp[N - 1].end()) << endl;

    return 0;
}
