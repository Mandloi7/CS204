//************Palindrome in O(nlgn)*****************


#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	lli n;
	cin >> n;
	vector<string> a, b;
	for(lli i=0; i<n; i++)
	{   
	    string s;
		cin >> s;
		string r = s;
		reverse(r.begin(), r.end());
		if(s != r)
		{
			a.push_back(s);
			b.push_back(r);
		}
	}
	sort(a.begin(), a.end());
	for(lli i=0; i<b.size(); i++)
	{
		if (binary_search(a.begin(), a.end(), b[i]))
		{
			cout << "YES\n";
			return 0;
		}
		
	}
	
	cout << "NO\n";
	return 0;
}
