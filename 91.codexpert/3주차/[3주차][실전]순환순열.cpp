// 순환순열
#include<iostream>
using namespace std;

int N; // N은 1부터 100
int P; // P는 2부터 97
void InputData(){
	cin >> N >> P;
}

#define MAXN 1000
int check[MAXN + 10] = { 0, }; // check 함수 이용 - 중복을 체크하기 위함
int Solve(){
	int cnt = 0;
	int val = N;
	while (true){
		val = (val*N) % P;
		if (check[val] == 1) break;
		check[val] = 1; // 사용 여부 체크
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
