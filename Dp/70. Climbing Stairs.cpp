
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
    int dp[100];

    int func(int n){
        if(n==1 || n==2)return n;
        if(dp[n]!=-1)return dp[n];

        int ans=0;

        if(n-1>=0)ans=ans+func(n-1);
        if(n-2>=0)ans=ans+func(n-2);

        return dp[n]=ans;
    }

    int climbStairs(int n) {
        
        memset(dp,-1,sizeof(dp));

        return func(n);
        
       
        
    }
};

int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.climbStairs(n)<<endl;
    return 0;
}