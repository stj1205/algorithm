// NQueen
#include<iostream>
#include<stdio.h>
using namespace std;

int N;

void InputData(){
	cin >> N;
}

#define MAXN (12 + 10)
int sol = 0;
int queen[MAXN][MAXN];

bool check(int y, int x){

	// y 확인
	for (int i = 0; i<y; i++){
		if (queen[i][x] == 1) return false;
	}

	// 왼쪽 대각선 확인
	int i, j;
	for (i = y - 1, j = x - 1; i >= 0 && j >= 0; i--, j--){
		if (queen[i][j] == 1) return false;
	}

	// 오른쪽 대각선 확인
	for (i = y - 1, j = x + 1; i >= 0 && j<N; i--, j++){
		if (queen[i][j] == 1) return false;
	}

	return true;
}

void combination(int depth){
	// check
	if (depth == N){
		sol++;
		return;
	}

	for (int i = 0; i<N; i++){
		if (check(depth, i)){ // 놓을 수 있으면
			queen[depth][i] = 1;
			combination(depth + 1);
			queen[depth][i] = 0;
		}
	}

}

int Solve(){
	combination(0); // depth - 중복허용
	return sol;
}

int main(){
	int ans = 0;
	InputData();
	ans = Solve();
	cout << ans << endl;
	return 0;
}