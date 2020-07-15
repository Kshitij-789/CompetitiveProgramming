#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
#define ord tree<llo,null_type,less_equal<llo>,rb_tree_tag,tree_order_statistics_node_update>




int n,c;
ord aa[10001];
int it[300001];
int tree2[1200001];
void build(int no,int l,int r){
	if(l==r){
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
	}
	int ma=0;
	int ind=0;
	for(int i=l;i<=r;i++){
		int x=aa[it[i]].order_of_key(r+1)-aa[it[i]].order_of_key(l);
		if(x>ma){
			ma=x;
			ind=it[i];
		}
	}
	tree2[no]=ind;
}
int ans=-1;
void query(int no,int l,int r,int ac,int bb){
	if(r<ac or l>bb){
		return ;
	}
	if(ac<=l and r<=bb){
		int xx=aa[tree2[no]].order_of_key(bb+1)-aa[tree2[no]].order_of_key(ac);
		if(xx>(bb-ac+1)/2){
			ans=tree2[no];
		}
	}
	else{
		int mid=(l+r)/2;
		query(no*2+1,l,mid,ac,bb);
		query(no*2+2,mid+1,r,ac,bb);
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>it[i];
		aa[it[i]].insert(i);
	}
	build(0,0,n-1);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int ac,bb;
		cin>>ac>>bb;
		ac--;
		bb--;
		ans=-1;
		query(0,0,n-1,ac,bb);
		if(ans==-1){
			cout<<"no"<<endl;
		}
		else{
			cout<<"yes"<<" "<<ans<<endl;
		}

	}







	return 0;
}