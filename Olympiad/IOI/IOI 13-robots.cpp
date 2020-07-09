
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
#include "robots.h"


vector<pair<pair<int,int>,int>> cc;
vector<pair<int,int>> dd;
int t;
int aa,bb;
int it[1000001];
int it2[1000001];
int vis[1000001];
int check(int mid){
	priority_queue<pair<int,int>> cur;
	int ind=-1;
	for(int i=0;i<t;i++){
		vis[i]=0;
	}
	for(int i=0;i<aa;i++){
		while(ind+1<t){
			if(cc[ind+1].a.a<it[i]){
				ind+=1;
				cur.push({cc[ind].a.b,cc[ind].b});
			}
			else{
				break;
			}
		}
		int cot=0;
		for(int i=0;i<mid;i++){
			if(cur.size()==0){
				break;
			}
			pair<int,int> ac=cur.top();
		//	cur.erase(cur.begin());
			cur.pop();
			vis[ac.b]=1;
			cot++;
		}
	}
	ind=-1;
	while(ind+1<t){
		if(vis[ind+1]){
			ind++;
			continue;
		}
		break;
	}

//	cur.clear();
	for(int i=0;i<bb;i++){
		int cot=0;
		while(ind+1<t){
			if(vis[ind+1]){
				ind++;
				continue;
			}
			if(cot==mid){
				break;
			}
			if(dd[ind+1].a<it2[i]){
				cot++;
				ind++;
			}
			else{
				break;
			}
		}
	}
	if(ind<t-1){
		return false;
	}
	return true;
}
int putaway(int aaa, int bbb, int tt, int x[], int y[], int w[], int s[]) {
	t=tt;
	aa=aaa;
	bb=bbb;

	int low=1;
	int high=t;

	for(int i=0;i<t;i++){
		dd.pb({s[i],w[i]});
	}
	sort(dd.begin(),dd.end());
	for(int i=0;i<t;i++){
		cc.pb({{dd[i].b,dd[i].a},i});
	}
	sort(cc.begin(),cc.end());


	sort(x,x+aa);
	sort(y,y+bb);

	for(int i=0;i<aa;i++){
		it[i]=x[i];
	}
	for(int i=0;i<bb;i++){
		it2[i]=y[i];
	}
	if(check(t)==false){
		return -1;
	}
	
	while(low<high-1){
		int mid=(low+high)/2;
		if(check(mid)){
			high=mid;
		}
		else{
			low=mid;
		}
	}
	int ans=high;
	if(check(low)){
		ans=min(ans,low);
	}
	return ans;
}


/*int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ac,bc,tc;
	cin>>ac>>bc>>tc;
	int xx[ac];
	int yy[bc];
	for(int i=0;i<ac;i++){
		cin>>xx[i];
	}
	for(int j=0;j<bc;j++){
		cin>>yy[j];
	}
	int kk[tc];
	int mm[tc];
	for(int j=0;j<tc;j++){
		cin>>kk[j]>>mm[j];
	}
	cout<<putaway(ac,bc,tc,xx,yy,kk,mm)<<endl;



	return 0;
}*/
/*
3 2 10
6 2 9
4 7
4 6
8 5
2 3
7 9
1 8
5 1
3 3
8 7
7 6
10 5
*/
/*
2 1 3
2 5
2
3 1
5 3
2 2
*/