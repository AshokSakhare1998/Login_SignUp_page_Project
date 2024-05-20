#include<iostream>
#include<winsock.h>
#include<fstream>
#define PORT 8080
using namespace std;
//TCP socket server handling multiple clients
int nListener =0;
struct sockaddr_in srv;
int nMaxFd=0;
fd_set fr;

int nClient[5]={0,   };

int main(){
WSADATA ws;
if(WSAStartup(MAKEWORD(2, 2),   &ws)<0){
  cout <<endl<<"The WSAStrartup failed....";
  return EXIT_FAILURE;
}
nListener= socket (AF_INET,  SOCK_STREAM, IPPROTO_TCP);
if(nListener <0){
  cout<<"Not able to open the socket..";
  return EXIT_FAILURE;
}
srv.sin_family = AF_INET;
srv.sin_port = htons(PORT);
srv.sin_addr.s_addr=INADDR_ANY;
memset (&srv.sin_zero,0,8);


int err= bind(nListener, (struct  sockaddr*)&srv, sizeof(sockaddr));
if(err<0){
  cout<<endl<<"The bind failed..";
  return EXIT_FAILURE;
}
err= listen(nListener, 5);
if(err<0){
  cout<<endl<<"The listen failed..";
  return EXIT_FAILURE;
}
nMaxFd =nListener  +1;
struct timeval tv;
tv.tv_sec =1;
tv.tv_usec =0;
while (1)
{
 FD_ZERO(&fr);
 FD_SET(nListener,&fr);
  int nIndex;


 for( nIndex =0; nIndex<5; nIndex++){
  if(nClient[nIndex]  !=0)
  {
    FD_SET(nClient[nIndex], &fr);
  }
 } 

err=select(nMaxFd, &fr,NULL,  NULL,  &tv);
if(err<0)
{
  cout<<endl<<"Select failed..";
  return EXIT_FAILURE;
}
  else  if(err ==0)
  {
    cout<<"No client available to connect/message";

  }
  else
  {
    cout<<endl<<"Someone connected...";
    // reset of the processing to connect/recv the request
  }

}

return 0;
}
