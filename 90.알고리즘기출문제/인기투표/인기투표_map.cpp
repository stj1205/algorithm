#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N;
char str[10000 + 10][20 + 10]; // 후보자 이름
int M; // 투표참가인원
char name[100000 + 10][20 + 10]; // 투표용지에 써있는 이름
int score[100000 + 10]; // 점수

unordered_map<string, pair<int, int>> _map; // 이름, 사번, 점수
// 정렬 시 필요하기 때문에 사번의 정보를 가짐

// 점수로 1차 정렬, 2차로 사번 순으로 정렬
// 내림 차순 정렬
bool compare(pair<string, pair<int, int>> &a, pair<string, pair<int, int>>& b){
	if (a.second.second == b.second.second) return a.second.first < b.second.first;
	else return a.second.second > b.second.second;
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

void solve(){
	// 1. map에 후보자 이름을 삽입
	for (int i = 0; i < N; i++){
		_map.insert(make_pair(str[i], make_pair(i, 0)));
	}

	// 2. 투표 참가 인원 M 에 대한 후보자 점수 업데이트
	for (int i = 0; i < M; i++){
		auto it = _map.find(name[i]);
		if (it == _map.end()) continue; // 후보자에 없는 경우
		else it->second.second += score[i];
	}

	// 3. score를 기준으로 정렬
	// map을 정렬할 수는 없음에 따라, map의 요소들을 value값을 기준으로 정렬
	// 3-1. map을 vector로 이동
	vector<pair<string, pair<int, int>>> vec(_map.begin(), _map.end());
	// 3-2. vector를 second 기준으로 정렬
	sort(vec.begin(), vec.end(), compare);

	// 4. 상위 3개 출력
	for (int i = 0; i < 3; i++){
		cout << vec[i].first << " " << vec[i].second.second << endl;
	}
}

int main(){
	InputData();
	
	// ToDo
	solve();

	return 0;
}