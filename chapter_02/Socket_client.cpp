#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

int main()
{
    // 1. 初始化 Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("WSAStartup failed\n");
        return -1;
    }

    // 2. 创建客户端 socket
    SOCKET sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sClient == INVALID_SOCKET)
    {
        printf("socket error\n");
        WSACleanup();
        return -1;
    }

    // 3. 设置服务器地址
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9999);                  // 必须和服务器一致
    serverAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    // 4. 连接服务器
    if (connect(sClient, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        printf("connect error\n");
        closesocket(sClient);
        WSACleanup();
        return -1;
    }

    printf("Connected to server\n");

    // 5. 向服务器发送数据
    const char* sendData = "hello server";
    send(sClient, sendData, strlen(sendData), 0);

    // 6. 接收服务器返回的数据
    char recvBuf[256] = { 0 };
    int ret = recv(sClient, recvBuf, sizeof(recvBuf) - 1, 0);
    if (ret > 0)
    {
        recvBuf[ret] = '\0';
        printf("Received from server: %s\n", recvBuf);
    }
    else if (ret == 0)
    {
        printf("Server closed connection\n");
    }
    else
    {
        printf("recv error\n");
    }

    // 7. 关闭连接
    closesocket(sClient);
    WSACleanup();

    return 0;
}
