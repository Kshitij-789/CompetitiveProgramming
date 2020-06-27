#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n;
int aa[5001];
int bb[5001];
int dist[50001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>aa[i];
		bb[i]=aa[i];
		
	}
	for(int i=1;i<n;i++){
		bb[i]%=aa[0];
	}
	for(int i=0;i<aa[0];i++){
		dist[i]=1e9+1;
	}
	dist[0]=0;
	priority_queue<pair<int,int>> ss;
	ss.push({-aa[0],0});
	while(ss.size()){
		pair<int,int> no=ss.top();
		ss.pop();
		no.a=-no.a;
	/*	if(no.a>dist[no.b]){
			continue;
		}*/
		for(int i=1;i<n;i++){
			int x=no.b+bb[i];
			if(x>=aa[0]){
				x-=aa[0];
			}
			if(dist[x]>dist[no.b]+aa[i]){
				dist[x]=dist[no.b]+aa[i];
				ss.push({-dist[x],x});
			}
		}
	}
	int m;
	cin>>m;
	int x;
	while(m--){
		
		cin>>x;
		//cout<<x%aa[0]<<":"<<endl;
		/*if(dist[x%aa[0]]==-1){
			cout<<"NIE"<<endl;
			continue;
		}*/
		if(dist[x%aa[0]]<=x){
			cout<<"TAK"<<endl;
		}
		else{
			cout<<"NIE"<<endl;
		}
	}



	
	return 0;
}

