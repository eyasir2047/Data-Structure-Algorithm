#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define lll long long
#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define all(x) sort(x.begin(),x.end())
#define rall(x) sort(x.rbegin(),x.rend())
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);
#define tup tuple<int,int,int>

class Solution {
public:
//as origin sqrt(x^2+y^2)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //{distance,{x,y}}
        priority_queue<pair<int,pair<int,int>>>pq;//max heap

        for(int i=0;i<points.size();i++){//row
          int x=points[i][0];
          int y=points[i][1];
          int distance=x*x+y*y;//distance from origin
          pq.push({distance,{x,y}});
          if(pq.size()>k)pq.pop();//maximum element delete
        }

        vector<vector<int>>ans;
        while(pq.size()>0){
            vector<int>res;
            res.push_back(pq.top().second.first);
            res.push_back(pq.top().second.second);
           // cout<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
            ans.push_back(res);
            pq.pop();
        }

        return ans;

    }
};

int main(){
    eyasir2047;
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>>points(n,vector<int>(m));

    fo(i,n){
        fo(j,m){
            cin>>points[i][j];
        }
    }

    Solution obj;
  vector<vector<int>>ans=obj.kClosest(points,k);

    for(auto it:ans){
        for(auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}