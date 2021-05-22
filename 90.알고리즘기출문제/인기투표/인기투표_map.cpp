#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N;
char str[10000 + 10][20 + 10]; // �ĺ��� �̸�
int M; // ��ǥ�����ο�
char name[100000 + 10][20 + 10]; // ��ǥ������ ���ִ� �̸�
int score[100000 + 10]; // ����

unordered_map<string, pair<int, int>> _map; // �̸�, ���, ����
// ���� �� �ʿ��ϱ� ������ ����� ������ ����

// ������ 1�� ����, 2���� ��� ������ ����
// ���� ���� ����
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
	// 1. map�� �ĺ��� �̸��� ����
	for (int i = 0; i < N; i++){
		_map.insert(make_pair(str[i], make_pair(i, 0)));
	}

	// 2. ��ǥ ���� �ο� M �� ���� �ĺ��� ���� ������Ʈ
	for (int i = 0; i < M; i++){
		auto it = _map.find(name[i]);
		if (it == _map.end()) continue; // �ĺ��ڿ� ���� ���
		else it->second.second += score[i];
	}

	// 3. score�� �������� ����
	// map�� ������ ���� ������ ����, map�� ��ҵ��� value���� �������� ����
	// 3-1. map�� vector�� �̵�
	vector<pair<string, pair<int, int>>> vec(_map.begin(), _map.end());
	// 3-2. vector�� second �������� ����
	sort(vec.begin(), vec.end(), compare);

	// 4. ���� 3�� ���
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