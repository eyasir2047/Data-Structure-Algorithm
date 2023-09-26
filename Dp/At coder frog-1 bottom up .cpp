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



//top down(recursion + memoisattion)


int main(){

    eyasir2047;

    

    int n;cin>>n;
    int dp[n+1];
    for(int i=0;i<=(n+1);i++)
    dp[i]=INT_MAX;

    vector<int>a(n);
    fo(i,n)cin>>a[i];

    dp[0]=0;

    for(int i=1;i<n;i++){
        dp[i]=min(dp[i],dp[i-1]+abs(a[i]-a[i-1]));
        if(i>=2) dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-2]));
    }

    cout<<dp[n-1]<<endl;
   



    


    return 0;
}