#include <bits/stdc++.h>

using namespace std;

int n, arr[80002];
long long ans;
stack<int> s;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    long long h;
    while(n--){
        cin>>h;
        // 스택엔 현재 건물보다 큰 건물들이 저장된다.
        // 저장된 건물들은 h를 모두 바라볼 수 있으므로 ans += size
        while(!s.empty() && s.top() <= h)
            s.pop();
        ans += s.size();
        s.push(h);
    }
    cout<<ans;

}