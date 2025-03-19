#include <bits/stdc++.h>

using namespace std;

queue<int> q;
int n;

int main(){
    cin>>n;
    for(int i=1; i<=n; i++) q.push(i);
    while(q.size()>1){
        q.pop();
        int tmp=q.front();
        q.pop();
        q.push(tmp);
    }
    cout<<q.front();
}