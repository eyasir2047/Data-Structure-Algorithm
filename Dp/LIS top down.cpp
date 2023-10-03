#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define all(x) sort(x.begin(),x.end())
#define rall(x) sort(x.rbegin(),x.rend())
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);
#define tup tuple<int,int,int>

int dp[1005][1005];

int func(int n,vector<int>&a,int curr,int prev){
    if(curr==n)return 0;
    if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
    //prev+1 as prev can be -1

    //include
    int take=0;
    if(prev==-1 || a[curr]>a[prev]){//increasing
        take=1 + func(n,a,curr+1,curr);
}

    //exclude
    int notTake=0;
    notTake=0+func(n,a,curr+1,prev);

    return dp[curr][prev+1]=max(take,notTake);
}


int main(){
    eyasir2047;
    memset(dp,-1,sizeof(dp));

    int n;cin>>n;

    vector<int>a(n);
    fo(i,n)cin>>a[i];

    cout<<func(n,a,0,-1)<<endl;

    return 0;

}