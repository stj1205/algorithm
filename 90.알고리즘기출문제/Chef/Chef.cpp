// Chef
// ���� Ȯ�� �ð��� �����Ͽ� ���� �� �ִ� �ִ� ������ ���ϴ� ����
// �ݾ��� ���� �� �켱���� �ϹǷ� �ݾ� �������� ���� �� ���� ������ �ð��� ������ �ϴ� ���·� ����

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // �մ� ��
int P[10000 + 10]; // ���� ��
int T[10000 + 10]; // ���� ��� �ð�

int sIndex[10000 + 10]; // ���İ� �������� ������ ���� Index
int sol[10000 + 10]; // ���� Ȯ�� �ð� �� ���� ��

void inputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d %d", &P[i], &T[i]);
	}
}

bool compare(int& a, int& b){
	return P[a] > P[b];
}

int solve(){
	// init sIndex
	for (int i = 0; i < N; i++) sIndex[i] = i;

	// ���İ� �������� �������� sIndex ����
	sort(sIndex, sIndex + N, compare);
	//for (int i = 0; i < N; i++) cout << P[sIndex[i]] << endl;

	for (int i = 0; i < N; i++){
		int rt = T[sIndex[i]]; // ���� Ȯ�� �ð�
		while (rt != 0){
			if (sol[rt] == 0) { // ��� ������ ���İ� ����
				sol[rt] = P[sIndex[i]];
				break;
			}
			else{
				rt--; // ��� ���� ���� ��� ���� �ð� ����(-1)
			}
		}
	}

	// ���� �ð� index �������� �����ϰ� �����Ƿ�
	int sum = 0;
	for (int i = 1; i <= 10000; i++){
		sum += sol[i];
	}

	return sum;

}

int main(){
	int ans = -1;
	inputData();

	// ToDo
	ans = solve();
	cout << ans << endl;

	return 0;
}
