#include <iostream>
using namespace std;

int N;

void InputData(){
	cin >> N;
}

int C[4] = { 500, 100, 50, 10 }; // coin ����
int Solve(){
	int cnt = 0;
	for (int i = 0; i<4; i++){
		cnt += (N / C[i]);
		N = (N%C[i]);
	}
	return cnt;
}

int main(){
	int ans = 0;
	InputData();// �Է¹޴� �κ�
	ans = Solve();
	cout << ans << endl;// ����ϴ� �κ�
	return 0;
}