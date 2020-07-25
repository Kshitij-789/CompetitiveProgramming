//#pragma GCC optimize("Ofast,unroll-loops")
/*
notice that the f(x) if x can win the race is monotonic with respect to th time.
it is initially 1 and can change to 0 permamantly.

sort everything(a1 biggest an smallest)
to check if a car can win-check if n+ai>=max(a1+1,a2+2,,,,,,a_(i-1)+(i-1));
we maintain 2 seg trees one with ai and one with ai+i
while processing updates we can use binary search on seg tree to find the index
1. update we update seg tree in (1,ind);we also have a function which checks if there is value which can no longer win.
we run that function with max(tree2[1],,,,tree2[ind]) on index ind+1,n
(update3 function)

updates of type 2 are just the same done in reverse



notice that an element can be cancelled only once so only logn ancestors in seg tree and complexity nlogn
if a node is disabled I replace it by 1e18


*/
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

llo tree[1200001];
llo tree2[1200001];
llo tree3[1200001];
llo tree4[1200001];

llo inf=1e18;
llo lazy[1200001];
llo lazy2[1200001];
llo lazy3[1200001];

llo it[300001];
llo n,q;
void build(llo no,llo l,llo r){
	lazy[no]=0;
	if(l==r){
		tree[no]=it[l];
		tree3[no]=it[l];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
		tree3[no]=min(tree3[no*2+1],tree3[no*2+2]);
	}
	tree4[no]=tree3[no];
}
void push(llo no,llo l,llo r){
	if(lazy[no]==0){
		return;
	}
	tree[no]+=lazy[no];
	tree3[no]+=lazy[no];
	tree4[no]+=lazy[no];
	if(l<r){
		lazy[no*2+1]+=lazy[no];
		lazy[no*2+2]+=lazy[no];
	}
	lazy[no]=0;
}
void push2(llo no,llo l,llo r){
	if(lazy2[no]==0){
		return;
	}
	tree2[no]+=lazy2[no];
	if(l<r){
		lazy2[no*2+1]+=lazy2[no];
		lazy2[no*2+2]+=lazy2[no];
	}
	lazy2[no]=0;
}


llo find(llo no,llo l,llo r,llo val,llo ba=-1){
	push(no,l,r);
//	cout<<l<<','<<r<<','<<ba<<endl;
//	cout<<tree[no]<<endl;
	if(l==r){
		if(tree3[no]>=val){
			return l;
		}
		return ba;
	}
	else{
		llo mid=(l+r)/2;
		if(tree3[no*2+1]+lazy[no*2+1]>=val){
			return find(no*2+2,mid+1,r,val,mid);
		}
		else{
			return find(no*2+1,l,mid,val,ba);
		}
	}
}
llo find2(llo no,llo l,llo r,llo val,llo ba=-1){
	push(no,l,r);
	if(l==r){
		if(tree[no]<=val){
			return l;
		}
		return ba;
	}
	else{
		llo mid=(l+r)/2;
		if(tree[no*2+2]+lazy[no*2+2]<=val){
			return find2(no*2+1,l,mid,val,mid+1);
		}
		else{
			return find2(no*2+2,mid+1,r,val,ba);
		}
	}
}
void update(llo no,llo l,llo r,llo aa,llo bb,llo val){
	push(no,l,r);
	if(r<aa or l>bb){
		return;
	}
	if(aa<=l and r<=bb){
		tree[no]+=val;
		tree3[no]+=val;
		tree4[no]+=val;
		if(l<r){
			lazy[no*2+1]+=val;
			lazy[no*2+2]+=val;
		}
	}
	else{
		llo mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,val);
		update(no*2+2,mid+1,r,aa,bb,val);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
		tree3[no]=min(tree3[no*2+1],tree3[no*2+2]);
		tree4[no]=min(tree4[no*2+1],tree4[no*2+2]);
	}
}
//deleting uselss indices
void update4(llo no,llo l,llo r,llo aa,llo val){
	push(no,l,r);
	if(l==r){
		tree4[no]+=val;

	}
	else{
		llo mid=(l+r)/2;
		if(aa<=mid){
			update4(no*2+1,l,mid,aa,val);
			push(no*2+2,mid+1,r);
		}
		else{
			update4(no*2+2,mid+1,r,aa,val);
			push(no*2+1,l,mid);
		}
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
		tree3[no]=min(tree3[no*2+1],tree3[no*2+2]);
		tree4[no]=min(tree4[no*2+1],tree4[no*2+2]);
	}
}

