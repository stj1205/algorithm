// 송수신안테나
// N개의 안테나를 일렬로 설치해서 얼마나 송수신이 가능한지 계산하는 문제
// 송수신 안테나 수는 최대 10^5이므로 이중 for문으로는 시간복잡도 문제가 생김 -> O(N)에 가까운 시간복잡도로 해결 필요
// 인접한 아테나의 높이를 고려하여 확인하는 문제로 stack이 사용 필요
#include<iostream>
#include<stack>
using namespace std;

int N; // 송수신 안테나 수
int H[100000 + 10]; // 송수신 안테나 높이

stack<int> s;

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &H[i]);
}

int Solve(){
	int cnt = 0;

	for (int i = 0; i < N; i++){
		while (!s.empty()){
			int v = s.top();
			if (v < H[i]){ // 큰 값이 오는 경우
				s.pop();
				cnt++;
			}
			else if (v == H[i]){ // 같은 경우
				s.pop();
				cnt++; // 처음부터 연속된 값이 들어오는 case를 위해
				break;
			}
			else{ // 작으면 break;
				cnt++;
				break;
			}
		}
		s.push(H[i]);
	}

	return cnt;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = Solve();

	printf("%d\n", ans); // 출력
	return 0;
}