#pragma comment(lib, "ws2_32.lib")
#include<stdio.h>
#include<winsock2.h>
#include<windows.h>

int main(int argc, char *argv[])
{
    WORD sockVersion = MAKEWORD(2,2);
    WSADATA WSAData;
    if(WSAStartup(sockVersion, &WSAData) != 0)
    {
        return -1;
    }
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(slisten == INVALID_SOCKET)
    {
        printf("socket error!");
        return -1;
    }
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(9999);
    sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if(bind(slisten, (LPSOCKADDR) &sin,sizeof(sin))==SOCKET_ERROR)
    {
        printf("bind error!");
        return -1;
    }
    if(listen(slisten, 5) == SOCKET_ERROR)
    {
        printf("listen error!");
        return -1;

    }
    SOCKET sClient;
    struct sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    printf("Waiting for connection\n");
    sClient = accept(slisten, (SOCKADDR *) &remoteAddr, &nAddrlen);
    char revData[255];
    if(sClient == INVALID_SOCKET)
    {
        printf("accept error!");
        return -1;
    }
    printf("Client connected from %s:%d\n", inet_ntoa(remoteAddr.sin_addr), ntohs(remoteAddr.sin_port));
    int ret = recv(sClient, revData, 255, 0);
    if(ret > 0)
    {
        revData[ret] = 0;
        printf("Received: %s\n", revData);
    }
    const char *sendData = "hi, TCP Client";
    send(sClient, sendData, strlen(sendData), 0);
    closesocket(sClient);
    closesocket(slisten);
    WSACleanup();

    return 0;
}