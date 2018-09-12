//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
using namespace std;

const int maxn = 2005;

char s[maxn];

int  main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("\n%c", &s[i]);
	}
	int lf = 0, rt = n-1;
	int cnt = 0;
	while(lf<=rt){
		int flag;
		for(int i=0; lf+i<=rt; i++){
			if(s[lf+i]<s[rt-i]){
				flag = 1;
				break;
			}
			else if(s[lf+i]>s[rt-i]){
				flag = 0;
				break;
			}
		}
		if(flag) printf("%c", s[lf++]);
		else printf("%c", s[rt--]);
		cnt++;
		if(cnt%80 == 0){
			printf("\n");
		}
	}
	return 0;
}
