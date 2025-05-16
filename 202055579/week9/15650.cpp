#include <bits/stdc++.h>

using namespace std;

int n, m;

int used[10];
vector<int> v;


void dfs(int depth) {
    if(depth == m){
        for(auto i: v) cout<<i<<" ";
        cout<<"\n";
        return ;
    }

    // 비어있으면 오름차순로직 미수행
    // 안비어있으면 오름차순로직 수행
    for(int i=1; i<=n; i++){
        if(used[i]) continue;
        if(!v.empty() && v.back()>i) continue;
        
        used[i] = 1;
        v.push_back(i);
        dfs(depth + 1);
        v.pop_back();
        used[i] = 0;
    }
}


int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>n>>m;
    dfs(0);
}