#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void primefactor(int n){
    if(n%2==0){
        while(n%2==0){
            cout<<2<<" ";
            n=n/2;
        }
    }
    for(ll i=3;i<=sqrt(n+1);i=i+2){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>1){
        cout<<n<<" ";
    }
    cout<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        primefactor(n);
        
    }
    return 0;
}