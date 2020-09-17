#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
std::vector<bool> v(100001,1);
std::vector<int> ans(100001);
std::vector<int> counter(100001);
void sieve()
{
	int p;
	v[1]=0;
	for (int p=2; p*p<=100001; p++)
    {
        if (v[p])
        {
            for (int i=p*2; i<=100001; i += p)
                v[i] = false;
        }
    }
}
int main()
{
	int q,i,j;
	cin>>q;
	sieve();
	counter[0]=0;
	for(i=1;i<=100000;i++){
		counter[i]=counter[i-1];
		if(v[i]==1 && v[(i+1)/2]==1)
			counter[i]++;
	}
	int l,r;
	for (int i = 0; i < q; i++)
	{
		cin>>l>>r;
		cout<<counter[r]-counter[l-1]<<endl;
	}
	return 0;
}