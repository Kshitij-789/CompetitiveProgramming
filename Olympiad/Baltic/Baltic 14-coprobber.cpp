#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#include "coprobber.h"

#define MAX_N 500

//#include "coprobber.h"
vector<int> adj[500*500*2];
vector<int> adj2[500*500*2];
int vis[500*500*2];
int back[500*500*2];

int co[500*500*2];
//i*j+n*n*k,k=0 if police,i police turn,j robber
int cur=0;
int n;
int start(int nn, bool aa[MAX_N][MAX_N]){
	n=nn;

	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adj[i*n+j].pb(n*n+i*n+j);
			adj2[n*n+i*n+j].pb(i*n+j);
			for(int k=0;k<n;k++){
				if(aa[i][k]){
					adj[i*n+j].pb(k*n+j+n*n);
					adj2[k*n+j+n*n].pb(i*n+j);
				}
			}
		}
	}*/
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){			
			for(int k=0;k<n;k++){
				if(aa[j][k]){
					co[i*n+j+n*n]+=1;
					/*adj[i*n+j+n*n].pb(i*n+k);
					adj2[i*n+k].pb(i*n+j+n*n);*/
				}
			}
		}
	}
	queue<int> ss;
	for(int i=0;i<n;i++){
		vis[i*n+i]=1;
		ss.push(i*n+i);
		vis[n*n+i*n+i]=1;
		ss.push(n*n+i*n+i);
	}
	while(ss.size()){
		int no=ss.front();
		ss.pop();
		if(no<n*n){
			int i=no/n;
			int j=no%n;
			for(int k=0;k<n;k++){
				if(aa[j][k]){
					if(vis[i*n+k+n*n]==0){
						co[i*n+k+n*n]-=1;
						if(co[i*n+k+n*n]==0){
							vis[i*n+k+n*n]=1;
							ss.push(i*n+k+n*n);
						}
					}
				}
			}
		}
		else{
			int i=no/n-n;
			int j=no%n;
			for(int k=0;k<n;k++){
				if(aa[i][k]){
					if(vis[k*n+j]==0){
						vis[k*n+j]=1;
						ss.push(k*n+j);
						back[k*n+j]=no;
					}
				}
			}
			int kk=no-n*n;
			if(vis[kk]==0){
				vis[kk]=1;
				back[kk]=no;
				ss.push(kk);
			}

		}
	}



	for(int i=0;i<n;i++){
		int st=1;
		for(int j=0;j<n;j++){
			if(vis[i*n+j]==0){
				st=0;
			}
		}
		if(st){
			cur=i;
		//	cout<<i<<endl;
			return i;
		}
	}
	return -1;
}

int nextMove(int rr){
//	cout<<back[cur*n+rr]<<endl;
	cur=back[cur*n+rr]/n-n;

    return cur;
}

/*
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	return 0;
}*/

/*
g++  -o aa -O2 aa.cpp grader.cpp -std=c++14
*/
