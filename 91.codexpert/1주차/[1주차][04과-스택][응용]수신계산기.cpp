// 수식의 연산 결과를 출력하는 문제
// e.g. 1 - 4 * 9 + 10 => -25
#include <iostream>
#include<stack>
using namespace std;

#define MAX (20)
int N;
int M[MAX + 10];
char op[MAX + 10];

stack<int> s;

void InputData(){
	cin >> N;
	cin >> M[0];
	for (int i = 1; i<N; i++){
		cin >> op[i] >> M[i];
	}
}

int solve(){
	// 1. 가장 처음 수 push
	s.push(M[0]);

	// 2. 연산에 따른 push
	int v = 0;
	for (int i = 1; i < N; i++){
		switch (op[i]){
		case '+':
			s.push(M[i]);
			break;
		case '-':
			s.push(-1 * M[i]);
			break;
		case '*':
			v = s.top();
			s.pop();
			s.push(v * M[i]);
			break;
		case '/':
			v = s.top();
			s.pop();
			s.push(v / M[i]);
			break;
		default:
			break;
		}
	}

	// 3. stack에 있는 수 연산
	int sum = 0;
	while (!s.empty()){
		sum += s.top();
		s.pop();
	}

	return sum;
}

int main(){
	int ans = -1;
	InputData();//입력

	//여기서부터 작성
	ans = solve();
	cout << ans << endl;

	return 0;
}