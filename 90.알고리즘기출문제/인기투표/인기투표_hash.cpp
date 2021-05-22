// Hash table을 이용한 방법
// 1. HashTable struct 생성 - id, hkey, str
// 2. insertkey, getkey 구현
// 3. getkey를 통해 찾으면 score를 통해 투표점수 업데이트
// 4. 상위 3명 출력 - 뽑을 때마다 뽑은 아이의 점수는 0으로 갱신하여 그 다음에는 뽑히지 않도록 함

#include<iostream>
#include<stdio.h>
using namespace std;

int N;
char str[10000 + 10][20 + 10]; // 후보자 이름
int M; // 투표참가인원
char name[100000 + 10][20 + 10]; // 투표용지에 써있는 이름
int score[100000 + 10]; // 점수

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
		if (htbl[idx].id == 0){ // 새로운 문자열
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
			return htbl[idx].id; // 이미 존재하는 문자열
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
