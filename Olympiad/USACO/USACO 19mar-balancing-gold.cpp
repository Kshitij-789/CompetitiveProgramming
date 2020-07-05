/*
The solution I got turned out to be the same as the official solution
http://usaco.org/current/data/sol_balance_gold_open19.html
*/
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
llo n;
vector<llo> co[2];
vector<llo> co2[2];

llo pre[200001];
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("balance");
	cin>>n;
	
	
	llo co3=0;
	llo co4=0;
	llo su=0;
	llo su2=0;
	for(llo i=0;i<2*n;i++){
		cin>>it[i];
		if(i<n){
			co[it[i]].pb(i);
		}
		else{
			co2[it[i]].pb(i);
		}
		if(i>=n and it[i]==1){
			co4+=1;
		}
		else if(i>=n){
			su2+=co4;
		}
		if(i<n and it[i]==1){
			co3+=1;
		}
		else if(i<n){
			su+=co3;
		}
		if(i>0){
			pre[i]=pre[i-1];
		}
		if(it[i]==1){
			pre[i]+=1;
		}
	}
/*	if(n==5){
		cout<<1<<endl;
		return 0;
	}
*/
	llo ans=abs(su-su2);
	llo su3=su;
	llo su4=su2;
//	cout<<su<<"::"<<su2<<endl;
	llo mo=0;
	reverse(co[0].begin(),co[0].end());
	reverse(co[1].begin(),co[1].end());

	for(llo i=0;i<min(co[0].size(),co2[1].size());i++){
		mo+=n-1-co[0][i];
		mo+=co2[1][i]-n;
		mo+=1;
		su3-=pre[co[0][i]];
		su4-=((2*n-1-co2[1][i])-(pre[2*n-1]-pre[co2[1][i]]));
	//	cout<<mo<<","<<su3<<","<<su4<<endl;
	//	cout<<co[0][i]<<","<<co2[1][i]<<endl;
		ans=min(ans,mo+abs(su3-su4));
	}
	su3=su;
	su4=su2;
	mo=0;

	for(llo i=0;i<min(co[1].size(),co2[0].size());i++){
		mo+=n-1-co[1][i];
		mo+=co2[0][i]-n;
		mo+=1;
		su3-=(n-1-co[1][i]);
		su4-=(co2[0][i]-n);

		su3+=(pre[co[1][i]]-1);
		su4+=(2*n-1-co2[0][i])-(pre[2*n-1]-pre[co2[0][i]]);


	//	cout<<mo<<","<<su3<<","<<su4<<endl;
	//	cout<<co[0][i]<<","<<co2[1][i]<<endl;
		ans=min(ans,mo+abs(su3-su4));
	}

	//cout<<ans<<endl;










	cout<<ans<<endl;









	return 0;
}