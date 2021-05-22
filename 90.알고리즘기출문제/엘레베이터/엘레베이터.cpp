// 엘레베이터 - 교집합을 구하는 문제

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // 건물의 층수
int X[100 + 10]; // 층별 공급지의 위치
int Y[100 + 10]; // 층별 소비지의 위치

typedef struct NODE{
	int x, y;
}NODE;
NODE F[100 + 10];

//  정렬 시 층별 공급지의 위치에 따라 정렬하도록 수정
bool compare(NODE& a, NODE& b){
	return a.x < b.x;
}

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d %d", &X[i], &Y[i]);
}

int solve(){
	int cnt = 0;

	// init
	for (int i = 0; i < N; i++){
		F[i].x = X[i];
		F[i].y = Y[i];
	}

	// sort
	sort(F, F + N, compare);

	cnt++;
	int ct = F[0].y;
	for (int i = 1; i < N; i++){
		if (F[i].x > ct){
			cnt++;
			ct = F[i].y;
		}
		else{
			if (F[i].y < ct) ct = F[i].y;
		}
	}
	return cnt;
}

int main()
{
	int ans = -1;
	InputData();

	// ToDo
	ans = solve();

	printf("%d\n", ans);
	return 0;
}