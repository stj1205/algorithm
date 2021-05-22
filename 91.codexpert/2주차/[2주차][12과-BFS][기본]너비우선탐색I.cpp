#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int s[200 + 10];
int e[200 + 10];
int sol[100 + 10];

void InputData()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> s[i] >> e[i];
	}
}
void OutputData()
{
	cout << sol[0];
	for (int i = 1; i<N; i++)
	{
		cout << " " << sol[i];
	}
}

int visit[100 + 10]; // �湮 ��� �迭
vector<int> v[100]; // ������ ��带 ������ �迭
queue<int> q;

void updateMap(){
	for (int i = 1; i <= M; i++){
		v[s[i]].push_back(e[i]);
		v[e[i]].push_back(s[i]); // �ݴ뵵 �־��� - ���� ������ ������ �����Ƿ�
	}
}

void BFS(int target){
	int depth = 0;

	// 1. vector ������ ������Ʈ
	updateMap();

	// 2. BFS ����
	q.push(target);
	visit[target] = 1; // �湮 ó��
	while (!q.empty()){
		int node = q.front();
		sol[depth++] = node;
		q.pop();

		// ������ ��� ���� Ž�� �� �湮
		for (int i = 0; i < v[node].size(); i++){
			if (visit[v[node][i]] == 1) continue; // �湮�Ǿ������� �湮���� ����
			q.push(v[node][i]); // �湮
			visit[v[node][i]] = 1; // �湮 ó��
		}
	}
}

int main()
{
	InputData();// �Է¹޴� �κ�

	// ���⼭���� �ۼ�
	BFS(1); // ������� 1

	OutputData();// ����ϴ� �κ�
	return 0;
}