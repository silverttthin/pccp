#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int arr[100002];

int main(){
    cin>>n;
    arr[0]= -1;
    arr[1]= -1;
    arr[2]= 1;
    arr[3]= -1;
    arr[4]= 2;
    arr[5]= 1;

    for(int i=6; i<=n; i++){
        if(arr[i-2]!=-1) arr[i] = arr[i-2] + 1; 
        if(arr[i-5]!=-1) arr[i] = min(arr[i], arr[i-5] + 1);
    }
    cout<<arr[n];

}