#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	double d;
	scanf("%lf", &d);
	double ans = max(d * sqrt(2.0), floor(d) + 1);
	printf("%.12lf\n", ans);
	return 0;
}
/*ok*/
