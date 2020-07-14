#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
llo n,m;
llo it[2001][2001];

llo par[2001];
llo ss[2001];
llo find(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
llo ne[2001];
vector<llo> pre[2001];
llo co[2001];
llo vis[2001];
llo su=0;
void merge(llo aa,llo bb){
//	cout<<aa<<"::"<<bb<<endl;
	llo x=find(aa);
	llo y=find(bb);
	if(x==y){
		return ;
	}
	if(vis[x]){
		su-=co[ss[x]];
	}
	if(vis[y]){
		su-=co[ss[y]];
	}
	vis[x]=1;
	vis[y]=1;
	par[x]=y;
	ss[y]+=ss[x];
	su+=co[ss[y]];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<m;j++){
			char s;
			cin>>s;
			if(s=='#'){
				it[i][j]=0;
			}
			else{
				it[i][j]=1;
			}
		}
	}
	co[1]=1;
	for(llo i=2;i<=n;i++){
		co[i]=co[i-1]+(i*(i+1))/2;
	}
	llo ans=0;
	for(llo i=0;i<m;i++){
		su=0;
		for(llo j=0;j<=m;j++){
			pre[j].clear();
		}
		for(llo j=0;j<n;j++){
			ss[j]=1;
			vis[j]=0;
			par[j]=j;
			if(it[j][i]==0){
				ne[j]=0;
			}
			else{
				ne[j]=ne[j]+1;
			}
			pre[ne[j]].pb(j);
		}
		//cout<<i<<endl;
		for(llo j=m;j>=0;j--){
			for(auto k:pre[j]){
		//		cout<<j<<":"<<k<<endl;
				if(k>0){
					if(ne[k-1]>=ne[k]){
						merge(k-1,k);
					}
				}
				if(k<n-1){
					if(ne[k+1]>=ne[k]){
						merge(k,k+1);
					}
				}
				if(vis[k]==0){
					vis[k]=1;
					su+=1;
				}

			}
			

			ans+=j*su;
		}

	}
	cout<<ans<<endl;






	return 0;
}

