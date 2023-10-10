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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        //{distance,{x,y}}
       vector<pair<int,pair<int,int>>>v;
        for(auto it:points){
            int x=it[0];
            int y=it[1];
            int d=x*x+y*y;
            v.push_back({d,{x,y}});
    }
    sort(v.begin(),v.end());
    vector<vector<int>>ans;
    for(int i=0;i<k;i++){
            ans.push_back({v[i].second.first,v[i].second.second});
           // cout<<v[i].second.first<<" "<<v[i].second.second<<endl;
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