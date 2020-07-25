/*
every assignment is minmimum
observe what happens when you swap 2 assignments

so we sweep from right left by x coordinate and always take the pipe with closest y coordinate
can be done with set

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
llo n;
vector<pair<pair<llo,llo>,pair<llo,llo>>> ss;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	
	for(llo i=0;i<n;i++){
		llo aa,bb;
		cin>>aa>>bb;
		ss.pb({{aa,-bb},{0,i}});
	}
	for(llo i=0;i<n;i++){
		llo aa,bb;
		cin>>aa>>bb;
		ss.pb({{aa,-bb},{1,i}});
	}
	sort(ss.begin(),ss.end());
	reverse(ss.begin(),ss.end());
	for(llo i=0;i<2*n;i++){
		ss[i].a.b*=-1;
	}
	llo ans=0;
	vector<pair<llo,llo>> ans2;
	set<pair<llo,pair<llo,llo>>> tt;
	for(auto j:ss){
		//cout<<j.a.a<<":"<<j.a.b<<":"<<j.b.a<<":"<<j.b.b<<endl;
		if(j.b.a==0){
			if(tt.size()==0){
				while(true){
					continue;
				}
			}
			auto x=tt.upper_bound({j.a.b+1,{-1,-1}});
			if(x==tt.begin()){
					while(true){
						continue;
					}
				
			}
			x--;
			ans2.pb({j.b.b+1,(*x).b.a+1});
			ans+=abs(abs(j.a.a-(*x).b.b)+abs(j.a.b-(*x).a));
			tt.erase(x);
		}
		else{
			tt.insert({j.a.b,{j.b.b,j.a.a}});
		}
	}
	cout<<ans<<endl;
	for(auto j:ans2){
		cout<<j.a<<" "<<j.b<<endl;
	}








	return 0;
}