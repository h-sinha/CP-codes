#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
ll arr[200002],seg[8000010],a[200002],cumsum[200002];
void build(int s,int e,int index)
{
	if(s>=e)
	{
		seg[index]=arr[s];
		return;
	}
	int mid=(s+e)/2;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	seg[index]=max(seg[index<<1],seg[(index<<1)+1]);
	return;
}
ll query(int s,int e,int l,int r,int index)
{
	if(e<l || s>r )return LLONG_MIN;
	if(s>=l && e<=r)
		return seg[index];
	ll q1,q2;
	int mid=(s+e)/2;
	q1=query(s,mid,l,r,index<<1);
	q2=query(mid+1,e,l,r,(index<<1)+1);
	return max(q1,q2);
}
struct comp{
	bool operator ()(pii x,ll y)
	{
		return x.first<y;
	}
};
bool compare(pii x,pii y)
{
	if(x.first==y.first)return x.second<y.second;
	return x.first<y.first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	FOR(i,1,n+1)cin>>a[i];
	FOR(i,1,n+1)
	{
		cumsum[i]+=cumsum[i-1];
		cumsum[i]+=a[i];
	}
	std::vector<pii> v;
	FOR(i,1,n-k+2)
	{
		arr[i]=cumsum[i+k-1]-cumsum[i-1];
		// counter[arr[i]]=i;
		v.pb(mp(arr[i],i));
	}
	sort(v.begin(), v.end(),compare);
	FOR(i,n-k+2,n+1)arr[i]=LLONG_MIN;
	// FOR(i,1,n+1)cout<<i<<" "<<arr[i]<<ln;
	build(1,n,1);
	ll ans=0,out1,out2;
	std::vector<pii> ::iterator it;
	FOR(i,1,n-k+2)
	{
		ll tmp=query(1,n,i+k,n,1);
		if(ans<cumsum[i+k-1]-cumsum[i-1]+tmp)
		{
			ans=cumsum[i+k-1]-cumsum[i-1]+tmp;	
			out1=i;
			it=lower_bound(v.begin(), v.end(),tmp,comp());
			int pnt=it-v.begin();
			FOR(j,pnt,sz(v))
			{
				if(v[j].first==tmp && v[j].second>i+k-1)
				{
					out2=v[j].second;
					break;
				}
			}
		}
	}
	cout<<out1<<" "<<out2<<ln;
	// cout<<ans;
	return 0;
}{
		return x.first<y;
	}
};
bool compare(pii x,pii y)
{
	if(x.first==y.first)return x.second<y.second;
	return x.first<y.first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	size_of_base=n;
	FOR(i,1,n+1)cin>>a[i];
	FOR(i,1,n+1)
	{
		cumsum[i]+=cumsum[i-1];
		cumsum[i]+=a[i];
	}
	std::vector<pii> v;
	FOR(i,1,n-k+2)
	{
		baseArray[i]=cumsum[i+k-1]-cumsum[i-1];
		v.pb(mp(baseArray[i],i));
	}
	sort(v.begin(), v.end(),compare);
	build();
	ll ans=0,out1,out2;
	std::vector<pii> ::iterator it;
	FOR(i,1,n-k+2)
	{
		ll tmp=query(i+k,n);
		if(ans<cumsum[i+k-1]-cumsum[i-1]+tmp)
		{
			ans=cumsum[i+k-1]-cumsum[i-1]+tmp;	
			out1=i;
			it=lower_bound(v.begin(), v.end(),tmp,comp());
			int pnt=it-v.begin();
			FOR(j,pnt,sz(v))
			{
				if(v[j].first==tmp && v[j].second>i+k-1)
				{
					out2=v[j].second;
					break;
				}
			}
		}
	}
	cout<<out1<<" "<<out2<<ln;
	return 0;
}