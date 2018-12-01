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
const int L=1e6+7;
std::vector<int> counter(L,-INT_MAX);
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	cin >> s;
	 	int len =s.length();
	 	stack<int> st;
	 	int mx=0;
	 	st.push(-1);
	 	FOR(i,0,len)
	 	{
	 		if(s[i] == '(')st.push(i);
	 		else 
	 		{
	 			st.pop();
	 			if(st.empty())st.push(i)	;
	 			else 
	 			{
	 				counter[i] = st.top();
	 				mx = max(mx, i-counter[i]);
	 			} 
	 		}
	 	}
	 	int ans = 0;
	 	FOR(i,0,len)
	 	{
	 		debug2(i,counter[i]);
	 		if(i-counter[i] == mx)ans++;
	 	}
	 	if(mx == 0)ans=1;
	 	cout<<mx<<" "<<ans;
		return 0;
}