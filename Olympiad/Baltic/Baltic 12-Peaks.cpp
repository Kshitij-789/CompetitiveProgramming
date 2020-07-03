#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n,m;
int it[2001][2001];
int par[100001];
int find(int no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int ma[100001];
int mi[100001];

vector<int> x={-1,-1,-1,0,0,1,1,1};
vector<int> y={-1,0,1,1,-1,1,-1,0};

int back[100001];
int ma2[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>it[i][j];
			par[i*m+j]=i*m+j;
			ma[i*m+j]=it[i][j];
		}
	}
	vector<pair<int,pair<int,int>>> ed;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<8;k++){
				int ii=i+x[k];
				int jj=j+y[k];
				
				if(ii<0 or jj<0 or ii>=n or jj>=m){
					continue;
				}
				ed.pb({min(it[i][j],it[ii][jj]),{i*m+j,ii*m+jj}});
				int x=find(i*m+j);
				int y=find(ii*m+jj);
				if(it[x/m][x%m]==it[y/m][y%m]){
					par[x]=y;
					ma[y]=max(ma[y],ma[x]);
		//			cout<<x<<","<<y<<endl;
				}
				ma[x]=max(ma[x],it[ii][jj]);
				ma[y]=max(it[i][j],ma[y]);
			}
		}
	}
	sort(ed.begin(),ed.end());
	reverse(ed.begin(),ed.end());
	int q=0;
	vector<int> ac;
	vector<int> low;
	vector<int> high;
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ma[find(i*m+j)]<<endl;
		}
		cout<<endl;
	}*/
	for(int i=0;i<n*m;i++){
		back[i]=find(i);
		ma2[i]=it[i/m][i%m];
		if(find(i)==i){
	//		cout<<i/m<<",,"<<i%m<<endl;
			if(ma[i]<=it[i/m][i%m]){
				low.pb(0);
				high.pb(1e6);
				ac.pb(i);
				q+=1;
			}
		}
	}
	vector<int> ans;
	/*for(auto j:ed){
		cout<<j.a<<","<<j.b.a<<","<<j.b.b<<endl;
	}*/
	for(int i=0;i<23;i++){
		vector<pair<int,int>> cur;
		for(int j=0;j<q;j++){
			if(i==22){
				ans.pb(high[j]);
				cur.pb({low[j],j});
				continue;
			}
			cur.pb({(low[j]+high[j])/2,j});
		}
		sort(cur.begin(),cur.end());
		reverse(cur.begin(),cur.end());
		int ind=0;
		for(int j=0;j<n*m;j++){
			par[j]=back[j];
			ma[j]=it[j/m][j%m];
		}
		for(auto j:ed){
			while(ind<cur.size()){
				if(cur[ind].a>j.a){
					if(ma[find(ac[cur[ind].b])]>ma2[ac[cur[ind].b]]){
						if(i==22){
							ans[cur[ind].b]=min(ans[cur[ind].b],cur[ind].a);
						}
						else{
							low[cur[ind].b]=cur[ind].a;
						}
					}
					else{
						high[cur[ind].b]=cur[ind].a;
					}
					ind+=1;
				}
				else{
					break;
				}
			}
			int x=find(j.b.a);
			int y=find(j.b.b);
			par[x]=y;
			ma[y]=max(ma[y],ma[x]);

		}
		while(ind<cur.size()){
			if(ma[find(ac[cur[ind].b])]>ma2[ac[cur[ind].b]]){
				if(i==22){
					ans[cur[ind].b]=min(ans[cur[ind].b],cur[ind].a);
				}
				else{
					low[cur[ind].b]=cur[ind].a;
				}
			}
			else{
				high[cur[ind].b]=cur[ind].a;
			}
			ind+=1;
		}





	}
	vector<pair<int,int>> ans2;
	for(int i=0;i<q;i++){
		ans2.pb({ma2[ac[i]],ans[i]});
	}
	sort(ans2.begin(),ans2.end());
	reverse(ans2.begin(),ans2.end());
	cout<<ans2.size()<<endl;
	for(auto j:ans2){
		cout<<j.a<<" "<<j.b<<endl;
	}




	return 0;
}