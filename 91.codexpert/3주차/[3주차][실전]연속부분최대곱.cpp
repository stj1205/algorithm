#include <iostream>
#include <stdio.h>
using namespace std;

int N;
double D[10000 + 10];


void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> D[i];
	}
}

double SolveN2(){
	double maxv = 0, mul;
	for (int s = 0; s < N; s++){
		mul = 1;
		for (int k = s; k < N; k++){
			mul *= D[k];
			if (maxv < mul) maxv = mul;
		}
	}
	return maxv;
}

double Solve(){
	double maxv = 0, mul = 1;
	for (int i = 0; i < N; i++){
		if (mul <= 1) mul = D[i]; // ���� �� ����� 1 ���ϸ� ���� ����
		else mul *= D[i]; // 1 �ʰ���� ��� ���ϴ°� �̵�

		if (maxv < mul) maxv = mul;
	}
	return maxv;
}

int main(){
	double ans = -1;
	InputData();// �Է¹޴� �κ�

	// ���⼭���� �ۼ�
	ans = Solve();

	printf("%.3lf\n", ans);// ����ϴ� �κ�
	return 0;
}