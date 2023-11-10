#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 505;

bool vis[maxN];
int N, M, K, cnt, mt[maxN];
vector<int> G[maxN];
vector<pii> pairs;

bool dfs(int u){
    if(vis[u]) return false;

    vis[u] = true;
    
    for(int child : G[u]){
        if(!mt[child] || dfs(mt[child])){
            mt[child] = u;
            return true;
        }
    }

    return false;
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i = 0, a, b; i < K; i++){
        scanf("%d %d", &a, &b);
        G[b].push_back(a);
    }

    for(int i = 1; i <= M; i++){
     fill(vis+1, vis+N+1, false);
        dfs(i);
    }

    cnt = 0;
    for(int i = 1; i <= N; i++){
        if(mt[i]){
            pairs.push_back({i, mt[i]});
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for(pii P : pairs)
        printf("%d %d\n", P.first, P.second);
}

//-- maximum bipartite matching 