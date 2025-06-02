#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10];
bool isused[10];

void dfs(int depth){
    if(depth == m){ // 5. m개 고르는데 만약 깊이가 m+1이 된다면 출력
        for(int i=0; i<m; i++) cout<<arr[i]<<" ";
        cout<<"\n";
        return ;
    }

    for(int i=1; i<=n; i++){ // 1. 현재 깊이의 수를 1~n에서 고른다. 
        if(!isused[i]){ // 2. 만약 안쓰인 숫자면
            arr[depth] = i;
            isused[i] = 1; // 3. 그 깊이 수를 정하고 사용체크
            dfs(depth+1); 
            isused[i] = 0; // 4. 다음 깊이로 넘어갔다 오고 사용해제
        }
    }    
    
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    dfs(0);
    
}
