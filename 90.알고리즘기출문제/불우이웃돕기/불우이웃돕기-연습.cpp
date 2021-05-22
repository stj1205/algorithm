// �ҿ��̿�����
// ��Ȯ�ϰ� N���� �����鼭 �ִ��� ���� BOX�� ���� �� BOX�� �� ������ �� �������� �� BOX�� ������ ������ ���ϴ� ����
// �ݴ�� �����ϸ� ��ü����-N���� ����鼭 ���� ���� BOX�� ���⵵�� ���ϴ� �Ͱ� ����.
#include<iostream>
#include<stdio.h>
using namespace std;

int N; // �������� ��ǰ ����
int C[10]; // BOX ����(1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10]; // ������ BOX ����

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
	// ��ǰ �� ���� = ���� ��ǰ ����(N) + ���� ��ǰ ����
	// �ּ����� BOX�� ���⵵�� ������ ��ȯ�Ͽ� Ȯ��

	// 1. ���� ��ǰ�� ���� Ȯ��
	int totCnt = 0; // ��ǰ�� �� ���� Ȯ��
	for (int i = 0; i<10; i++){
		totCnt += (M[i] * C[i]);
	}
	int getCnt = totCnt - N; // ���� ��ǰ�� ����

	// 2. Ž����� ���� ��� -> ���� BOX Ȯ��
	for (int i = 9; i >= 0; i--){
		sol[i] = getCnt / M[i];
		if (sol[i] > C[i]) sol[i] = C[i]; // ���ѵ� BOX���� Ŭ ���
		getCnt -= (sol[i] * M[i]);
	}

	// 3. ���� BOX�� ������ ���� BOX�� ������ ��ȯ �� �� ���� BOX ���� ���ϱ�
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