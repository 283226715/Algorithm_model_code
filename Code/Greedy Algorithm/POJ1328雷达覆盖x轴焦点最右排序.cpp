//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
using namespace std;

typedef long long ll;
const int maxn = 1e3+5;
const ll inf = 1e8;

pair<double, double> p[maxn];

int main(){
	int n;
	double d;
	int cas = 1;
	while(scanf("%d%lf", &n, &d) == 2 && n && d) {
		int flag = 0;
		double d2 = d*d;
		for(int i=0; i<n; i++){
			double a, b; 
			scanf("%lf%lf", &a, &b);
			double tmp = sqrt(d2-b*b);
			p[i].second = a-tmp;
			p[i].first = a+tmp;
			if(b>d){
				flag = 1;
			}
		}
		if(flag){
			printf("Case %d: -1\n", cas++);
			continue;
		}
		sort(p, p+n);
		int ans = 1;
		double ed = p[0].first;
		for(int i=1; i<n; i++){
			if(p[i].second>ed){
				ed = p[i].first;
				ans++;
			}
		}
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}

