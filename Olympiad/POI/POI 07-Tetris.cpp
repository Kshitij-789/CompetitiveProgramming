#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n;
//vector<int> ind[50001];
/*int tree[500001];
void u(int i,int j){
	while(i<500001){
		tree[i]+=j;
		i+=(i&-i);
	}
}
int s(int i){
	int tot=0;
	while(i>0){
		tot+=tree[i];
		i-=(i&-i);
	}
	return tot; 
}*/
int vis[100001];

vector<int> bb;
/*void eval(int i){
	if(i<0 or i>=2*n-1){
		return;
	}
	if(ind[bb[i]][0]<=ind[bb[i+1]][0] and ind[bb[i+1]][0]<=ind[bb[i]][1] and ind[bb[i]][1]<=ind[bb[i+1]][1]){
		if(ind[bb[i]][0]+1==ind[bb[i+1]][0] and ind[bb[i]][1]+1==ind[bb[i+1]][1]){
			if(ind[bb[i]][0]!=i){
				continue;
			}
		}		cur.insert(i);
	}
}*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	
	vector<int> ans;
	for(int i=0;i<2*n;i++){
		int aa;
		//u(i+1,1);
		cin>>aa;
	//	ind[aa].pb(i);
	//	bb.pb(aa);
		if(vis[aa]==1){
			vector<int> ss;
			while(bb.size()){
				if(bb.back()==aa){
					bb.pop_back();
					break;
				}
				ans.pb(bb.size());
				ss.pb(bb.back());
				bb.pop_back();
			}
			reverse(ss.begin(),ss.end());
			for(auto j:ss){
				bb.pb(j);
			}
		}
		else{
			bb.pb(aa);
		}
		vis[aa]=1;
		/*for(auto j:bb){
			cout<<j<<",";
		}
		cout<<endl;*/
		//ind[aa-1].pb(i);
	}
	cout<<ans.size()<<endl;
	
/*
	for(int i=0;i<2*n-1;i++){
		eval(i);
		if(ind[bb[i]][0]<=ind[bb[i+1]][0] and ind[bb[i+1]][0]<=ind[bb[i]][1] and ind[bb[i]][1]<=ind[bb[i+1]][1]){
			if(ind[bb[i]][0]+1==ind[bb[i+1]][0] and ind[bb[i]][1]+1==ind[bb[i+1]][1]){
				if(ind[bb[i]][0]!=i){
					continue;
				}
			}
			cur.insert(i);
		}
	}
	while(cur.size()){
		int x=cur.begin();
		cur.pop();
		swap()

	}*/
	for(auto j:ans){
		cout<<j<<endl;
	}



	return 0;
}