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

int lis(int i,vector<int>&a){
   
   if(dp[i]!=-1)return dp[i];

    int ans=1;
    for(int j=0;j<i;j++){
        if(a[i]>a[j])
        ans=max(ans,lis(j,a)+1);
    }

    return dp[i]=ans;

}



int main(){

    eyasir2047;
    
    memset(dp,-1,sizeof(dp));

    int n;cin>>n;

    vector<int>a(n);
    fo(i,n)cin>>a[i];

    int ans=0;

    fo(i,n){
        ans=max(ans,lis(i,a));
    }

    cout<<ans<<endl;


  


    


    return 0;
}