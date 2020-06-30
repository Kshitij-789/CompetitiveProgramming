#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n,k;
int aa[201];
int bb[201];
int dp[20001][201];
int back[20001][201];
int ans[20001];
deque<pair<int,int>> mi[20001];
int min2(int aa,int bb){
	if(aa==-1){
		return bb;
	}
	else if(bb==-1){
		return aa;
	}
	return min(aa,bb);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>aa[i];
	}
	for(int i=0;i<n;i++){
		cin>>bb[i];
	}
	cin>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<=k;j++){
			dp[j][i]=-1;
		}
	}

	dp[0][0]=0;
	for(int i=aa[0];i<=min(aa[0]*bb[0],k);i+=aa[0]){
		dp[i][0]=i/aa[0];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<aa[i];j++){
			while(mi[j].size()){
				mi[j].pop_back();
			}
		}
		for(int j=0;j<=k;j++){
			dp[j][i]=dp[j][i-1];
			back[j][i]=j;
			while(mi[j%aa[i]].size()){
				if(mi[j%aa[i]].front().b<j-aa[i]*bb[i]){
					mi[j%aa[i]].pop_front();
					continue;
				}
				int cost=mi[j%aa[i]].front().a+j/aa[i];
				if(cost<dp[j][i] or dp[j][i]==-1){
					dp[j][i]=cost;
					back[j][i]=mi[j%aa[i]].front().b;
				}
				break;
			}
			if(dp[j][i-1]!=-1){
				int cur=dp[j][i-1]-j/aa[i];
				while(mi[j%aa[i]].size()){
					if(mi[j%aa[i]].back().a>cur){
						mi[j%aa[i]].pop_back();
						continue;
					}
					break;
				}
				mi[j%aa[i]].pb({cur,j});
			}
		}

	}
/*	for(int i=0;i<n;i++){
		for(int j=0;j<=k;j++){
			cout<<dp[j][i]<<",";
		}
		cout<<endl;
	}*/
	cout<<dp[k][n-1]<<endl;
	int ind=k;
	for(int i=n-1;i>=0;i--){
		ans[i]=(ind-back[ind][i])/aa[i];
		if(ind==0){
			break;
		}
		ind=back[ind][i];
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;



	
	return 0;


}