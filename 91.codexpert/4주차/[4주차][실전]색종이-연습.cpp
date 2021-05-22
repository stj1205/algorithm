// â��ٰ���
// ���� ������ ũ�Ⱑ ���� 10�� ���簢�� ����� ������ ������
// ������ ���� 100 ����
// ����, ������ ũ�Ⱑ ���� 100�� ���簢�� ����� ��� ��ȭ��

#include <iostream>
using namespace std;

int N;
int A[100 + 10];
int B[100 + 10];
void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> A[i] >> B[i];
	}
}

#define MAXN 100
int map[MAXN + 10][MAXN + 10];
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };

void initMap(){
	// ��ȭ�� ������ŭ
	for (int k = 0; k<N; k++){
		for (int i = A[k]; i<A[k] + 10; i++){
			for (int j = B[k]; j<B[k] + 10; j++){
				map[i][j] = 1; // ��ȭ�� ������ 1�� ǥ��
			}
		}
	}
}

int Solve(){
	// 1. map�� ��ȭ�� �׸���
	initMap();

	// 2. map ������ �������� �ѷ��� ���� ���ϱ�
	int slen = 0;
	for (int y = 0; y<MAXN; y++){
		for (int x = 0; x<MAXN; x++){

			if (map[y][x] == 1){ // ĥ���� �����̸�
				// �ֺ� Ȯ�� - �ѷ� ���̸� ���ϱ� ����
				for (int i = 0; i<4; i++){
					int dx = x + mx[i];
					int dy = y + my[i];

					// ������ ���̸� �ѷ� Ȯ�� �ʿ�
					if (dx < 0 || dx >= MAXN || dy < 0 || dy >= MAXN){
						slen++;
						continue;
					}

					if (map[dy][dx] != 1) slen++;
				}
			}
		}
	}
	return slen;
}

int main(){
	int ans = -1;
	InputData();// �Է¹޴� �κ�
	ans = Solve();
	cout << ans << endl;// ����ϴ� �κ�
	return 0;
}