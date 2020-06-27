#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n;
int freq[16][26];
int dp[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		for(int j=0;j<t.size();j++){
			freq[i][t[j]-'a']++;
		}
		dp[(1<<i)]=t.size();
	}
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)==1){
			continue;
		}
		dp[i]=1e6;
		int co[26];
		for(int j=0;j<26;j++){
			co[j]=1000000;
		}
		for(int j=0;j<n;j++){
			if((1<<j)&i){
				for(int k=0;k<26;k++){
					co[k]=min(co[k],freq[j][k]);
				}
			}
		}
		int su=0;
		for(int j=0;j<26;j++){
			su+=co[j];
		}
		for(int j=i;j>0;j=(j-1)&i){
			if(j==i){
				continue;
			}
			dp[i]=min(dp[i],dp[j]+dp[i-j]-su);
		}
	}
	cout<<dp[(1<<n)-1]+1<<endl;






	
	return 0;
}

