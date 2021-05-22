// ������ ���� N(1<=N<=150000)
// ������ �Ϸķ� �þ��� ������ 0���� N-1������ ����
// ������ ���ִ� ���� P(P=�ڿ���, 1<=P<=500)

// ������ �Դ� ��Ģ
// 1. ������ 0�� ���� ������� ������ ���� ������ �����ؾ���
// 2. ù ��°�� ���� ������ ���ڸ�ŭ Ű�� Ŀ��
// 3. �� ��°�� ���� ������ ���ڸ�ŭ Ű�� �۾���
// 4. ��, Ȧ�� ��°�� ���� ������ ���ڸ�ŭ Ŀ���� ¦�� ��°�� ���� ���ڸ�ŭ �۾���

#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int N; // ������ ����
int P[150000 + 10]; //  ���ڸ� ������ �ִ� �迭

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

	// ¦���̸� pop
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