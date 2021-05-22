// DFS - 더하기 문제
// 조합 알고리즘을 활용
// 조합 중 찾으면 return하도록 구현
// depth를 이용하지 않은 이유는 idx가 N을 넘어서면 끝나기 때문
// check에 부분에서 sum에 대한 값을 확인하여 return하며, DFS에 대한 리턴이 있으면 다시 리턴하는 형태로 구현
#include <iostream>
using namespace std;

#define MAXN (20)
int N, K;//자연수 개수, 만들수
int A[MAXN + 10];//자연수 값

char *msg[] = { "NO", "YES" };

void InputData(){
	cin >> N >> K;
	for (int i = 1; i <= N; i++){
		cin >> A[i];
	}
}

// depth 없이 확인
int DFS(int idx, int sum){
	// check
	if (sum == K){ // sum이 K와 같으면
		return 1;
	}
	
	// 조합별 확인
	for (int i = idx; i <= N; i++){
		int ret = DFS(i + 1, sum + A[i]);
		if (ret == 1) return 1;
	}

	return 0;
}

// debug를 위해 depth 추가하여  어떤 수를 출력했는지 저장 및 확인
int dpArr[MAXN + 10];
void printdpArr(int depth){
	for (int i = 1; i < depth; i++){
		cout << dpArr[i] << " ";
	}
	cout << endl;
}
int DFS2(int depth, int idx, int sum){
	// check
	if (sum == K){ // sum이 K와 같으면
		printdpArr(depth);
		return 1;
	}

	// 조합별 확인
	for (int i = idx; i <= N; i++){
		dpArr[depth] = A[i];
		int ret = DFS2(depth+1, i + 1, sum + A[i]);
		if (ret == 1) return 1;
	}

	return 0;
}

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		InputData();//입력

		//여기서부터 작성
		//int ans = DFS(1, 0);
		int ans = DFS2(1, 1, 0);

		cout << msg[ans] << endl;//출력
	}
	return 0;
}