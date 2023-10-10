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


    int k_store[1000][1000];


    void print_parenthesis(int i, int j){

    if(i == j) {
        cout<<(char)('A' + i - 1);
        return;
    }

    cout<<"(";
    print_parenthesis( i, k_store[i][j]);
    print_parenthesis( k_store[i][j] + 1, j );

    cout<<")";

        }

    

    int matrixMultiplication(int n, int arr[])
    {
       
       int dp[1000][1000];
       int cnt=0;
       
       for(int i=1;i<=(n-1);i++)dp[i][i]=0;//base case
       
       for(int i=n-1;i>=1;i--){
           for(int j=i+1;j<=(n-1);j++){
               //i<j
            int mini=INT_MAX;
          for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
            //mini=min(mini,steps);
            if(steps<mini){
                mini=min(mini,steps);
                k_store[i][j]=k;
                cnt++;
            }
        }
        
        dp[i][j]=mini;
           
               
           }
       }

      // print_parenthesis(1,cnt-1);
       cout<<endl;
       
       
      
       
        
        return dp[1][n-1];
    }
};



int main(){
    int t;
    //cin>>t;
    t=1;
    while(t--){
        int N;
        cin>>N;
        int arr[N+5];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;

    }
    return 0;
}
