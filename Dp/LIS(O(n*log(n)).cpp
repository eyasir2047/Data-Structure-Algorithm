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

int func(int n,vector<int>&a){
    if(n==0)return 0;

    vector<int>ans;
    ans.push_back(a[0]);
    
    po(i,n){
        if(a[i]>ans.back()){//increasing
            ans.push_back(a[i]);
        }else{
            //have to find the element from whom a[i] is just bigger

            int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
            ans[index]=a[i];

        }
    }
    return ans.size(); // can't print the LIS subsequence through this method

}

int main(){
     eyasir2047;

    int n;cin>>n;

    vector<int>a(n);
    fo(i,n)cin>>a[i];

    cout<<func(a.size(),a)<<endl;


    return 0;

}