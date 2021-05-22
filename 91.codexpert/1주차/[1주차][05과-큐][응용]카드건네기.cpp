// N�� �ִ� 100�̹Ƿ� ���� ť�� ����, Size�� �ʹ� Ŭ ��� ���� ť ��� �ʿ�
// ���� �Ʒ��� ���� ī�忡 ��� �����ؾ� �ϹǷ� queue�� �����Ͽ� ��� �ʿ��ϴ�. ��, wp-1 ��ġ �� rp ��ġ ��� ���� �ʿ�
// STL�� queue�� front()�Լ��� ���� rp ��ġ���� ���� ����
#include <iostream>
using namespace std;

#define MAXN (100)
int N;
int sol[MAXN + 10];

typedef struct QUEUE{
	int wp;
	int rp;
	//int size;
	int q[MAXN * MAXN + 10];

	bool empty(){
		if (wp == rp) return true;
		else return false;
	}
	void push(int v){ q[wp++] = v; }
	int front() { return q[rp]; }
	void pop() { rp++; }
	int back(){ return q[wp - 1]; }
}QUEUE;

QUEUE que;

void InputData(){
	cin >> N;
}

void OutputData(){
	for (int i = 0; i<N; i++){
		cout << sol[i] << endl;
	}
}

void Solve(){
	// 1. queue�� push
	for (int i = 1; i <= N; i++) que.push(i);

	// N-1����ŭ ����
	for (int k = 0; k < N - 1; k++){
		// 2. ���� �Ʒ� ī�� ��ȣ�� 2�� ���� ���� ������ŭ �ݺ��Ͽ� ���� �ö�� �ִ� ī�� ������ �ű�
		int mok = que.back() / 2;
		//cout << que.back() << endl;
		for (int i = 0; i < mok; i++){
			int v = que.front();
			que.pop();
			que.push(v);
		}

		// 3. �ű� �� ���� ���� �ö�� �ִ� ī�� ������ �ѱ��.
		sol[k] = que.front();
		que.pop();
	}
	// ������ ���� ī�� ó��
	sol[N - 1] = que.front();
	que.pop();
}

int main(){
	InputData();//�Է�

	//���⼭���� �ۼ�
	Solve();

	OutputData();//���
	return 0;
}