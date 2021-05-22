// ��ȯ����
#include<iostream>
using namespace std;

int N; // N�� 1���� 100
int P; // P�� 2���� 97
void InputData(){
	cin >> N >> P;
}

#define MAXN 1000
int check[MAXN + 10] = { 0, }; // check �Լ� �̿� - �ߺ��� üũ�ϱ� ����
int Solve(){
	int cnt = 0;
	int val = N;
	while (true){
		val = (val*N) % P;
		if (check[val] == 1) break;
		check[val] = 1; // ��� ���� üũ
		cnt++;
	}
	return cnt;
}

int main(){
	int ans = -1;
	InputData();
	ans = Solve();
	cout << ans << endl;
	return 0;
}
