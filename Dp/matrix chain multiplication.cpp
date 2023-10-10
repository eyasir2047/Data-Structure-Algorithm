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


class Solution{
public:

    int dp[110][110];


    int func(int i,int j, int arr[]){
        if(i==j)return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j]+func(i,k,arr)+func(k+1,j,arr);
            mini=min(mini,steps);
            
        }
        
        return dp[i][j]=mini;
        
    }

    int matrixMultiplication(int n, int arr[])
    {
       
        memset(dp,-1,sizeof(dp));
        
        return func(1,n-1,arr);
    }
};



int main(){
    int t;
    //cin>>t;
    t=1;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
