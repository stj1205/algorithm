#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX ((int)2e5) 

int N;
int A[MAX + 10];
int M;
int B[MAX + 10];

void InputData() {
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i<M; i++) {
		scanf("%d", &B[i]);
	}
}

void OutputData() {
	for (int i = 0; i<M; i++) {
		printf("%d ", B[i]);
	}
}

// binearySearch 함수
// 같은 수가 중복되는 경우 가장 처음 나오는 수의 index를 리턴
int bslow(int target){
	int s = 0;
	int e = N - 1;
	int sol = -1;
	while (s <= e){
		int mid = (s + e) / 2;
		if (target < A[mid]) e = mid - 1;
		else if (target > A[mid]) s = mid + 1;
		else{
			sol = mid;
			e = sol - 1;
		}
	}
	return sol;
}

int main(void) {
	// 입력받는 부분 
	InputData();

	// 여기서부터 작성 
	int cnt;
	for (int i = 0; i < M; i++){
		int idx = bslow(B[i]);
		if (idx == -1){
			B[i] = 0;
			continue; // 없을 경우
		}

		// count 구하기
		cnt = 0;
		while (B[i] == A[idx] && idx < N){
			idx++;
			cnt++;
		}
		B[i] = cnt;
	}


	// 출력하는 부분 
	OutputData();
	return 0;
}