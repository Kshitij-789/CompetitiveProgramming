#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int n,m;
int it[301];

int dp[301][301][2];
int dp2[301][301][2];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	n+=1;
	it[n-1]=0;
	sort(it,it+n);
	int ind=0;
	for(int i=0;i<n;i++){
		if(it[i]==0){
			ind=i;
		}
	}
	int ans=0;
	for(int k=1;k<=n;k++){

		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				dp[i][j][0]=n*m;
				if(i>0){
					dp[i][j][0]=min(dp[i][j][0],dp2[i-1][j][0]+k*(it[i]-it[i-1]));
				}
				if(j<n-1){
					dp[i][j][0]=min(dp[i][j][0],dp2[i][j+1][1]+k*(it[j+1]-it[i]));
				}
				dp[i][j][1]=n*m;
				if(i>0){
					dp[i][j][1]=min(dp[i][j][1],dp2[i-1][j][0]+k*(it[j]-it[i-1]));
				}
				if(j<n-1){
					dp[i][j][1]=min(dp[i][j][1],dp2[i][j+1][1]+k*(it[j+1]-it[j]));
				}
			}
		}
	/*	for(int i=0;i<n;i++){
			ans=max(ans,k*m-(dp[i][i][1]+(k*abs(it[i]))));
		}*/
		ans=max(ans,k*m-dp[ind][ind][1]);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp2[i][j][0]=dp[i][j][0];
				dp2[i][j][1]=dp[i][j][1];
	//			cout<<dp[i][j][0]<<" ";
			}
	//		cout<<endl;
		}
	//	cout<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
	//			cout<<dp[i][j][1]<<" ";
			}
		//	cout<<endl;
		}
	}
	cout<<ans<<endl;



	return 0;
}