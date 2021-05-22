// ��������ɾ�
// N*N �� ���� ������ LED �ѷ� ����, ��� ����� ��ǥ�� �־����� �� �� ���� ����� �� �ִ� �ִ� ������ ���ϴ� ����
// �ѷ� ���� L�� 10���� �־��� ��� ��� ������ 1X4, 2X3, 3X2, 4X1�� ���� 4���� ������ ���簢���� �ȴ�.
// L/2 = W + H

// N*N ��ü�� ���ؼ� Ȯ���ϴ� ����� N�� �ִ� 10000�� ������ �����Ƿ� �ѷ��� ���� Ȯ�α��� �ϸ� �ð����⵵ ������ �߻��� �� �ִ�.
// ��� ����� ��ǥ�� �������� ������ ��Ƽ� Ȯ���غ��� �ð����⵵�� ���� �� �ִ�.
#include<iostream>
#include <stdio.h>
using namespace std;

int y[110]; // ��� ����� y ��ǥ �迭
int x[110]; // ��� ����� x ��ǥ �迭
int N; // ���� �� ���� ũ��
int L; // LED�� ����(����)
int M; // ��մ���� ����
int sol; // ����

// Timeout -> getCount�� ����
void checkCnt(int r, int c, int h, int w){
	int cnt = 0;
	for (int i = r; i <= r + h; i++){
		for (int j = c; j <= c + w; j++){
			// ��� ���
			for (int k = 0; k < M; k++){
				if (y[k] == i && x[k] == j) cnt++;
			}
		}
	}

	if (sol < cnt) sol = cnt;
}

void getCount(int r, int c, int h, int w){
	int cnt = 0;
	for (int k = 0; k < M; k++){
		if (y[k] >= r && y[k] <= r + h && x[k] >= c && x[k] <= c + w) cnt++;
	}
	if (sol < cnt) sol = cnt;
}

void Solve(){
	//��� ���� ���� �˻�
	int h = 0;
	for (int w = 1; w < L / 2; w++){
		h = L / 2 - w;

		// ��մ����ǥ ���� �˻�
		for (int i = 0; i < M; i++){
			for (int j = 0; j < M; j++){
				// ��ǥ �� ��� ���� �������� �� ���� ��� ����� �ִ��� Ȯ���Ͽ� �ִ� ��� ������ ������Ʈ
				getCount(y[i], x[j], h, w);
			}
		}
	}
}

int main(){
	int i;
	scanf("%d %d %d", &N, &L, &M);
	for (i = 0; i < M; i++){
		scanf("%d %d", &y[i], &x[i]);
	}

	// ToDo
	Solve();

	printf("%d", sol);

	return 0;
}