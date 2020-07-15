/*
dp[i][j] max sum if spent j time to from i to down in its subtree and back
dp2[i][j] max sum if spent j time to from i to down in its subtree(not neccesarily returning)

answer is max(dp[0][m],dp2[0][m])
transitions in code
if done naively O(n^3)
passes can be optimized to O(n^2) using few small optimizations
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

int n,m;
int dp[501][501];
int dp2[501][501];
int it[501];
vector<int> adj[501];
int ss[501];
void dfs(int no,int par2=-1){
	ss[no]=1;
	for(auto j:adj[no]){
		if(j==par2){
			continue;
		}
		dfs(j,no);
		ss[no]+=ss[j];
	}
	for(auto j:adj[no]){
		if(j==par2){
			continue;
		}
		for(int k=min(m,3*ss[no]);k>=1;k--){
			for(int i=min(min(k-1,m),3*ss[j]);i>=1;i--){
				dp2[no][k]=max(dp2[no][k],dp[no][k-i-1]+dp2[j][i]);
			}
			for(int i=min(min(k-2,m),3*ss[j]);i>=1;i--){
				dp2[no][k]=max(dp2[no][k],dp2[no][k-i-2]+dp[j][i]);
				dp[no][k]=max(dp[no][k],dp[no][k-i-2]+dp[j][i]);
			}
		}
	}

	for(int i=m;i>=1;i--){
		dp[no][i]=max(dp[no][i],dp[no][i-1]+it[no]);
		dp2[no][i]=max(dp2[no][i],dp2[no][i-1]+it[no]);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	cout<<max(dp[0][m],dp2[0][m])<<endl;
	


	return 0;
}

