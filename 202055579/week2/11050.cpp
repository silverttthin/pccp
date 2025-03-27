#include <bits/stdc++.h>
using namespace std;

// 그래프와 관련없는 이항계수 문제입니다. 그냥 풀어본거입니다

int facto(int t){
    if(t==0) return 1;
    int result =1;
    for(int i=t; i>=1; i--){
        result *= i;
    }
    return result;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int result = facto(n) / (facto(k) * facto(n-k));

    cout<<result;
    

}