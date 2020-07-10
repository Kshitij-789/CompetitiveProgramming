
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
llo n;
llo s;
llo aa[10001];
llo bb[10001];
llo pre[10001];
llo pre2[10001];
llo dp[10001];
vector<pair<llo,llo>> cur;
llo ind=0;
void insert(llo m,llo b){
	while(cur.size()>=2){
		//check aa/bb<cc/dd
		llo aa=b-cur.back().b;
		llo bb=cur.back().a-m;
		llo cc=cur[cur.size()-2].b-cur.back().b;
		llo dd=cur.back().a-cur[cur.size()-2].a;
		if(bb<0){
			bb=-bb;
			aa=-aa;
		}
		if(dd<0){
			dd=-dd;
			cc=-cc;
		}
		/*b-cur.back().b;
		cur.back().a-m;
		
		cur[cur.size()-2].b-cur.back().b;
		cur.back().a-cur[cur.size()-2].a;
		*/

		if(aa*dd<bb*cc){
			cur.pop_back();
		}
		else{
			break;
		}

	}
	cur.pb({m,b});
}
llo query(llo x){
	if(ind==cur.size()-1){
		return cur[ind].a*x+cur[ind].b;
	}
	while(ind<cur.size()-1){
		if(cur[ind].a*x+cur[ind].b>cur[ind+1].a*x+cur[ind+1].b){
			ind+=1;
		}
		else{
			break;
		}
	}
	return cur[ind].a*x+cur[ind].b;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	cin>>s;
	for(llo i=0;i<n;i++){
		cin>>aa[i]>>bb[i];
		pre[i+1]=pre[i]+aa[i];
	}
	pre2[n]=bb[n-1];
	for(llo i=n-2;i>=0;i--){
		pre2[i+1]=pre2[i+2]+bb[i];
	}
	for(llo i=0;i<n;i++){
		dp[i]=(s+pre[i+1])*pre2[1];
		if(i>0){
			dp[i]=min(dp[i],query(pre[i+1]));
		}
		if(i<n-1){
			insert(pre2[i+2],dp[i]+s*(pre2[i+2])-(pre[i+1]*pre2[i+2]));
		}
	//	cout<<dp[i]<<",";
	}
	cout<<dp[n-1];
	cout<<endl;






	return 0;
}