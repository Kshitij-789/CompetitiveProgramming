
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int it[500001];
int n;
int pre[500001];
int val[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	int po=0;
	for(int i=0;i<n;i++){
		cin>>it[i];
		po+=it[i];
		pre[i+1]=it[i]+pre[i];
	}
	/*if(n%2==0){
		while(true){
			continue;
		}
	}
*/
	int kk=0;
	for(int i=0;i<n;i++){
		int j=(i-((n-1)/2)+n)%n;
		if(i<j){
			val[i]=pre[i+1]+pre[n]-pre[j];
		}
		else{
			val[i]=pre[i+1]-pre[j];
		}
		val[n+i]=val[i];
	//	cout<<val[i]<<",";
	}
	//cout<<endl;
	multiset<int> cur;
	for(int i=0;i<2*n;i++){
		if(i>=(n+1)/2){
			auto j=cur.find(val[i-(n+1)/2]);
			cur.erase(j);
		}
		cur.insert(val[i]);
		if(i>=(n+1)/2-1){
			kk=max(kk,*(cur.begin()));
		}
	}
	cout<<kk<<endl;
	return 0;






	int stt=n;
	if(n>5000){
		stt=1;
	}
/*
	for(int i=0;i<stt;i++){
	//for(auto i:mm){

		if(i>=n){
			continue;
		}
		
		int ans=0;
		for(int j=i+1;j<n;j++){
			int kk=(j-i-1);
			int su=it[i];
			su+=pre[i+kk/2+1]-pre[i+1];
			int tt=0;
			if(kk%2==1){
				tt=max(tt,it[i+kk/2+1]);
			}

			kk=i+n-j-1;
			int ii=(i-kk/2+n)%n;
			if(ii>i){
				su+=pre[i]+pre[n]-pre[ii];
			}
			else{
				su+=pre[i]-pre[ii];
			}

			if(kk%2==1){
				tt=max(tt,it[(i-(kk)/2-1+n+n)%n]);
			}
			su+=tt;
			if(ans==0){
				ans=su;
			}
	//		cout<<i<<","<<j<<","<<su<<endl;
			ans=min(ans,su);
		}
		for(int j=0;j<i;j++){
			int kk=(i-j-1);
			int su=it[i];
			su+=pre[i]-pre[i-kk/2];
			int tt=0;
			if(kk%2==1){
				tt=max(tt,it[(i-kk/2-1+n+n)%n]);
			}
			kk=j+n-i-1;
			if(kk%2==1){
				tt=max(tt,it[(i+kk/2+1+n+n)%n]);
			}
			int ii=(i+kk/2)%n;
			if(ii<i){
				su+=pre[n]-pre[i+1];
				su+=pre[ii+1];
			}
			else{
				su+=pre[ii+1]-pre[i+1];
			}
			su+=tt;
			if(ans==0){
				ans=su;
			}
	//		cout<<i<<","<<j<<","<<su<<endl;
			ans=min(ans,su);
		}
		kk=max(kk,ans);
	}
	cout<<kk<<endl;


*/




	return 0;
}