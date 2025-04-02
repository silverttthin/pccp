#include <bits/stdc++.h>

// not divide and conquer but DP

using namespace std;
using ll = long long;
int t, n;
ll arr[101]; // 오버플로우가 날까? 하는 고민을 항상 가져야함

int main(){
    cin>>t;
    arr[1]=1; arr[2]=1; arr[3]=1;

    for(int i=4; i<101; i++) arr[i] = arr[i-3]+arr[i-2];
    while(t--){
        cin>>n;
        cout<<arr[n]<<"\n";
    }

}