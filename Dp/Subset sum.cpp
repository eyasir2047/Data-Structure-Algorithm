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


bool func(ll i,ll sum,vector<ll>&a){
    if(sum==0)return true;
    if(i<0)return false;
    if(dp[i][sum]!=-1)return dp[i][sum];

    //not taking the element
    bool isPossible= func(i-1,sum,a);


    //taking the element 
    if(sum-a[i]>=0)
    isPossible|= func(i-1,sum-a[i],a);

    return dp[i][sum]=isPossible;
}



int main(){

    eyasir2047;

    memset(dp,-1,sizeof(dp));
    ll n,sum;
    cin>>n>>sum;


    vector<ll>a(n);
    fo(i,n)cin>>a[i];

    cout<<func(n-1,sum,a)<<endl;



   

    return 0;
}