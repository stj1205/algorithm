#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // �ĺ��ڼ�
char str[10000 + 10][20 + 10]; // �ĺ��� �̸�
int M; // ��ǥ�����ο�
char name[100000 + 10][20 + 10]; // ��ǥ������ ���ִ� �̸�
int score[100000 + 10]; // ����

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i<N; i++){
		scanf("%s", str[i]);
	}
	scanf("%d", &M);
	for (i = 0; i<M; i++){
		scanf("%s %d", name[i], &score[i]);
	}
}

// 1. N���� str name�� index�� �����ϰ� �ִ� �迭 ����
int strIdx[10000 + 10]; // ���� �� �ش� index �迭�� �����Ͽ� �̿�
int fScore[10000 + 10] = { 0 }; // N���� score�� ������ �迭
// 2. bslow�� ���� �ð����⵵�� ���̱� ���� �Ʒ��� ���� �˰��� ����
// 2.1. N���� �ĺ��� �̸����� �������� ���� -> �̸� ���� strcompare �Լ� �ʿ�
// 2.2. �ð����⵵�� ���̱� ���� bslow �Լ� ����

int strcompare(char* a, char* b){
	int i;
	for (i = 0; (a[i] && b[i] && a[i] == b[i]); i++); // ��ȣ�� ����!!
	return a[i] - b[i];
}

bool compare(int& a, int& b){
	// strcompare�� ����� ������ return
	if (strcompare(str[a], str[b]) < 0) return true;
	else return false;
}

int bslow(char* target){
	int s = 0;
	int e = N - 1;
	while (s <= e){
		int m = (s + e) / 2;
		if (strcompare(target, str[strIdx[m]]) < 0) e = m - 1;
		else if (strcompare(target, str[strIdx[m]]) > 0) s = m + 1;
		else return m;
	}

	return -1;
}

void Solve(){
	// 1. strIdx �ʱ�ȭ
	for (int i = 0; i<N; i++){
		strIdx[i] = i;
	}

	// 2. ����
	sort(strIdx, strIdx + N, compare); // string�� ������� idx ����

	// ���� Ȯ��
	//for(int i=0; i<N; i++){
	//	cout << str[strIdx[i]] << endl;
	//}

	// 3. ã�Ƽ� ������ score ������Ʈ
	for (int i = 0; i<M; i++){
		// bslow�� ���� search
		int pos = bslow(name[i]);
		//cout << pos << endl;
		if (pos == -1) continue; // ������
		fScore[strIdx[pos]] += score[i];
	}

	// 4. �������� ���ķ� ���� 3�� ���
	int maxScore = 0;
	int maxIdx = 0;
	for (int i = 0; i<3; i++){
		maxScore = -1;
		maxIdx = -1;
		for (int j = 0; j<N; j++){ // �ĺ��ڵ鿡 ���ؼ� ��
			if (maxScore < fScore[j]){ // ���� ���� ��� ���̹Ƿ� ������Ʈ�� �ʿ䰡 ����.
				maxScore = fScore[j];
				maxIdx = j;
			}
		}

		cout << str[maxIdx] << " " << fScore[maxIdx] << endl;
		fScore[maxIdx] = 0; // 0���� �ʱ�ȭ���� ���õ��� �ʵ��� ��
	}

}

int main(){
	InputData();

	// ToDo
	Solve();

	return 0;
}