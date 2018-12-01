#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n,arr[100001];
	char str[100001];
	cin>>str;
	int f=0,k=strlen(str);
    for(int i=k-1;i>=0;i--)
    	arr[k-1-i]=int(str[i]-'0');
    for(int i=k-1;i>=0;i--)
    {
    	if(arr[i]%2==0 && arr[i]<arr[0])
    	{
    		swap(arr[i],arr[0]);
    		f=1;
    		break;
    	}
    }
    if(!f)
    {
    	for (int i = 1; i < k; i++)
    	{
    		if(!(arr[i]%2))
    		{
    			swap(arr[i],arr[0]);
    			f=1;
    			break;
    		}
    	}
    }
    if(f)
    	for (int i = k-1; i>=0; i--)
    		cout<<arr[i];
    else
    	cout<<"-1";
	return 0;
}