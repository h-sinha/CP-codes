#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
std::vector<bool> visit(100002);
int dist[10002],petrol[10002],inp[1000002];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int arr[1000003];
std::vector<pii> seg(5000002);
void build(int s,int e,int index)
{
	if(s>=e)
	{
		seg[index]=mp(inp[s],s);
		// if(s<=10)
		// cout<<s<<" "<<inp[s]<<endl;
		return;
	}
	int mid=(s+e)>>1;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	// seg[index]=max(seg[index<<1],seg[(index<<1)+1]);
	if(seg[index<<1].first>seg[(index<<1)+1].first)
		seg[index]=mp(seg[index<<1].first,seg[index<<1].second);
	else if(seg[index<<1].first==seg[(index<<1)+1].first)
	{
		if(seg[index<<1].second<seg[(index<<1)+1].second)
			seg[index]=mp(seg[(index<<1)+1].first,seg[(index<<1)+1].second);
		else
			seg[index]=mp(seg[index<<1].first,seg[index<<1].second);	
	}
	else
		seg[index]=mp(seg[(index<<1)+1].first,seg[(index<<1)+1].second);

	return;
}
pii query(int s,int e,int l,int r,int index)
{
	if(l>e || r<s)return mp(INT_MIN,-1);
	if(s>=l && r>=e)return seg[index];
	int mid=(s+e)>>1;
	pii q1,q2;
	q1=query(s,mid,l,r,index<<1);
	q2=query(mid+1,e,l,r,(index<<1)+1);
	if (q1.first>q2.first)return q1;
	else if (q1.first==q2.first)
	{
		if(q1.second>q2.second)return q1;
		else return q2;
	}
	else return q2;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,t,l,p;
	 	cin>>t;
	 	while(t--)
	 	{
	 		cin>>n;
	 		FOR(i,1,n+1)cin>>dist[i]>>petrol[i];
	 		cin>>l>>p;
	 		FOR(i,0,1000001)inp[i]=INT_MIN;
	 		seg.clear();
	 		FOR(i,1,n+1){if(dist[i]<=l){inp[l-dist[i]]=petrol[i];}}
	 		int co=0,cur=0;
	 		build(1,1000000,1);
	 		int f=0;
	 		while(cur+p<l)
	 		{
	 			// cout<<cur<<" "<<p<<" "<<l<<endl;
	 			pii temp=query(1,1000000,cur+1,cur+p,1);
	 			if(cur==0 && inp[0]!=INT_MIN)
	 			{
	 				if(inp[0]>temp.first)
	 				{
	 					inp[0]=0;
	 					temp=mp(inp[0],int(0));
						p+=inp[0];
						continue;	
	 				}

	 			}
	 			p+=temp.first;
	 			// cout<<temp.first<<endl;
	 			if(temp.first==0 ||temp.first==INT_MIN){f=1;cout<<"-1"<<ln;break;}
	 			p-=(temp.second-cur);
	 			co++;
	 			// cout<<"trmp"<<temp<<endl;
	 			cur=temp.second;
	 			// if(cur==0){f=1;cout<<"-1"<<ln;break;}
	 		}
	 			// cout<<cur<<" "<<p<<" "<<l<<endl;
	 		if(!f)
	 		cout<<co<<ln;
	 	}
		return 0;
}