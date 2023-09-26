#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int dp[2500+10];
int lis(int i,vector<int>&a){
    if(dp[i]!=-1)return dp[i];
    int ans=1;
        if(i==0)return ans;
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                ans=max(ans,lis(j,a)+1);
            }
        }
        return dp[i]=ans;
}
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
                ans=max(ans,lis(i,nums));
        }
        return ans;
    }
};