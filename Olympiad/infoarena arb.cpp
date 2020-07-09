
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
int n;
int tree[250001];
int it[250001];
void u(int i,int j){
	while(i<n+1){
		tree[i]+=j;
		i+=(i&-i);
	}
}
int ss(int i){
	int su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}
int ans[500001];
vector<int> kk[250001];
vector<int> adj[250001];

int lev[250001];
int st[250001];
int endd[250001];
int co=0;
void dfs(int no,int levv=0){
	lev[no]=levv;
	st[no]=co;
	co++;
	kk[levv].pb(no);
	for(auto j:adj[no]){
		dfs(j,levv+1);
	}
	endd[no]=co-1;
}
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	setIO("arb");
	cin>>n;
	int aa,bb;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	for(int i=1;i<n;i++){
		cin>>aa;
		aa--;
		adj[aa].pb(i);
	}
	dfs(0);
	int q;
	cin>>q;
	vector<pair<pair<int,int>,int>> cur;
	for(int i=0;i<q;i++){
		
		cin>>aa>>bb;
		aa--;
		cur.pb({{min(lev[aa]+bb,n),aa},i});
	}
	sort(cur.begin(),cur.end());
	int ind=-1;
	for(auto j:cur){
		while(ind<j.a.a){
			ind++;
			for(auto k:kk[ind]){
				u(st[k]+1,it[k]);
			}
		}
		ans[j.b]=ss(endd[j.a.b]+1)-ss(st[j.a.b]);
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<"\n";
	}





	return 0;
}