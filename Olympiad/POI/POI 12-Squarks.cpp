/*
https://github.com/thecodingwizard/competitive-programming/blob/master/POI/POI12-Squarks.cpp
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<int> aa;
	for(int i=0;i<(n*(n-1))/2;i++){
		int bb;
		cin>>bb;
		aa.pb(bb);
	}
	sort(aa.begin(),aa.end());
	int co=0;
	vector<vector<int>> ans;
	for(int i=2;i<n;i++){
		int bb=aa[0];
		int cc=aa[1];
		int dd=aa[i];
		int ss=bb+cc+dd;
		if(i>2){
			if(aa[i]==aa[i-1]){
				continue;
			}
		}
		if(ss%2==1){
			continue;
		}
		ss/=2;
		vector<int> cur;
		cur={ss-aa[i],ss-aa[1],ss-aa[0]};
		int st=1;
		for(auto j:cur){
			if(j<=0){
				st=0;
			}
		}
		if(st==0){
			continue;
		}
	//	cout<<i<<endl;
		multiset<int> tot;
		for(int j=2;j<aa.size();j++){
			if(j==i){
				continue;
			}
			tot.insert(aa[j]);
		}
	/*	for(auto j:tot){
			cout<<j<<",";
		}
		cout<<endl;*/
		for(int j=3;j<n;j++){
			int x=*(tot.begin());
			for(auto jj:cur){
				auto kk=tot.find(x-cur[0]+jj);
				if(kk==tot.end()){
					st=0;
					break;
				}
				tot.erase(kk);
			}
			if(x-cur[0]<=cur.back()){
				st=0;
				break;
			}
			cur.pb(x-cur[0]);
		}
		/*for(auto j:cur){
			cout<<j<<" ";
		}
		cout<<endl;*/
		if(st==0){
			continue;
		}
		ans.pb(cur);
	}

	cout<<ans.size()<<endl;
	for(auto j:ans){
		for(auto i:j){
			cout<<i<<" ";
		}
		cout<<endl;
	}






	return 0;
}
/*
8 2 12
1 2 4 2 1 3 5 6 2 3 6 4
*/
