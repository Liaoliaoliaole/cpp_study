PROJECT(robo)
CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
SET (CLIENT src/socket.cpp src/parse.cpp src/vectr.cpp src/object.cpp src/ball.cpp src/player.cpp src/opponent.cpp src/strategy.cpp src/roboClient.cpp)
ADD_COMPILE_OPTIONS(-Wall)
ADD_EXECUTABLE(robo ${CLIENT} )

