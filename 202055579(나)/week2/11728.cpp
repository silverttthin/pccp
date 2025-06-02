#include <bits/stdc++.h>

using namespace std;

// 알고리즘 수업 머지소트 복습용 문제'

int a[1000002];
int b[1000002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    int aPointer=0, bPointer=0;
    while(aPointer<n && bPointer<m){
        if(a[aPointer]<=b[bPointer]){
            cout<<a[aPointer++]<<" ";
        } else {
            cout<<b[bPointer++]<<" ";
        }
    }

    if(aPointer>=n){
        for(int i=bPointer; i<m; i++) cout<<b[i]<<" ";
    }
    else{
        for(int i=aPointer; i<n; i++)cout<<a[i]<<" ";
    }

    
}