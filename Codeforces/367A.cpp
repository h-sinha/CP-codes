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
int counter[L][3];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	int q, l, r, tmp, aux;
	 	cin >> s;
	 	cin >> q;
	 	int len = s.length();
	 	FOR(i,0,len)
	 		counter[i][s[i]-'x']++;
	 	FOR(i,1,len)
	 		FOR(j,0,3)
	 			counter[i][j]+=counter[i-1][j];
		int aa[3],f=1;
		while(q--)
		{
			cin >> l >> r;
			--l,--r;
			if(r-l+1<3)
			{
				cout<<"YES\n";
				continue;
			}
			f=1;
			if(l>0)
			{
				FOR(i,0,3)aa[i] = counter[r][i] - counter[l-1][i];
			}
			else
			{
				FOR(i,0,3)aa[i] = counter[r][i];
			}
			// FOR(i,0,3)
			sort(aa,aa+3);
			tmp = (r-l+1)/3;
			aux = (r-l+1)%3;
			// cout<<aux<<ln;
			// FOR(i,0,3)cout<<aa[i]<<" ";
			// cout<<ln;
			if(aux==0)
			{
				FOR(i,0,3)
				{
					if(aa[i]!=tmp)
					{
						f=0;
						break;
					}
				}
			}
			else if(aux==1)
			{
				FOR(i,0,2)
				{
					if(aa[i]!=tmp)
					{
						f=0;
						break;
					}
				}
				if(aa[2] != tmp+1)f=0;
			}
			else 
			{
				if(aa[0]!=tmp)f=0;
				FOR(i,1,3)
				{
					if(aa[i]!=tmp+1)
					{
						f=0;
						break;
					}
				}
			}
			if(f)cout<<"YES\n";
			else cout<<"NO\n";
		}
		return 0;
}