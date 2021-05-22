#include <iostream>
#include<algorithm>
using namespace std;

int N, C, M;
int S[10000 + 10];
int E[10000 + 10];
int NUM[10000 + 10];

typedef struct DATA{
	int s;
	int e;
	int cnt;
}DATA;
DATA A[10000 + 10];

bool compare(DATA& a, DATA& b){
	return a.e < b.e;
}

void InputData(){
	cin >> N >> C;
	cin >> M;
	for (int i = 0; i<M; i++){
		cin >> S[i] >> E[i] >> NUM[i];
	}
}

int truck[2000 + 10]; // Ʈ������ �� ���� �� ������ ���� BOX �� ����
int Solve(){
	// 1. struct�� ����
	for (int i = 0; i < M; i++){
		A[i].s = S[i];
		A[i].e = E[i];
		A[i].cnt = NUM[i];
	}

	// 2. �޴� ���� �������� ��������
	sort(A, A + M, compare);

	// 3. ���
	int sum = 0;
	// 3-1. �ڽ� ������ ���� �������� Ȯ��
	for (int i = 0; i < M; i++){
		int maxv = 0;
		for (int k = A[i].s; k < A[i].e; k++){
			if (maxv < truck[k]) maxv = truck[k];
		}
		
		// 3-2. �ű� �� �ִ� �ִ� ���� ����
		if (maxv + A[i].cnt <= C) maxv = A[i].cnt;
		else maxv = C - maxv;

		sum += maxv; // �� �ű� �� �ִ� �� update
		// truck �迭 ����
		for (int k = A[i].s; k < A[i].e; k++){
			truck[k] += maxv;
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