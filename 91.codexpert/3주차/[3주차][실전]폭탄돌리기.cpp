// ��ź������
// �����̹Ƿ� mod ���
#include<iostream>
using namespace std;

#define MAXN 100

int K; // ó�� ��ź�� ���� ��� ��ȣ
int N; // ���� ����
int T[MAXN + 10]; // �ɸ� �ð�
char Z[MAXN + 10]; // ���� ����
// ��� ���� 8������ ������ ����

void InputData(){
	cin >> K;
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> T[i] >> Z[i];
	}
}

#define MAXH 8
int Solve(){
	int s = K - 1; // 0���� 7�� ��ȯ
	int stime = 0;

	// ���� ����� Ȯ��
	for (int i = 0; i<N; i++){
		// 1. �ð� ���
		stime += T[i];
		if (stime >= 210) break; // 210�ʰ� �������� Ȯ��

		// ���� �����̸� ���� ������� �̵�, ���� �ƴϸ� �״��
		if (Z[i] == 'T') s = (s + 1) % MAXH;
	}
	return s + 1; // 1 ~ 8�� ��ȯ�Ͽ� ����
}

int main(){
	int ans = -1;
	InputData();
	ans = Solve();
	cout << ans << endl;
	return 0;
}