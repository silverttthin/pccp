#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647

vector<pair<int,int>> adj[1005];
int node, edge, p, q;

vector<int> dijkstra(int start){

    vector<int> dist(node + 1, INF);
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start]=0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second; pq.pop();

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

    return dist;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);

    cin>>node>>edge;
    for(int i=0; i<edge; i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    cin>>p>>q;

    vector<int> dist = dijkstra(p);
    cout<<dist[q];
}