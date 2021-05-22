// [2����][10��-�������ϰ���][����] â��ٰ���
// ù �ٿ��� ����� ������ ��Ÿ���� ���� N�� �־�����. N�� 1�̻� 1,000 ���� �̴�. 
// �� ���� N���� �ٿ��� �� ���� ����� ���� ���� ��ġ�� ��Ÿ���� ���� L�� ���̸� ��Ÿ���� ���� H�� �� ���� �� ĭ�� ���̿� �ΰ� �־�����. L�� H�� �� �� 1 �̻� 1,000 ���� �̴�.
// ù �ٿ� â�� �ٰ����� ������ ��Ÿ���� ������ ����Ѵ�.

#include <iostream>
#include <algorithm>
using namespace std;

int N;//����� ����
struct POLE {
	int L, H;//����� ���� ���� ��ġ, ��� ����
};
POLE pole[1000 + 10];

// ���̰� ū ������� ����
bool compare(POLE& a, POLE& b){
	return a.H > b.H;
}

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pole[i].L >> pole[i].H;
	}
}

int solve(){
	int area = 0;
	int min;
	int max;

	// ���� �������� sort
	sort(pole, pole + N, compare);

	min = pole[0].L;
	max = min + 1;
	area = pole[0].H;
	for (int i = 1; i<N; i++){
		if (max <= pole[i].L){ // L max ���� ����
			area += pole[i].H * (pole[i].L + 1 - max);
			max = pole[i].L + 1;
		}
		else if (min > pole[i].L){
			area += pole[i].H * (min - pole[i].L);
			min = pole[i].L;
		}
	}

	return area;
}

int main() {
	int ans;
	InputData();//�Է�

	//���⼭���� �ۼ�
	ans = solve();

	cout << ans << endl;//���
	return 0;
}