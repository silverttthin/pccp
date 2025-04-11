/*
14501/퇴사/BOG
0ms
60m
*/

#include <iostream>
using namespace std;

int t[17];
int p[17];

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;
    for (int i=1; i<=n; ++i)
    {
        cin >> t[i] >> p[i];
    }

    int dp[18] = {0, };

    int result = 0;

    for (int i=n; i>0; --i)
    {
        if (i + t[i] <= n + 1)
        {
            dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
        } 
        else
        {
            dp[i] = dp[i + 1];
        }
    }
    
    // for (int i=0; i<=n; ++i)
    // {
    //     cout << "dp[" << i << "] = " << dp[i] << '\n';
    //     result = max(result, dp[i]);
    // }

    cout << dp[1];
}