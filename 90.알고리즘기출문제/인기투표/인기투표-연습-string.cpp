#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // 후보자수
char str[10000 + 10][20 + 10]; // 후보자 이름
int M; // 투표참가인원
char name[100000 + 10][20 + 10]; // 투표용지에 써있는 이름
int score[100000 + 10]; // 점수

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

// 1. N명의 str name의 index를 저장하고 있는 배열 생성
int strIdx[10000 + 10]; // 정렬 시 해당 index 배열만 정렬하여 이용
int fScore[10000 + 10] = { 0 }; // N명의 score를 저장할 배열
// 2. bslow를 통한 시간복잡도를 줄이기 위해 아래와 같은 알고리즘 수행
// 2.1. N명의 후보자 이름으로 내림차순 정렬 -> 이를 위해 strcompare 함수 필요
// 2.2. 시간복잡도를 줄이기 위한 bslow 함수 정의

int strcompare(char* a, char* b){
	int i;
	for (i = 0; (a[i] && b[i] && a[i] == b[i]); i++); // 부호식 주의!!
	return a[i] - b[i];
}

bool compare(int& a, int& b){
	// strcompare의 결과를 가지고 return
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
	// 1. strIdx 초기화
	for (int i = 0; i<N; i++){
		strIdx[i] = i;
	}

	// 2. 정렬
	sort(strIdx, strIdx + N, compare); // string을 기반으로 idx 정렬

	// 정렬 확인
	//for(int i=0; i<N; i++){
	//	cout << str[strIdx[i]] << endl;
	//}

	// 3. 찾아서 있으면 score 업데이트
	for (int i = 0; i<M; i++){
		// bslow를 통한 search
		int pos = bslow(name[i]);
		//cout << pos << endl;
		if (pos == -1) continue; // 없으면
		fScore[strIdx[pos]] += score[i];
	}

	// 4. 내림차순 정렬로 상위 3명 출력
	int maxScore = 0;
	int maxIdx = 0;
	for (int i = 0; i<3; i++){
		maxScore = -1;
		maxIdx = -1;
		for (int j = 0; j<N; j++){ // 후보자들에 대해서 비교
			if (maxScore < fScore[j]){ // 같을 경우는 사번 순이므로 업데이트할 필요가 없다.
				maxScore = fScore[j];
				maxIdx = j;
			}
		}

		cout << str[maxIdx] << " " << fScore[maxIdx] << endl;
		fScore[maxIdx] = 0; // 0으로 초기화시켜 선택되지 않도록 함
	}

}

int main(){
	InputData();

	// ToDo
	Solve();

	return 0;
}