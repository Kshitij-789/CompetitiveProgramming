#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n,m,s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>s;
	vector<pair<llo,llo>> kk;
	for(llo i=0;i<n;i++){
		llo aa,bb;
		cin>>aa>>bb;
		kk.pb({aa,bb});
	}
	sort(kk.begin(),kk.end());
	llo su=0;
	reverse(kk.begin(),kk.end());
	set<pair<llo,llo>> ss;
	set<pair<llo,llo>> tt;
	set<pair<llo,llo>> mm;
	for(llo i=0;i<n;i++){
		if(i<m){
			su+=kk[i].a;
			ss.insert({kk[i].a-kk[i].b,i});
		}		
		else{
			tt.insert({-kk[i].b,i});
			mm.insert({-kk[i].a,i});
		}
	}
	if(m==n){
		cout<<su<<endl;
		return 0;
	}
	for(llo i=0;i<s;i++){
		llo x=-(*tt.begin()).a;
		llo y=-(*ss.begin()).a-(*mm.begin()).a;
		if(y>x){
			su+=y;
			ss.erase(ss.begin());
			pair<llo,llo> no=*(mm.begin());
			mm.erase(mm.begin());
			tt.erase({-kk[no.b].b,no.b});
			ss.insert({kk[no.b].a-kk[no.b].b,no.b});
		}
		else{
			pair<llo,llo> no=*(tt.begin());
			mm.erase({-kk[no.b].a,no.b});
			tt.erase(tt.begin());
			su+=x;
		}
	}
	cout<<su<<endl;

	






	
	return 0;
}

