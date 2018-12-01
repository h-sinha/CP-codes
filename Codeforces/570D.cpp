#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,char>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
const int L=5e5+7;
std::vector<int> v[L];
std::vector<pii> seg[4*L];
int posinbase[L],t=1,start[L],endis[L],distanceroot[L];
string str;
void dfs(int vertex,int parent,int dist)
{
	start[vertex]=t++;
	posinbase[t-1]=vertex;
	distanceroot[vertex]=dist+1;
	trace(v[vertex],x)
		if(x!=parent)
			dfs(x,vertex,dist+1);
	endis[vertex]=t-1;
	// posinbase[t-1]=vertex;
}
void build(int s,int e,int index)
{
	if(s>=e)
	{
		seg[index].pb(mp(distanceroot[posinbase[s]],str[posinbase[s]-1]));
		// cout<<str[s-1]<<" "<<posinbase[s]<<endl;
		return;
	}
	int mid=(s+e)>>1;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	trace(seg[index<<1],x)seg[index].pb(x);
	trace(seg[(index<<1)+1],x)seg[index].pb(x);
	sort(all(seg[index]));
	return;
}
bool comp(const pii x,int y)
{
	return x.F<y;
}
struct node{
	int arr[26]={0};
};
node au;
node query(int s,int e,int index,int l,int r,int val)
{
	// node temp;
	// FOR(i,0,26)temp.arr[i]=0;
	if(s>e || s>r || e<l )return au;
	if(s>=l && e<=r)
	{
		// string ret="";
		// std::vecto> v;
		std::vector<pii>::iterator it,itup;
		it=lower_bound(all(seg[index]),val,comp);
		itup=lower_bound(all(seg[index]),val,comp);
		// it--;
		// cout<<*it;
		// cout<<val<<" "<<it.F<<endl;
		node temp;
		while(it!=seg[index].end() && (*it).F==val)
		{
			// ret+=(*it).S;
			temp.arr[(*it).S-'a']++;
			++it;
		}
		// cout<<"s"<<endl;
		return temp;
	}
	node q1,q2;
	int mid=(s+e)>>1;
	q1=query(s,mid,index<<1,l,r,val);
	q2=query(mid+1,e,(index<<1)+1,l,r,val);
	FOR(i,0,26)q1.arr[i]+=q2.arr[i];
	return q1;
}
int co[27];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL),cout.tie(NULL);
		int n,m,a,b;
		cin>>n>>m;
		FOR(i,2,n+1)
		{
			cin>>a;
			v[a].pb(i);
			v[i].pb(a);
		}
		cin>>str;
		dfs(1,-1,0);
		--t;
		build(1,t,1);
		FOR(i,0,26)au.arr[i]=0;
		FOR(i,1,4*n+1)
		{
			FOR(j,0,26)seg[i]
		}
		// FOR(i,1,7)cout<<posinbase[i]<<endl;
		// FOR(i,1,25)cout<<posinbase[i]<<" ";
		while(m--)
		{
			node tmp;
			int odd=0,eve=0,len;
			cin>>a>>b;
			tmp=query(1,t,1,start[a],endis[a],b);
			// len=tmp.length();
			// if(len==0){cout<<"Yes"<<ln;continue;}
			// FOR(i,0,26)co[i]=0;
			// FOR(i,0,len)co[tmp[i]-'a']++;
			FOR(i,0,26)
			{
				if(tmp.arr[i]&1)odd++;
				else if(tmp.arr[i])eve++;
			}
			if(odd>1)cout<<"No"<<ln;
			else cout<<"Yes"<<ln;
		}
		return 0;
}