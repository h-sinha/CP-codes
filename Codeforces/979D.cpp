#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define INT_SIZE 32
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int mark[100002];
std::vector<int> v[100002];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
struct TrieNode
{
    int value;
    TrieNode *arr[2];
};
TrieNode *root[100002];

TrieNode *newNode()
{
    TrieNode *temp = new TrieNode;
    temp->value = 1000000;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}
void insert(TrieNode *root, int pre_xor)
{
    TrieNode *temp = root;
    int val=pre_xor;
    if(root->value>pre_xor)root->value=min(root->value,pre_xor);
    RFOR(i,31,0)
    {
        bool val = pre_xor & (1<<i);
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
        temp = temp->arr[val];
 
        temp->value=min(temp->value,pre_xor);
        // cout<<temp->value;
// 
   		// cout<<val;
    }
   	// cout<<endl;

    temp->value=min(pre_xor,temp->value);
}
int query(int x,int k,int s)
{
    int ans=0,val1=x;
    // cout<<x<<" "<<k<<" "<<s-x<<" "<<root[k]->value<<endl;
	if(x%k || s<root[k]->value+x)return -1;
	x=val1;   
    TrieNode *temp = root[k];
    for (int i=31; i>=0; i--)
    {
 	     bool val = x & (1<<i);
       // cout<<x<<" "<<temp->value<<endl;
       if (temp->arr[1-val]!=NULL && x+temp->arr[1-val]->value<=s) 
   	    {
   	        temp = temp->arr[1-val];
            // cout<<i<<" "<<"ONe"<<endl;
   	        // ans=ans+(1-val)<<i;
            // cout<<ans<<" "<<1-val<<endl;
   	    }
        else if(temp->arr[val]!=NULL && x+temp->arr[val]->value<=s)
   	    {   
          // cout<<i<<" Two"<<endl;
   	     	temp = temp->arr[val];
   	        // ans=ans+(val)<<i;
            // cout<<ans<<" "<<val<<endl;
   	    }
   	}
    // cout<<endl;
   	return temp->value;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int num,s,x,y,k,q,type,sofar=0;
	 	FOR(i,1,100002)root[i]=newNode();
	 	cin>>q;
    FOR(i,1,100001)for (int j = 0; j < 100001; j+=i)v[j].pb(i);
	 	while(q--)
	 	{
	 		cin>>type;
	 		if(type==1)
	 		{
	 				cin>>num;
	 				if(mark[num])continue;
	 				mark[num];
          for(auto &x:v[num])insert(root[x],num);
	 		}
	 		else 
	 		{
	 				cin>>x>>k>>s;
	 				if(x%k){cout<<"-1"<<ln;continue;}
	 				cout<<query(x,k,s)<<endl;
	 		}
	 	}
		return 0;
}