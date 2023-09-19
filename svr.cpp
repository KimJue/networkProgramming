#include "Common.h"

int main(int argc, char* argv[])
{
	//���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return 1;

	printf("[�˸�] ���� �ʱ�ȭ ����\n");
	printf("Suggested version: %d.%d!\n", LOBYTE(wsa.wVersion), HIBYTE(wsa.wVersion));
	printf("High supported version: %d.%d!\n", LOBYTE(wsa.wHighVersion), HIBYTE(wsa.wHighVersion));
	printf("szDescription:%s\n", wsa.szDescription);//���� ����
	printf("szSystemStatus:%s\n", wsa.szSystemStatus);//���ӻ���
	
	// ���� ����
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) err_quit("socket()");
	printf("[�˸�] ���� ���� ����\n");
	
	closesocket(sock); //���� �ݱ�

	WSACleanup(); // ���� ����
	
	return 0;
}