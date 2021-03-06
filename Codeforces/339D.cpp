#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
int level[100002],temp,modu=1000000007;
ll arr[100002],seg[400010];
void build(int s,int e,int index);
ll query(int s,int e,int l,int r,int index);
void modify(int s,int e,int index,int update,int x,int step);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,a,b;
	cin>>n>>m;
	int aux=n;
	n=1<<n;


	FOR(i,1,n+1)
	{
		cin>>arr[i];
		modify(1,n,1,i,arr[i],aux);
	}
	FOR(i,0,m)
	{
		cin>>a>>b;
		arr[a]=b;		
		modify(1,n,1,a,b,aux);
		cout<<seg[1]<<endl;
	}
	return 0;
}
void modify(int s,int e,int index,int update,int x,int step)
{
	if(s>e)return;
	if(s==e && update==s)
	{
		seg[index]=x;
		return;
	}
	int mid=(s+e)/2;
	if(update<=mid && update>=s)
		modify(s,mid,index<<1,update,x,step-1);
	else if(update>=mid+1 && update<=e)
		modify(mid+1,e,(index<<1)+1,update,x,step-1);
	if(step&1)
		seg[index]=seg[index<<1]|seg[(index<<1)+1];
	else
		seg[index]=seg[index<<1]^seg[(index<<1)+1];
	// cout<<index<<" "<<seg[index]<<endl;

}