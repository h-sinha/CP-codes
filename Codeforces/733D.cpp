#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define F first
#define S second
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<pii,pii> counter;
std::vector<int> v;
std::vector<int> v1;
int p[100002][5];
void addtomap(int a,int b,int c)
{
	if(counter[{a,b}].F==0)counter[{a,b}].F=c;
	else if(counter[{a,b}].S==0)
	{
	 	if(counter[{a,b}].F>c)counter[{a,b}].S=c;
	 	else
	 	{
	 		swap(counter[{a,b}].F,counter[{a,b}].S);
	 		counter[{a,b}].F=c;
	 	}
	}
	else 
	{
		if(counter[{a,b}].F<c)
		{
			swap(counter[{a,b}].F,counter[{a,b}].S);
	 		counter[{a,b}].F=c;
		}
		else if(counter[{a,b}].S<c)counter[{a,b}].S=c;
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll ans=INT_MIN,n,a,b,c,idx,temp1,temp2,temp3;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a>>b>>c;
	 		p[i][0]=a;
	 		p[i][1]=b;
	 		p[i][2]=c;
	 		v.pb(a);
	 		v.pb(b);
	 		v.pb(c);
	 		sort(v.begin(), v.end());
	 		addtomap(v[2],v[1],v[0]);
	 		v.clear();
	 	}
	 	int prevans;

	 	for(auto &x:counter)
	 	{
	 		temp1=-5;
	 		if(x.S.S!=0);
	 		temp1=min(x.F.F,min(x.F.S,x.S.F+x.S.S));
	 		temp2=min(x.F.F,min(x.F.S,x.S.F));
	 		temp3=min(x.F.F,min(x.F.S,x.S.S));
	 		prevans=ans;
	 		ans=max(ans,max(temp1,max(temp2,temp3)));
	 		if(prevans==ans)continue;
	 		if(ans==temp1 && ans!=temp2 && ans!=temp3)
	 		{
	 			v.clear();
	 			v.pb(x.F.F);
	 			v.pb(x.F.S);
	 			v.pb(x.S.F);
	 			v1.clear();
	 			v1.pb(x.F.F);
	 			v1.pb(x.F.S);
	 			v1.pb(x.S.S);
	 		}
	 		else if(ans==temp2)
	 		{
	 			v.clear();
	 			v.pb(x.F.F);
	 			v.pb(x.F.S);
	 			v.pb(x.S.F);
	 			v1.clear();

	 		}
	 		else
	 		{
	 			v.clear();
	 			v.pb(x.F.F);
	 			v.pb(x.F.S);
	 			v.pb(x.S.S);	
	 			v1.clear();
	 		}
	 	}
	 	// for(auto &x:v1)cout<<x;
	 		// cout<<ln;
	 	// cout<<sz(v1);
	 	cout<<(sz(v)+sz(v1))/3<<ln;
	 	std::vector<int> aux;
	 	sort(v.begin(), v.end());
	 	sort(v1.begin(), v1.end());
	 	ans=-1;
	 	FOR(i,0,n)
	 	{
	 		aux.pb(p[i][0]);
	 		aux.pb(p[i][1]);
	 		aux.pb(p[i][2]);
	 		sort(aux.begin(), aux.end());
	 		if(sz(v))
	 		{
	 			if(v[0]==aux[0] && v[1]==aux[1] && v[2]==aux[2])
	 			{
	 				if(ans!=i+1)
	 				{
	 					ans=i+1;
	 					cout<<i+1<<"  ";
	 					v.clear();
		 				if(sz(v1)==0)return 0;
	 				}
	 			}
	 		}
	 		if(sz(v1))
	 		{
	 			if(v1[0]==aux[0] && v1[1]==aux[1] && v1[2]==aux[2])
	 			{
	 				if(ans!=i+1)
	 				{
	 					ans=i+1;
	 					cout<<i+1<<"  ";
	 					v1.clear();
	 					if(sz(v)==0)return 0;
	 				}
	 			}
	 		}
	 		aux.clear();
	 	}
		return 0;
}