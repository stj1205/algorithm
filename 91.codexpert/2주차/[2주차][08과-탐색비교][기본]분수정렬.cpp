// 분수 정렬
// 0과 1 사이의 분수의 분자와 분모의 값이 0 ~ N인 모든 숫자를 작은 수부터 순서대로 배열하는 프로그램 작성
// 값이 겹치는 경우 분모가 작은 값을 선택한다.

#include <iostream>
#include<algorithm>
using namespace std;

#define MAX 1000000
// 메모리를 너무 많이 잡으면 문제 생길 수 있음

int N;//정수 - 160

int index[MAX]; // sorting할 index
double V[MAX]; // 나누어진 결과값 저장하는 배열
int P[MAX]; // 분자
int C[MAX]; // 분모

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
	// i는 분모 - 분모는 0이 나올 수 없으므로 1부터 시작
	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= i; j++){ // 분자
			V[cnt] = (double)j / i;
			P[cnt] = j;
			C[cnt] = i;
			index[cnt] = cnt;
			cnt++;
		}
	}

	// 오름 차순으로 index를 sort
	sort(index, index + cnt, compare);

	// 출력
	//cout << 0 << "/" << 1 << endl;
	double tmp = -1;
	for (int i = 0; i < cnt; i++){
		if (tmp == V[index[i]]) continue;
		cout << P[index[i]] << "/" << C[index[i]] << endl;
		tmp = V[index[i]];
	}
}

int main() {
	InputData();//입력

	//여기서부터 작성
	solve();

	return 0;
}