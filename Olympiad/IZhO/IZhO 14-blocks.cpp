/*
let dp[i][j] denote minimum answer for splitting first i in j segments
naive dp is n^2*k
we can optimize using  observations

let x be max index element with a_x>a_i(classical problem in o(N) using stacks)

notice answer is min(dp[x][j],min(dp[x][j-1],dp[x+1][j-1],,,,,,,,(dp[i-1][j-1]))+a_i)
observe that x to (i-1) segments intersect only at endpoints
can be done using stack
amortized O(nk)


note nk*log(n) wit segment tree gets TLE
I first tried that

*/
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int n,k;

int dp[100001];
int dp2[100001];

int it[100001];
int tree[400001];
int pre[100001];
/*void build(int no,int l,int r){
	if(l==r){
		tree[no]=dp[l];
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
	}
}
int query(int no,int l,int r,int aa,int bb){
	if(r<aa or l>bb){
		return 1e9;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	else{
		int mid=(l+r)/2;
		return min(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));
	}
}*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	vector<pair<int,int>> ac;
	for(int i=0;i<n;i++){
		cin>>it[i];

		while(ac.size()){
			if(ac.back().a<=it[i]){
				ac.pop_back();
			}
			else{
				break;
			}
		}
		if(ac.size()==0){
			pre[i]=-1;
		}
		else{
			pre[i]=ac.back().b;
			
		}
		ac.pb({it[i],i});
	/*	for(int kk=pre[i]+1;kk<i;kk++){
			if(it[kk]>it[i]){
				while(true){
					continue;
				}
			}
		}*/

	//	cout<<pre[i]<<",";
	}
	//cout<<endl;


	int ma=0;
	for(int i=0;i<n;i++){
		ma=max(ma,it[i]);
		dp[i]=ma;
		dp2[i]=1e9;
	}


	for(int i=1;i<k;i++){
		//build(0,0,n-1);
		vector<pair<pair<int,int>,int>> cur;
		int mo=1e9;
		for(int j=i;j<n;j++){
			
			mo=min(mo,dp[j-1]);
			if(pre[j]>=i){
				dp2[j]=dp2[pre[j]];
			}
			cur.pb({{j-1,j-1},dp[j-1]});
		//	cout<<j<<endl;
			if(pre[j]==-1){
				dp2[j]=min(dp2[j],mo+it[j]);
			}
			else{
				pair<pair<int,int>,int> mi={{-1,-1},1e9};
				int mk=1e9;
				while(cur.size()){
					if(cur.back().a.a>=pre[j]){
						if(mi.a.a==-1){
							mi=cur.back();
						}
						else{
							mi.a.a=min(mi.a.a,cur.back().a.a);
							mi.a.b=max(mi.a.b,cur.back().a.b);
							mi.b=min(mi.b,cur.back().b);
						}
						mk=mi.b;
						cur.pop_back();
				//		cout<<mi.a.a<<","<<mi.a.b<<","<<mi.b<<endl;
					}
					else{
						for(int kk=pre[j];kk<mi.a.a;kk++){
							mk=min(mk,dp[kk]);
						}
						break;
					}
				}
				cur.pb(mi);

				dp2[j]=min(dp2[j],mk+it[j]);
			}
		}
		for(int j=0;j<n;j++){
			dp[j]=dp2[j];
			dp2[j]=1e9;
		}
	}

	cout<<dp[n-1]<<endl;






	return 0;
}