@echo off
call premake5 gmake2
cd build
make clean
make config=debug -j10
cd Debug
CodeForces.exe
