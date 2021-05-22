#include <iostream>
using namespace std;

int N;

void InputData(){
	cin >> N;
}

int C[4] = { 500, 100, 50, 10 }; // coin 종류
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
	InputData();// 입력받는 부분
	ans = Solve();
	cout << ans << endl;// 출력하는 부분
	return 0;
}