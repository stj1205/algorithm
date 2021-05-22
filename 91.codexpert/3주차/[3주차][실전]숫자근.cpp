// 숫자근
// n개의 정수가 입력되면 숫자근이 가장 큰 값을 찾는 프로그램을 작성하시오.
#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N;//정수개수
int A[MAXN + 10];//입력 정수
int sol[MAXN + 10]; // 숫자근을 저장할 배열
void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> A[i];
	}
}

int getRoot(int v){
	int num = v;
	int root = 0;
	if (num < 10) root = num;
	else{
		while (true){
			while (num != 0){
				root += num % 10;
				num = num / 10;
			}
			if (root < 10) return root;
			else{
				num = root;
				root = 0;
			}
		}
	}
	return root;
}

int Solve(){
	// 1. 모든 값의 숫자근을 구함
	for (int i = 0; i<N; i++){
		sol[i] = getRoot(A[i]);
	}

	// 2. 가장 큰 숫자근을 가지는 값 리턴
	// 단, 가장 큰 숫자근이 여러 개이면 그 중 가장 작은 수를 출력한다.
	int maxv = 0;
	int maxIdx = 0;
	for (int i = 0; i<N; i++){
		if (maxv < sol[i]){
			maxv = sol[i];
			maxIdx = i;
		}
		else if (maxv == sol[i]){
			if (A[i] < A[maxIdx]) maxIdx = i;
		}
	}
	return A[maxIdx];
}

int main(){
	int ans = -1;
	InputData();//입력 받는 부분
	//여기서부터 작성
	ans = Solve();
	cout << ans << endl;//출력하는 부분
	return 0;
}
