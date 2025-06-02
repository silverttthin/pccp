    #include <bits/stdc++.h>

    using namespace std;

    #define INF 1e10
    #define ll long long

    int node, edges, k;

    vector<ll> interviewPlaces;
    vector<pair<ll,ll>> adj[100005];

    vector<ll> dijkstra(){

        priority_queue<pair<ll,ll>> pq;
        vector<ll> dist(node+1, INF);
        for(auto interviewPlace: interviewPlaces){
            pq.push({0, interviewPlace});
            dist[interviewPlace]=0;
        }

        while(!pq.empty()){
            ll cost = -pq.top().first;
            ll cur = pq.top().second; pq.pop();

            if(dist[cur]<cost) continue;

            for(auto edge: adj[cur]){
                ll next = edge.first;
                ll nCost = edge.second;

                if(dist[cur]+nCost < dist[next]){
                    dist[next] = dist[cur]+nCost;
                    pq.push({-dist[next], next});
                }
            }
        }

        return dist;
    }



    int main(){
        cin.tie(0); ios::sync_with_stdio(0);

        cin>>node>>edges>>k;
        for(int i=0;i<edges;i++){
            int a,b,c; cin>>a>>b>>c;
            adj[b].push_back({a,c});
        }
        for(int i=0; i<k; i++) {
            int tmp; cin>>tmp;
            interviewPlaces.push_back(tmp);
        }

        // 여러개의 시작점을 넣고 한번의 다익스트라 수행하면
        // 출발점은 몰라도 가장 가까운 도착점은 구해진다
        vector<ll> dist = dijkstra(); 

        
        // auto max_it = max_element(dist.begin() + 1, dist.end());

        // int ansNode = max_it - dist.begin();
        // int ansWeight = *max_it;

        int ansNode;
        ll ansWeight = -1;
        for(int i=1; i<=node; i++){
            if(dist[i]!=INF && ansWeight<dist[i]){
                ansNode = i;
                ansWeight = dist[i];
            }
        }

        cout<<ansNode<<"\n"<<ansWeight;

    }