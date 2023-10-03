
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
    string ans;
    int dp[1005][1005];
    int lcs(int i,int j, string &s1, string &s2){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=lcs(i-1,j,s1,s2);
        ans=max(ans,lcs(i,j-1,s1,s2));
        ans=max(ans,lcs(i-1,j-1,s1,s2)+(s1[i]==s2[j]));
        return dp[i][j]= ans;

    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lcs(text1.size()-1,text2.size()-1,text1,text2);
    }

    void print(int i,int j,string &s1,string &s2){

        if(i<0 || j<0){
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
            return;
        }

        if(s1[i]==s2[j]){
            ans+=s1[i];
            print(i-1,j-1,s1,s2);
        }
        else if(dp[i-1][j]<=dp[i][j-1]){
            print(i,j-1,s1,s2);
        }else{
            print(i-1,j,s1,s2);
        }
    }
};

int main(){
    string s1="kabczzfer";
    string s2="kkahbcggerdd";
    Solution obj;
    cout<<obj.longestCommonSubsequence(s1,s2)<<endl;
    obj.print(s1.size()-1,s2.size()-1,s1,s2);
    
    return 0;

}