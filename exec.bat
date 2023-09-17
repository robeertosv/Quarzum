echo off
g++ main.cpp -o main.exe
main.exe math.qz --debug
del main.exe
exit