// �ǹ���������
// ������ �ڱ� �ǹ� ���̺��� ���� �ǹ��� ���� �� �� ����
// �ǹ� ���̰� ���ų� ���� �ǹ��� ������ �� �ǹ� ���� �� �ƴ϶� �� �ڿ� ��ġ�� ��� �ǹ� ������ �� �� ����
// �ǹ� ���� N�� �� �ǹ��� ���̰� �־����� ��, �� �ǹ����� �� �� �ִ� ������ �� ���� ���ϴ� ����
// ������ ����� Ȯ���� �߿��ϴٴ� ������ stack ��� �ʿ�
// �ǹ��� �� ���̹Ƿ� long long�� ���
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int N;	// �ǹ� �� - 80000 ����
int H[80010]; // �ǹ� ����

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &H[i]);
	}
}

stack<int> s;
long long solve(){
	long long cnt = 0;

	// �ǹ� ����ŭ Ȯ��
	for (int i = 0; i < N; i++){
		while (!s.empty()){
			int v = s.top();
			if (H[i] < v){ // ������
				cnt += s.size();
				break;
			}
			else{ // ũ�ų� ������
				s.pop();
			}
		}
		s.push(H[i]);
	}

	return cnt;
}

int main(){
	long long ans = -1;
	InputData();

	ans = solve();
	printf("%lld", ans);
	return 0;
}