// 십자카드문제
// 1. 시계수를 구하고
// 모든 시계 수들 중에서 몇 번째로 작은 시계 수인지를 알아내는 프로그램을 작성
#include <iostream>
using namespace std;

int num[4];//입력된 카드 번호

void InputData(){
	for (int i = 0; i < 4; i++) {
		cin >> num[i];
	}
}

void divide(int n, int* arr){
	for (int i = 3; i >= 0; i--){
		arr[i] = n % 10;
		n = n / 10;
	}
}

int getClockNum(int* arr){
	int val = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	int clknum = val;
	for (int i = 0; i<3; i++){
		// 시계수 변환
		val = (val % 10) * 1000 + val / 10;
		if (clknum > val) clknum = val;
	}
	return clknum;
}

int Solve(){
	// 1. 시계수 확인
	int val = getClockNum(num);

	// 2. cnt 확인
	int cnt = 1;
	int arr[4];
	for (int i = 1111; i<val; i++)
	{
		divide(i, arr); // arr로 변환
		if (getClockNum(arr) == i) cnt++; // 시계수이면 cnt++
	}
	return cnt;
}

int main() {
	int ans;
	InputData();//입력
	ans = Solve();
	cout << ans << endl;//출력
	return 0;
}