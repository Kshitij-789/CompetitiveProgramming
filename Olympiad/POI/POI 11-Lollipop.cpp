#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int n,m;
int pre[1000001];
pair<int,int> ans[2000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='T'){
			pre[i+1]=pre[i]+2;
		}
		else if(s[i]=='W'){
			pre[i+1]=pre[i]+1;
		}
	}
	/*for(int i=0;i<=2*n;i++){
		ans[i]={-1,-1};
	}*/
	int ma=0;
	int ind=-1;
	pair<int,int> cur[2];
	cur[0]={-1,-1};
	cur[1]={-1,-1};
	for(int i=0;i<n;i++){
		if(s[i]=='W'){
			ind=i;
			ma=pre[n]-pre[i];
			for(int j=i;j<n;j++){
				int su=pre[j+1]-pre[i];
				if(su>cur[su%2].a){
					cur[su%2]={su,j};
				}
				ans[su]={ind,j};
			}
			for(int j=i+1;j<n;j++){
				int su=pre[j+1]-pre[i+1];
				ans[su]={ind+1,j};
			}
			break;
		}
	}

	for(int i=0;i<m;i++){
		int aa;
		cin>>aa;
		if(ind==-1){
			if(aa%2==0 and aa/2<=n){
				cout<<"1"<<" "<<aa/2<<endl;
			}
			else{
				cout<<"NIE"<<endl;
			}
		}
		else{
			if(aa<=ma){
				cout<<ans[aa].a+1<<" "<<ans[aa].b+1<<endl;
			}
			else{
				if(aa%2==0){
					if(cur[0].a==-1){
						cout<<"NIE"<<endl;
					}
					else{
						if((aa-cur[0].a)/2>ind){
							cout<<"NIE"<<endl;
						}
						else{
							cout<<ind-(aa-cur[0].a)/2+1<<" "<<cur[0].b+1<<endl;
						}
					}
				}
				else{
					if(cur[1].a==-1){
						cout<<"NIE"<<endl;
					}
					else{
						if((aa-cur[1].a)/2>ind){
							cout<<"NIE"<<endl;
						}
						else{
							cout<<ind-(aa-cur[1].a)/2+1<<" "<<cur[1].b+1<<endl;
						}
					}
				}
			}

		}
	}



	




	return 0;
}