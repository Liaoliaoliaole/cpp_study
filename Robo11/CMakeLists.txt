PROJECT(robo)
CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
FIND_PACKAGE(Eigen3 REQUIRED)
link_directories(${Eigen_INCLUDE_DIRS})
SET (PROJECT_NAME src/socket.cpp src/constants.cpp src/vector2.cpp src/network.cpp src/kalmanFilter.cpp src/parser.cpp src/object.cpp src/ball.cpp src/player.cpp src/opponent.cpp src/strategy.cpp src/roboClient.cpp)
ADD_COMPILE_OPTIONS(-Wall)
ADD_EXECUTABLE(robo ${PROJECT_NAME} )
target_link_libraries(robo
   ${Eigen_LIBRARIES}
   )

