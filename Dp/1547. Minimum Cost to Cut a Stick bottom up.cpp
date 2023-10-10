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

class Solution {
public:

    int minCost(int n, vector<int>& cuts) {


        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());

        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

        //base case if(i>j)return 0;

        for(int i=c;i>0;i--){
            for(int j=1;j<=c;j++){
                if(i>j)continue;
                else{

                      int mini=INT_MAX;
    
                     for(int ind=i;ind<=j;ind++){
                   int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                     mini=min(mini,cost);
                    }

                     dp[i][j]=mini;
                  }
            }
        }
        


        return dp[1][c];
}
};

int main(){
    int n,c;cin>>n>>c;
    vector<int>cuts(c);
    fo(i,c){
        cin>>cuts[i];
    }

    Solution obj;
    cout<<obj.minCost(n,cuts)<<endl;

    return 0;
}