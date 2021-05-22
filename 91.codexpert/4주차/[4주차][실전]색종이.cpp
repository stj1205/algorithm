// ����, ������ ũ�Ⱑ ���� 100 -> ������ ��� Ȯ���ص� �ð� ���⵵�� �������� �ʴ´�
// ����, ������ ũ�Ⱑ ���� 10�� ���簢�� ����� ������ ����
// �ٱ� �ѷ��� ��� max, min�� ���ϸ� ���� ���� �� ������ ��� ��ġ�� ���� ���� �ѷ��� ���ϱ� �����
// ��, ��ȭ���� �迭�� ǥ���ϰ� ������ 1�� ���� -> 1 �ֺ� Ȯ���Ͽ� ������ ����ų� 0�� ��� �ѷ� ���� ������Ʈ
#include <iostream>
using namespace std;

#define MAXN 100

int N;
int A[100 + 10];
int B[100 + 10];

int D[MAXN + 10][MAXN + 10]; // ��ȭ��
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };

void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> A[i] >> B[i];
	}
}

void printD(){
	for (int y = 0; y < MAXN; y++){
		for (int x = 0; x < MAXN; x++){
			cout << D[y][x];
		}
		cout << endl;
	}
}

int Solve(){
	// 1. ��ȭ���� �� ���� ������
	for (int i = 0; i < N; i++){
		// y��ǥ-x��ǥ�� ���ؼ� �� ���� ����
		for (int y = B[i]; y < B[i] + 10 && y < MAXN; y++){
			for (int x = A[i]; x < A[i] + 10 && x < MAXN; x++){
				D[y][x] = 1;
			}
		}
	}

	// 2. �ѷ� ���� ���ϱ�
	int sum = 0;
	for (int y = 0; y < MAXN; y++){
		for (int x = 0; x < MAXN; x++){
			
			// �� ������ �ִ� ��� �����¿� Ȯ��
			if (D[y][x] == 1){
				for (int i = 0; i < 4; i++){
					int dx = x + mx[i];
					int dy = y + my[i];

					if (dx < 0 || dx >= MAXN || dy < 0 || dy >= MAXN) sum++;
					else if (D[dy][dx] == 0) sum++;
				}
			}

		}
	}

	return sum;
}

int main(){
	int ans = -1;

	InputData();// �Է¹޴� �κ�

	// ���⼭���� �ۼ�
	ans = Solve();

	cout << ans << endl;// ����ϴ� �κ�
	return 0;
}