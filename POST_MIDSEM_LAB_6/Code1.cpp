//************Palindrome in O(nlgn)*****************


#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	lli n;
	cin >> n;
	vector<string> a, b;
	vector<string> p;
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
		}else{
		    p.push_back(s);
		}
	}
	sort(a.begin(), a.end());
	sort(p.begin(), p.end());
	for(lli i=0; i<b.size(); i++)
	{
		if (binary_search(a.begin(), a.end(), b[i]))
		{
			cout << "YES\n";
			return 0;
		}
		
	}
	for(lli i=0; i<p.size()-1; i++)
	{
		if(p[i]==p[i+1]){
		    cout << "YES\n";
		    return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
