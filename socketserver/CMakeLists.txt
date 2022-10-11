PROJECT(socketserver)
CMAKE_MINIMUM_REQUIRED(VERSION 3.7)

SET (SERVER src/socket.cpp src/server.cpp)
SET (CLIENT src/socket.cpp src/client.cpp)
ADD_COMPILE_OPTIONS(-Wall)
ADD_EXECUTABLE(server ${SERVER} )
ADD_EXECUTABLE(client ${CLIENT} )

