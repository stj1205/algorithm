// 행복한 수
#include<iostream>
#include<cmath>
using namespace std;

int N;

void InputData(){
	cin >> N;
}

#define MAXN 1000
int getNi(int x){
	int num = x;
	int cv = 0;
	while (num != 0){
		cv += pow(num % 10, 2);
		num = num / 10;
	}
	return cv;
}

bool isHappyNum(int x){
	int val = x;
	int check[MAXN + 10] = { 0, };

	while (true){
		int i = getNi(val);
		if (i == 1) return true;
		if (check[i] == 1) break; // false
		check[i] = 1;
		val = i;
	}
	return false;
}

int Solve(){
	int i;
	for (i = N; i >= 0; i--){
		if (isHappyNum(i)) break;
	}
	return i;
}

int main(){
	int ans = -1;
	InputData();//입력받는 부분
	ans = Solve();
	cout << ans << endl;//출력하는 부분
	return 0;
}
