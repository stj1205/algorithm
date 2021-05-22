// N이 최대 100이므로 선형 큐로 구현, Size가 너무 클 경우 원형 큐 사용 필요
// 위와 아래에 대한 카드에 모두 접근해야 하므로 queue를 구현하여 사용 필요하다. 즉, wp-1 위치 및 rp 위치 모두 접근 필요
// STL의 queue는 front()함수를 통한 rp 위치에만 접근 가능
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
	// 1. queue에 push
	for (int i = 1; i <= N; i++) que.push(i);

	// N-1번만큼 수행
	for (int k = 0; k < N - 1; k++){
		// 2. 가장 아래 카드 번호를 2로 나눈 몫의 정수만큼 반복하여 위에 올라와 있는 카드 밑으로 옮김
		int mok = que.back() / 2;
		//cout << que.back() << endl;
		for (int i = 0; i < mok; i++){
			int v = que.front();
			que.pop();
			que.push(v);
		}

		// 3. 옮긴 후 가장 위에 올라와 있는 카드 한장을 넘긴다.
		sol[k] = que.front();
		que.pop();
	}
	// 마지막 남은 카드 처리
	sol[N - 1] = que.front();
	que.pop();
}

int main(){
	InputData();//입력

	//여기서부터 작성
	Solve();

	OutputData();//출력
	return 0;
}