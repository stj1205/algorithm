// �׸��νĹ���
// N*N ��ȭ���� ���簢�� ������� ��ĥ�� �� -> N�� size�� 4���� 10
// ���� ������ 0���� 9(0�� ��ĥ�� �ȵ�)
// ��ȭ���� ���̴� �� �߿� ��ĥ���� ���� ���� ������ ����ϴ� ����
// ��ĥ�� ���� ������ �����ϴ� �迭�� �̿��Ͽ� Ȯ�� �ʿ� -> ��ĥ���� ���� ���� ��ĥ���� ���� ���� ���� �ʿ�
#include<iostream>
#include<stdio.h>
using namespace std;

int N; // ��ȭ���� ũ��
char A[10 + 2][10 + 2];

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i<N; i++) scanf("%s", A[i]);
}

#define MAXN 10
int check[MAXN];
int Solve(){
	int cnt = 0;
	int minX, minY, maxX, maxY;

	// ���� ���� �������� �˻�
	for (int i = 1; i<10; i++){
		minX = minY = MAXN;
		maxX = maxY = 0;
		// ���� ���ϱ�(���簢���̹Ƿ�)
		for (int y = 0; y<N; y++){
			for (int x = 0; x<N; x++){
				// ���� ������ ��ġ�ϴ� ��� ���� ������Ʈ
				if (A[y][x] - '0' == i){
					if (minX > x) minX = x;
					if (minY > y) minY = y;
					if (maxX < x) maxX = x;
					if (maxY < y) maxY = y;
				}
			}
		}

		// cout << i << minX << " " << maxX << " " << minY << " " << maxY << endl;

		// ��ĥ�� ������ �ִ��� Ȯ��
		if (minX == MAXN) continue; // MAXN�� ���� �̿��� �����̹Ƿ� ���� ������ �ǹ�
		else check[i]++; // ���� ������ 1 �߰� ������Ʈ - ��ĥ���� ���� ������ �и��� ����
		// �߰��� 1�� �ٲٸ� ���� ���� ������ Ȯ���ϸ鼭 ��ĥ�� ���� ������ ���� �� �ִ�.(���� �ʿ�!)
		// Ȥ�� 0���̸� -1�� �����Ͽ� �и��� �ص� �� �� ����. 

		// �� ���� ������ �ٸ� ���� ��ĥ�Ǿ� ������ ��ĥ�Ǿ� �ִ� ���� count�� ����
		for (int y = minY; y <= maxY; y++){ // min ���� max���� �˻�
			for (int x = minX; x <= maxX; x++){
				int col = A[y][x] - '0';
				if (col != i) check[col]++; // ��ĥ�Ǿ� �ִ� ���� count�� ����
			}
		}
	}

	// check �迭�� ���� ��ĥ���� ���� ���� ������ ���
	for (int i = 1; i<10; i++){
		if (check[i] == 1) cnt++;
	}
	return cnt;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = Solve();

	printf("%d\n", ans);
	return 0;
}
