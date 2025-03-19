#include <iostream>
#include <queue>
#include <utility>

using namespace std;

// 백준 1966 : 프린터 큐
// https://www.acmicpc.net/problem/1966

int main() {
    int T; cin >> T;

    while (T--) {
        int N, M; cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int i = 0; i < N; i++) {
            int t; cin >> t;
            pq.push(t);
            q.push({t, i});
        }

        int count = 0;
        while (!q.empty()) {
            auto [n, idx] = q.front(); q.pop();
            if (pq.top() == n) {
                count++;
                pq.pop();
                if (idx == M) break;
            }
            else {
                q.push({n, idx});
            }
        }
        
        // printf("count : %d\n", count);
        cout << count << endl;
    }

    return 0;
}
