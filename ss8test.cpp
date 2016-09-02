#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<cstddef>

using namespace std;

vector<string>split(string str)
{

vector<string>tokens;
string token;

for_each(str.begin(),str.end(),[&](char c) {
if(c != '/')
token += c;
else
{

if(token.length())
   tokens.push_back(token);
   token.clear();
}

});

if(token.length()) 
    tokens.push_back(token);

return tokens;

}

string changeDir(string &currentDir,string targetDir)
{

vector<string>dest = split(targetDir);
string s = "/";
string st(1,targetDir[0]);
string target;

size_t in = targetDir.find("..");

//check for cases like ..klm
if(in!= string::npos){
string nextchar = targetDir.substr(in+2,1);
if(nextchar.compare("/"))
{
	cout<<"Error in operations "<<endl;
	return NULL;
}
}

//Go through destination

for(auto str:dest)
{

//check if found root directory as first in target
if(!st.compare("/"))
{
   target = target + "/" +str;
}

else
if(!str.compare(".."))
{
    size_t index = currentDir.find_last_of("/\\");
    currentDir = currentDir.substr(0,index);
}

else
{

    currentDir = currentDir + "/" + str;
}

}

if(!st.compare("/"))
 return target;

else
 return currentDir;

}


int main(int argc,char *argv[])
{


string currentDir,targetDir;
if(argc < 3)
  cout << "Error in supplying arguments "<<endl;

currentDir=argv[1];
targetDir=argv[2];

cout << "current Directory: "<< currentDir<<endl;
cout << "target Directory: " << targetDir<<endl;
cout << "after operations: " <<endl;
cout <<changeDir(currentDir,targetDir);

}
