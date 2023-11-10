class Solution {
public:
    vector<int>color,visit;
    vector<vector<int>>adj,dis;
    vector<int>comp;

    bool bfs(int i)
    {
      queue<int>q;
        q.push(i);
        visit[i]=0;
        while(!q.empty())
        {
            int f=q.front();
            comp.push_back(f);
            q.pop();
            for(auto it :adj[f])
            {
                if(visit[it]!=-1)
                {
                    if(visit[it]!=(!visit[f]))return 0;
                }
                else{
                    visit[it]=(!visit[f]);
                    q.push(it);
                }
            }
        }
        return 1;
            
    }
    
    void  bfs1(int i)
    {
      dis[i][i]=1;
      queue<int>q;
      q.push(i);
      while(!q.empty())
      {
          int f=q.front();
          q.pop();
         for(auto it :adj[f])
         {
             if(dis[i][it]>dis[i][f]+1)
             {
                 dis[i][it]=dis[i][f]+1;
                 q.push(it);
             }
         }
      }
            
    }
    
    int magnificentSets(int n, vector<vector<int>>& edges) {
        adj=vector<vector<int>>(n+1);
        dis=vector<vector<int>>(n+1,vector<int>(n+1,1e9));
        
        for(auto it :edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
       
        
       
        
        visit=vector<int>(n+1,-1);
        bool check=1;
         for(int i=1;i<=n;i++)
        {
            bfs1(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(visit[i]!=-1)continue;
           
            check&=bfs(i);
            int x=0;
           for(int j=0;j<comp.size();j++)
           {
               for(int k=j;k<comp.size();k++)
               {
                     if(dis[comp[j]][comp[k]]<1e9)
                     {
                         x=max(x,dis[comp[j]][comp[k]]);
                     }
               }
           }
            comp.clear();
           ans+=x;

        }
        if(check==0)return -1;
        
        for(int i=1;i<=n;i++)
        {
            for(auto it : adj[i])
            {
                if(visit[it]!=(!visit[i]))return -1;
            }
         }
        
       
        
       
        
       
        
        return ans;
        
        
        
        
        
    }
};