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

const int M=1e9+10;

int f(int a,int b){
    if(b==0)return 1;
    int x=f(a,b/2);
    if(b&1){//odd
        return (a*(x*1LL*x)%M)%M;
    }else{
        return (x*x*1LL)%M;
    }
}

int main(){
    int a,b;cin>>a>>b;
    cout<<f(a,b)<<endl;

    return 0;
}