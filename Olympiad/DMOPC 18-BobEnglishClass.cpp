/*
solution same as editorial
*/
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo k,n;
llo co[200001];
llo ss[200001];
vector<pair<llo,llo>> adj[200001];
void dfs(llo no,llo par2=-1){
	ss[no]=co[no];
	for(auto j:adj[no]){
		if(j.a==par2){
			continue;
		}
		dfs(j.a,no);
		ss[no]+=ss[j.a];
	}
}
llo dfs2(llo no,llo par2=-1){
	for(auto j:adj[no]){
		if(j.a==par2){
			continue;
		}
		if(ss[j.a]>k/2){
			return dfs2(j.a,no);
		}
	}
	return no;
}
llo ans2=0;
void dfs3(llo no,llo par2=-1,llo levv=0){
	ans2+=co[no]*levv;
	for(auto j:adj[no]){
		if(j.a==par2){
			continue;
		}
		dfs3(j.a,no,levv+j.b);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>k>>n;
	for(llo i=0;i<k;i++){
		llo ko;
		cin>>ko;
		
		co[ko-1]++;
	}
	for(llo i=0;i<n-1;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		adj[aa].pb({bb,cc});
		adj[bb].pb({aa,cc});
	}
	dfs(0);
	llo cen=dfs2(0);
	dfs3(cen);

	cout<<ans2<<endl;








	return 0;
}