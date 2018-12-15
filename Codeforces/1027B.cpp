#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e6+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		string s;
		cin >> s;
		int a,b,xx;
		int len = s.length();
			// cout<<len;
		if(len<=20)
		{
			cout<<"1 "<<len<<ln;
			cout<<s;
			return 0;
		}
		if(len<=40)
		{
			a = 2;
			FOR(i,1,21)
			{
				if(2*i>=len)
				{
					b= i;
					break;
				}
			}
			cout<<a<<" "<<b<<ln;
			FOR(i,0,b)cout<<s[i];
			cout<<ln;
			FOR(i,b,2*b)
			{
				if(i<len)cout<<s[i];
				else cout<<"*";
			}
			cout<<ln;
			return 0;
		}
		if(len<=60)
		{
			a = 3;
			FOR(i,1,21)
			{
				if(3*i>=len)
				{
					b= i;
					break;
				}
			}
			cout<<a<<" "<<b<<ln;
			FOR(i,0,b)cout<<s[i];
			cout<<ln;
			xx = a - (len%a);
			if(xx%a)
			{
				cout<<"*";
				FOR(i,b,2*b-1)
				{
					cout<<s[i];
				}
				cout<<ln;
				if(xx%a==2)
				{
					cout<<"*";
					FOR(i,2*b-1,3*b-2)
					{
						cout<<s[i];
					}
					cout<<ln;

				}
				else 
				{
					FOR(i,2*b-1,3*b-1)
					{
						cout<<s[i];
					}
					cout<<ln;

				}
			}
			else 
			{
				FOR(i,b,2*b)
				{
					cout<<s[i];
				}
				cout<<ln;
				FOR(i,2*b,3*b)
				{
					cout<<s[i];
				}
			cout<<ln;
				
			}
			return 0;
		}
		if(len<=80)
		{
			a = 4;
			FOR(i,1,21)
			{
				if(4*i>=len)
				{
					b= i;
					break;
				}
			}
			cout<<a<<" "<<b<<ln;
			FOR(i,0,b)cout<<s[i];
			cout<<ln;
			xx = a - (len%a);

			if(xx%a)
			{
				cout<<"*";
				FOR(i,b,2*b-1)
				{
					cout<<s[i];
				}
				cout<<ln;
				if(xx%a>=2)
				{
					cout<<"*";
					FOR(i,2*b-1,3*b-2)
					{
						cout<<s[i];
					}
					cout<<ln;
					if(xx%a>=3)
					{
						cout<<"*";
						FOR(i,3*b-2,4*b-3)
						{
							cout<<s[i];
						}
					cout<<ln;

					}
					else
					{
						FOR(i,3*b-2,4*b-2)
						{
							cout<<s[i];
						}
					cout<<ln;

					}
				}
				else 
				{
					FOR(i,2*b-1,3*b-1)
					{
						if(i<len)cout<<s[i];
						else cout<<"*";
					}
					cout<<ln;
					FOR(i,3*b-1,4*b-1)
					{
						if(i<len)cout<<s[i];
						else cout<<"*";
						}
					cout<<ln;


				}
			}
			else 
			{
				FOR(i,b,2*b)
				{
					cout<<s[i];
				}
				cout<<ln;
				FOR(i,2*b,3*b)
				{
					cout<<s[i];
				}
				cout<<ln;
				FOR(i,3*b,4*b)
				{
					cout<<s[i];
				}
					cout<<ln;

			}
			return 0;
		}

			a = 5;
			FOR(i,1,21)
			{
				if(5*i>=len)
				{
					b= i;
					break;
				}
			}
			cout<<a<<" "<<b<<ln;
			xx = a - (len%a);
			FOR(i,0,b)cout<<s[i];
			cout<<ln;
			if(xx%a)
			{
				cout<<"*";
				FOR(i,b,2*b-1)
				{
					cout<<s[i];
				}
				cout<<ln;
				if(xx%a>=2)
				{
					cout<<"*";
					FOR(i,2*b-1,3*b-2)
					{
						cout<<s[i];
					}
					cout<<ln;
					if(xx%a>=3)
					{
						cout<<"*";
						FOR(i,3*b-2,4*b-3)
						{
							cout<<s[i];
						}
						cout<<ln;

						if(xx%a>=4)
						{
							cout<<"*";
							FOR(i,4*b-3,5*b-4)
							{
								cout<<s[i];
							}
							cout<<ln;
							
						}
						else
						{
							FOR(i,4*b-3,5*b-3)
							{
								cout<<s[i];
							}
							cout<<ln;
						}

					}
					else
					{
						FOR(i,3*b-2,4*b-2)
						{
							cout<<s[i];
						}
						cout<<ln;
						FOR(i,4*b-2,5*b-2)
						{
							cout<<s[i];
						}
					}
				}
				else 
				{
					FOR(i,2*b-1,3*b-1)
					{
						if(i<len)cout<<s[i];
						else cout<<"*";
					}
					cout<<ln;
					FOR(i,3*b-1,4*b-1)
					{
						if(i<len)cout<<s[i];
						else cout<<"*";
					}
					cout<<ln;
					FOR(i,4*b-1,5*b-1)
					{
						if(i<len)cout<<s[i];
						else cout<<"*";
					}
					cout<<ln;

				}
			}
			else 
			{
				FOR(i,b,2*b)
				{
					cout<<s[i];
				}
				cout<<ln;
				FOR(i,2*b,3*b)
				{
					cout<<s[i];
				}
				cout<<ln;
				FOR(i,3*b,4*b)
				{
					cout<<s[i];
				}
				cout<<ln;
				FOR(i,4*b,5*b)
				{
					cout<<s[i];
				}
			}
		return 0;
}