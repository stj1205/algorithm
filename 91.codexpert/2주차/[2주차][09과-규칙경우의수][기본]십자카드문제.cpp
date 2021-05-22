// ����ī�幮��
// 1. �ð���� ���ϰ�
// ��� �ð� ���� �߿��� �� ��°�� ���� �ð� �������� �˾Ƴ��� ���α׷��� �ۼ�
#include <iostream>
using namespace std;

int num[4];//�Էµ� ī�� ��ȣ

void InputData(){
	for (int i = 0; i < 4; i++) {
		cin >> num[i];
	}
}

void divide(int n, int* arr){
	for (int i = 3; i >= 0; i--){
		arr[i] = n % 10;
		n = n / 10;
	}
}

int getClockNum(int* arr){
	int val = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	int clknum = val;
	for (int i = 0; i<3; i++){
		// �ð�� ��ȯ
		val = (val % 10) * 1000 + val / 10;
		if (clknum > val) clknum = val;
	}
	return clknum;
}

int Solve(){
	// 1. �ð�� Ȯ��
	int val = getClockNum(num);

	// 2. cnt Ȯ��
	int cnt = 1;
	int arr[4];
	for (int i = 1111; i<val; i++)
	{
		divide(i, arr); // arr�� ��ȯ
		if (getClockNum(arr) == i) cnt++; // �ð���̸� cnt++
	}
	return cnt;
}

int main() {
	int ans;
	InputData();//�Է�
	ans = Solve();
	cout << ans << endl;//���
	return 0;
}