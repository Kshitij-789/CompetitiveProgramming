/*
dilworth thereom 
min partition into chains=max antichain
so the solution is to sort on one coordinate and lds on other
for the queries they can be done offline easily with the help of a segment tree



*/

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
llo n,q;
llo tree[800001];
void update(llo no,llo l,llo r,llo i,llo val2){
	if(l==r){
		tree[no]=val2;
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,val2);
		}
		else{
			update(no*2+2,mid+1,r,i,val2);
		}
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	else{
		llo mid=(l+r)/2;
		return max(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));

	}
}
llo ind3[200001];
llo val[200001];
llo ss=0;
llo ans[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	vector<pair<pair<llo,llo>,llo>> cur;
	vector<pair<llo,llo>> cur2;
	for(llo i=0;i<n;i++){
		llo aa,bb;
		cin>>aa>>bb;
		cur2.pb({aa,i});
		cur.pb({{bb,-aa},i});
	}

	sort(cur.begin(),cur.end());
/*	for(llo i=0;i<n;i++){
		ind[cur[i].b]=i;
	}*/
	vector<llo> kk;
	for(llo i=0;i<n;i++){
		cur[i].a.b*=n;
		cur[i].a.b+=i;
		if(i==0){
			val[i]=1;
			kk.pb(cur[i].a.b);
		}
		else{
			if(kk.back()<cur[i].a.b){
				kk.pb(cur[i].a.b);
				val[i]=kk.size();
				continue;
			}
			if(cur[i].a.b<kk[0]){
				kk[0]=cur[i].a.b;
				val[i]=1;
				continue;
			}
			llo x=lower_bound(kk.begin(),kk.end(),cur[i].a.b)-kk.begin();
			kk[x]=cur[i].a.b;
			val[i]=x+1;
		}
		cur[i].a.b=(cur[i].a.b-i)/n;
	}
	sort(cur2.begin(),cur2.end());
	for(llo i=0;i<n;i++){
		ind3[cur2[i].b]=i;
	}


	vector<pair<pair<llo,llo>,llo>> qq;

	for(llo i=0;i<q;i++){
		llo aa,bb;
		cin>>aa>>bb;
		swap(aa,bb);
		qq.pb({{aa,bb},i});
	}
	sort(qq.begin(),qq.end());
	llo ind=0;
	llo ind2=0;
	while(ind<n or ind2<q){
		llo st=0;
		if(ind==n){
			st=1;
		}
		else if(ind2<q){
			if(qq[ind2].a.a<cur[ind].a.a){
				st=1;
			}
		}
		if(st==0){
			//cur
			update(0,0,n-1,ind3[cur[ind].b],val[ind]);
			ind++;
		}
		else{
			//qq
			if(cur2[n-1].a<qq[ind2].a.b){
				ans[qq[ind2].b]=0;
			}
			else{
				llo x=lower_bound(cur2.begin(),cur2.end(),make_pair(qq[ind2].a.b,(llo)0))-cur2.begin();
				ans[qq[ind2].b]=query(0,0,n-1,x,n-1);
			}
			ind2++;
		}
	}
	for(llo i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}





	return 0;
}