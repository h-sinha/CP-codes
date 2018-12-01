#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define L 1e5
#define pb push_back
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int modu=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	std::vector<int> v(n);
	FOR(i,0,n){cin>>v[i];counter[v[i]]++;}
	sort(v.begin(), v.end());
	if(counter[v[n-1]]==1)
	{
		cout<<"Conan";
		return 0;
	}
	FOR(i,0,n-1)
		if(counter[v[i]]%2){cout<<"Conan";return 0;}
	cout<<"Agasa";
	return 0;
}