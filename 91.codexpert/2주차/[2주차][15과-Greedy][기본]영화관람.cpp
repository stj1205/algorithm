// ������ �� �ִ� �ִ� ��ȭ�� ���� ���ϴ� ����
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN ((int)1e5)
int N;//��ȭ��
struct DATA{
	int s, e;//���۽ð�, ����ð�
};
DATA A[MAXN + 10];


void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> A[i].s >> A[i].e;
	}
}
bool compare(DATA& a, DATA& b){
	return a.e < b.e;
}
int Solve(){
	// 1. ������ ���� �������� ����
	sort(A, A + N, compare);

	// 2. �ִ� ��ȭ �� Ȯ��
	int cnt = 0;
	int e = 0; // ���� �ð����� �� ���� ������ ����
	for (int i = 0; i<N; i++){
		if (e < A[i].s){
			cnt++;
			e = A[i].e;
		}
	}
	return cnt;
}

int main(){
	int ans;
	InputData();//�Է�
	ans = Solve();
	cout << ans << endl;//���
	return 0;
}