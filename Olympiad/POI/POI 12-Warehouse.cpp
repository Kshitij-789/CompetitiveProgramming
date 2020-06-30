#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n;
llo aa[250001];
llo bb[250001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	for(llo i=0;i<n;i++){
		cin>>bb[i];
	}
	set<llo> ans;
	for(llo i=0;i<n;i++){
		ans.insert(i+1);
	}
	set<pair<llo,llo>> ma;
	llo su=0;
	for(llo i=0;i<n;i++){
		su+=aa[i]-bb[i];
		ma.insert({-bb[i],i+1});
		if(su<0){
			pair<llo,llo> no=*(ma.begin());
			su-=no.a;
			ans.erase(no.b);
			ma.erase(ma.begin());
		}
	}
	cout<<ans.size()<<endl;
	for(auto j:ans){
		cout<<j<<" ";
	}
	cout<<endl;




	
	return 0;
}

