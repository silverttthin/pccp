#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a,b,c;

// 처음 코드, b 최대=21억 -> O(21억)은 0.5초내에 못푼다
// int main(){
//     cin>>a>>b>>c;
//     long long ans = 1;

//     for(int i=0; i<b; i++){
//         ans = ans * a % c;
//     }

//     cout<<ans;
// }


// a^n * a^n = a^2n
// k승을 알면 2k승, 2k +1 승을 바로 구할 수 있다.
ll pow(ll a, ll b, ll m){
    if(b == 1) return a % m; // 4) 2의 1승까지 내려왔다면 2^1 = 2이므로 a 리턴

    ll half_val = pow(a,b/2, m); // 2) 2의 3승이 아닌 2승을 val로 가져오겠지
    if(b%2 == 0) return half_val * half_val % m;
    return half_val * half_val % m * a % m; // 3) 따라서 2의 1승(a)를 하나 더 곱해준 값을 리턴
    // 모듈러 합동공식을 제대로 적용했어야 했다!!
}

int main(){
    cin>>a>>b>>c;
    cout<<pow(a,b,c); // 1) 만약 2의 5승이라면?
}