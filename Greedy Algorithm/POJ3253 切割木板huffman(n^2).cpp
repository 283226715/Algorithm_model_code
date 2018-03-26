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
const int maxn = 2e4+5;
const ll inf = 1e8;

ll a[maxn];

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++){
			scanf("%lld", &a[i]);
		}
		sort(a, a+n);
		int fir = 0, sec = 1;
		ll ans = 0;
		while(n>1){
			if(a[fir]>a[sec]) swap(fir, sec);
			for(int i=0; i<n; i++){
				if(a[i]<a[fir]){
					swap(a[i], a[fir]);
				}
				if(a[i]<a[sec]){
					swap(a[i], a[sec]);
				}
			}
			a[sec] += a[fir];
			ans += a[sec];
			a[fir] = a[n-1];
			n--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
