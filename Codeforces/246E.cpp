#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
map<string,int> counter;
map<int,string> position;
int baseArray[L],  pos_in_base[L], level[L],end_vertex[L];
// set< pair<string,int> >seg[4*L];
std::vector< pair<string,int> > seg[4*L];
int size_of_base, start_time = 1, number_of_nodes;
std::vector<int> v[L];
std::vector<int> root;
void eulerTour(int vertex, int parent)
{
	pos_in_base[vertex] = start_time;
	baseArray[start_time++] = vertex;
	if(parent!=-1)level[vertex] = level[parent] + 1;
	else level[vertex]=0;
	for(auto &x : v[vertex])
	{
		if(x != parent)
		{
			eulerTour(x, vertex);
		}
	}
	end_vertex[vertex] = start_time;
	baseArray[start_time++] = vertex;
	return;
}
void build(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		seg[index] .pb( mp( position[baseArray[start]] , level[baseArray[start]] ));
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	trace(seg[index<<1],x)
	{
		if(find(all(seg[index]),x)==seg[index].end())
			seg[index].pb(x);
	}	
	trace(seg[ (index<<1) +1],x)
	{
		if(find(all(seg[index]),x)==seg[index].end())
			seg[index].pb(x);

	}
	// sort(all(seg[index]));
	// cout<<ln;
	// trace(seg[index],x)cout<<x.F<<" "<<x.S<<ln;
	// cout<<ln;
	return;
}
set<string> query(int l, int r, int val, int start = 1, int end = size_of_base, int index = 1)
{
	set<string>SET;
	if( start > r || end < l )return SET;
	if(start >= l && end <= r)
	{
		int co=0;
		trace(seg[index],x)
		{
			// cout<<x.F<<" "<<x.S<<" "<<val<<endl;
			if(x.S==val)
			{
				SET.insert(x.F);
			}
			// if(x.S>val)return sz(SET);
		}
		return SET;
		// cout<<ln;
		// trace()
		// return sz(SET);
	}
	// set<string>SET;
	int mid = (start + end)/2;
	set<string> query_left, query_right;
	query_left = query(l, r, val, start, mid, 2*index );
	query_right = query(l, r, val, mid+1, end, 2*index + 1);
	trace(query_left,x)SET.insert(x);
	trace(query_right,x)SET.insert(x);
	return SET;
}
int main()
{
	int v1,v2,m,l;
	cin >> number_of_nodes;
	string str;
	for (int i = 1; i < number_of_nodes + 1; ++i)
	{
		cin >> str >> v2;
		position[i]=str;
		if(v2==0)root.pb(i);
		v[i].push_back(v2);
		v[v2].push_back(i);
	}
	// trace(root,x)
	eulerTour(0,-1);
	// FOR(i,1,number_of_nodes+1)cout<<position[i]<<ln;
	// FOR(i,1,start_time)cout<<baseArray[i]<<" ";
	// cout<<ln;
	size_of_base = start_time -1;
	build();
	cin>>m;
	FOR(i,0,m)
	{
		cin>>v1>>l;
		cout<<sz(query(pos_in_base[v1],end_vertex[v1],level[v1]+l))<<ln;
	}

	return 0;
}