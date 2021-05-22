// Hash table�� �̿��� ���
// 1. HashTable struct ���� - id, hkey, str
// 2. insertkey, getkey ����
// 3. getkey�� ���� ã���� score�� ���� ��ǥ���� ������Ʈ
// 4. ���� 3�� ��� - ���� ������ ���� ������ ������ 0���� �����Ͽ� �� �������� ������ �ʵ��� ��

#include<iostream>
#include<stdio.h>
using namespace std;

int N;
char str[10000 + 10][20 + 10]; // �ĺ��� �̸�
int M; // ��ǥ�����ο�
char name[100000 + 10][20 + 10]; // ��ǥ������ ���ִ� �̸�
int score[100000 + 10]; // ����

int sum[10000 + 10];

#define MAX_HASH (1<<14)
#define MOD (MAX_HASH-1)

int strcompare(char* a, char* b){
	int i;
	for (i = 0; a[i] && b[i] && (a[i] == b[i]); i++);
	return a[i] - b[i];
}

int calhash(char *str){
	int hash = 5381;
	int c;
	while (c = *str++) hash = (((hash << 5) + hash) + c) & MOD;
	return hash;
}

typedef struct HT{
	int id;
	int hkey;
	char* org;

	HT(){
		id = 0;
		hkey = 0;
		org = NULL;
	}

	HT(int nid, int nk, char* str){
		id = nid;
		hkey = nk;
		org = str;
	}
};
int IDkey;
HT htbl[MAX_HASH];

void insertkey(char *str){ // openaddressing
	int hkey = calhash(str);
	int idx = hkey;
	for (int i = 0; i < MAX_HASH; i++){
		if (htbl[idx].id == 0){ // ���ο� ���ڿ�
			htbl[idx] = HT(++IDkey, hkey, str);
			break;
		}
		idx = (idx + 13) & MOD;
	}
}

int getkey(char *str){
	int hkey = calhash(str);
	int idx = hkey;
	for (int i = 0; i < MAX_HASH; i++){
		if (htbl[idx].id == 0){
			return 0;
		}
		else if ((htbl[idx].hkey == hkey) && (strcompare(htbl[idx].org, str) == 0)){
			return htbl[idx].id; // �̹� �����ϴ� ���ڿ�
		}
		idx = (idx + 13) & MOD;
	}

	return 0;
}

void solve(){
	int key, i;
	for (i = 0; i < N; i++){
		insertkey(str[i]);
	}
	for (i = 0; i < M; i++){
		key = getkey(name[i]);
		if (key) sum[key] += score[i];
	}
}

void InputData(){
	int i;
	cin >> N;
	for (i = 0; i < N; i++){
		cin >> str[i];
	}

	cin >> M;
	for (i = 0; i < M; i++){
		cin >> name[i] >> score[i];
	}
}

void OutputData(){
	int i, j, max, maxIdx;
	for (i = 0; i < 3; i++){
		max = 0;
		maxIdx = 0;
		for (j = 1; j <= N; j++){
			if (max < sum[j]){
				max = sum[j];
				maxIdx = j;
			}
		}
		cout << str[maxIdx - 1] << " " << max << endl;
		sum[maxIdx] = 0;
	}
}

int main(){
	InputData();
	solve();
	OutputData();

	return 0;
}
