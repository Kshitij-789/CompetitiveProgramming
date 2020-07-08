

#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

llo dp[21][21][21];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	dp[1][1][0]=1;
	dp[1][1][1]=1;
	for(llo i=2;i<21;i++){
		for(llo j=1;j<i+1;j++){
			for(llo k=1;k<j;k++){
				dp[i][j][0]+=dp[i-1][k][1];
			}
			for(llo k=j;k<i;k++){
				dp[i][j][1]+=dp[i-1][k][0];
			}
		}
	}
	llo k;
	cin>>k;
	while(k--){
		llo n,c;
		cin>>n>>c;
		llo cur=0;
		llo par=0;
		llo lim=0;
		set<llo> val;
		for(llo i=1;i<n+1;i++){
			val.insert(i);
		}
		for(llo i=0;i<n;i++){
			cur+=dp[n][i+1][0];
			if(cur>=c){
				cur-=dp[n][i+1][0];
				lim=i+1;
				cout<<i+1<<" ";
				val.erase(i+1);
				par=0;
				break;
			}
			else{
				cur+=dp[n][i+1][1];
				if(cur>=c){

					lim=i+1;
					cur-=dp[n][i+1][1];
					cout<<i+1<<" ";
					val.erase(i+1);
					par=1;
					break;
				}
				else{
				}
			}
		}
		for(llo i=n-1;i>0;i--){
			if(par==0){
				llo ind=0;
				for(auto j:val){
					ind+=1;
					if(j<lim){
						cur+=dp[i][ind][1-par];
						if(cur>=c){
							lim=j;
							cur-=dp[i][ind][1-par];
							break;
						}

					}
					else{
						break;
					}
				}
			}
			else{
				llo ind=0;
				for(auto j:val){
					ind+=1;
					if(j>lim){
						cur+=dp[i][ind][1-par];
						if(cur>=c){
							lim=j;
							cur-=dp[i][ind][1-par];
							break;
						}
					}
				}
			}
			val.erase(lim);
			cout<<lim<<" ";
			par=1-par;
		}
		cout<<endl;
	}








	return 0;
}