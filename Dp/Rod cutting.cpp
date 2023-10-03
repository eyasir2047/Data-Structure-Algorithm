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


const ll N=1e5+10;
const ll M=10;


ll dp[N];

int MMMMod=1e9+7;

//top down(recursion + memoisattion)



ll func(ll len,vector<ll>&prices){
    if(len==0)return 0;
    if(dp[len]!=-1)return dp[len];

    ll ans=0;

    for(ll rod_to_cut=1;rod_to_cut<=prices.size();rod_to_cut++){
        if(len-rod_to_cut>=0)
        ans=max(ans,func(len-rod_to_cut,prices)+prices[rod_to_cut-1]);
    }

    return dp[len]=ans;
}
//0(N^2)



int main(){

    eyasir2047;

    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;

    vector<ll>prices(n);
    fo(i,n)cin>>prices[i];

    cout<<func(n,prices)<<endl;


    



    




  
  
   return 0;
}