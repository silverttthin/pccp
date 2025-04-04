// 15649번/N과 M(1)/baekjoon 
// 24ms
// 1h


#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> result;
vector<bool> used;

void make(int k) {
    if (k == M) {
        for (int num : result)
            cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (!used[i]) {
            used[i] = true;
            result.push_back(i);
            make(k + 1);
            result.pop_back();   
            used[i] = false;    
        }
    }
}

int main() {
    cin >> N >> M;
    used.resize(N + 1, false);
    make(0);
    return 0;
}
