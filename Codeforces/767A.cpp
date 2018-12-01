#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define L 1e5
#define pb push_back
typedef long long ll;
typedef long double ld;
//std::map<int, int> counter;
int counter[100002],modu=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	std::vector<int> v(n);
	std::vector<bool> aux(n,0);
	int top=n,j;
	FOR(i,0,n)
	{
		cin>>v[i];
		aux[v[i]]=1;
		if(v[i]==top)
		{
			while(1)
			{
				cout<<top--<<" ";
				if(aux[top]==0)break;
			}
		}
		cout<<endl;
	}
	return 0;
}