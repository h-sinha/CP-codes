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
struct comp
{	
	bool operator()(ll x,ll y)
	{
		return x>y;
	}
};
set<ll>pos,neg;
set<ll,comp>curp,curn;
std::map<ll, ll> cn,pn,cp,pp;
int a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll sump=0,sumn=0,cop=0,con=0,tot=0,tmp;
	 	int n,len,k;
	 	cin>>n>>len;
	 	FOR(i,0,n)cin>>a[i];
	 	cin>>k;
	 	FOR(i,0,len)
	 	{
	 		// debug2(i,a[i]);
	 		if(a[i]>0)
	 		{
	 			pos.insert(a[i]);
	 			pp[a[i]]++;
	 		}
	 		else if(a[i]<0)
	 		{
	 			neg.insert(-a[i]);
	 			pn[-a[i]]++;
	 		}
	 		tot+=a[i];
	 	}
	 	
	 	// cout<<tot<<endl;
	 	while(cop<k && !(pos.empty()))
	 	{
	 		tmp=*(--pos.end());
	 		curp.insert(tmp);
	 		sump+=tmp;
	 		cp[tmp]++;
	 		cop++;
	 		pp[tmp]--;
	 		if(pp[tmp]==0)
	 		pos.erase(--pos.end());
	 	}
	 	// cout<<sz(neg)<<endl;
	 	while(con<k && !(neg.empty()))
	 	{
	 		tmp=*(--neg.end());
	 		curn.insert(tmp);
	 		cn[tmp]++;
	 		con++;
	 		sumn-=tmp;
	 		pn[tmp]--;
	 		if(pn[tmp]==0)
	 		neg.erase(--neg.end());
	 		// cout<<tmp<<endl;
	 	}
	 	// cout<<sz(curn)<<" "<<sz(neg)<<endl;
	 	ll ans=0;
	 	// cout<<sumn<<" "<<sump;
		if(tot<0)ans=abs(tot-2*sump-0);
		else ans=abs(tot-2*sumn-0);
		FOR(i,1,n)
		{
			// cout<<i<<" "<<a[i-1]<<endl;
			// cout<<i<<" "<<tot<<" "<<sumn<<" "<<sump<<endl;
			if(i+len-1>=n)break;
			if(a[i-1]>0)
			{
				if(curp.find(a[i-1])!=curp.end())
				{
					sump-=a[i-1];
					cp[a[i-1]]--;
					cop--;
					if(cp[a[i-1]]==0)
					curp.erase(a[i-1]);
				}
				else if(pos.find(a[i-1])!=pos.end())
				{
					pp[a[i-1]]--;
					if(pp[a[i-1]]==0)
				 	pos.erase(a[i-1]);
				}
			}
			else if(a[i-1]<0)
			{
			// cout<<i<<" "<<sumn<<endl;
				if(curn.find(-a[i-1])!=curn.end())
				{
					// cout<<i<<"sda";
					cn[-a[i-1]]--;
					if(cn[-a[i-1]]==0)
					curn.erase(-a[i-1]);
				// cout<<a[i-1]<<" & "<<cn[-a[i-1]]<<endl;
					con--;
					sumn-=a[i-1];
				}
				else if(neg.find(-a[i-1])!=neg.end())
				{
					// cout<<i<<"sda1";
					pn[-a[i-1]]--;
					if(pn[-a[i-1]]==0)
					neg.erase(-a[i-1]);
				}
				// cout<<a[i-1]<<" "<<pn[-a[i-1]]<<endl;
			}
			// cout<<i<<" "<<sumn<<endl;
			tot-=a[i-1];
			if(a[i+len-1]>0)
			{
				if(!curp.empty() && a[i+len-1]>*(--curp.end()))
				{
					tmp=*(--curp.end());
					cp[tmp]--;
					if(cp[tmp]==0)
					curp.erase(--curp.end());
					curp.insert(a[i+len-1]);
					sump-=tmp;
					sump+=a[i+len-1];
					cp[a[i+len-1]]++;
					pp[tmp]++;
					pos.insert(tmp);
				}
				else
				{
					pp[a[i+len-1]]++;
					pos.insert(a[i+len-1]);
				}	
			}
			else if(a[i+len-1]<0) 
			{
				if(!curn.empty() && -a[i+len-1]>*(--curn.end()))
				{
					tmp=*(--curn.end());
					cn[tmp]--;
					if(cn[tmp]==0)
					curn.erase(--curn.end());
					curn.insert(-a[i+len-1]);
					cn[-a[i+len-1]]++;
					sumn+=tmp;
					sumn+=a[i+len-1];
					pn[tmp]++;
					neg.insert(tmp);
				}
				else
				{
					pn[-a[i+len-1]]++;
					neg.insert(-a[i+len-1]);
				}
			}
			// debug2(i,sumn);
			// cout<<sumn<<"_"<<sump<<ln;
			while(cop<k && !pos.empty())
			{
				tmp=*(--pos.end());
				sump+=tmp;
				pp[tmp]--;
				if(pp[tmp]==0)
				pos.erase(--pos.end());
				cp[tmp]++;
				curp.insert(tmp);
				cop++;
			}
			while(con<k && !(neg.empty()))
			{
				tmp=*(--neg.end());
				// cout<<tmp<<endl;
				sumn-=tmp;
				pn[tmp]--;
				if(pn[tmp]==0)
				neg.erase(--neg.end());
				cn[tmp]++;
				con++;
				curn.insert(tmp);
				// cout<<sz(neg)<<endl;
			}
			// debug2(con,sz(neg));
			tot+=a[i+len-1];
			// debug2(sz(curn),sz(neg));
			// cout<<sump<<" & "<<sumn<<ln;
			// if(tot<0)ans=max(abs(tot-2*sump-0),ans);
			// else ans=max(ans,abs(tot-2*sumn-0));
			// cout<<tot<<" "<<sumn
			ans=max(ans,max(abs(tot-2*sump) ,abs(tot-2*sumn)));
			// debug3(i,sump,sumn);
			// cout<<i<<" "<<ans<<ln;
			// cout<<i<<" "<<tot<<" "<<sump<<" "<<sumn<<ln;
		}
		cout<<ans;
		return 0;

}