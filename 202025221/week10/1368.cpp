/*
 * 1368/물대기/BOJ
 * 실행 시간: 8ms
 * 해결하는데 걸린 시간: 1h 20m
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> dig;
int adj[300][300];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
vector<int> visited(300, 0);

int main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    //  Q.  우물 파는 비용이 제일 낮은 논(L)은 우물을 무조건 파야 하는가?
    //  A.  YES. L이 다른 논과 연결되어 있는 경우, L의 우물을 파는 것이 가장 비용이 적게 듬
    //      L이 독립적인 논인 경우, L의 우물은 항상 파야 함

    cin >> n;
    for (int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        dig.emplace_back(cost, i);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    // 논을 최소한으로 연결해야함 -> MST 사용이 좋아 보임

    int start = 0;
    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        if (dig[i].first < ans) {
            ans = dig[i].first;
            start = i;
        }
    }

    int cnt = 0;
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (start == i) continue;
        pq.emplace(adj[start][i], start, i);
        pq.emplace(dig[i].first, -1, i);
    }

    while (cnt < n - 1) {
        int a, b, cost;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (visited[b]) continue;

        visited[b] = 1;
        ans += cost;
        cnt++;

        for (int i = 0; i < n; i++) {
            if (b == i or visited[i]) continue;
            pq.emplace(adj[b][i], b, i);
        }
    }
    cout << ans;
}
