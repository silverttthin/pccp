#include <bits/stdc++.h>

using namespace std;

int N, ans; 
int arr[100002];

int main(){
    // n개의 로프 중 k개를 사용해 중량이 w인 물체를 들어올린다'
    // 이때 각 로프는 w/k의 중량이 걸릴 때 가능한 물체의 최대 중량을 구하라
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    sort(arr, arr + N);
    // 로프를 정렬 후 k개를 뒤에서 고를 떄 그 로프가 들 수 있는 중량은
    // k개 중 가장 낮은 중량의 로프의 무게 * k이다
    for(int i=1; i<=N; i++){
        int tmp = arr[N-i]*i;
        ans = max(ans, tmp);
    }
    cout<<ans;
}