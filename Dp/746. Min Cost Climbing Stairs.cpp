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

class Solution {
public:

    int dp[1005];
    int func(int i,vector<int>&cost){

        if(i==0)return cost[0];
        if(i==1) return cost[1];

        if(dp[i]!=-1)return dp[i];

        int ans=cost[i]+min(func(i-1,cost),func(i-2,cost));

        return dp[i]=ans;
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        

        memset(dp,-1,sizeof(dp));
        int n=cost.size();
         return min(func(n-1,cost),func(n-2,cost));
    }
};