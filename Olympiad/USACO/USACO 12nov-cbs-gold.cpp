#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
llo n,k;
llo pre[10][50001];
llo ne[10][50001];
//vector<pair<pair<llo,llo>,llo>> cur[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("cbs");
	cin>>k>>n;
	for(llo i=0;i<k;i++){
		string s;
		cin>>s;
		for(llo j=0;j<n;j++){
			pre[i][j+1]=pre[i][j];
			if(s[j]=='('){
				pre[i][j+1]+=1;
			}
			else{
				pre[i][j+1]-=1;
			}
		}
		vector<pair<llo,llo>> ac;
		for(llo j=n;j>=0;j--){
			while(ac.size()){
				if(ac.back().a>=pre[i][j]){
					ac.pop_back();
				}
				else{
					break;
				}
			}
			if(ac.size()){
				ne[i][j]=ac.back().b;
			}
			else{
				ne[i][j]=n+1;
			}
		//	cout<<i<<","<<j<<","<<ne[i][j]<<endl;
			ac.pb({pre[i][j],j});
		}
	}
	map<vector<llo>,vector<llo>> tt;
	llo ans2=0;
	for(llo j=n;j>=0;j--){
		llo prev=n+1;

		vector<llo> kk;
		for(llo i=0;i<k;i++){
			kk.pb(pre[i][j]);
			prev=min(prev,ne[i][j]);
		}
	//	cout<<j<<":"<<prev<<endl;


		if(tt.find(kk)!=tt.end()){
	//		cout<<j<<endl;
/*			for(auto j:tt[kk]){
				if(j<prev){
					ans2+=1;
				}
			}*/
			if(tt[kk].back()<prev){
				llo low=0;
				llo high=(llo)(tt[kk].size())-1;

				llo ans=0;
				while(low<high-1){
					llo mid=(low+high)/2;
					if(tt[kk][mid]<prev){
						high=mid;
					}
					else{
						low=mid+1;
					}
				}
				ans=tt[kk].size()-high;
				if(tt[kk][low]<prev){
					ans=max(ans,(llo)(tt[kk].size())-low);
				}

				ans2+=ans;
			}

			tt[kk].pb(j);

		}
		else{
			tt[kk]={j};
		}

		
		
	}
	cout<<ans2<<endl;




	return 0;
}