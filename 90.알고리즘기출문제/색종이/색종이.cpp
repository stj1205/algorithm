// ������
// N * N ũ���� ��� ��ȭ���� �ִ� 9���� �����̸� ���簢�� ������� ���δ�.
// �����̰� ���� ���� ������ �κ��� ���� õ����� ������ �ȴ�.
// �� ���� õ����� ���� �� �ִ� �������� �ִ� ����� ���Ͻÿ�

// ��ȭ���� ũ�� N(N�� ����, 4<=N<10)
// �� ������ 0���� 9���� ������ 0�� ������̹Ƿ� ���� ���� 1~9

// char�� input�� �޾����Ƿ� int�� �����ϱ� ���ؼ��� A[i][j] - '0'�� ������ �ʿ���
// min, max�� ���� ������ ���ϰ� �ִ� ��ġ�� ������ ������ ���ϴ� ����

#include<iostream>
using namespace std;

int N; // ��ȭ�� ũ��
char A[10 + 2][10 + 2]; // ��ȭ�� �� ����

int cnt[10 + 2][10 + 2]; // ��ĥ�� ��ȭ�� ����

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

int solve(){
	for (int i = 1; i <= 9; i++){
		// �� ������ ���� minX, maxX, minY, maxY�� ���Ѵ�.
		int minX = 100;
		int maxX = 0;
		int minY = 100;
		int maxY = 0;

		for (int y = 0; y < N; y++){
			for (int x = 0; x < N; x++){
				// �� ������ ��ġ�ϴ� ���
				if (A[y][x] - '0' == i){
					// min/max ��ǥ ������Ʈ
					if (minX > x) minX = x;
					if (maxX < x) maxX = x;
					if (minY > y) minY = y;
					if (maxY < y) maxY = y;
				}
			}
		}

		// �ش� ��ǥ�� +1�� �� ���� ĥ�ϱ�
		for (int y = minY; y <= maxY; y++){
			for (int x = minX; x <= maxX; x++){
				cnt[y][x]++;
			}
		}
	}

	int res = 0;
	for (int y = 0; y < N; y++){
		for (int x = 0; x < N; x++){
			if (cnt[y][x] > res) res = cnt[y][x];
		}
	}
	return res;
}

int main(){
	int ans = -1;
	InputData();

	// To Do
	ans = solve();

	cout << ans << endl;
	return 0;
}