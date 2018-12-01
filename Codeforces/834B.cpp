#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	char ch[1000002];
	std::vector<int> aux(26);
	cin>>ch;
	FOR(i,0,n)counter[ch[i]-'A']++;
	FOR(i,0,n)
	{
		int co=0;
		counter[ch[i]-'A']--;
		aux[ch[i]-'A']=1;
		if(!counter[ch[i]-'A'])co++;
		FOR(j,0,26)if(counter[j]>0 && aux[j]==1)co++;
		if(co>k){cout<<"YES";return 0;}
	}
	cout<<"NO";
	return 0;
}