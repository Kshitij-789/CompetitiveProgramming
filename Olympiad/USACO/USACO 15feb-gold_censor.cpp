/*
store hashes of suffixes of the n strings in a map with value 0 if length of suffix=length of that particulat string
iterate from i from 1 to n
binary search for longest suffix ending at i.check with hash values

update the hashes also when deleting suffix
details in code



*/
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
llo mod=1e9+7;
llo pre[100001];
llo e(llo aa,llo bb){
	if(bb==0){
		return 1;
	}
	llo ans=e(aa,bb/2);
	ans*=ans;
	ans%=mod;
	if(bb%2==1){
		ans*=aa;
		ans%=mod;
	}
	return ans;
}
llo pre2[100001];
map<llo,llo> x;
//llo indd[100001];
vector<llo> pre4;
llo sub(llo aa,llo bb){
	return ((pre4[bb+1]-pre4[aa]+mod)*(pre2[aa]))%mod;
}
llo mod2=1e9+9;
llo pre7[100001];

llo e2(llo aa,llo bb){
	if(bb==0){
		return 1;
	}
	llo ans=e2(aa,bb/2);
	ans*=ans;
	ans%=mod2;
	if(bb%2==1){
		ans*=aa;
		ans%=mod2;
	}
	return ans;
}
llo pre8[100001];
map<llo,llo> y;
//llo pre3[100001];
llo indd[100001];
vector<llo> pre9;
llo sub2(llo aa,llo bb){
	return ((pre9[bb+1]-pre9[aa]+mod2)*(pre8[aa]))%mod2;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO("censor");
	mt19937 rng;
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());

	pre4.pb(0);
	llo pp=((rng())%(mod-30))+30;//137;//1e7+20;
	pre[0]=1;
	for(llo i=1;i<100001;i++){
		pre[i]=(pre[i-1]*pp)%mod;
	}
	for(llo i=0;i<100001;i++){
		pre2[i]=e(pre[i],mod-2);
	}
	pre9.pb(0);
	llo pe=(rng()%(mod2-30))+30;//1e8+1000;
	pre7[0]=1;
	for(llo i=1;i<100001;i++){
		pre7[i]=(pre7[i-1]*pe)%mod2;
	}
	for(llo i=0;i<100001;i++){
		pre8[i]=e2(pre7[i],mod2-2);
	}


	string s;
	cin>>s;
	n=s.size();
	string ans="";
	llo m;
	cin>>m;
	for(llo i=0;i<m;i++){
		string t;
		cin>>t;
		llo nn=t.size();
		llo su=0;
		for(llo j=nn-1;j>=0;j--){
			su+=(t[j]-'a'+1)*pre[j];
			su%=mod;
			llo tu=su*pre2[j];
			tu%=mod;
			/*su*=pre2[j];
			su%=mod;
*/
			if(j==0){
				x[tu]=0;
			}
			else{
				x[tu]=1;
			}
	//		cout<<su<<endl;
			
		}
		su=0;
		for(llo j=nn-1;j>=0;j--){
			su+=(t[j]-'a'+1)*pre7[j];
			su%=mod2;
			llo tu=su*pre8[j];
			tu%=mod2;
			/*su*=pre8[j];
			su%=mod2;
*/
			if(j==0){
				y[tu]=0;
			}
			else{
				y[tu]=1;
			}
	//		cout<<su<<endl;
			
		}
	}
	llo i=0;
	vector<llo> cur;

	while(i<n){
		indd[i]=cur.size();
		pre4.pb((pre4.back()+pre[cur.size()]*(s[i]-'a'+1))%mod);
		pre9.pb((pre9.back()+pre7[cur.size()]*(s[i]-'a'+1))%mod2);
	
		cur.pb(i);
		/*for(int j=0;j<cur.size();j++){

		}*/
		llo low=0;
		llo high=cur.size()-1;
		while(low<high-1){
			llo mid=(low+high)/2;
			if(x.find(sub(mid,cur.size()-1))!=x.end() and y.find(sub2(mid,cur.size()-1))!=y.end()){
				high=mid;
			}
			else{
				low=mid;
			}
		}
		llo ind=high;
		if(x.find(sub(low,cur.size()-1))!=x.end() and y.find(sub2(low,cur.size()-1))!=y.end()){
			ind=min(ind,low);
		}
	
		if(x.find(sub(ind,cur.size()-1))!=x.end() and y.find(sub2(ind,cur.size()-1))!=y.end()){
			if(x[sub(ind,cur.size()-1)]==0 and y[sub2(ind,cur.size()-1)]==0){
				int xx=cur.size();
				for(llo j=ind;j<xx;j++){

					llo xx=((((s[cur.back()]-'a'+1)*pre[indd[cur.back()]]))%mod);
					xx=mod-xx;
					pre4.pop_back();
					cur.pop_back();
				}
				for(llo j=ind;j<xx;j++){
					pre9.pop_back();
				}
				i+=1;
			}
			else{
				i+=1;
			}
		}
		else{
			i+=1;
		}
	}
	for(auto j:cur){
		cout<<s[j];
	}
	cout<<endl;

	//cout<<ans<<endl;





	return 0;
}