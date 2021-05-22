// 값 범위
// 1. 보내려는 물품 개수 N (N=자연수, 1<=N<=453,320)
// 2. BOX 개수 Ci(Ci=정수, 0 <= Ci <= 20)

// 보내려는 물품 개수 N과 각 종류의 BOX 개수 Ci가 주어질 때,
// 정확하게 N개를 보내면서도 최대한 많은 BOX를 보낼 때 BOX의 총 개수와 각 종류 별로 몇 BOS를 보내면 되는지 구하시오.

// 최대한 많은 BOX를 보낸 다는 것은 적은 금액부터 많이 보낸다는 의미
// greedy 알고리즘에 따라 큰 금액부터 확인 필요
// 반대로 생각하면 N개 BOX(전체 BOX 개수 - 보낼 개수)를 최소의 BOX로 남길 수 있는 것과 같다 -> 큰 금액부터 최대한 많이 BOX를 가져가면 됨

#include<iostream>
#include<stdio.h>
using namespace std;

int N; // 보내려는 물품 개수
int M[10] = { 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 }; // 금액 - 금액을 보았을 때 greedy 문제로 보여짐
int C[10]; // BOX 개수
int sol[10]; // 보내려는 BOX 개수

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < 10; i++) scanf("%d", &C[i]);
}

void OutputData(int ans){
	int i;
	printf("%d\n", ans);
	for (i = 0; i < 10; i++){
		printf("%d ", sol[i]);
	}
	printf("\n");
}

int solve(){
	int ret = 0;

	// 박스의 총합을 구함
	int sum = 0;
	for (int i = 0; i < 10; i++){
		sum += (M[i] * C[i]);
	}

	// 남길 박스의 개수로 수정
	sum -= N;

	// Box 처리 - 큰 금액부터 확인 필요
	for (int k = 9; k >= 0; k--){
		int n = C[k];
		if (n == 0) continue;
		while (sum / (n * M[k]) < 1){
			n--;
			if (n == 0) break;
		}

		sum -= (M[k] * n);
		sol[k] = C[k] - n;
	}

	for (int j = 0; j < 10; j++){
		ret += sol[j];
	}
	return ret;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = solve();
	OutputData(ans);

	return 0;
}