#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define L 1e5
#define pb push_back
typedef long long ll;
typedef long double ld;
//std::map<int, int> counter;
int modu=1000000007;
int counter[300002],n,q,type,num,ans=0,l=0,ind=0,stor[300002],auxcount[300002];
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	FOR(i,0,q)
	{
		cin>>type>>num;
		switch (type)
		{
			case 1:
				counter[num]++;
				stor[++ind]=num;
				ans++;
				break;
			case 2:
				ans-=counter[num];
				counter[num]=0;
				auxcount[num]=ind;
				break;
			case 3:
				for(;l<=num;l++)
					if(l>auxcount[stor[l]]){counter[stor[l]]--;ans--;}
				break;
		}
	cout<<ans<<endl;
	}
	return 0;
}