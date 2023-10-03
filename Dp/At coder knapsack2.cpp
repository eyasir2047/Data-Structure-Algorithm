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


//this function will return the minimum weight to get the maximum value which is 1e5
ll func(ll index,ll max_value,vector<ll>&weight,vector<ll>&value){
        if(max_value==0)return 0;
        if(index<0)return 1e15;
        if(dp[index][max_value]!=-1)return dp[index][max_value];

        ll ans;

        ans=func(index-1,max_value,weight,value);

        if(max_value-value[index]>=0)
        ans=min(ans,func(index-1,max_value-value[index],weight,value)+weight[index]);

        

        return dp[index][max_value]=ans;
}

int main(){

    eyasir2047;

    memset(dp,-1,sizeof(dp));
    
    ll n,w;cin>>n>>w;
    vector<ll>weight(n+1);
    vector<ll>value(n+1);

    fo(i,n)cin>>weight[i]>>value[i];

    for(ll i=1e5;i>=0;i--){

        if(func(n-1,i,weight,value)<=w){
            cout<<i<<endl;
            break;
        }

    }
    
    return 0;
}