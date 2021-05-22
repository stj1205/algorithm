// 불우이웃돕기
// 정확하게 N개를 보내면서 최대한 많은 BOX를 보낼 때 BOX의 총 개수와 각 종류별로 몇 BOX를 보내면 되지는 구하는 문제
// 반대로 생각하면 전체개수-N개를 남기면서 가장 적은 BOX를 남기도록 구하는 것과 같다.
#include<iostream>
#include<stdio.h>
using namespace std;

int N; // 보내려는 물품 개수
int C[10]; // BOX 개수(1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10]; // 보내는 BOX 개수

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i<10; i++) scanf("%d", &C[i]);
}

void OutputData(int ans){
	int i;
	printf("%d\n", ans);
	for (i = 0; i<10; i++){
		printf("%d", sol[i]);
	}
	printf("\n");
}

int M[10] = { 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 };
int Solve(){
	// 물품 총 개수 = 보낼 물품 개수(N) + 남길 물품 개수
	// 최소한의 BOX를 남기도록 역으로 변환하여 확인

	// 1. 남길 물품의 개수 확인
	int totCnt = 0; // 물품의 총 개수 확인
	for (int i = 0; i<10; i++){
		totCnt += (M[i] * C[i]);
	}
	int getCnt = totCnt - N; // 남길 물품의 개수

	// 2. 탐욕법에 의한 계산 -> 남길 BOX 확인
	for (int i = 9; i >= 0; i--){
		sol[i] = getCnt / M[i];
		if (sol[i] > C[i]) sol[i] = C[i]; // 제한된 BOX보다 클 경우
		getCnt -= (sol[i] * M[i]);
	}

	// 3. 남길 BOX의 개수를 보낼 BOX의 개수로 변환 및 총 보낼 BOX 개수 구하기
	int totalBox = 0;
	for (int i = 0; i<10; i++){
		sol[i] = C[i] - sol[i];
		totalBox += sol[i];
	}
	return totalBox;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = Solve();

	OutputData(ans);
	return 0;
}