#include<bits/stdc++.h>
using namespace std;


int rock_climbing_BottomUp(vector<vector<int>>& grid, vector<vector<int>>& dp,int n, int m){
    
    int i=0, j=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(i==0){
                dp[i][j] = grid[i][j] + 0;
            }else{
                if(j>=1 and j+1<=m-1)dp[i][j] = grid[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
                else if(j-1<0 and j+1>=m) dp[i][j] = grid[i][j] + dp[i-1][j];
                else if(j-1<0) dp[i][j] = grid[i][j] +  min(dp[i-1][j], dp[i-1][j+1]);
                else{
                    dp[i][j] = grid[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }
    }

    int mini = INT_MAX;

    for(int j=0; j<m; j++){

        mini = min(mini, dp[n-1][j]);
    }

    return mini;
}

int findMin(vector<vector<int>>& dp, int i, int j){

    if( dp[i-1][j-1]>=dp[i-1][j]  and  dp[i-1][j] <= dp[i-1][j+1]){
        return j;
    }
    else if(j-1 >= 0 and dp[i-1][j-1] <= dp[i-1][j]  and  dp[i-1][j] <= dp[i-1][j+1]){
        return j-1;
    }else{
        return j+1;
    }
}


void print(vector<vector<int>>& dp, vector<vector<int>>& grid,int n, int m ,int i, int j){

    vector<int>path;

    for(; i>=0; i--){
        int x,y;

        path.push_back(grid[i][j]);

        if(i!=0)j = findMin(dp,i,j);
        
    }

    reverse(path.begin(), path.end());

    for(int a: path){
        cout<<a<<" ";
    }
    cout<<endl;

}


int main(){

int n=4, m=5;


vector<vector<int>> grid = {
        {3, 2, 5, 4, 8},
        {5, 7, 5, 6, 1},
        {4, 4, 6, 2, 3},
        {2, 8, 9, 5, 8}
    };

vector<vector<int>> dp(4, vector<int>(4));

//answer is wrong

int ans ;

ans = rock_climbing_BottomUp(grid, dp,n,m);

cout<<ans<<endl;

   for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int j=0; j<m; j++){
        if(dp[n-1][j]==ans) print(dp,grid,n,m,n-1,j); 
    }

return 0;
}
