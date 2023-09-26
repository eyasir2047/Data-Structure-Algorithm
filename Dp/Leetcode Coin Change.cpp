#include<bits/stdc++.h>
using namespace std;

class Solution {
public://11 10 9 6 
int dp[10000+10];
    int fun(int i,int n,vector<int>&coins){
        if(dp[i]!=-1)return dp[i];
        if(i==0)return 0;
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0)
            ans=min(ans+0LL,fun(i-coins[j],n,coins)+1LL);
        }
        return dp[i]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
         //greedy algorithm fails.as it is not canonical system
         memset(dp,-1,sizeof(dp));
         int n=coins.size();
         int ans=fun(amount,n,coins);
         return ans==INT_MAX ? -1: ans;
        
    }
};