void build2(llo no,llo l,llo r){
	lazy2[no]=0;
	if(l==r){
		tree2[no]=it[l]+l+1;
	}
	else{
		llo mid=(l+r)/2;
		build2(no*2+1,l,mid);
		build2(no*2+2,mid+1,r);
		tree2[no]=max(tree2[no*2+1],tree2[no*2+2]);
	}
}
void update2(llo no,llo l,llo r,llo aa,llo bb,llo val){
	push2(no,l,r);
	if(r<aa or l>bb){
		return;
	}
	if(aa<=l and r<=bb){
		tree2[no]+=val;
		if(l<r){
			lazy2[no*2+1]+=val;
			lazy2[no*2+2]+=val;
		}
	}
	else{
		llo mid=(l+r)/2;
		update2(no*2+1,l,mid,aa,bb,val);
		update2(no*2+2,mid+1,r,aa,bb,val);
		tree2[no]=max(tree2[no*2+1],tree2[no*2+2]);
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	push2(no,l,r);
	if(r<aa or l>bb){
		return -inf;
	}
	if(aa<=l and r<=bb){
		return tree2[no];
	}
	else{
		llo mid=(l+r)/2;
		return max(query(no*2+1,l,mid,aa,bb),query(no*2+2,mid+1,r,aa,bb));		
	}
}
llo query2(llo no,llo l,llo r,llo ind){
	push(no,l,r);
	if(l==r){
		return tree[no];
	}
	else{
		llo mid=(l+r)/2;
		if(ind<=mid){
			return query2(no*2+1,l,mid,ind);
		}
		else{
			return query2(no*2+2,mid+1,r,ind);
		}
		//return max(query2(no*2+1,l,mid,aa,bb),query2(no*2+2,mid+1,r,aa,bb));		
	}
}
llo ans5;
vector<llo> cur;
void update3(llo no,llo l,llo r,llo aa,llo bb,llo val){
	push(no,l,r);
	if(tree4[no]+n>=val){
		return;
	}
	if(r<aa or l>bb){
		return;
	}
	if(l==r){
		ans5-=1;
		cur.pb(l);
	}
	else{
		llo mid=(l+r)/2;
		update3(no*2+1,l,mid,aa,bb,val);
		update3(no*2+2,mid+1,r,aa,bb,val);
	}
}






llo co[500010];
vector<pair<pair<llo,llo>,pair<llo,llo>>> qq3[500001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	ans5=n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	sort(it,it+n);
	for(llo i=0;i<n/2;i++){
		llo x=it[i];
		llo y=it[n-i-1];
		it[i]=y;
		it[n-i-1]=x;
	}

	vector<llo> qq2;
	vector<pair<pair<llo,llo>,pair<llo,llo>>> qq;
	build(0,0,n-1);
	build2(0,0,n-1);
	
	for(llo i=1;i<n;i++){
		if(query(0,0,n-1,0,i-1)>query2(0,0,n-1,i)+n){
			ans5-=1;
			update4(0,0,n-1,i,(llo)1e18);
		}
	}
	for(llo i=0;i<q;i++){
		char s;
		cin>>s;
		if(s=='Z'){
			cout<<ans5<<endl;
		//	qq2.pb(i+1);
		}
		else if(s=='B'){
			llo aa,bb;

			cin>>aa>>bb;
			llo x=find(0,0,n-1,aa);
			if(x==-1){
				continue;
			}
			update(0,0,n-1,0,x,bb);
			update2(0,0,n-1,0,x,bb);
			if(x==n-1){
				continue;
			}
			update3(0,0,n-1,x+1,n-1,query(0,0,n-1,0,x));
			for(auto j:cur){
				update4(0,0,n-1,j,(llo)1e18);
			}
			cur.clear();

		}
		else{
			llo aa,bb;
			cin>>aa>>bb;
			llo x=find2(0,0,n-1,aa);
			if(x==-1){
				continue;
			}
			update(0,0,n-1,x,n-1,-bb);
			update2(0,0,n-1,x,n-1,-bb);
			if(x==0){
				continue;
			}
			update3(0,0,n-1,x,n-1,query(0,0,n-1,0,x-1));
			for(auto j:cur){
				update4(0,0,n-1,j,(llo)1e18);
			}
			cur.clear();
		}
	} 
	/*for(auto j:qq){
		qq3[j.a.a].pb(j);
	}
	vector<llo> low;
	vector<llo> high;
	vector<llo> mid;
	vector<llo> ans;
	for(llo i=0;i<n;i++){
		low.pb(0);
		high.pb(q);
		mid.pb(0);
		ans.pb(0);
	}
	llo coo=0;
	llo ko=1;
	while(ko<=q){
		ko*=2;
		coo+=1;
	}
	llo pp=coo+1;*/
	/*for(llo i=0;i<pp;i++){
		//vector<pair<pair<llo,llo>,pair<llo,llo>>> qq3=qq;
		//build segtree 1,2
		build(0,0,n-1);
		build2(0,0,n-1);
		for(llo j=0;j<n;j++){
			mid[j]=(low[j]+high[j])/2;
			
			if(i==pp-1){
				ans[j]=low[j];
				qq3[high[j]].pb({{high[j],2},{j,-1}});
				continue;
			}
			qq3[mid[j]].pb({{mid[j],2},{j,-1}});
			//qq3.pb({{mid[j],2},{j,-1}});
		}
		//sort(qq3.begin(),qq3.end());
		for(llo ii=0;ii<=q;ii++){
			for(auto j:qq3[ii]){
				if(j.a.b==0){
					llo x=find(0,0,n-1,j.b.a);
				//	cout<<x<<"::"<<endl;
					if(x==-1){
						continue;
					}
					update(0,0,n-1,0,x,j.b.b);
				//	update2(0,0,n-1,0,x,j.b.b);
					//find max index using bin search seg tree logn
					//lazy update in both trees
				}
				else if(j.a.b==1){
					llo x=find2(0,0,n-1,j.b.a);
					if(x==-1){
						continue;
					}
					update(0,0,n-1,x,n-1,-j.b.b);
				//	update2(0,0,n-1,x,n-1,-j.b.b);
					//find min index using bin search seg tree logn
					//lazy update in both trees
				}
				else{
					llo st=0;
					if(j.b.a==0){
						st=1;
					}
					else{
						llo x=query(0,0,n-1,0,j.b.a-1);
						llo y=query2(0,0,n-1,j.b.a);
						
						if(y+n>=x){
							st=1;
						}
					}
					if(st==1){
						low[j.b.a]=mid[j.b.a];
						if(i==pp-1){
							ans[j.b.a]=max(ans[j.b.a],(llo)j.a.a);
						}
					}
					else{
						high[j.b.a]=mid[j.b.a];
					}
					//check if max(0,i-1) in segtree 2<=query(i)+n in segtree 1
					//update low,high,and if i=20 update answer as well
				}

			}
			while(qq3[ii].size()){
				if(qq3[ii].back().a.b==2){
					qq3[ii].pop_back();
				}
				else{
					break;
				}
			}
		}
	}
	for(llo j=0;j<n;j++){
		co[ans[j]+1]+=1;
	//	cout<<ans[j]<<",";
	}
	//cout<<endl;
	llo ans2=n;
	llo prev=0;
	for(auto j:qq2){
		for(llo i=prev;i<=j;i++){
			ans2-=co[i];
		}
		prev=j+1;
		cout<<ans2<<endl;
	}
*/

	//update index answer using prefix sums
	//answer queries

	return 0;
}