/*
skipping subtree dp-same trick used in tst 2017 Coin collector
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#include "boxes.h"
int back[200001][501];
int n,m;
int dp[501];
vector<int> adj[200001];
int it[200001];
int cur=0;
void dfs(int no,int par2=-1){
	for(int i=1;i<=m;i++){
		if(dp[i-1]==-1){
			back[no][i]=-1;
			continue;
		}
		back[no][i]=it[no]+dp[i-1];
	}
	for(auto j:adj[no]){
		dfs(j,no);
	}
	for(int i=1;i<=m;i++){
		dp[i]=max(dp[i],back[no][i]);
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int ind=0;
	for(int i=1;i<=m;i++){
		dp[i]=-1;
	}
	for(int  i=0;i<n;i++){
		int aa;
		cin>>aa>>it[i];
		aa--;
		if(aa>=0){
			adj[aa].pb(i);
		}
		else{
			ind=i;
		}
	}
	dfs(ind);
	cout<<dp[m]<<endl;


	return 0;
}

/*
g++  -o aa -O2 box.cpp grader.cpp -std=c++14
*/
