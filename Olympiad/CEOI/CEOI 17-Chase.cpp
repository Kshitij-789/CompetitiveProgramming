/*
dp[i][j][k]-max difference -v crumbs used from i to some other node in its subtree,crumb used in i if k=1 else not
dp2[i][j][k]-same but path reversed

details to calculate answer from these 2 values in code
*/
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n,m;
llo it[100001];
llo co[100001];
vector<llo> adj[100001];
llo dp[100001][101][2];
llo dp2[100001][101][2];
llo ans=0;
vector<pair<llo,int>> ac[101][2][2];
void dfs(llo no,llo par2=-1){
	for(llo i=1;i<=m;i++){
		dp[no][i][0]=0;
		dp2[no][i][0]=0;
		dp[no][i][1]=co[no];
		dp2[no][i][1]=co[no];
	}
	
	for(auto j:adj[no]){
		if(j==par2){
			continue;
		}
		dfs(j,no);
	}
	for(int i=0;i<=m;i++){
		ac[i][0][0].clear();
		ac[i][1][0].clear();
		ac[i][1][1].clear();
		ac[i][0][1].clear();
	}
	for(auto j:adj[no]){
		if(j==par2){
			continue;
		}
		for(llo i=0;i<=m;i++){
			llo x=0;
			llo y=0;
			if(i>0){
				x=max(x,dp[j][i-1][0]+co[no]);
				if(i>1){
					x=max(x,dp[j][i-1][1]+co[no]-it[no]);
				}
			}

			dp[no][i][1]=max(dp[no][i][1],x);

			y=max(y,dp[j][i][0]);
			if(i>0){
				y=max(y,dp[j][i][1]-it[no]);
			}
			dp[no][i][0]=max(dp[no][i][0],y);
	//		ac[i][0][1].pb({x,j});
			ac[i][0][0].pb({y,j});
			if(ac[i][0][0].size()==3){
				sort(ac[i][0][0].begin(),ac[i][0][0].end());
				reverse(ac[i][0][0].begin(),ac[i][0][0].end());
				ac[i][0][0].pop_back();
			}
			
		//	ac[i][0].pb({max(x,y),j});
			x=0;
			y=0;

			if(i>0){
				x=max(x,dp2[j][i-1][0]+co[no]-it[j]);
				if(i>1){
					x=max(x,dp2[j][i-1][1]+co[no]-it[j]);
				}
				y=max(y,dp2[j][i][1]);
			}
			y=max(y,dp2[j][i][0]);
			dp2[no][i][0]=max(dp2[no][i][0],y);
			dp2[no][i][1]=max(dp2[no][i][1],x);
			ac[i][1][0].pb({y,j});
			if(ac[i][1][0].size()==3){
				sort(ac[i][1][0].begin(),ac[i][1][0].end());
				reverse(ac[i][1][0].begin(),ac[i][1][0].end());
				ac[i][1][0].pop_back();
			}
			ac[i][1][1].pb({x,j});
			if(ac[i][1][1].size()==3){
				sort(ac[i][1][1].begin(),ac[i][1][1].end());
				reverse(ac[i][1][1].begin(),ac[i][1][1].end());
				ac[i][1][1].pop_back();
			}
		//	ac[i][1].pb({max(x,y),j});
		}
	}
	ans=max(ans,dp[no][m][0]);
	ans=max(ans,dp[no][m][1]);
	ans=max(ans,dp2[no][m][0]);
	ans=max(ans,dp2[no][m][1]);

	for(llo i=0;i<=m;i++){
		for(int k=0;k<2;k++){
			for(int l=0;l<2;l++){
				sort(ac[i][k][l].begin(),ac[i][k][l].end());
				reverse(ac[i][k][l].begin(),ac[i][k][l].end());
			}
		}
		for(int k=0;k<2;k++){
			for(int l=0;l<2;l++){
				if(l==1 and k==1){
					continue;
				}
				if(l==0 and k==1){
					continue;
				}
			
				if(ac[i][0][k].size()>0 and ac[m-i][1][l].size()>0){
					if(ac[i][0][k][0].b==ac[m-i][1][l][0].b){
						if(ac[i][0][k].size()>1){
							ans=max(ans,ac[i][0][k][1].a+ac[m-i][1][l][0].a);
						}
						if(ac[m-i][1][l].size()>1){
							ans=max(ans,ac[i][0][k][0].a+ac[m-i][1][l][1].a);
						}
					}
					else{
						ans=max(ans,ac[i][0][k][0].a+ac[m-i][1][l][0].a);
					}
				}
			}
		}
	}




}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
		co[aa]+=it[bb];
		co[bb]+=it[aa];
	}
	/*if(n<=1000){
		for(int i=0;i<n;i++){
			dfs(i);
		}
	}*/
	dfs(0);
	cout<<ans<<endl;
//	cout<<max(dp[0][m][1],dp[0][m][0])<<endl;


	return 0;
}