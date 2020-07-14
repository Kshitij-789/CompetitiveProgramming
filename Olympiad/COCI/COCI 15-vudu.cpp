/*
reduce each element by p
problem reduces to finding number of subarrays with sum>=0

memory limit tight had to replace pbds with compression+bit.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
#define ord tree<llo,null_type,less_equal<llo>,rb_tree_tag,tree_order_statistics_node_update>


*/

int n;
int it[1000001];
int ind[1000001];
int p;
int tree[1000001];
void u(int i,int j){
	while(i<1000001){
		tree[i]+=j;
		i+=(i&-i);
	}
}
int s(int i){
	int su=0;
	while(i){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	cin>>p;
	vector<pair<llo,int>> pp;
	llo su2=0;
	pp.pb({0,-1});

	for(int i=0;i<n;i++){
		it[i]-=p;
		su2+=it[i];
		pp.pb({su2,i});
	}
	sort(pp.begin(),pp.end());
	int ind2;
	for(int i=0;i<n+1;i++){
		if(pp[i].b==-1){
			ind2=i;
		}
		else{
			ind[pp[i].b]=i;
		}
	}
//	ord ss;
	llo ans=0;
	llo su=0;
	u(ind2+1,1);
//	ss.insert(0);
	for(int i=0;i<n;i++){
		su+=it[i];
		ans+=s(ind[i]+1);//ss.order_of_key(su+1);
		u(ind[i]+1,1);
	//	ss.insert(su);
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;







	return 0;
}

