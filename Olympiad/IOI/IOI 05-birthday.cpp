/*
https://www.oi.edu.pl/old/ioi/downloads/ioi2005-tasks-and-solutions-a5.pdf
*/
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n;
int it[1000001];
/*//increasing distance
vector<pair<int,int>> a1[1000001];
vector<int> b1[1000001];

//decreasing distance
vector<int> a2[1000001];
vector<int> b2[1000001];*/
int vis[2000001];
int solve(){




}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
		vis[(i-it[i]+n)%n]=1;
		vis[((i-it[i]+n)%n)+n]=1;
	}
	int ma=0;
	int cur=0;
	for(int i=0;i<2*n;i++){
		if(vis[i]==0){
			cur+=1;
		}
		else{
			cur=0;
		}
		ma=max(ma,cur);
	}
	for(int i=0;i<2*n;i++){
		vis[i]=0;
	}
	for(int i=0;i<n/2;i++){
		swap(it[i],it[n-i-1]);
	}
	for(int i=0;i<n;i++){
		vis[(i-it[i]+n)%n]=1;
		vis[((i-it[i]+n)%n)+n]=1;
	}
	cur=0;
	for(int i=0;i<2*n;i++){
		if(vis[i]==0){
			cur+=1;
		}
		else{
			cur=0;
		}
		ma=max(ma,cur);
	}

	cout<<(n-ma)/2<<endl;
	return 0;
}