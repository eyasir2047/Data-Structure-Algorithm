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


const ll N=1e2+10;
const ll M=1e5+10;


ll dp[N][M];

int MMMMod=1e9+7;

//top down(recursion + memoisattion)


ll func(ll index,ll w,vector<ll>&weight,vector<ll>&value){
  
    if(w==0)return 0;
    if(index<0)return 0;

      if(dp[index][w]!=-1)return dp[index][w];

    ll ans;

    //don't choose an item 
    ans=func(index-1,w,weight,value);

    //choose an item 
    if(w-weight[index]>=0)
    ans=max(ans,func(index-1,w-weight[index],weight,value)+value[index]);//state --> index and weight

    return dp[index][w]=ans;  
}


int main(){

    eyasir2047;

    memset(dp,-1,sizeof(dp));
    
    ll n,w;cin>>n>>w;
    vector<ll>weight(n+1);
    vector<ll>value(n+1);

    fo(i,n)cin>>weight[i]>>value[i];
    

    cout<<func(n-1,w,weight,value)<<endl;





  
  
   return 0;
}