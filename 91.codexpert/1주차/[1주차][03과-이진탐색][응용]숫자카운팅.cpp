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

// binearySearch �Լ�
// ���� ���� �ߺ��Ǵ� ��� ���� ó�� ������ ���� index�� ����
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
	// �Է¹޴� �κ� 
	InputData();

	// ���⼭���� �ۼ� 
	int cnt;
	for (int i = 0; i < M; i++){
		int idx = bslow(B[i]);
		if (idx == -1){
			B[i] = 0;
			continue; // ���� ���
		}

		// count ���ϱ�
		cnt = 0;
		while (B[i] == A[idx] && idx < N){
			idx++;
			cnt++;
		}
		B[i] = cnt;
	}


	// ����ϴ� �κ� 
	OutputData();
	return 0;
}