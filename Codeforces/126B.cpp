#include <bits/stdc++.h>
using namespace std;
const int L = 1e6+7;
int lps[L];
void preprocess(string s)
{
	int len = s.length(), cur = 0;
	lps[0] = 0;
	for (int i = 1; i < len; ++i)
	{
		if(s[i] == s[cur])
		{
			lps[i] = ++cur;
		}
		else
		{
			if(cur == 0)
			{
				lps[i] = 0;
				continue;
			}
			while(cur > 0 && s[i] != s[cur])cur = lps[cur-1];
			if(s[i] == s[cur])cur++;
			lps[i] = cur;
		}
	}
}
int main()
{
	string text;
	cin >> text;
	preprocess(text);
	int len = text.length();
	int idx = -1;
	for (int i = 0; i < len - 1; ++i)
	{
		if(lps[i] == lps[len-1])
		{
			idx = lps[len - 1];
			break;
		}
	}
	if(idx == -1 && lps[len - 1] && lps[lps[len-1] - 1] != 0)idx = lps[lps[len-1] - 1];
	if(!idx)idx = -1;
	if(idx == -1)cout<<"Just a legend\n";
	else
	{
		for (int i = 0; i < idx; ++i)
		{
			cout<<text[i];
		}
	}
}