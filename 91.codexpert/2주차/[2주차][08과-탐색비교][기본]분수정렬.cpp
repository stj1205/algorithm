// �м� ����
// 0�� 1 ������ �м��� ���ڿ� �и��� ���� 0 ~ N�� ��� ���ڸ� ���� ������ ������� �迭�ϴ� ���α׷� �ۼ�
// ���� ��ġ�� ��� �и� ���� ���� �����Ѵ�.

#include <iostream>
#include<algorithm>
using namespace std;

#define MAX 1000000
// �޸𸮸� �ʹ� ���� ������ ���� ���� �� ����

int N;//���� - 160

int index[MAX]; // sorting�� index
double V[MAX]; // �������� ����� �����ϴ� �迭
int P[MAX]; // ����
int C[MAX]; // �и�

void InputData(){
	cin >> N;
}

bool compare(int& a, int &b){
	if (V[a] == V[b]){
		return C[a] < C[b];
	}
	else{
		return V[a] < V[b];
	}
}

void solve(){
	int cnt = 0;
	// i�� �и� - �и�� 0�� ���� �� �����Ƿ� 1���� ����
	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= i; j++){ // ����
			V[cnt] = (double)j / i;
			P[cnt] = j;
			C[cnt] = i;
			index[cnt] = cnt;
			cnt++;
		}
	}

	// ���� �������� index�� sort
	sort(index, index + cnt, compare);

	// ���
	//cout << 0 << "/" << 1 << endl;
	double tmp = -1;
	for (int i = 0; i < cnt; i++){
		if (tmp == V[index[i]]) continue;
		cout << P[index[i]] << "/" << C[index[i]] << endl;
		tmp = V[index[i]];
	}
}

int main() {
	InputData();//�Է�

	//���⼭���� �ۼ�
	solve();

	return 0;
}