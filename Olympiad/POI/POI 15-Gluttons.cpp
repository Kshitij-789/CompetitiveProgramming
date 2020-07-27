/*
let dp[i][j][k] be true if there is assignment for first  i indexes(2nd to i-1th are correct) such that last 2 of the i have bitmaks k,and first 2 have bitmask j
when finished processing check each case seprately for validity of 1 and n
tight mremory replaced int array by bool


*/


#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second


int n;
int it[1000001];
bool dp[1000001][4][4];
bool back[1000001][4][4];
bool back2[1000001][4][4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n; 
	if(n>1000001-1){
		while(true){
			continue;
		}
	}
	for(int i=0;i<n;i++){
		cin>>it[i];
		it[i]*=2;
	}
	dp[1][0][0]=1;
	dp[1][1][1]=1;
	dp[1][2][2]=1;
	dp[1][3][3]=1;

	for(int i=2;i<n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<4;k++){
				int val=it[i-1];
				int val2=it[i];
				if(j==0){
					val2/=2;
				}
				if((k&2)){
					val/=2;
				}
				if((k&1)){
					if(val<=val2){
						int xx=(k&1)*2+j;
						for(int l=0;l<4;l++){
							if(dp[i][l][xx]==0 and dp[i-1][l][k]){
								dp[i][l][xx]=1;
								back[i][l][xx]=(k&2)/2;
								back2[i][l][xx]=k&1;
							}
						}
					}
				}
				else{
					if(val>=val2){
						int xx=(k&1)*2+j;
						for(int l=0;l<4;l++){
							if(dp[i][l][xx]==0 and dp[i-1][l][k]){
								dp[i][l][xx]=1;
								back[i][l][xx]=(k&2)/2;
								back2[i][l][xx]=k&1;
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(dp[n-1][i][j]==0){
				continue;
			}
		//	cout<<i<<","<<j<<endl;

		//	cout<<i<<":"<<j<<endl;
			int val=it[n-1];//left
			int val2=it[0];//right
			if((i&2)==0){
				val2/=2;
			}
			if((j&2)){
				val/=2;
			}
			if(j&1){
				if(val>val2){
					continue;
				}
			}
			else{
				if(val<val2){
					continue;
				}
			}
		//	cout<<val<<":"<<val2<<endl;
			val=it[0];//left
			val2=it[1];//right
			//cout<<i<<"/"<<j<<endl;
			if(j&1){
				val/=2;
			}
			if((i&1)==0){
				val2/=2;
			}
			if(i&2){
				if(val>val2){
					continue;
				}
			}
			else{
				if(val<val2){
					continue;
				}
			}
		//	cout<<val<<":"<<val2<<endl;
			//cout<<i<<":"<<j<<endl;
			vector<int> ans;
			//cout<<i<<","<<j<<endl;
			int cur=j;
			for(int k=n-1;k>0;k--){
				if(cur&1){
					ans.pb((k+1)%n);
				}
				else{
					ans.pb(k);
				}
				cur=(int)back[k][i][cur]*2+(int)back2[k][i][cur];
			}
			if(i&2){
				ans.pb(1);
			}
			else{
				ans.pb(0);
			}
			for(int k=n-1;k>=0;k--){
				cout<<ans[k]+1<<" ";
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<"NIE"<<endl;




	return 0;
}