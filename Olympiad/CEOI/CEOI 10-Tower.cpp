#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

llo n,d;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>d;
	vector<llo> aa;
	for(llo i=0;i<n;i++){
		llo bb;
		cin>>bb;
		aa.pb(bb);
	}
	sort(aa.begin(),aa.end());
	llo ans=1;
	llo mod=1e9+9;
	for(llo i=1;i<n;i++){
		if(aa[i-1]<aa[i]-d){
			continue;
		}
		llo x=lower_bound(aa.begin(),aa.end(),aa[i]-d)-aa.begin();

		ans*=(i-x+1);
		ans%=mod;

	}
	cout<<ans<<endl;




	return 0;
}

