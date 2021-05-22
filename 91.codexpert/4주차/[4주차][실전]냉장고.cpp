// ��� �����ϱ� ���� �ʿ��� �ּ��� ����� ���ϴ� ���� -> ������
#include <iostream>
#include<algorithm>
using namespace std;

int N;
int X[100 + 10];
int Y[100 + 10];

struct DATA{
	int x;
	int y;
};
DATA D[100 + 10];
bool compare(DATA& a, DATA& b){
	return a.y < b.y;
}

void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> X[i] >> Y[i];
	}
}

int Solve(){
	int cnt = 0;

	// 1. DATA ����ü�� �� �ֱ�
	for (int i = 0; i < N; i++){
		D[i].x = X[i];
		D[i].y = Y[i];
	}

	// 2. y �������� ����
	sort(D, D + N, compare);

	// 3. �ּ��� ����� ���ϱ� - ������ ���ϱ�
	int s = -280;
	int e = -280;
	for (int i = 0; i < N; i++){
		if (e >= D[i].x){ // ��ġ�� ���� �߻�
			// s�� e ����
			if (e > D[i].y) e = D[i].y;
			if (s < D[i].x) s = D[i].x;
		}
		else{ // ��ġ�� ���� �߻����� ����
			cnt++;
			s = D[i].x;
			e = D[i].y;
		}
	}

	return cnt;
}

int main(){
	int ans = -1;

	InputData();// �Է¹޴� �κ�

	// ���⼭���� �ۼ�
	ans = Solve();

	cout << ans << endl;// ����ϴ� �κ�
	return 0;
}