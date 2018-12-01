#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
bool occ[302][302];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int curi=1,curj=1,n,m,k,co=0;
		cin>>n>>m>>k;
		if(k==1)
		{
			cout<<n*m<<" ";
			int tmp=1;
			while(curi<=n)
			{
				cout<<curi<<" "<<curj<<" ";
				if(tmp&1)
				{
					++curj;
					if(curj>m)curi++,curj=m,++tmp;
				}
				else
				{
					--curj;
					if(curj<1)curi++,curj=1,++tmp;
				}
			}
			return 0;
		}
		if(m%2==0)
		{
			while(k!=1)
			{
				if(k>2 || curi==n)
				cout<<"2 "<<curi<<" "<<curj<<" "<<curi<<" "<<curj+1<<ln;
				else
				{
					cout<<m-(curj-1)<<" ";
					while(curj<=m)
					{
						cout<<curi<<" "<<curj<<" ";
						co++;
						++curj;
					}
					cout<<ln;
					++curi;
					curj=1;
					--k;
					break;
				}
				curj+=2;
				co+=2;
				if(curj>m)++curi,curj=1;
				--k;
			}
			if(n*m-co==0)return 0;
			// cout<<co<<ln;
			cout<<n*m-co<<" ";
			int tmp=1;
			while(curi<=n)
			{
				cout<<curi<<" "<<curj<<" ";
				if(tmp&1)
				{
					++curj;
					if(curj>m)curi++,curj=m,++tmp;
				}
				else
				{
					--curj;
					if(curj<1)curi++,curj=1,++tmp;
				}
			}
		}
		else
		{
			while(k!=1)
			{
				// cout<<"one";
				if(curi>n)break;
				if(k>2)
					cout<<"2 "<<curi<<" "<<curj<<" "<<curi<<" "<<curj+1<<ln;
				else
				{
					cout<<m-(curj)<<" ";
					while(curj<=m-1)
					{
						cout<<curi<<" "<<curj<<" ";
						co++;
						++curj;
					}
					cout<<ln;
					++curi;
					curj=1;
					--k;
					break;
				}
				curj+=2;
				co+=2;
				if(curj>=m)++curi,curj=1;
				--k;
			}
			if(k>1)
			{
				curi=1;
				while(k!=1)
				{
					cout<<"2 "<<curi<<" "<<m<<" "<<curi+1<<" "<<m<<ln;
					curi+=2;
					co+=2;
					--k;
				}
				cout<<n*m-co<<" ";
				while(curi<=n)
				{
					cout<<curi<<" "<<m<<" ";
					++curi;
				}
				return 0;
			}
			cout<<n*m-co<<" ";
			int tmp=1;
			int finishi=curi;
			// cout<<finishi<<ln;
			curi=1,curj=m;
			while(curi<=n)
			{
				cout<<curi<<" "<<curj<<" ";
				++curi;
			}
			tmp=0;
			curi=n,curj=m-1;
			while(curi>=finishi)
			{
				cout<<curi<<" "<<curj<<" ";
				if(tmp&1)
				{
					++curj;
					if(curj>=m)--curi,curj=m-1,++tmp;
				}
				else
				{
					--curj;
					if(curj<1)--curi,curj=1,++tmp;
				}
			}

		}
		return 0;
}