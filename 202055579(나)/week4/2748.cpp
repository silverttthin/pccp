#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll dp[92];

int main(){
    cin>>n;
    dp[0] = 0; dp[1] = 1;
    for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
    cout<<dp[n];
}