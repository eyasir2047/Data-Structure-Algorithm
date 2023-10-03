
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
     static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]<b[0])return true;
        else if(a[0]==b[0]){
            if(a[1]>=b[1])return true;
            else return false;
        }
        else return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),cmp);

        //width is in increasing and if width is equal,then 
        // height is in decreasing order

        int col=envelopes.size();//row=col

        vector<int>ans; //0(n*logn)
        //LIS is in height

        ans.push_back(envelopes[0][1]);

        for(int i=1;i<col;i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }else{
             int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
             ans[index]=envelopes[i][1];
            }
        }

        return ans.size();
    }
};

int main(){
    eyasir2047;
    int n;cin>>n;
    vector<vector<int>>a(n,vector<int>(2));

    fo(i,n){
        fo(j,2){
            cin>>a[i][j];
        }
    }
    Solution obj;
    cout<<obj.maxEnvelopes(a)<<endl;


    return 0;
}