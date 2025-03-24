#include <bits/stdc++.h>

using namespace std;

int n, arr[500003];
stack<pair<int, int>> q;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    q.push({100000005, 0}); // ㅈㄴ 큰탑 넣어두기 for empty case 배제
    q.push({arr[1], 1});
    
    for(int i=1; i<=n; i++){
        int height;
        cin>>height;
        while(q.top().first < height) q.pop(); // top이 더 작다 == 현재 건물의 레이저가 맞을 건물이 아니다
        cout<<q.top().second<<" "; // 그냥 실시간으로 답 출력해가기
        q.push({height, i}); // push
        }
    }

