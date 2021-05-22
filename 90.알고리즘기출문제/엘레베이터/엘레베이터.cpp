// ���������� - �������� ���ϴ� ����

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // �ǹ��� ����
int X[100 + 10]; // ���� �������� ��ġ
int Y[100 + 10]; // ���� �Һ����� ��ġ

typedef struct NODE{
	int x, y;
}NODE;
NODE F[100 + 10];

//  ���� �� ���� �������� ��ġ�� ���� �����ϵ��� ����
bool compare(NODE& a, NODE& b){
	return a.x < b.x;
}

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d %d", &X[i], &Y[i]);
}

int solve(){
	int cnt = 0;

	// init
	for (int i = 0; i < N; i++){
		F[i].x = X[i];
		F[i].y = Y[i];
	}

	// sort
	sort(F, F + N, compare);

	cnt++;
	int ct = F[0].y;
	for (int i = 1; i < N; i++){
		if (F[i].x > ct){
			cnt++;
			ct = F[i].y;
		}
		else{
			if (F[i].y < ct) ct = F[i].y;
		}
	}
	return cnt;
}

int main()
{
	int ans = -1;
	InputData();

	// ToDo
	ans = solve();

	printf("%d\n", ans);
	return 0;
}