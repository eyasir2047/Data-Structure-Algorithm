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


const int N=1e7+10;

int dp[N];

//top down(recursion + memoisattion)

int func(int amount,vector<int>&coins){

    if(dp[amount]!=-1)return dp[amount];

    if(amount==0)return 0;

    int ans=INT_MAX;

    for(int it:coins){
        if(amount-it>=0)
        ans=min(ans+0LL,func(amount-it,coins)+1LL);
    }

    return dp[amount]=ans;
}



int main(){

    eyasir2047;

    memset(dp,-1,sizeof(dp));
    
    int n,amount;cin>>n>>amount;

    vector<int>coins(n);
    fo(i,n)cin>>coins[i];

    if(func(amount,coins)!=INT_MAX){
        cout<<func(amount,coins)<<endl;
    }else{
        cout<<-1<<endl;
    }



    


    


    return 0;
}