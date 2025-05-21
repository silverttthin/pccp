// 2252 / 줄 세우기 / baekjoon 
//80ms, 1.5h

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> in_degree(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        in_degree[B]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int next : adj[curr]) {
            in_degree[next]--;
            if (in_degree[next] == 0)
                q.push(next);
        }
    }
    return 0;
}
