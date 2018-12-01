#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)     for(int i=a;i<b;++i)
#define RFOR(i,a,b)     for(int i=a;i>=b;--i)
#define ln         "\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)    ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
std::vector<int> arr;
std::vector<int> brr;
int pos[1000002],mark[1000002];
int main()
{
        ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         int n,a,co=0,temp;
         cin>>n;
         FOR(i,0,n){cin>>a;arr.pb(a);brr.pb(a);pos[a]=i;mark[i]=a;}
         sort(arr.begin(), arr.end());
         FOR(i,0,n)
         {
            if(pos[arr[i]]==i)continue;
            co++;
            temp=pos[arr[i]];
            int aux=mark[i];
            pos[mark[i]]=temp;
            mark[temp]=aux;
            pos[arr[i]]=i;
            mark[i]=arr[i];
         }
         // cout<<co<<endl;
         if((3*n-co)%2==0)cout<<"Petr";
         else cout<<"Um_nik";
        return 0;
}