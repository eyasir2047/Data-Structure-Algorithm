
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
#define INF 1e9

  int index2=0;
  vector<int>anss;

int func(vector<vector<int>>&grid,vector<vector<int>> &dp,int n,int m){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        if(i==1)dp[i][j]=grid[i][j]+0;
        else if(j==1)dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
        else if(j==m)dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
        else{
                //in the middle
                int k=min(dp[i-1][j-1],dp[i-1][j]);
                k=min(k,dp[i-1][j+1]);
                dp[i][j]=grid[i][j]+k;
            }
        }
    }

    int maxi=INT_MIN;
    
  

    for(int j=1;j<=m;j++){
       // cout<<dp[n][j]<<" ";
        if(maxi<dp[n][j]){
            maxi=max(maxi,dp[n][j]);
            index2=j;
        }
       // max=max(maxi,dp[n][j]);
       
    }
 //   cout<<endl;

    return maxi;
}

void print(vector<vector<int>>&dp,int i,int j,int m,vector<vector<int>>&grid){
    if(i==0 || j==0 || j==(m+1))return;
    if(dp[i-1][j-1]<=dp[i-1][j] && dp[i-1][j-1]<=dp[i-1][j+1]){
        anss.push_back(grid[i-1][j-1]);
        print(dp,i-1,j-1,m,grid);
    }
    else if(dp[i-1][j]<=dp[i-1][j-1] && dp[i-1][j]<=dp[i-1][j+1]){
         anss.push_back(grid[i-1][j]);
        print(dp,i-1,j,m,grid);
    }
    else if(dp[i-1][j+1]<=dp[i-1][j] && dp[i-1][j+1]<=dp[i-1][j-1]) {
         anss.push_back(grid[i-1][j+1]);
        print(dp,i-1,j+1,m,grid);
    }
    
  
    
    
}

int main(){
    eyasir2047;

    int n,m;cin>>n>>m;

    vector<vector<int>>grid(n+1,vector<int>(m+1));

    fo(i,n){
        fo(j,m){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>dp(n+5,vector<int>(m+5));
    
        int i=0,j=0;
    for( i=0;i<=(n+1);i++){
        for( j=0;j<=(m+1);j++){
           if(j==0 || j==(m+1))dp[i][j]=INF; 
           else if(i==0)dp[i][j]=0;
        }
    }

    int ans=func(grid,dp,n,m);//least dangerous path
    //this function will return the minimum difficulty of rock climbling

    cout<<ans<<endl;
    
    // for(int i=1;i<=(n);i++){
    //     for(int j=1;j<=(m);j++){
    //         if(dp[i][j]!=INF)
    //       cout<<dp[i][j]<<" ";
    //       else
    //       cout<<"INF"<<" ";
    //     }
    //     cout<<endl;
    // }
    
    
    print(dp,n,index2,m,grid);
    
    for(int i:anss)cout<<i<<" ";
    cout<<endl;
    


   


    return 0;
}