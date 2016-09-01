
Write a program that simulates a "cd" Unix command in an abstract file system. The command takes two path strings from the command line and prints a new path or an error. The first path is a current directory. The second path is a new directory. Examples:

% mycd /abc/def ghi
/abc/def/ghi
% mycd /abc/def ..
/abc
% mycd /abc/def /abc
/abc
% mycd /abc/def /abc/klm
/abc/klm
% mycd /abc/def ../..
/
% mycd /abc/def ../../..
/
% mycd /abc/def .
/abc/def
% mycd /abc/def ..klm
..klm: No such file or directory



# Tests
Compile using g++ as below
g++ -std=c++11 ss8.cpp

Run
a.exe <currentDir> <targetDir>
Ouput:

Current Directory:<currentDir>
Target Directiory:<targetDir>
After Operations:<Directory>


