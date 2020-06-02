#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define rall(c) c.rbegin(), c.rend()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
#define init(a, x) memset(a,x,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L=1e6+7;

struct Line
{
	ld a, b, c;
};
struct Point
{
	ld x, y;
};
ld PI =3.14159265358979323846;
Point p[L];
// returns equation of Line joining p1 and p2
Line getLine(Point p1, Point p2)
{
	// ax + by + c = 0;
	ld a = p1.y-p2.y;
	ld b = p2.x-p1.x;
	ld c = (p1.x-p2.x)*p1.y + (p2.y-p1.y)*p1.x;
	return Line{a,b,c};
}
// return distance of point p from line l
ld distFromLine(Line l, Point p)
{
	ld d = abs((l.a * p.x + l.b * p.y + l.c)) / (sqrt(l.a * l.a + l.b * l.b)); 
	return d;
}
Point footOfPerpendicular(Line l, Point p)
{
	ld temp = -1 * (l.a * p.x + l.b * p.y + l.c) / (l.a * l.a + l.b * l.b); 
    ld x1 = temp * l.a + p.x; 
    ld y1 = temp * l.b + p.y;
    return Point{x1, y1}; 
}
ld distance(Point p1, Point p2)
{
	ld x = (p1.x - p2.x) * (p1.x - p2.x);
	ld y = (p1.y - p2.y) * (p1.y - p2.y);
	return sqrt(x + y);
}
ld dist[L];
void fff()
{
	int n;
	Point centre;
	cin >> n >> centre.x >> centre.y;
	ld ri = LLONG_MAX, ro = LLONG_MIN, d;	
	FOR(i,0,n)
	{
		cin >> p[i].x >> p[i].y;
		d = distance(p[i],centre);
		ro = max(ro,d);
		ri = min(ri,d);
	}
	FOR(i,0,n-1)
	{
		Line l = getLine(p[i],p[i+1]);
		Point f = footOfPerpendicular(l, centre);
		if(abs(distance(p[i],f)+distance(p[i+1],f) - distance(p[i],p[i+1])) <= 1e-6)
		{
			d = distFromLine(l,centre);
			ri = min(ri,d);
			ro = max(ro,d);
		}
	}
	Line l = getLine(p[n-1],p[0]);
	Point f = footOfPerpendicular(l, centre);
	if(abs(distance(p[n-1],f)+distance(p[0],f) - distance(p[n-1],p[0])) <= 1e-6)
	{
		d = distFromLine(l,centre);
		ri = min(ri,d);
		ro = max(ro,d);
	}
	printf("%.10Lf\n",PI*(ro*ro-ri*ri));

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}