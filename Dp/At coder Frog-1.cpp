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


const int N=1e5+10;

int dp[N];

//top down(recursion + memoisattion)

int fib(int n,vector<int>&a){
    if(n==0)return 0;

      if(dp[n]!=-1)return dp[n];

    int cost=INT_MAX;

    

    if(n>=1) cost=min(cost,fib(n-1,a)+abs(a[n]-a[n-1]));
    if(n>=2)cost=min(cost,fib(n-2,a)+abs(a[n]-a[n-2]));

    return dp[n]=cost;
}

int main(){

    eyasir2047;

    memset(dp,-1,sizeof(dp));

    int n;cin>>n;

    vector<int>a(n);
    fo(i,n)cin>>a[i];

    cout<<fib(n-1,a)<<endl;




    


    return 0;
}