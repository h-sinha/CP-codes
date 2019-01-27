#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

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
string a[5201];
int sum[5201][5201], N,M;
void preProcess()
{
	sum[0][0] = (a[0][0] - '0');

	// pre-process first row
	for (int j = 1; j < N; j++)
		sum[0][j] = (a[0][j]-'0') + sum[0][j - 1];

	// pre-process first column
	for (int i = 1; i < M; i++)
		sum[i][0] = (a[i][0]-'0') + sum[i - 1][0];

	// pre-process rest of the matrix
	for (int i = 1; i < M; i++)
		for (int j = 1; j < N; j++)
			sum[i][j] = (a[i][j]-'0') + sum[i - 1][j] + sum[i][j - 1]
				- sum[i - 1][j - 1];
}

int findSubmatrixSum( int p, int q, int r, int s)
{
	int total = sum[r][s];

	if (q - 1 >= 0)
		total -= sum[r][q - 1];

	if (p - 1 >= 0)
		total -= sum[p - 1][s];

	if (p - 1 >= 0 && q - 1 >= 0)
		total += sum[p - 1][q - 1];

	return total;
}

int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> N;
	 	string s;
	 	M=N;
	 	FOR(i,0,N)
	 	{
	 		cin >> s;
	 		a[i] = "";
	 		FOR(j,0,N/4)
	 		{
	 			if(s[j] == '0')a[i] += "0000";
	 			else if(s[j] == '1')a[i] += "0001";
	 			else if(s[j] == '2')a[i] += "0010";
	 			else if(s[j] == '3')a[i] += "0011";
	 			else if(s[j] == '4')a[i] += "0100";
	 			else if(s[j] == '5')a[i] += "0101";
	 			else if(s[j] == '6')a[i] += "0110";
	 			else if(s[j] == '7')a[i] += "0111";
	 			else if(s[j] == '8')a[i] += "1000";
	 			else if(s[j] == '9')a[i] += "1001";
	 			else if(s[j] == 'A')a[i] += "1010";
	 			else if(s[j] == 'B')a[i] += "1011";
	 			else if(s[j] == 'C')a[i] += "1100";
	 			else if(s[j] == 'D')a[i] += "1101";
	 			else if(s[j] == 'E')a[i] += "1110";
	 			else if(s[j] == 'F')a[i] += "1111";
	 		}
	 	}
	 	// FOR(i,0,N)
	 	// {
	 	// 	cout<<a[i];
	 	// 	cout<<ln;
	 	// }
	 	preProcess();
	 	std::vector<int> v;
	 	int tmp = sqrt(N)+1;
	 	v.pb(N);
	 	FOR(i,2,tmp)
	 	{
	 		if(N%i == 0)
	 		{
	 			v.pb(i);
	 			if(i*i != N)v.pb(N/i);
	 		}
	 	}
	 	int co,f,ans = 1;
	 	// FOR(i,0,N)
	 	// {
	 	// 	FOR(j,0,N)cout<<aux[i][j]<<" ";
	 	// 	cout<<ln;
	 	// }
	 	// cout<<ln;
	 	trace(v,x)
	 	{
	 		co = 0, f=  0;
	 		for (int i = 0; i < N; i += (x))
	 		{
	 			for (int j = 0; j < N; j += (x))
	 			{
	 				tmp = findSubmatrixSum(i,j, i+x-1, j+x-1);
	 				if(tmp == 0 || tmp == x*x )co++;
	 				else 
	 				{
	 					f=1;
	 					break;
	 				}
	 			}
	 		}
	 		// debug(x,co);
	 		if(f || co!=((N/x)*(N/x)))continue;
	 		ans = max(ans,x);
	 	}
	 	cout<<ans;
		return 0;
}