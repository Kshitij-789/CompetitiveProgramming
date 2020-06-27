#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo par[200001];
llo n,q;

/*llo find(llo no){
	//cout<<no<<endl;
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}*/
llo vis[200001];
vector<llo> co[200001];
llo tree[200001];
llo mod=1e9+7;

void u(llo i,llo j){
	j%=mod;
	while(i<200001){
		tree[i]+=j;
		tree[i]%=mod;
		i+=(i&-i);
	}
}
llo s(llo i){
	llo tot=0;
	while(i>0){
		tot+=tree[i];
		tot%=mod;
		i-=(i&-i);
	}
	return tot;
}
llo tree2[200001];
void u2(llo i,llo j){
	j%=mod;
	while(i<200001){
		tree2[i]+=j;
		tree2[i]%=mod;
		i+=(i&-i);
	}
}
llo s2(llo i){
	llo tot=0;
	while(i>0){
		tot+=tree2[i];
		i-=(i&-i);
		tot%=mod;
	}
	return tot;
}
llo pre[200001];
llo pre2[200001];
llo e(llo aa,llo bb,llo cc){
	if(bb==0){
		return 1;
	}
	llo ans=e(aa,bb/2,cc);
	ans*=ans;
	ans%=cc;
	if(bb%2==1){
		ans*=aa;
		ans%=cc;
	}
	return ans;
}
llo comp(llo aa,llo bb){
	return (((s(bb+1)-s(aa)+2*mod)%mod)*(pre2[aa]))%mod;
}
llo comp2(llo aa,llo bb){
	aa=n-aa-1;
	bb=n-bb-1;
	return (((s2(bb+1)-s2(aa)+2*mod)%mod)*(pre2[aa]))%mod;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin>>n>>q;
	pre[0]=1;
	llo pp=1e7+6;
	for(llo i=1;i<200001;i++){
		pre[i]=(pre[i-1]*pp)%mod;
	}
	for(int i=0;i<200001;i++){
		pre2[i]=e(pre[i],mod-2,mod);
	}


	for(llo i=0;i<n;i++){
		par[i]=i;
		co[i].pb(i);
	}

	llo ans=n;
	for(llo i=0;i<n;i++){
		u(i+1,i*pre[i]);
	}
	for(llo i=0;i<n;i++){
		llo ko=i*pre[n-i-1];
		u2(n-i-1+1,i*pre[n-i-1]);
		/*u2(1,ko);
		u2(i+2,-ko+mod);*/
	//	u2(i+1,i*pre[n-i-1]);
	}
	for(llo j=0;j<q;j++){
	//	cout<<j<<endl;
		llo l,r;
		cin>>l>>r;
		l--;
		r--;
		while(l<r){
			llo low=0;
			llo high=(r-l-1)/2;
			if(comp(l,l+high)==comp2(r,r-high)){
		//		cout<<high<<endl;
		//		cout<<l<<"::"<<l+high<<" "<<r<<","<<r-high<<endl;
		//		cout<<comp(l,l+high)<<","<<comp2(r,r-high)<<endl;
				break;
			}
			while(low<high-1){
				llo mid=(low+high)/2;
				if(comp(l,l+mid)==comp2(r,r-mid)){
					low=mid+1;
				}
				else{
					high=mid;
				}
			}
			llo ind=high;
			if(comp(l,l+low)!=comp2(r,r-low)){
				ind=min(ind,low);
			}
			llo ll=par[l+ind];

			llo rr=par[r-ind];
		//	cout<<l<<","<<r<<","<<ind<<":"<<endl;
			if(co[ll].size()<co[rr].size()){
				swap(ll,rr);
			}
			for(auto j:co[rr]){
				co[ll].pb(j);
				u(j+1,(ll-par[j]+mod)*pre[j]);
				u2(n-j-1+1,(ll-par[j]+mod)*pre[n-j-1]);
			/*	u2(1,(ll-par[j]+mod)*(pre[n-j-1]));
				llo ko=(ll-par[j]+mod)*(pre[n-j-1]);
				ko%=mod;
				u2(j+2,(-ko+mod)%mod);*/
				par[j]=ll;
			}

			l+=ind+1;
			r-=ind+1;
			ans--;
		}
	/*	for(int i=0;i<n;i++){
			cout<<s(i+1)<<":"<<s2(i+1)<<endl;
		}
		for(int i=0;i<n;i++){
			cout<<par[i]<<" ";
		}
		cout<<endl;*/

		cout<<ans<<endl;

	}






	
	return 0;
}

