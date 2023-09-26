#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);

ll h[100000+5];
ll dp[100000+10];
ll k;

ll func(ll n){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    ll cost=INT_MAX;
    
    for(ll i=1;i<=k;i++){
        if(n-i>=0)
        cost=min(cost,func(n-i)+abs(h[n]-h[n-i]));

       /* if(n>=1)
        cost=min(cost,func(n-1)+abs(h[n]-h[n-1]));
        if(n>=2)
        cost=min(cost,func(n-2)+abs(h[n]-h[n-2]));
        */
    }
  
    
    return dp[n]=cost;
}


int main(){
            eyasir2047
          ll n;
          cin>>n>>k;
          memset(dp,-1,sizeof(dp));
        
          fo(i,n){
              cin>>h[i];
          }
          
          cout<<func(n-1)<<endl;//0-based indexing
          
	   
	    
	   
	    
	   
	    return 0;
}