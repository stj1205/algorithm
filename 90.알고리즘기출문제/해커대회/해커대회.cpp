// ��Ŀ��ȸ - linked list�� ����ϴ� ����

#include<stdio.h>
#include<iostream>
using namespace std;

char str[100000 + 10]; // �ʱ� ���ڿ�
char cmd[500000 + 10]; // ��ɾ� ���ڿ�

char result[600000 + 10]; // ��� ���� �迭 - �迭�� �Űܼ� ���

typedef struct NODE{
	char ch;
	NODE* prev;
	NODE* next;
};

NODE* head;
NODE* tail;
NODE* cur;

void left(){
	if (cur->prev != head) cur = cur->prev;
}

void right(){
	if (cur != tail) cur = cur->next;
}

void add(char ch){
	NODE* n = new NODE();
	n->ch = ch;
	n->prev = cur->prev;
	n->next = cur;
	cur->prev->next = n;
	cur->prev = n;
}

void del(){
	if (cur->prev != head){
		cur->prev = cur->prev->prev;
		delete cur->prev->next;
		cur->prev->next = cur;
	}
}

void solve(){

	// init
	head = new NODE();
	tail = new NODE();
	cur = tail;
	head->next = cur;
	cur->prev = head; // �� ������� init ó������� ��!!

	// �ʱ� ���ڿ���  linked list�� ��ȯ
	for (int i = 0; str[i]; i++){
		add(str[i]);
	}

	// cmd ����
	for (int i = 0; cmd[i]; i++){
		switch (cmd[i]){
		case 'L':
			left();
			break;
		case 'R':
			right();
			break;
		case 'B':
			del();
			break;
		default:
			add(cmd[i]);
			break;
		}
	}

	// print
	/*
	cur = head->next;
	while (cur != tail){
		cout << cur->ch;
		cur = cur->next;
	}*/
}

void InputData(){
	scanf("%s", str);
	scanf("%s", cmd);
}

void OutputData(){
	cur = head->next;
	for (int i = 0; cur != tail; i++, cur = cur->next){
		result[i] = cur->ch;
	}
	cout << result << endl;
}

int main(){

	InputData();

	// ToDo
	solve();

	OutputData();

	return 0;
}