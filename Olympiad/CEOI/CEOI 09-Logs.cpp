/*
too easy
my solution is same as this-https://github.com/MetalBall887/Competitive-Programming/blob/master/Olympiad/CEOI/CEOI%2009-Logs.cpp
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

int n,m;
string it[15001];
void setIO(string s){
	freopen((s+".in").c_str(),"r",stdin);
	//freopen((s+".out").c_str(),"w",stdout);

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//setIO("log");
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	int ans=0;
	vector<pair<int,int>> ss;
	for(int i=0;i<m;i++){
		ss.pb({0,i});
	}
	vector<pair<int,int>> tt;
	vector<pair<int,int>> mm;
	for(int i=n-1;i>=0;i--){

		for(auto j:ss){
			if(it[i][j.b]=='1'){
				tt.pb({j.a+1,j.b});
			}
			else{
				mm.pb({0,j.b});
			}
		}
		ss=tt;
		for(auto j:mm){
			ss.pb(j);
		}
		tt.clear();
		mm.clear();
		int ind=0;
		for(int j=0;j<m;j++){
			ans=max(ans,(j+1)*ss[j].a);
		}
	}

	cout<<ans<<endl;

	return 0;
}