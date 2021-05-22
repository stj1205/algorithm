// �� ����
// 1. �������� ��ǰ ���� N (N=�ڿ���, 1<=N<=453,320)
// 2. BOX ���� Ci(Ci=����, 0 <= Ci <= 20)

// �������� ��ǰ ���� N�� �� ������ BOX ���� Ci�� �־��� ��,
// ��Ȯ�ϰ� N���� �����鼭�� �ִ��� ���� BOX�� ���� �� BOX�� �� ������ �� ���� ���� �� BOS�� ������ �Ǵ��� ���Ͻÿ�.

// �ִ��� ���� BOX�� ���� �ٴ� ���� ���� �ݾ׺��� ���� �����ٴ� �ǹ�
// greedy �˰��� ���� ū �ݾ׺��� Ȯ�� �ʿ�
// �ݴ�� �����ϸ� N�� BOX(��ü BOX ���� - ���� ����)�� �ּ��� BOX�� ���� �� �ִ� �Ͱ� ���� -> ū �ݾ׺��� �ִ��� ���� BOX�� �������� ��

#include<iostream>
#include<stdio.h>
using namespace std;

int N; // �������� ��ǰ ����
int M[10] = { 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 }; // �ݾ� - �ݾ��� ������ �� greedy ������ ������
int C[10]; // BOX ����
int sol[10]; // �������� BOX ����

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

	// �ڽ��� ������ ����
	int sum = 0;
	for (int i = 0; i < 10; i++){
		sum += (M[i] * C[i]);
	}

	// ���� �ڽ��� ������ ����
	sum -= N;

	// Box ó�� - ū �ݾ׺��� Ȯ�� �ʿ�
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