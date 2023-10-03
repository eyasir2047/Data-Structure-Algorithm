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


const ll N=1e5+10;
const ll M=10;


ll dp[N][M];

int MMMMod=1e9+7;

//top down(recursion + memoisattion)

ll n;

ll func(ll day,ll flag,vector<ll>&a,vector<ll>&b,vector<ll>&c){

    if(day==n)return 0;

    if(dp[day][flag]!=-1)return dp[day][flag];
   

    ll maxi=0;

    if(flag==0){
        maxi=max(maxi,a[day]+func(day+1,1,a,b,c));
         maxi=max(maxi,b[day]+func(day+1,2,a,b,c));
          maxi=max(maxi,c[day]+func(day+1,3,a,b,c));
       
    }else if(flag==2){
         maxi=max(maxi,a[day]+func(day+1,1,a,b,c));
          maxi=max(maxi,c[day]+func(day+1,3,a,b,c));
    }
    else if(flag==1){
         maxi=max(maxi,b[day]+func(day+1,2,a,b,c));
          maxi=max(maxi,c[day]+func(day+1,3,a,b,c));
    }
    else{//flag==3
         maxi=max(maxi,a[day]+func(day+1,1,a,b,c));
          maxi=max(maxi,b[day]+func(day+1,2,a,b,c));
    }

    return dp[day][flag]=maxi;


}



int main(){

    eyasir2047;

    memset(dp,-1,sizeof(dp));

    cin>>n;

    vector<ll>a(n),b(n),c(n);

    fo(i,n)cin>>a[i]>>b[i]>>c[i];

    cout<<func(0,0,a,b,c)<<endl;


    




  
  
   return 0;
}