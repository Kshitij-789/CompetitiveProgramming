/*
let dp[i][j] denote minimum mistakes in sequence till index i if ith index is j
naive is L*N*N which gets only 65 points
optimize using bitsets and basic sqrt decomposition
*/
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
bitset<100> adj[101];
string kk[101];
int n,s,g;
int dp[100001][101];
int bb[100001][101];
int pp;
bool cmp(int ac,int cc){
	return dp[pp][ac]<dp[pp][cc]; 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>s>>g;
	for(int i=0;i<n;i++){
		cin>>kk[i];
		adj[i].set(i);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int co=0;
			for(int k=0;k<s;k++){
				if(kk[i][k]!=kk[j][k]){
					co+=1;
				}
			}
			if(co<=g){
				adj[i].set(j);
				adj[j].set(i);
		//		cout<<i<<","<<j<<endl;
			}
		}
	}
	int lo;
	cin>>lo;
	vector<int> back;
	for(int i=0;i<lo;i++){
		int cur;
		cin>>cur;
		cur--;
		if(i==0){
			for(int j=0;j<n;j++){
				if(cur==j){
					dp[0][j]=0;
				}
				else{
					dp[0][j]=1;
				}
			}
			back.pb(cur);
			for(int j=0;j<n;j++){
				if(cur==j){
				}
				else{
					back.pb(j);
				}
			}
			continue;
		}
		bitset<100> aa[10];
		/*for(auto j:back){
			cout<<j<<"::";
		}
		cout<<endl;*/
		for(int i=0;i<=(n-1)/10;i++){
			for(int j=i*10;j<min(n,(i+1)*10);j++){
				aa[i].set(back[j]);
			}
		}
		for(int j=0;j<n;j++){
			for(int p=0;p<=(n-1)/10;p++){
				if((aa[p]&adj[j]).any()){
					for(int k=p*10;k<min(n,(p+1)*10);k++){

						if(adj[j].test(back[k])){

							int kp=1;
							if(j==cur){
								kp=0;
							}
							dp[i][j]=dp[i-1][back[k]]+kp;
							bb[i][j]=back[k];
							break;
						}
					}
					break;
				}
			}
	//		cout<<dp[i][j]<<",";
		}
	//	cout<<endl;
		back.clear();
		for(int j=0;j<n;j++){
			back.pb(j);
		}
		pp=i;
		sort(back.begin(),back.end(),cmp);
	}
	cout<<dp[lo-1][back[0]]<<endl;
	int x=back[0];
	vector<int> ans;
	for(int i=0;i<lo;i++){
	//	cout<<x+1<<" ";
		ans.pb(x+1);
		if(i<lo-1){
			x=bb[lo-i-1][x];
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto j:ans){
		cout<<j<<" ";
	}
	cout<<endl;





 
 
	return 0;
}