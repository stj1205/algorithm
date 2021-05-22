// ������, ������ ���ϴ� ����
// 1. ���۽ð��� �������� ����
// 2. ������ �ð��� ���� ���� �ð��� ��
// 3. ������ �ð��� ���� �ð��� ��ġ�� ��� �������̹Ƿ� ������ �ð��� ū ������ ����
#include <iostream>
#include<algorithm>
using namespace std;

int N;
int S[10000 + 10];
int E[10000 + 10];
int present;
int absent;

typedef struct ST {
	int s;
	int e;
}ST;
ST student[10000 + 10];

bool compare(ST& a, ST& b) {
	return a.s < b.s;
}

void InputData(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> E[i];
	}
}

void solve() {
	// 1. init
	for (int i = 0; i < N; i++) {
		student[i].s = S[i];
		student[i].e = E[i];
	}

	// 2. ���� �ð� �������� ����
	sort(student, student + N, compare);

	// 3. present & absent ���ϱ�
	int s = student[0].s;
	int e = student[0].e;
	for (int i = 1; i < N; i++) {
		if (e >= student[i].s) { // �̾���
			if (e < student[i].e) e = student[i].e;
			if (present < e - s) present = e - s;
		}
		else { // �̾����� ���� - ����
			if (absent < student[i].s - e) absent = student[i].s - e;
			s = student[i].s;
			e = student[i].e;
		}
	}
}

int main(void) {
	InputData();// �Է¹޴� �κ�

	// ���⼭���� �ۼ�
	solve();

	cout << present << " " << absent << endl;// ����ϴ� �κ�
	return 0;
}