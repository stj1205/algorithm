#include<iostream>
#include<algorithm>
using namespace std;

int N;//����

void InputData(){
	cin >> N;
}

#define MAXN 160
int bj[MAXN * MAXN];
int bm[MAXN * MAXN];

double A[MAXN * MAXN]; // ������
int Aidx[MAXN * MAXN]; // idx

bool compare(int& a, int& b){
	if (A[a] == A[b]){
		return bm[a] < bm[b];
	}
	else{
		return A[a] < A[b];
	}
}

void Solve(){
	int idx = 0;
	// 1. ����� �� �����
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= i; j++){
			bm[idx] = i;
			bj[idx] = j;

			A[idx] = (double)j / i;
			Aidx[idx] = idx;
			idx++;
		}
	}

	// 2. A���� �����ϵ� idx�� ����
	sort(Aidx, Aidx + idx, compare);

	// 3. ���
	cout << "0/1" << endl;
	double prev = 0;
	for (int i = 0; i<idx; i++){
		if (A[Aidx[i]] == prev) continue;
		prev = A[Aidx[i]];
		cout << bj[Aidx[i]] << "/" << bm[Aidx[i]] << endl;
	}
}

int main() {
	InputData();//�Է�

	//���⼭���� �ۼ�
	Solve();

	return 0;
}