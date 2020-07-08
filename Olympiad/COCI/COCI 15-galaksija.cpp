/*
v[x]=xor of edges from root to x 
problem is number of pairs with equal values

run queries in reverse
small to large and update answer using pbds

*/

#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n;
vector<pair<llo,llo>> adj[100001];
vector<pair<llo,llo>> ed;
llo val[100001];
void dfs(llo no,llo par2=-1,llo val2=0){
	val[no]=val2;
	for(auto j:adj[no]){
		if(j.a==par2){
			continue;
		}
		dfs(j.a,no,val2^j.b);
	}
}
llo ans[100001];
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;
#define ord tree<pair<llo,llo>,null_type,less<pair<llo,llo>>,rb_tree_tag,tree_order_statistics_node_update>


ord ss[100001];
llo par[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n-1;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		ed.pb({aa-1,bb-1});
		aa--;
		bb--;
		adj[aa].pb({bb,cc});
		adj[bb].pb({aa,cc});
	}
	dfs(0);
	for(llo i=0;i<n;i++){
		ss[i].insert({val[i],i});
		par[i]=i;
	}
	vector<llo> kk;
	for(llo i=0;i<n-1;i++){
		llo aa;
		cin>>aa;kk.pb(aa-1);
	}
	ans[n-1]=0;
	llo ans2=0;
	for(llo i=n-2;i>=0;i--){
		llo x=par[ed[kk[i]].a];
		llo y=par[ed[kk[i]].b];

		if(ss[x].size()<ss[y].size()){
			swap(x,y);
		}
	//	cout<<x<<":"<<y<<endl;
		for(auto j:ss[y]){
		//	cout<<j<<','<<x<<","<<ss[x].order_of_key({j.a+1,0})-ss[x].order_of_key({j.a,0})<<endl;
			ans2+=ss[x].order_of_key({j.a+1,0})-ss[x].order_of_key({j.a,0});
		}
		for(auto j:ss[y]){
			ss[x].insert(j);
			par[j.b]=x;
		}
		ss[y].clear();
		ans[i]=ans2;
	}
	for(llo i=0;i<n;i++){
		cout<<ans[i]<<'\n';
	}






	return 0;
}