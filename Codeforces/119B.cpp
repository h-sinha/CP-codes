#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef long double ld;
std::map<ld,ld> co;
int main()
{
	int n,k,inp,it,q,f=0;
	cin>>n>>k;
	std::vector<ld> a(n+1);
	std::vector<ld> ans;
	std::vector<ld> aux;
	FOR(i,1,n+1)cin>>a[i];
	ld temp;
	it=n/k;
	cin>>q;
	int qwerty=q;
	std::vector<ld> w[q+1];
	FOR(i,0,q)
	{
		temp=0;
		FOR(j,0,it)
		{
			cin>>inp;
			co[inp]++;
			w[i].push_back(inp);
			temp+=a[inp];
		}
		sort(w[i].begin(),w[i].end());
		FOR(j,0,i)
		{
		int counter=0;
			FOR(k,0,it)
			{
				if(w[i][k]==w[j][k])
					counter++;
			}
			if(counter==it)qwerty--;
		}
		ans.push_back(temp/it);
	}
	FOR(i,1,n+1)if(!co[i])aux.push_back(a[i]);
	sort(aux.begin(), aux.end());
	int size=aux.size();
	ld max=INT_MIN,min=INT_MAX;
	if(qwerty!=k && size>=it)
	{
		max=0,min=0;
		FOR(i,size-it,size)max+=aux[i];
		FOR(i,0,it)min+=aux[i];
		max/=it;
		min/=it;
	}
	size=ans.size();
	sort(ans.begin(), ans.end());
	if(size>0)
	{	
		if(ans[size-1]>max)max=ans[size-1];
		if(ans[0]<min)min=ans[0];
	}
	printf("%.10Lf %.10Lf\n",min,max );	
	return 0;
}