#include <bits/stdc++.h>
typedef  long long int lli;
using namespace std;

struct Point {

lli x, y;

bool operator<(Point p)
{
 return x < p.x || (x == p.x && y < p.y);
}
};


lli orientation(Point O, Point A, Point B)
{
return (A.x - O.x) * (B.y - O.y)
 - (A.y - O.y) * (B.x - O.x);
}


vector<Point> convex_hull(vector<Point> A)
{
lli n = A.size(), k = 0;

if (n <= 3)
 return A;

vector<Point> ans( n);


sort(A.begin(), A.end());

for (int i = 0; i < n; ++i) {


 while (k >= 2 && orientation(ans[k - 2],
     ans[k - 1], A[i]) <= 0)
  k--;
 ans[k] = A[i];
 k++;
}


for (size_t i = n - 1, t = k + 1; i > 0; --i) {


 while (k >= t && orientation(ans[k - 2],
     ans[k - 1], A[i - 1]) <= 0)
  k--;
 ans[k] = A[i - 1];
 k++;
}


ans.resize(k-1);

return ans;
}


int main()
{
    lli n;
    cin >>n;
vector<Point> points;
    for(lli i=0;i<n;i++){
        lli a,b;
        cin >> a >> b;
        points.push_back({ a, b });
        
    }

vector<Point> hull = convex_hull(points);

cout << hull.size() <<endl;
cout << "(" << hull[0].x << ", "<< hull[0].y << ")"<< endl;
for (lli i = hull.size()-1; i >=1; i--)
 cout << "(" << hull[i].x << ", "
  << hull[i].y << ")" << endl;

return 0;
}
