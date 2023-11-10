/*
There are M job applicants and N jobs.  Each applicant has a subset of jobs that he/she 
is interseted in. Each job opening can only accept one applicant and a job applicant can be 
appointed for only one job. Given a matrix G where G(i,j) denotes ith applicant is interested in jth job.
 Find an assignment of jobs to applicant in such that as many applicants as possible get jobs.*/



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	vector<int>mt;
	vector<bool>used;
	bool try_kunh(int u, vector<vector<int>>&G){
	    for (int v = 0; v < G[0].size(); v++){
	        if (G[u][v] && !used[v])
	        {
	            used[v] = true;
	            if (mt[v] < 0 || try_kunh(mt[v], G))
	            {
	                mt[v] = u;
	                return true;
	            }
	        }
	    }
    return false;
	}
	int maximumMatch(vector<vector<int>>&G){
		int m = G.size();
		int n = G[0].size();
		int N = max(n, m);
		int ans = 0;
		mt.assign(N, -1);
		for(int i = 0; i < m; i++){
			used.assign(N, false);
			if(try_kunh(i, G))
				ans++;
		}
		return ans;
	}

};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
