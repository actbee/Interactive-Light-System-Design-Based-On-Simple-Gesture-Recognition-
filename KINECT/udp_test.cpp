
#pragma warning(disable:4996)
#include <iostream>//���̱߳��
using namespace std;
#include <winsock2.h>
#include <process.h> //_beginthread��Ҫ��ͷ�ļ� �����߳�
#pragma comment(lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
//WORD wVer = 0x0302; //2.3�汾
//WORD wVer = 0x0300; //0.3
//WORD wVer = 0x0202; //2.2�汾
const unsigned short PORT = 8888;//�˿�
SOCKET sock;
void RecvMain(void * p)
{

	char s[2048];
	sockaddr_in sfrom = { 0 };
	int slen = sizeof(sfrom);//in out
	SOCKET sock = (SOCKET)p;
	int n = 0;
	while ((n = recvfrom(sock, s, sizeof(s), 0, (sockaddr*)&sfrom, &slen)) > 0)
	{
		cout << "running" << endl;
		s[n] = '\0';
		//cout << WSAGetLastError() << endl;
		cout << endl <<"receive messeage"<< inet_ntoa(sfrom.sin_addr) << "-" << htons(sfrom.sin_port) << ": " << s << endl;
	}
}
int main(int argc, char* argv[])
{
	WSADATA wd;
	SOCKET sock;
	int n = WSAStartup(0x0202, &wd);//0����ɹ���������ֱ�ӷ��ش�����
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == sock)
	{
		cout << "socket��������" << WSAGetLastError << endl;
		return -1;
	}
	struct sockaddr_in sa = { AF_INET,htons(PORT) };
	//sa.sin_addr.Sun.S_addr = inet_addr("192.168.1.1");
	n = bind(sock, (sockaddr*)&sa, sizeof(sa));
	//Address Family ��ַ��
	if (n == SOCKET_ERROR)
		cout << "bind��������" << WSAGetLastError() << endl;
	else
		cout << "�˿ڷ����ɹ���" << PORT << endl;
	_beginthread(RecvMain, 1024 * 1024, (void*)sock);//���̣߳��ٴε���int main������ ʵ�������߳�

	char s[2048];
	char sIP[20]= "192.168.56.1";
	while (true)
	{
	//	cout << "������Է���IP: ";
	//	cin >> sIP;
	//	cout << sIP << endl;
	//	cin.get();
		cout << "������Ҫ���͵����ݣ�";
		fflush(stdin);
		cin.getline(s, 2047);
		sa.sin_addr.S_un.S_addr = inet_addr(sIP);
		sa.sin_port = htons(PORT);
		sendto(sock, s, strlen(s), 0, (sockaddr*)&sa, sizeof(sa));
		Sleep(16); //�ӳ�16����
	}
	cin.get();
	return 0;
}
