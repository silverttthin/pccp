#include <bits/stdc++.h>

using namespace std;

int N;
int t[17];
int p[17];
int dp[17];

int main(){
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>t[i]>>p[i];
    }

    int max_pay = 0;
    for(int i=0; i<=N; i++){ // N까지 진행돼야함
        dp[i] = max(max_pay, dp[i]); // 기존 최대값이 현재 dp로 작업 전 들어와야함
        
        if(t[i] + i <= N){ // 일이 퇴사 후를 넘지 않는다면 dp값 비교갱신
            dp[t[i] + i] = max(dp[t[i] + i], dp[i] + p[i]);
        }
        max_pay = max(max_pay, dp[i]); // i번째 dp값과 max를 비교해 갱신해나간다.
    }

    cout<<max_pay;
}


