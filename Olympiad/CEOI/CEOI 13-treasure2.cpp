
/*
querying for all (1,1,i,j) submaatrices gets 50ish points(find solution using inclusion-exclusion/logic)

instead query for the biggest among (1,1,i,j),(i+1,j+1,n,n) and the other 2
gets 100

*/
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int pre[101][101];
int ans[101][101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;

	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(i<=n/2){
				if(j<=n/2){
					cout<<i+1<<" "<<j+1<<" "<<n<<" "<<n<<endl;
					cin>>pre[i][j];
					continue;
				}
				cout<<i+1<<" 1 "<<n<<" "<<j<<endl;
				cin>>pre[i][j];
			}
			else{
				if(j<=n/2){// and i!=n){
					cout<<1<<" "<<j+1<<" "<<i<<" "<<n<<endl;
					cin>>pre[i][j];
					continue;
				}
				cout<<"1 1 "<<i<<" "<<j<<endl;
				cin>>pre[i][j];
			}
		}
	}
	for(int i=1;i<n+1;i++){
		if(i<=n/2){
			pre[n][i]=pre[n][n]-pre[n][i];
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(i<=n/2){
				if(j>n/2){
					pre[i][j]=pre[n][j]-pre[i][j];
				}
			}
		}
	}
				/*else if(j<=n/2){
				
			}*/

	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(i<=n/2){
				
			}
			else if(j<=n/2 and i!=n){
		//		cout<<i<<":"<<j<<":"<<pre[i][n]<<":"<<pre[i][j]<<endl;
				pre[i][j]=pre[i][n]-pre[i][j];
			}

		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(i<=n/2){
				if(j<=n/2){
					pre[i][j]=pre[i][n]+pre[n][j]-(pre[n][n]-pre[i][j]);
				}
			}

		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<pre[i][j];
		}
		cout<<endl;
	}*/

	/*for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			cout<<pre[i][j];
		}
		cout<<endl;
	}*/
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			ans[i][j]=pre[i][j]-(pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]);
		}
	}
	cout<<"END"<<endl;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}






	return 0;
}