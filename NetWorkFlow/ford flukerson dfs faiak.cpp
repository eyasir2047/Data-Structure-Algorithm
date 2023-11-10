

#include <bits/stdc++.h>
using namespace std;


bool dfs(vector<vector<int>>& res_graph, int s, int t, vector<bool>& vis, int & flow_path){

    if(s == t){
        return true;
    }

    vis[s] = true;

    for(int v=0; v<res_graph.size(); v++){

        if(!vis[v] and res_graph[s][v]>0){
            int bottleneck_capacity = min(flow_path, res_graph[s][v]);

            if(dfs(res_graph,v,t,vis,bottleneck_capacity)){
                flow_path = bottleneck_capacity;

                res_graph[s][v] -= flow_path;
                res_graph[v][s] += flow_path;

                return true;
            }
        }
    }

    return false;
}


int ford_fulkerson_dfs(vector<vector<int>>& graph, int s, int t){

    int n = graph.size();
    vector<vector<int>> res_graph = graph;
    int max_flow = 0;

    while(47){// 0 chara onno kono kisu

        int flow_path = INT_MAX;
        vector<bool> vis(n, false);
        vis[s] = true;

        if(dfs(res_graph, s, t, vis, flow_path)){
            max_flow += flow_path;
        }
        else{
            break;
        }
    }

    return max_flow;
    //TC - O(f*E), f = maximum flow capacity , E = # of edges
    //SC - O(V*V + V + V + logE) = O(V*V) -> ??
}


int main() {
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    }; // ans = 23

    int n = graph.size();

    cout<<ford_fulkerson_dfs(graph,0,n-1)<<endl;

return 0;
}