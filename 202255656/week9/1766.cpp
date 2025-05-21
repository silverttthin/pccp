#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

// 백준 1766 문제집 (위상정렬, 우선순위 큐)

using namespace std;

struct compare {
    bool operator()(int i1, int i2) {
        return i1 > i2;
    }
};

int main() {
    cin.tie(NULL);

    int N, M; cin >> N >> M;

    vector<int> inDegree (N + 1, 0);
    vector<vector<int>> graph (N + 1, vector<int>());
    priority_queue<int, vector<int>, compare> pq;

    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        graph[A].push_back(B);
        inDegree[B]++;
    }

    for (int i = 1; i <= N; i++) 
        if (inDegree[i] == 0)
            pq.push(i);

    while (!pq.empty()) {
        int i = pq.top(); pq.pop();
        cout << i << " ";
        for (int j : graph[i]) {
            inDegree[j]--;
            if (inDegree[j] == 0) pq.push(j);
        }
    }

    return 0;
}
