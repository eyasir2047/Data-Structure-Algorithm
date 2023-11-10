#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
const int maxN = 501;
const ll INF = 1e10+10;
bool vis[maxN];
int N, M, parent[maxN];
ll cap[maxN][maxN];
vector<int> G[maxN];

ll bfs(int s = 1, int t = N){
    
    fill(parent+1, parent+N+1, -1);
    parent[s] = -2;

    queue<pair<ll,ll>> Q;
    
    Q.push({s, INF});//{node,weight}
    
    
    while(!Q.empty()){
        int u = Q.front().first;
        ll f = Q.front().second;
        Q.pop();

        for(int v : G[u]){//go to neighbour and pushing it to the Queue
            if(parent[v] == -1 && cap[u][v]){//parent[v]==-1 means that node is not visited && cap[u][v]>=0
                parent[v] = u;
                ll aug = min(f, cap[u][v]);//have to return the minimum weight from the augmented path
                //aug= min(residual capacity,f)
                if(v == t)  return aug;//reach the sink
                Q.push({v, aug});
            }
        }
    }

    return 0;
}

/*
The correct condition while((aug = bfs()) > 0) means that the while loop will continue as long as 
the value returned by the
 bfs function is greater than 0, indicating that there is still an augmenting path to be found. 
*/

ll maxflow(int s , int t){

    ll flow = 0, aug = 0;
    while((aug = bfs()) > 0){

        vector<ll>ans;
        flow += aug;
        int u = t;//sink
        while(u != s){//until reach the source
            ans.push_back(u);
            int v = parent[u];
            cap[v][u] -= aug;
            cap[u][v] += aug;//cap[u][v]-> +ve , as I am moving backward 
            u = v;
        }
        
        
    }
    
    
    return flow;
}

void dfs(int u = 1){
    vis[u] = true;
    for(int child : G[u])
        if(!vis[child] && cap[u][child]>0)
            dfs(child);
}


int main(){
  
  cin>>N>>M;
  
    for(int i = 0, a, b; i < M; i++){
      
       cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        cap[a][b] += 1;
        cap[b][a] += 1;//initial capactiy ,then it will reduce
    }
  
   
   cout<<maxflow(1,N)<<endl;

   dfs();
    for(int u = 1; u <= N; u++){
      if(vis[u]){
        for(int child : G[u])
            if(!vis[child])
                cout<<u<<" "<<child<<endl;
      }
    }
}