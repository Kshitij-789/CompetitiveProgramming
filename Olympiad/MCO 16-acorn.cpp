/*
The solution I got was same as https://github.com/luciocf/Problems/blob/master/MCO/MCO%202016/acorn.cpp

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

llo n;
vector<pair<llo,llo>> aa;
vector<pair<llo,llo>> it;
llo check(llo cc,llo ind){
	pair<llo,llo> i=it[ind];
	llo ind2=-1;
	for(auto j:it){
		ind2++;
		if(ind2==ind){
			continue;
		}
		llo ac=max((llo)0,(cc-j.a)*j.b);
		llo bc=max((llo)0,(cc-i.a)*i.b);
		if(ac>bc){
			return 0;
		}
		if(ac==bc and ind2>ind){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		llo bb,cc;
		cin>>bb>>cc;
		aa.pb({bb,-cc});
	}
	sort(aa.begin(),aa.end());
	for(llo i=0;i<aa.size();i++){
		aa[i].b=-aa[i].b;
	}
	llo ma=0;
	
	llo ans=0;
	for(llo i=0;i<n;i++){
		if(aa[i].b<=ma){
			ans+=1;
			continue;
		}
		ma=aa[i].b;
		it.pb(aa[i]);
	//	cout<<aa[i].a<<",,"<<aa[i].b<<endl;
	}
	llo ind=-1;
	llo low=1;
	llo high=1e6+1;
	for(auto i:it){
		ind++;
		low=max(low,i.a+1);
		if(!check(low,ind)){
			ans+=1;
			continue;
		}
		
		high=1e6+1;
		while(low<high-1){
			llo mid=(low+high)/2;
			if(check(mid,ind)){
				low=mid;
			}
			else{
				high=mid;
			}
		}
		llo anss=low;
		if(check(high,ind)){
			anss=max(anss,high);
		}
		low=anss+1;
		
		//llo ind2=-1;
	/*	pair<llo,llo> mi={i.a+1,1};//time>=mi
		pair<llo,llo> ma={1e6+1,1};//time<ma*/
		/*pair<llo,llo> mi={-1,1};
		pair<llo,llo> ma={1e9+1,1};*/
		/*for(auto j:it){
			ind2++;
			if(ind2==ind){
				continue;
			}
			if(ind2<ind){
				pair<llo,llo> kk={i.a*i.b-j.a*j.b,i.b-j.b};

				if(kk.a*mi.b>mi.a*kk.b){
					mi=kk;
				}
			}
			else{
				pair<llo,llo> kk={i.a*i.b-j.a*j.b,j.b-i.b};
				kk.a=-kk.a;
	//			cout<<kk.a<<"?"<<kk.b<<endl;
				if(kk.a*ma.b<kk.b*ma.a){
					ma=kk;
				}
			}
		}*/
	//	cout<<i.a<<":"<<i.b<<endl;
	//	cout<<mi.a<<":"<<mi.b<<"::"<<ma.a<<":"<<ma.b<<endl;
		/*if(ind!=(llo)(it.size())-1){
			if((i.a+1)*mi.b>mi.a){
				mi={i.a+1,1};
			}
		}*/
	/*	if(ma.a*mi.b>mi.a*ma.b){
		}
		else{
			if(ind==it.size()-1){
				if(it[0].a>=1){
					continue;
				}
			}
			ans+=1;
		}*/
		//break;
	}
	cout<<ans<<endl;

	return 0;
}

