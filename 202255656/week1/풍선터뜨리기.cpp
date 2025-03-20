#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& vi) {
    cout << endl;
    for (int i : vi) cout << i << " ";
    cout << endl;
}

int solution(vector<int> a) {
    int N = a.size();
        
    // L, m, R
    // L과 R에서 각각 가장 큰 풍선부터 터트림
    // L에서 마지막 남은 풍선, R에서 마지막 남은 풍선은 각각 L와 R의 최소값
    // Lmin, m, Rmin 중 m이 가장 크면 불가능
    // 양 끝 풍선은 항상 가능
    
    if (a.size() == 1) return 1;
    
    vector<int> Lmins (N); Lmins[0] = a[0];
    vector<int> Rmins (N); Rmins[N - 1] = a[N - 1];
    
    for (int i = 1; i < N; i++) Lmins[i] = min(Lmins[i - 1], a[i - 1]);
    for (int i = N - 2; i >= 0; i--) Rmins[i] = min(Rmins[i + 1], a[i + 1]);
    
    int count = 2;
    for (int i = 1; i < N - 1; i++) {
        if (a[i] <= Lmins[i] || a[i] <= Rmins[i]) count++;
    }
    
    return count;
}
