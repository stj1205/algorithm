// 디스플레이 필터
// 필터의 수 N, 반사 정도 R, 투과 정도 P
// 디스플레이에 반드시 하나 이상의 필터는 장착되야 한다.
// 최적의 가시성과 두께를 위해 제거해야 할 필터의 최대 개수를 구하는 문제 -> 몇 개를 선택해야 하는지로 생각할 수 있다. -> 조합문제
// 반사 정도와 투과 정도의 차가 0에 가장 가까울 때 최고의 성능을 낸다.
#include<iostream>
using namespace std;

int N; // 필터의 수
int R[11]; // 반사의 정도
int P[11]; // 투과의 정도

long long sum = 1000000000;
int minCnt = 100;

long long ABS(long long num){
	return (num < 0) ? -num : num;
}

void InputData(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> R[i] >> P[i];
	}
}

// print depth
int dpArr[11] = { 0 };
void printDepth(int* arr, int len){
	for (int i = 0; i < len; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void DFS(int cnt, long long r, long long p, int idx){
	// check - 개수에 따른 반사 정도와 투과 정도의 차이 확인
	if (cnt != 0){ 
		if (sum > ABS(r - p)){ 
			sum = ABS(r - p);
			minCnt = cnt;
		}
		else if (sum == ABS(r - p)){ // 같은 경우는 cnt가 작은 것을 저장한다
			if (cnt < minCnt) minCnt = cnt;
		}
	}

	// printDepth
	// if (idx == N+1) printDepth(dpArr, cnt);

	// DFS 수행
	for (int i = idx; i <= N; i++){
		// dpArr[cnt] = i;
		DFS(cnt + 1, r * R[i], p + P[i], i + 1);
	}

}

// 이진트리 형식으로 해결
void DFS_BT(int cnt, long long r, long long p, int idx){
	// check - 개수에 따른 반사 정도와 투과 정도의 차이 확인
	if (cnt != 0){
		if (sum > ABS(r - p)){
			sum = ABS(r - p);
			minCnt = cnt;
		}
		else if (sum == ABS(r - p)){ // 같은 경우는 cnt가 작은 것을 저장한다
			if (cnt < minCnt) minCnt = cnt;
		}
	}

	// DFS 수행 - 이진트리형식
	if (idx <= N){
		DFS(cnt + 1, r * R[idx], p + P[idx], idx + 1);
		DFS(cnt, r, p, idx + 1);
	}
}

int main(){

	int ans = -1;
	InputData(); // 입력

	// ToDo
	//DFS(0, 1, 0, 1);
	DFS_BT(0, 1, 0, 1);
	ans = N - minCnt;

	printf("%d\n", ans); // 출력
	return 0;
}