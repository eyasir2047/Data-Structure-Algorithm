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

class Solution {
public:
int dp[105][105];
int f(int i,int j,vector<int>&cuts){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int mini=INT_MAX;
    
    for(int ind=i;ind<=j;ind++){
        int cost=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts)+f(ind+1,j,cuts);
        mini=min(mini,cost);
    }

    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {

        memset(dp,-1,sizeof(dp));

        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return f(1,c,cuts);
}
};

int main(){
    int n,c;cin>>n>>c;
    vector<int>cuts(c);
    fo(i,c){
        cin>>cuts[i];
    }

    Solution obj;
    cout<<obj.minCost(n,cuts)<<endl;

    return 0;
}