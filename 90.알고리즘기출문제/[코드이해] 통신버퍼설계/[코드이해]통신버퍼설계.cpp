#include <iostream>
using namespace std;

typedef struct st
{
	int packet_no;
	int prior_level;
	struct st *next;
}PACKET;

PACKET buffer;
PACKET *last_packet;

void Input_Packet(PACKET& p)
{
	cin >> p.packet_no >> p.prior_level; // packet_no, prior_level �Է�
}

#define SUCCESS				(0)
#define ERROR_PUT_PACKET	(-1)
#define ERROR_BUF_EMPTY		(-2)

int Put_Packet_to_Buffer(PACKET& p)
{
	PACKET *pac;

	pac = new PACKET();

	*pac = p;

	// p�� ����ϸ� loop�� ���� �߻�!! -> pac�� ����ؾ� �Ѵ�.
	if (buffer.next == (PACKET*)0){ // �ƹ� ������ ���� ��
		last_packet->next = pac;
		last_packet = pac;
	}
	else{ // ���ϸ鼭 ���� ����
		PACKET* cur = &buffer;
		while (cur->next != NULL){
			if (pac->prior_level < cur->next->prior_level){
				pac->next = cur->next;
				cur->next = pac;
				break;
			}
			cur = cur->next;
		}

		// ���� �������� ���� ���
		if (cur->next == NULL){
			cur->next = pac;
			last_packet = pac;
		}
	}

	return SUCCESS;
}
int Get_Packet_from_Buffer(PACKET& p)
{
	if (buffer.next == (PACKET*)0) return ERROR_BUF_EMPTY;
	p = *buffer.next;
	delete buffer.next;

	buffer.next = p.next;

	return SUCCESS;
}

int main(void)
{
	int N;
	PACKET packet;

	cin >> N;	// ��Ŷ�� �� �Է�

	last_packet = &buffer;
	packet.next = NULL;
	// ��Ŷ�� ����
	for (int i = 0; i < N; i++)
	{
		Input_Packet(packet);
		Put_Packet_to_Buffer(packet);
	}

	// ��Ŷ ó������ ���
	while (Get_Packet_from_Buffer(packet) == SUCCESS)
	{
		cout << packet.packet_no << " ";
	}

	return 0;
}
