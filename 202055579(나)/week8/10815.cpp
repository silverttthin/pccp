#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(0);

    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(), arr.end());

    int m, num;
    cin>>m;
    while(m--){
        cin>>num;

        if(binary_search(arr.begin(), arr.end(), num)){
            cout<<"1 ";
        } else{
            cout<<"0 ";
        }
    }
}