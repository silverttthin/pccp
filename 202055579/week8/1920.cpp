#include <bits/stdc++.h>

using namespace std;

int N, M;
int targetNum;

int main(){
    cin.tie(0); ios::sync_with_stdio(0);

    cin>>N; 
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());

    cin>>M;
    while(M--){
        cin>>targetNum;
        if(binary_search(arr.begin(), arr.end(), targetNum)){
            cout<<"1\n";
        } else{
            cout<<"0\n";
        }
    }

}