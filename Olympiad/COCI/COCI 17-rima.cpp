/*
dp on the trie
my solution is same as this:

https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2017/contest4_solutions/solutions.pdf

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int co=0;
int n;
int pre[3100001][26];
vector<int> kk[3100001];
int val[3100001];
int dp[3100001];
void insert(string s){
	int cur=0;
	for(int i=s.size()-1;i>=0;i--){
		if(pre[cur][s[i]-'a']==0){
			co+=1;
			pre[cur][s[i]-'a']=co;
			kk[cur].pb(co);
		}
		cur=pre[cur][s[i]-'a'];
	}
	val[cur]+=1;
}
int ans=0;
void dfs(int no){
	int su=0;
	int ma=0;
	vector<int> mm;
	for(auto j:kk[no]){
		dfs(j);
		su+=min(dp[j],1);
		ma=max(ma,dp[j]);
		mm.pb(-dp[j]);
	}
	sort(mm.begin(),mm.end());
	int su2=su;
	for(int i=0;i<min((int)mm.size(),(int)2);i++){
		if(mm[i]<0){
			su2+=-mm[i]-1;
		}
	}
	if(ma){
		su+=ma-1;
	}
	ans=max(ans,su);
	ans=max(ans,su2);
	ans=max(ans,su2+val[no]);
	if(val[no]==1){
		dp[no]=su+1;
		ans=max(ans,dp[no]);
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		//	int x=s.size();
		insert(s);
	}
	dfs(0);
	cout<<ans<<endl;



	return 0;
}