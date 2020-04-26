#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h> 
#include<map>

struct node{
std::string fullName;
int scores[5];
int sumScore;
};
void readDatabase(std::string fileName,std::vector<struct node> &nodeList);
void print(std::vector<struct node> nodeList);
void printFile(std::vector<struct node> nodeList,std::string fileName);
void bubbleSort(std::vector<struct node> &nodeList,int type);
int main()
{
std::vector<node> nodeList;
int type=1;
while(type==1)
{
std::string dataBaseFileName="names_and_scores.txt";
//std::cout<<"please enter the database name"<<std::endl;
//std::cin>>dataBaseFileName;
readDatabase(dataBaseFileName,nodeList);
std::cout<<"read database"<<std::endl;
std::cout<<"Bubble sort by ? (0 for total score and 1 for fullname)" <<std::endl;
std::cin>>type;
bubbleSort(nodeList,type);
//print2D(root);
std::cout<<"Print in file or console?(0 for console and 1 for file)"<<std::endl;
std::cin>>type;
if(type==0)
print(nodeList);
else
{
std::string fileName;
std::cout<<"give me the output fileName"<<std::endl;
std::cin>>fileName;
printFile(nodeList,fileName);
}
std::cout<<"still want to continue using the program? (1 for yes and 0 for no)"<<std::endl;
std::cin>>type;
}
return 1374;
}
void readDatabase(std::string fileName,std::vector<struct node> &nodeList)
{
	std::ifstream in_file; //input stream
	std::string delimiter = " ";
	int pos = 0;
	in_file.open(fileName);
	std::string line;
	if(in_file.is_open())
	{
		while(std::getline(in_file,line))
		{
			struct node newNode;
			newNode.fullName="";
			newNode.sumScore=0;
			pos = line.find(delimiter);
			int counter=0;
			while(pos!=std::string::npos)
			{
			std::string word=line.substr(0,pos);
			if(isdigit(word[0]))
			{ 
			newNode.scores[counter]=stoi(word);
			counter=counter+1;
			newNode.sumScore=newNode.sumScore+stoi(word);
			}
			else
			{
			newNode.fullName= newNode.fullName+" "+word;
			
			}
			line.erase(0,pos+delimiter.length());
			pos = line.find(delimiter);
			}
			newNode.scores[4]=stoi(line);
			newNode.sumScore=newNode.sumScore+stoi(line);
			nodeList.push_back(newNode);
		}	
	}	
		
	else if(in_file.fail())
	{
		std::cout <<"Error opening file: "<<std::endl;
	}
	in_file.close();
	return;
}
void bubbleSort(std::vector<struct node> &nodeList,int type)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < nodeList.size()-1; i++) {
           if(type==0)
           {
            if (nodeList[i].sumScore>nodeList[i+1].sumScore )
            	{
            	struct node tempNode;
                tempNode=nodeList[i];
                nodeList[i] = nodeList[i+1];
                nodeList[i+1] =tempNode;
                swapp = true;
           	 }
            }
            else
            {
            if (strcmp(nodeList[i].fullName.c_str(),nodeList[i+1].fullName.c_str())>0 )
            	{
            	struct node tempNode;
                tempNode=nodeList[i];
                nodeList[i] = nodeList[i+1];
                nodeList[i+1] =tempNode;
                swapp = true;
           	 }
            }
            }
        }
}
void print(std::vector<struct node> nodeList)
{
	for (int i = 0; i < nodeList.size(); i++) {
		std::cout << nodeList[i].fullName <<" "<<nodeList[i].scores[0]<<" "<<nodeList[i].scores[1]<<" "<<nodeList[i].scores[2]<<" "<<nodeList[3].scores[1]<<" "<<nodeList[i].scores[4]<<" "<<"|| total score: "<<nodeList[i].sumScore<<" "<<std::endl;
	}
}
void printFile(std::vector<struct node> nodeList,std::string fileName)
{
  std::ofstream myfile;
  myfile.open (fileName);

	for (int i = 0; i < nodeList.size(); i++) {
		myfile << nodeList[i].fullName <<" "<<nodeList[i].scores[0]<<" "<<nodeList[i].scores[1]<<" "<<nodeList[i].scores[2]<<" "<<nodeList[3].scores[1]<<" "<<nodeList[i].scores[4]<<" "<<"|| total score: "<<nodeList[i].sumScore<<" "<<std::endl;
	}
	  myfile.close();
}
