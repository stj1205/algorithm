// �ɸ��н���
// �ĺ��� �� N�� �ĺ����� ���� �� Ai�� �־��� ��, ���� �� ���� 0�� ���� ����� �� �ĺ��ڸ� ã�Ƽ� ��ȣ�� ����Ͻÿ�
// �Է��� ������ ������������ �־�����, 0�� ���� ����� ������ ���� �� ���� ��� ���� �Էµ� ����� ������ ���̴�.

// ���� for������ �ϳ��� ���� Ȯ���ϴ� ��� �ð� ���⵵ O(N^2)���� ���Ͽ� Timeout�߻� -> �ð� ���⵵�� O(N)�� �������ϴ� �˰��� Ȯ�� �ʿ�
#include<stdio.h>
#include<iostream>
using namespace std;

int N; // �ĺ��� ��
int A[100000 + 10]; // ���� ��
int maxSum = 1000000000;

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);
}

int ABS(int num){
	return (num < 0) ? -num : num;
}

void Solve(){
	int num1 = N - 1;
	int num2 = N - 1; // �ĺ���

	int i = 0;
	int j = N - 1; // index
	int sum = 0;

	while (i < j){
		sum = A[i] + A[j];
		// sum�� ����
		if (ABS(sum) < maxSum){
			num1 = i;
			num2 = j;
			maxSum = ABS(sum);
		}

		if (sum < 0) i++;
		else if (sum > 0) j--;
		else break; // 0�̸� ���� ���� ����̹Ƿ�
	}

	cout << num1 << " " << num2 << endl;
}

int main()
{
	InputData();

	// ToDo
	Solve();

	return 0;
}