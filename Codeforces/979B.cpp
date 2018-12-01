#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
std::vector<bool> visit(100002);
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int c1[100],c2[100],c3[100],aux1=0,aux2=0,aux3=0;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	string s1,s2,s3;
	 	cin>>s1>>s2>>s3;
	 	int len=s1.length();
	 	FOR(i,0,len)c1[s1[i]-'A']++;
	 	FOR(i,0,len)c2[s2[i]-'A']++;
	 	FOR(i,0,len)c3[s3[i]-'A']++;
	 	FOR(i,0,100)aux1=max(aux1,c1[i]);
	 	FOR(i,0,100)aux2=max(aux2,c2[i]);
	 	FOR(i,0,100)aux3=max(aux3,c3[i]);
	 	// cout<<aux1<<" "<<aux2<<" "<<aux3<<endl;
	 	if(n==1)
	 	{
	 		if(len==aux1)aux1-=1;else aux1+=1;
	 		if(len==aux2)aux2-=1;else aux2+=1;
	 		if(len==aux3)aux3-=1;else aux3+=1;
	 		goto label;
	 	}
	 	aux1=min(aux1+n,len);
	 	aux2=min(aux2+n,len);
	 	aux3=min(aux3+n,len);
	 	label:
	 	// cout<<aux1<<" "<<aux2<<" "<<aux3<<endl;
	 	if(aux1>aux2 && aux1>aux3)
	 		cout<<"Kuro";
	 	else if(aux2>aux3 && aux2>aux1)
			cout<<"Shiro";
	 	else if(aux3>aux1 && aux3>aux2)
	 		cout<<"Katie";
	 	else cout<<"Draw";
		return 0;
}