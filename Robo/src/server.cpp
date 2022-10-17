#include<iostream>
#include "socket.h"

int main(int argc,char* argv[]){
string ip = "localhost";
string port = "1244";//one port one id

//create socket
unique_ptr<Socket> masterSocket = make_unique <Socket>(AF_INET,SOCK_STREAM,0); //AF_INET (Internet mode) SOCK_STREAM (TCP mode) 0 (Protocol any)

//bind socket
int optVal = 1;
masterSocket->socket_set_opt(SOL_SOCKET, SO_REUSEADDR, &optVal); //You can reuse the address and the port
masterSocket->bind(ip, port); //Bind socket on localhost:1244

//listen
masterSocket->listen(10); //Start listening for incoming connections (10 => maximum of 10 Connections in Queue)

string hello = "Hello from Server";
while (true) {
    vector<Socket> reads(1);
    reads[0] = *masterSocket;
    int seconds = 10; //Wait 10 seconds for incoming Connections
    if(Socket::select(&reads, NULL, NULL, seconds) < 1){ 
        //Socket::select waits until masterSocket reveives some input (for example a new connection)
        //No new Connection
        continue;
    }else{
        //Something happens, let's accept the connection
        break;
    }
}
unique_ptr<Socket> newSocket = masterSocket->accept(); //Accept the incoming connection and creates a Socket unique_ptr to the client

while (true) {
    vector<Socket> reads(1);
    reads[0] = *newSocket;
    int seconds = 10; //Wait 10 seconds for input
    if(Socket::select(&reads, NULL, NULL, seconds) < 1){ 
        //Socket::select waits until masterSocket reveives some input (for example a message)
        //No Input
        continue;
    }else{
        string buffer;
        newSocket->socket_read(buffer, 1024); //Read 1024 bytes of the stream
        
        //send hello to the client
        newSocket->socket_write(hello);
        
        newSocket->socket_write(buffer); //Sends the input back to the client (echo)
    }
}
newSocket->socket_shutdown(2);
newSocket->close();

masterSocket->socket_shutdown(2);
masterSocket->close();

return 0;
}
