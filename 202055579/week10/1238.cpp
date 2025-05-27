#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647

vector<pair<int,int>> adj[1002];
int returnDist[1002];
int startDist[1002];
int node, edge, x, ans;


void dijkstra(int start, int dist[]){

    priority_queue<pair<int,int>> pq;
    pq.push({0, start});
    dist[start]=0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(auto edge: adj[cur]){
            int next = edge.first;
            int nCost = edge.second;

            if(dist[cur] + nCost < dist[next]){
                dist[next] = dist[cur] + nCost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);

    cin>>node>>edge>>x;
    fill(returnDist, returnDist+node+1, INF);
    fill(startDist, startDist+node+1, INF);

    for(int i=0; i<edge; i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    // 귀가길 최단경로 dist 먼저 생성
    dijkstra(x, returnDist);

    for(int i=1; i<=node; i++){
        if(i==x) continue;
        fill(startDist, startDist+node+1, INF);
        dijkstra(i, startDist);
        ans = max(ans, startDist[x] + returnDist[i]);
    }

    cout<<ans;
}