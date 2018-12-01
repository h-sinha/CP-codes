#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	std::vector<ll> a(n);
	std::vector<ll> aux(n);
	std::vector<ll> x;
	std::vector<ll> y;
	FOR(i,0,n){cin>>a[i];aux[i]=a[i];}
	sort(aux.begin(), aux.end());
	FOR(i,0,n)
	{
		if(a[i]==aux[i])continue;
		FOR(j,i,n)
		{
			if(a[j]==aux[i])
			{
				x.push_back(i);
				y.push_back(j);
				swap(a[j],a[i]);
				break;
			}
		}
	}
	cout<<x.size()<<endl;
	FOR(i,0,x.size())cout<<x[i]<<" "<<y[i]<<endl;
	return 0;
}