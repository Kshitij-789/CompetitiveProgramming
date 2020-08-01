#pragma GCC optimize("Ofast,unroll-loops")

/*
https://www.youtube.com/watch?v=BG4vAoV5kWw
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n,k,m;
vector<pair<int,int>> adj[100001];
vector<int> dd;
llo dist[5][100001];
void dj(int tt,int s){
	for(llo i=0;i<n;i++){
		dist[tt][i]=-1;
	}
	dist[tt][s]=0;
	priority_queue<pair<llo,int>> ss;
	ss.push({0,s});
	/*	for(llo i=0;i<k;i++){
		for(llo j=0;j<n;j++){
			cout<<dist[i][j]<<",";
		}
		cout<<endl;
	}*/
	while(ss.size()){
		pair<llo,int> no=ss.top();
		ss.pop();
		if(-no.a>dist[tt][no.b]){
			continue;
		}
	//	cout<<no.a<<','<<no.b<<endl;
		for(auto j:adj[no.b]){
		//	cout<<j.a<<"::"<<j.b<<endl;

			if(dist[tt][j.a]==-1 or dist[tt][j.a]>dist[tt][no.b]+j.b){
				dist[tt][j.a]=dist[tt][no.b]+j.b;
				ss.push({-dist[tt][j.a],j.a});
			}
		}
	}
}
llo ans=0;
//vector<pair<pair<int,int>,llo>> adj2[100001][32];
llo dist2[100001][32];
vector<int>kc[32];
void dj2(){
	for(llo i=0;i<n;i++){
		for(llo j=0;j<(1<<k);j++){
			dist2[i][j]=-1;
		}
	}
	priority_queue<pair<llo,pair<int,int>>> ss;

	for(auto j:dd){
		dist2[j][0]=0;
		ss.push({0,{j,0}});
	}
//	dist2[s][0]=0;
//	ss.push({0,{s,0}});

	while(ss.size()){
		pair<llo,pair<int,int>> no=ss.top();
		ss.pop();
		if(-no.a>dist2[no.b.a][no.b.b]){
			continue;
		}
		for(auto j:adj[no.b.a]){
			if(dist2[j.a][no.b.b]==-1 or dist2[j.a][no.b.b]>dist2[no.b.a][no.b.b]+j.b){
				dist2[j.a][no.b.b]=dist2[no.b.a][no.b.b]+j.b;
				ss.push({-dist2[j.a][no.b.b],{j.a,no.b.b}});
			}
		}
		for(auto kk:kc[no.b.b]){
		//	if(((1<<kk)&no.b.b)==0){
				if(dist2[no.b.a][no.b.b+(1<<kk)]==-1 or dist2[no.b.a][no.b.b+(1<<kk)]>dist2[no.b.a][no.b.b]+dist[kk][no.b.a]){
					dist2[no.b.a][no.b.b+(1<<kk)]=dist2[no.b.a][no.b.b]+dist[kk][no.b.a];
					ss.push({-dist2[no.b.a][no.b.b+(1<<kk)],{no.b.a,no.b.b+(1<<kk)}});
				}	
		//	}
		}

		/*for(auto j:adj2[no.b.a][no.b.b]){
		//	cout<<j.a.a<<":"<<j.a.b<<":"<<j.b<<":"<<dist2[j.a.a][j.a.b]<<endl;
			if(dist2[j.a.a][j.a.b]==-1 or dist2[j.a.a][j.a.b]>dist2[no.b.a][no.b.b]+j.b){
				dist2[j.a.a][j.a.b]=dist2[no.b.a][no.b.b]+j.b;
				ss.push({-dist2[j.a.a][j.a.b],j.a});
			}
		}*/
	}
	for(auto j:dd){
		ans=min(ans,dist2[j][(1<<k)-1]);
	}
	/*cout<<endl;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<(1<<k);j++){
			cout<<dist[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<endl;*/
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k>>m;
	for(int i=0;i<k;i++){
		int aa;
		cin>>aa;
		aa--;
		dd.pb(aa);
	}
	for(int i=0;i<m;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		adj[aa].pb({bb,cc});
		adj[bb].pb({aa,cc});
		ans+=cc;
	}

	for(int i=0;i<k;i++){
		dj(i,dd[i]);
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<k;j++){
			if(((1<<j)&i)==0){
				kc[i].pb(j);
			}
		}
	}

/*	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<k);j++){
			for(int kk=0;kk<k;kk++){
				if((1<<kk)&j){
					adj2[i][j-(1<<kk)].pb({{i,j},dist[kk][i]});
				}
			}
			for(auto kk:adj[i]){
				adj2[i][j].pb({{kk.a,j},kk.b});
			}
		}
	}*/
	//for(int i=0;i<1;i++){
		dj2();
	//}
	cout<<ans<<endl;


	return 0;
}