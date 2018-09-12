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
using namespace std;

typedef long long ll;
const int maxn = 3e4+5;
const ll inf = 1e8;

pair<int, int> p[maxn];

int main(){
	int n, t;
	while(scanf("%d%d", &n, &t) == 2) {
		for(int i=0; i<n; i++){
			scanf("%d%d", &p[i].first, &p[i].second);
		}
		sort(p, p+n);
		int ans = 0;
		int st = 0, ed = 0;
		p[n].first= inf;
		int flag = 0;
		for(int i=0; i<n; i++){
			if(p[i].first<=st+1){
				if(p[i].second>ed){
					ed = p[i].second;
					flag = 1;
				}
				//和上一段连不起来的一定是属于另一个连续段的 
				if(p[i+1].first>st+1 && flag){
					ans++;
					st = ed;
					flag = 0;
				}
			}
		}
		if(ed<t){
			printf("-1\n");
		}
		else{
			printf("%d\n", ans);
		}
	}
	return 0;
}

