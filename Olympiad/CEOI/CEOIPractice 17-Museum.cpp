#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
 
int n,k,x;
vector<pair<int,int>> adj[10001];
int dp[10001][10001][2];
//0-return
//1-don't return
int ss[10001];
int min2(int aa,int bb){
	if(aa==0){
		return bb;
	}
	return min(aa,bb);
}
void dfs(int no,int par=-1){
 
	ss[no]=1;
 
	for(auto j:adj[no]){
		if(j.a==par){
			continue;
		}
		dfs(j.a,no);
		ss[no]+=ss[j.a];
	}
	int cur=0;
	dp[no][1][1]=0;
	dp[no][1][0]=0;
	for(auto j:adj[no]){
		if(j.a==par){
			continue;
		}
		cur+=ss[j.a];
		for(int i=cur+1;i>=2;i--){
			for(int kk=max(1,i-(cur-ss[j.a]+1));kk<=min(i-1,ss[j.a]);kk++){
				if(i-kk>cur-ss[j.a]+1){
					continue;
				}
				else{
					/*if(dp[no][i-kk][0]==-1){
						cout<<no<<","<<i-kk<<','<<0<<endl;
					}*/
				}
				//if(dp[no][i-kk][0]>-1){
					dp[no][i][0]=min2(dp[no][i][0],dp[no][i-kk][0]+dp[j.a][kk][0]+2*j.b);
					dp[no][i][1]=min2(dp[no][i][1],dp[no][i-kk][0]+dp[j.a][kk][1]+j.b);
				//}
				//if(dp[no][i-kk][1]>-1){
					dp[no][i][1]=min2(dp[no][i][1],dp[no][i-kk][1]+dp[j.a][kk][0]+2*j.b);
				//}
			}
		}
	}
	/*cout<<no<<endl;
	for(int j=1;j<=ss[no];j++){
		cout<<dp[no][j][0]<<",";
	}
	cout<<endl;
	for(int j=1;j<=ss[no];j++){
		cout<<dp[no][j][1]<<",";
	}
	cout<<endl;
*/
 
 
}
 
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k>>x;
	x--;
	for(int i=0;i<n-1;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		adj[aa].pb({bb,cc});
		adj[bb].pb({aa,cc});
	}
	/*for(int i=0;i<n;i++){
		for(int j=1;j<=k;j++){
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}*/
	dfs(x);
	cout<<min(dp[x][k][1],dp[x][k][0])<<endl;
	
 
 
 
	return 0;
}