#include<bits/stdc++.h>
#include<string>
#include"name.h"
using namespace std;
#define ALL 40

bool old[41]={false};
bool book[40]={false};
vector<int> past;
vector<int> now;
int num,n;

//读取日志
void FileRead(){
	FILE* data=NULL;
	data=fopen("data.log","r+");
	fscanf(data,"%d",&num);
	cout<<"以前抽过的人"<<endl;
//	cout<<name[num]<<endl;
	for(int i=0;i<num;i++){
		int tmp;
		fscanf(data,"%d",&tmp);
		old[tmp]=true;
		past.push_back(tmp);
//		cout<<tmp<<endl;
		cout<<name[tmp]<<endl;
	}
	fclose(data);
}

//产生随机数
void Extract(){
	srand((unsigned)time(NULL));
	int a;
	cout<<"请输入需要抽取多少人:"<<endl;
	cin>>n;
	if((ALL-num)<n){
		past.clear();
		int tmp=ALL-num;
		for(int i=1;i<=ALL;i++){
			if(!old[i]){
				past.push_back(i);
				now.push_back(i);
				book[i]=true;
			}
		}
		for(int i=0;i<=ALL;i++){
			old[i]=false;
		}
		n-=tmp;
	}
	for(int i=0;i<n;i++){
		tiger:
		a=rand()%40+1;
		if(old[a]==true){
			goto tiger;
		}
		old[a]=true;
		past.push_back(a);
		now.push_back(a);
	}
}

//打印抽中的人的姓名
void Printname(){
	for(int i=0;i<now.size();i++){
		cout<<name[now[i]]<<endl;
	}
}

//覆写日志
void Overwrite(){
	FILE* data;
	sort(past.begin(),past.end());
	data=fopen("data.log","w");
	fprintf(data,"%d\n",num+n);
	for(int i=0;i<num+n;i++){
		fprintf(data,"%d\n",past[i]);
	}
	fclose(data);
}


int main(){
	FileRead();
	Extract();
	Printname();
	Overwrite();
	return 0;
}
