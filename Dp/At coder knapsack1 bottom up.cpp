#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);




int main(){
            eyasir2047
        
	    ll n,W;
	    cin>>n>>W;
	    
	    vector<ll>wt(n+1);
	    vector<ll>val(n+1);
	    
	    fo(i,n){
	        cin>>wt[i]>>val[i];
	    }
	    
	   
	    
	    ll dp[n+1][W+1];//state--> index=n-1,w 
	    //i->n && j->w
	    //if(n==0 || W==0)
	    for(ll i=0;i<=n;i++){
	        for(ll j=0;j<=W;j++){
	            if(i==0 || j==0){
	                dp[i][j]=0;
	            }
	        }
	    }
	    
	   
	    
	    for(ll i=1;i<=n;i++){
	        for(ll j=1;j<=W;j++){
	            if(wt[i-1]<=j){
	              dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
	            }else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    
	    cout<<dp[n][W]<<endl;

        ll result=dp[n][W];

        // either the result comes from the top
        // (dp[i-1][j]) or from (val[i-1] + dp[i-1]
        // [j-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included

        ll knapsack_weight=W;

        for(ll i=n;i>0 && result>0;i--){
            if(result==dp[i-1][knapsack_weight])continue;//item is not included
            else{
                cout<<wt[i-1]<<" "<<val[i-1]<<endl;

                result=result-val[i-1];
                knapsack_weight=knapsack_weight-wt[i-1];
            }
        }



	    
	   
	    return 0;
}