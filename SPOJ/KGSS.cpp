#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
int m=1000000007;
int arr[100002];
pii seg[4000002];
void build(int s,int e,int index)
{
	if(s>=e)
	{
		seg[index]=mp(arr[s],INT_MIN);
		return;
	}
	int mid=(s+e)/2;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	std::vector<int> v;
	v.pb(seg[index<<1].F);
	v.pb(seg[index<<1].S);
	v.pb(seg[(index<<1)+1].F);
	v.pb(seg[(index<<1)+1].S);
	sort(v.begin(), v.end());
	pii temp=mp(v[3],v[2]);
	v.clear();
	seg[index]=temp;
	return ;
}
pii query(int s,int e,int l,int r,int index)
{
	if(e<l || s>r )return mp(INT_MIN,INT_MIN);
	if(s>=l && e<=r)
		return seg[index];
	pii q1,q2;
	int mid=(s+e)/2;
	q1=query(s,mid,l,r,index<<1);
	q2=query(mid+1,e,l,r,(index<<1)+1);
	std::vector<int> v;
	v.pb(q1.F);
	v.pb(q1.S);
	v.pb(q2.F);
	v.pb(q2.S);
	sort(v.begin(), v.end());
	pii temp=mp(v[3],v[2]);
	v.clear();
	return temp;
}
void update(int s,int e,int index,int updind)
{
	if(updind<s||updind>e)return;
	if(updind==s && updind==e)
	{
		seg[index]=mp(arr[s],INT_MIN);
		return;
	}
	int mid=(s+e)/2;
	if(updind<=mid)
		update(s,mid,index<<1,updind);
	else
		update(mid+1,e,(index<<1)+1,updind);
	std::vector<int> v;
	v.pb(seg[index<<1].F);
	v.pb(seg[index<<1].S);
	v.pb(seg[(index<<1)+1].F);
	v.pb(seg[(index<<1)+1].S);
	sort(v.begin(), v.end());
	pii temp=mp(v[3],v[2]);
	v.clear();
	seg[index]=temp;
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x,y,q;
	char ch;
	cin>>n;
	FOR(i,1,n+1)cin>>arr[i];
	build(1,n,1);
	cin>>q;
	while(q--)
	{
		cin>>ch>>x>>y;
		if(ch=='U')
		{
			arr[x]=y;
			update(1,n,1,x);
		}
		else 
		{
			pii temp=query(1,n,x,y,1);
			cout<<temp.F+temp.S<<ln;
		}
	}
	return 0;
}
