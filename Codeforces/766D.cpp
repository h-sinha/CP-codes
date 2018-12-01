#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
std::map<string, int> counter;
string a[L];
int parentsy[L], parentan[L], sizesy[L], sizean[L];
int findsy(int vertex)
{
	if(parentsy[vertex] == vertex)return vertex;
	return parentsy[vertex] = findsy(parentsy[vertex]);
}
int findan(int vertex)
{
	if(parentan[vertex] == vertex)return vertex;
	return parentan[vertex] = findan(parentan[vertex]);
}
void unsy(int v1, int v2)
{
	int tmp1 = findsy(v1), tmp2 = findsy(v2);
	if(sizesy[tmp1] > sizesy[tmp2])
	{
		parentsy[tmp2] = tmp1;
		sizesy[tmp2] += sizesy[tmp1];
	}
	else
	{
		parentsy[tmp1] = tmp2;
		sizesy[tmp1] += sizesy[tmp2];
	}
}
void unan(int v1, int v2)
{
	int tmp1 = findan(v1), tmp2 = findan(v2);
	if(sizean[tmp1] > sizean[tmp2])
	{
		parentan[tmp2] = tmp1;
		sizean[tmp2] += sizean[tmp1];
	}
	else
	{
		parentan[tmp1] = tmp2;
		sizean[tmp1] += sizean[tmp2];
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, q, type, v1, v2;
	 	string s1, s2;
	 	cin >> n >> m >> q;
	 	FOR(i,1,n+1)
	 	{
	 		cin >> a[i];
	 		counter[a[i]] = i;
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		parentan[i] = parentsy[i] = i;
	 		sizean[i] = sizesy[i] = 1;
	 	}
	 	FOR(i,0,m)
	 	{
	 		cin >> type >> s1 >> s2;
	 		v1 = counter[s1]; 
	 		v2 = counter[s2]; 
	 		cout<<v1<<" "<<v2<<" "<<findsy(findan(v1))<<" "<<findsy(findan(v2))<<" "<<findan(findsy(v1))<<" "<<findan(findsy(v2))<<ln;
	 		if(type == 1)
	 		{
	 			if(findan(findsy(v1)) == findan(findsy(v2)) )
	 			{
	 				cout<<"NO\n";
	 				continue;
	 			}
	 			unsy(v1,v2);
	 			cout<<"YES\n";
	 		}
	 		else
	 		{
	 			if(findsy(findan(v1)) == findsy(findan(v2)) )
	 			{
	 				cout<<"NO\n";
	 				continue;
	 			}
	 			unan(v1,v2);
	 			cout<<"YES\n";
	 		}
	 	}
	 	FOR(i,1,n+1)debug3(i,findsy(i),findan(i));
	 	FOR(i,0,q)
	 	{
	 		cin >> s1 >> s2;
	 		v1 = counter[s1], v2 = counter[s2];
	 		// cout<<v1<<" - "<<v2<<ln;
	 		// cout<<findsy(findan(v1))<<" "<<findsy(findan(v2))<<" "<<findan(findsy(v1))<<" "<<findan(findsy(v2))<<ln;
	 		if(findsy(v1) == findsy(v2))cout<<"1\n";
	 		else if(findan(v1) == findan(v2))cout<<"2\n";
	 		else cout<<"3\n";
	 	}
		return 0;
}