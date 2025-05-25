#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int node, edges;
int mid1, mid2;
vector<pair<int, int>> adj[805];

// Dijkstra 함수: 시작점에서 모든 정점까지의 최단거리 반환
vector<int> dijkstra(int start) {
    vector<int> dist(node + 1, INF);
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto& edge : adj[cur]) {
            int next = edge.first;
            int nCost = edge.second;

            if (dist[cur] + nCost < dist[next]) {
                dist[next] = dist[cur] + nCost;
                pq.push({-dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> node >> edges;
    for (int i = 0; i < edges; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c}); // 양방향 간선
    }

    cin >> mid1 >> mid2;

    // Dijkstra를 각 시작점 기준으로 3번 수행
    vector<int> from1 = dijkstra(1);
    vector<int> fromV1 = dijkstra(mid1);
    vector<int> fromV2 = dijkstra(mid2);

    // 두 경로 시도: 1 → v1 → v2 → N, 1 → v2 → v1 → N
    long long path1 = (long long)from1[mid1] + fromV1[mid2] + fromV2[node];
    long long path2 = (long long)from1[mid2] + fromV2[mid1] + fromV1[node];

    long long answer = min(path1, path2);

    if (answer >= INF) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}