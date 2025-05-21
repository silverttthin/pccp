#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    // 숫자카드 N개를 가지고 50만 이하일 때 
    // 정수 M이 주어지고 50만 이하일 때 이 수가 적힌 카드가 몇개 있는지 구하기
    
    int N, M, n;
    cin>>N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());

    cin>>M;
    while(M--){
        cin>>n;
        cout<<upper_bound(arr.begin(), arr.end(), n) - lower_bound(arr.begin(), arr.end(), n)<<" ";
    }
}