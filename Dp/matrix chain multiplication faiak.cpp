#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


void print_parenthesis(vector<vector<int>>& k_store,int i, int j){

    if(i == j) {
        cout<<(char)('A' + i - 1);
        return;
    }

    cout<<"(";
    print_parenthesis(k_store , i, k_store[i][j]);
    print_parenthesis(k_store, k_store[i][j] + 1, j );

    cout<<")";

}

void mcm_bottom_up(int p[], int n){

    vector<vector<ll>> m( n-1 + 1, vector<ll>(n-1 + 1, INT_MAX));
    vector<vector<int>> k_store(n-1 + 1, vector<int>(n-1 + 1, 0));

    // m.size() == n


    for(int i=0; i<m.size(); i++) m[i][i] = 0;

    for(int f=1; f< m.size() - 1; f++){
        
        for(int i=1; i<m.size() - f; i++){

            int j = i + f;
            
                ll q = INT_MAX;

                for(int k = i; k<j; k++){
                    
                    q =  m[i][k] + m[k+1][j] +  p[i-1]*p[k]*p[j];

                    if(q < m[i][j]){
                        m[i][j] = q;
                        k_store[i][j] = k;
                    }
                
            }
        }
    }


    // for(int i=1; i<m.size(); i++){
    //     for(int j=1; j<m.size(); j++){
    //         cout<<m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=1; i<k_store.size(); i++){
    //     for(int j=1; j<k_store.size(); j++){
    //         cout<<k_store[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    
    cout<<m[1][m.size()-1]<<endl;
    

    print_parenthesis(k_store, 1, k_store.size() - 1);


}

/*
void look_up_chain(int p[], int i, int j,vector<vector<int>> & dp){

    if(dp[i][j] < INT_MAX) return;


}



void mcm_top_down(int p[], int n){

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    look_up_chain(p,1,n-1,dp);

    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[0].size(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

*/



int main(){

    //int p[] = {1, 2, 3, 4, 3};
   // int p[] = {4, 3, 5, 2, 6};

    //int n = (sizeof p)/(sizeof p[0]);
    int n;cin>>n;
    int p[n];
    for(int i=0;i<n;i++)cin>>p[i];

    mcm_bottom_up(p, n);

return 0;
}