/*
my solution was same as https://github.com/dolphingarlic/CompetitiveProgramming/blob/master/Baltic/Baltic%2006-coins.cpp
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
llo n,k;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	llo su=0;
	llo cot=0;
	vector<pair<llo,llo>> cc;
	for(llo i=0;i<n;i++){
		llo aa,bb;
		cin>>aa>>bb;
		cc.pb({aa,bb});
	}
	for(llo i=0;i<n;i++){
		if(cc[i].b==1){
			continue;
		}
		if(i<n-1){
			if(su+cc[i].a>=cc[i+1].a){
				continue;
			}
		}
		if(su+cc[i].a>=k){
			break;
		}
		su+=cc[i].a;
		cot+=1;
		//cout<<su<<":"<<cot<<endl;
	}
	if(su==0){
		cout<<0<<endl;
		cout<<k-1<<endl;
		return 0;
	}
	cout<<cot<<endl;
	cout<<k-su<<endl;



	return 0;
}
/*
8 2 12
1 2 4 2 1 3 5 6 2 3 6 4
*/
