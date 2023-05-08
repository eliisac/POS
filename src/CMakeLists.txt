cmake_minimum_required(VERSION 3.10)

project(POS)

include_directories( "../include" "/usr/local/include/")

add_executable(posapplication main.cpp file.cpp Cashier.cpp CashierScreen.cpp HomeScreen.cpp Manager.cpp IUser.cpp Order.cpp ManagerScreen.cpp POSsystem.cpp Screen.cpp)

