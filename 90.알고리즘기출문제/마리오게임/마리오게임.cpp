// 버섯의 개수 N(1<=N<=150000)
// 버섯은 일렬로 늘어져 있으며 0부터 N-1번까지 있음
// 버섯에 써있는 숫자 P(P=자연수, 1<=P<=500)

// 버섯을 먹는 규칙
// 1. 버섯은 0번 부터 순서대로 먹을지 먹지 않을지 결정해야함
// 2. 첫 번째로 먹은 버섯의 숫자만큼 키가 커짐
// 3. 두 번째로 먹은 버섯의 숫자만큼 키가 작아짐
// 4. 즉, 홀수 번째로 먹은 버섯의 숫자만큼 커지고 짝수 번째로 먹은 숫자만큼 작아짐

#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int N; // 버섯의 개수
int P[150000 + 10]; //  숫자를 가지고 있는 배열

stack<int> s;

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i];
}

int solve(){
	int res = 0;

	s.push(P[0]);
	for (int i = 1; i < N; i++){
		int v = s.top();
		if (s.size() % 2 == 0){
			if (P[i] > v) s.push(P[i]);
			else{
				s.pop(); 
				s.push(P[i]);
			}
		}
		else{ // s.size()%2 == 1
			if (P[i] < v) s.push(P[i]);
			else{
				s.pop();
				s.push(P[i]);
			}
		}
	}

	// 짝수이면 pop
	if (s.size() % 2 == 0) s.pop();

	while (!s.empty()){
		int v = s.top();
		if (s.size() % 2 == 1) res += v;
		else res -= v;
		s.pop();
	}

	return res;
}

int main()
{
	int ans = -1;

	InputData();

	ans = solve();
	cout << ans << endl;
	return 0;
}