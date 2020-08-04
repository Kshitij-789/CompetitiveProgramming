/*

I proved that product does not exceed 3.ie there is only node more than 1 in the optimal path

even case
let there be path of size-2k
then split it in 2 parts of size k
let product of 2k nodes be x
there is one path with product<=root(x)

so look at the case where the path with product root(x) has more cost than the original one
root(x)/k>x/(2*k)
reduces to x<=3

so this shows that if there is even path with product more than 3 then we can obtain a better result

the odd case has similar proof just a bit more complicated

now to find such path see later half of this https://github.com/mostafa-saad/MyCompetitiveProgramming/tree/master/Olympiad/COCI/official/2017/contest1_solutions


*/
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define all(x) x.begin(),x.end()
void setIO(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

pair<llo,llo> ans;
vector<llo> adj[1000001];
vector<pair<llo,llo>> kk[1000001];
llo it[1000001];
llo dp[1000001];
llo n;
void remin(pair<llo,llo> xx){
	llo yo=__gcd(xx.a,xx.b);
	xx.a/=yo;
	xx.b/=yo;
	if(xx.a*ans.b<xx.b*ans.a){
		ans=xx;
	}
}
void dfs(llo no,llo par=-1,llo co=0){
	co+=1;
	if(it[no]>1){
		co=0;
	}
	llo ma=0;
	for(auto j:adj[no]){
		if(j==par){
			continue;
		}
		dfs(j,no,co);
		ma=max(ma,dp[j]);
		kk[no].pb({dp[j],j});
	}
	sort(all(kk[no]));
	reverse(all(kk[no]));
	llo cc=0;
	for(llo i=0;i<kk[no].size();i++){
		if(i==2){
			break;
		}
		cc+=kk[no][i].a;
	}
	remin({it[no],1+cc});
	if(it[no]==1){
		dp[no]=ma+1;
	}
}
void dfs2(llo no,llo par=-1,llo co=0){
	llo kp=co+1;
	if(kk[no].size()){
		kp+=kk[no][0].a;
	}
	remin({it[no],kp});
	if(it[no]==1){
		co+=1;
	}
	else{
		co=0;
	}
	llo ma=0;
	for(auto j:adj[no]){
		if(j==par){
			continue;
		}
		llo se=0;
		if(it[no]==1){
			se=max(se,co);
			llo su=1;
			for(int i=0;i<2;i++){
				if(i==kk[no].size()){
					break;
				}
				if(kk[no][i].b==j){
					continue;
				}
				su+=kk[no][i].a;
				break;
			}
			se=max(se,su);
		}
		dfs2(j,no,se);
	}


}




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	ans={it[0],1};
	dfs(0);
	dfs2(0);
	cout<<ans.a<<"/"<<ans.b<<endl;



	return 0;
}