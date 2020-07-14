/*
https://csacademy.com/contest/ioi-2016-training-round-2/task/increasing_subarrays/solution/
*/
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

llo n,m;
llo it[1000001];
llo pre[1000001];
llo ne[1000001];
llo su[1000001];

//llo ma[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		pre[i+1]=pre[i]+it[i];
	}
	vector<pair<llo,llo>> aa;
	for(llo i=n-1;i>=0;i--){
		while(aa.size()){
			if(aa.back().a<=it[i]){
				aa.pop_back();
			}
			else{
				break;
			}
		}
		if(aa.size()){
			ne[i]=aa.back().b;
		}
		else{
			ne[i]=-1;
		}
		aa.pb({it[i],i});
	}
	aa.clear();
	for(llo i=0;i<n;i++){
		if(ne[i]==-1){
			su[i]=(it[i]*(n-i-1))-(pre[n]-pre[i+1]);
		}
		else{
			su[i]=(it[i]*(ne[i]-i-1))-(pre[ne[i]]-pre[i+1]);
		}
	}
	llo ans=0;
	deque<llo> kk;
	llo prev=-1;
	llo tot=0;
	for(llo i=n-1;i>=0;i--){
		while(kk.size()){
			if(kk.front()!=ne[i]){
				tot-=su[kk.front()];
				kk.pop_front();
			}
			else{
				break;
			}
		}
		tot+=su[i];
		kk.push_front(i);
		while(kk.size()){
			if(tot-su[kk.back()]>m){
				kk.pop_back();
			}
			else{
				break;
			}
		}
		llo low=kk.back();
		llo high=n-1;
		if(ne[low]!=-1){
			high=ne[low]-1;
		}
		llo ko=tot-su[low];
		if(ko>m){
			while(true){
				continue;
			}
		}
		llo ind=kk.back();
		while(low<high-1){
			llo mid=(low+high)/2;
			if(ko+(it[ind]*(mid-ind)-(pre[mid+1]-pre[ind+1]))<=m){
				low=mid;
			}
			else{
				high=mid;
			}
		}
		llo ind2=low;
		if(ko+(it[ind]*(high-ind)-(pre[high+1]-pre[ind+1]))<=m){
			ind2=max(ind2,high);
		}
		ans+=ind2-i+1;
	}

	cout<<ans<<endl;





	return 0;
}

