//#pragma GCC optimize("Ofast,unroll-loops")
/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/Baltic/official/boi2010_solutions/candies-sol.pdf
only difference is that I am using bitsets for knapsack


*/

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n;
int it[101];
const int kk=7000*100+10;
const int mo=7000*100*3+10;
bitset<kk> dp[101];
bitset<mo> can;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	sort(it,it+n);
	for(int i=0;i<n;i++){
		dp[i].set(0);
	}
//	cout<<dp[0]<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				continue;
			}
			dp[j]|=(dp[j]<<it[i]);
		}
	}
	int mi=-1;
	int ind=-1;
	for(int i=0;i<n;i++){
		//cout<<dp[i]<<endl;
		int x=dp[i].count()-1;
		if(x>mi){
			mi=x;
			ind=i;
		}
	}
	
	vector<int> mm;
	for(int i=0;i<kk;i++){
		if(dp[ind].test(i)){
			mm.pb(i);
		}
	}
	can.set(kk);
	int xo=kk;
	for(int i=0;i<n;i++){
		int j=it[i];
		if(i==ind){
			continue;
		}
	//	cout<<j<<endl;

	//	for(int i=-14;i<14;i++){
	//		cout<<can[kk+i];
		//}
	//	cout<<endl;
		can|=(can<<(j));

		can|=(can>>(j));
		
	
	}


	cout<<it[ind]<<" ";
	for(int i=0;i<kk;i++){
		if(can.test(i+kk)){
		}
		else{
			cout<<i<<endl;
			return 0;
		}
	}



























	return 0;
}