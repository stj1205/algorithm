#include <iostream>
using namespace std;
int N; //������ ����
void InputData(){
	cin >> N;
}

int isPossible(int num){
	while (num){
		if (num % 10 == 4) return 0; // 4�� ����
		num = num / 10;
	}
	return 1; // 4�� ����
}

// �Ʒ��� ���� ����� ����ϴ� ��� �ð��ʰ��߻�
int solve1(){
	int cnt = 0;
	for (int i = 1; i <= N; i++){
		if (isPossible(i)) cnt++; // 4 �� �ȵ��� ����
	}
	return cnt;
}

// 4�� ����� 9������ �̿� -> 4���ϸ� �״��, 4 �̻��̸� 1 ���� ���
int solve2(){
	int real = 0;
	int digit = 1;
	while (N){
		int num = N % 10;
		if (num > 4) num -= 1; // 4���� ũ�� 1�� ��������
		real += num * digit;
		N = N / 10;
		digit *= 9;
	}
	return real;
}

int lookup[] = { 0, 1, 2, 3, 0, 4, 5, 6, 7, 8 };
int solve3(){
	int real = 0;
	int digit = 1;
	while (N){
		real += lookup[ N % 10] * digit;
		N = N / 10;
		digit *= 9;
	}
	return real;
}

int main(){
	int ans = -1;
	InputData();//�Է¹޴� �κ�

	//���⼭���� �ۼ�
	// ans = solve1(); // �ð� �ʰ� �߻�
	ans = solve3();

	cout << ans << endl;//����ϴ� �κ�
	return 0;
}