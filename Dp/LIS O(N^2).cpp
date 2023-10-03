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

void func(vector<int>&a){
    int n=a.size();

    //minimum answer is 1

    vector<int>dp(n+1,1),p(n+1,-1);

    fo(i,n){
        fo(j,i){
            if(a[i]>a[j] && dp[i]<dp[j]+1){
               // dp[i]=max(dp[i],dp[j]+1);
               dp[i]=dp[j]+1;
               p[i]=j;
            }
        }
    }

    // fo(i,n)cout<<p[i]<<" ";
    // cout<<endl;

    int ans=INT_MIN,pos=0;
    fo(i,n){
        //cout<<dp[i]<<" ";
       // ans=max(ans,dp[i]);
       if(dp[i]>ans){
        ans=dp[i];
        pos=i;

       }
    }
    cout<<ans<<endl;

    vector<int>subsequence;
    while(pos!=-1){
        subsequence.push_back(a[pos]);
        pos=p[pos];
    }
    reverse(subsequence.begin(),subsequence.end());
    
    for(int i: subsequence){
        cout<<i<<" ";
    }
    cout<<endl;

}


int main(){
    eyasir2047;

    int n;cin>>n;

    vector<int>a(n);
    fo(i,n)cin>>a[i];

    func(a);

    return 0;

}