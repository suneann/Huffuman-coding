#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;


class word//单词类 
{
	private:	    
//	    double chance[3500];//计算出现概率，用不上    
	public:
		
		string numW[3500];//单词类型 
		int wordI[3500];//频数 
		
		static long int charnum;//字符总数 
		
		static int allword;// 统单词类型 
		static int countww;//单词数 
		
		void sort(string ws[3500],int wn[3500],int wordnums);//排序 
		bool CompareW(string word[3500],string targetw,int current);//查重 
		void CalToWord(string wsl,int lenw); //赋值、统计 
		friend class Huffuman;
};


int word::allword=0;//  单词类型 
int word::countww=0;// 单词数
long int word::charnum=0;

void word::sort(string ws[3500],int wn[3500],int wordnums)//按出现频数排序 
{
	int i,j,swap;
	string temp;
	do{
		swap=0;
		for(i=1;i<wordnums;i++)
		{
			if(wn[i-1]>wn[i])
			{
				j=wn[i-1];
				wn[i-1]=wn[i];
				wn[i]=j;
				temp=ws[i-1];
				ws[i-1]=ws[i];
				ws[i]=temp;
				swap=1; 
			}
		}
	}while(swap);
}

bool word::CompareW(string word[3500],string targetw,int current)//避免重复 单词 
{
	for(int i=0;i<current;i++)
	{
		if(word[i]==targetw) return true;
	}
	return false;
}

void word::CalToWord(string wsl,int lenw)
{
    string tempW="";
	int i,j,k=0,index=0;
	bool FindNew;
	charnum=lenw; 
	
	for (i=0;i<3500;i++)//初始化 
	{
		wordI[i]=0;
		numW[i]="";
	}
	char c;
	while(k<lenw)
	{
		c=wsl.at(k);
		if (c!=' '&&c!=','&&c!='.'&&c!=34&&c!='-'&&c!='!'&&c!=40&&c!='?'&&c!=';'&&c!=41)tempW+=c;//' 39 ( 40 )41  34"
		else
		{
			FindNew=false;
			if(!CompareW(numW,tempW,index))
			{
				numW[index]=tempW;// 保存当前的单词
                wordI[index]=1;    // 标记出现次数为1次
                FindNew=true;
			}
			tempW="";  // 清空当前的单词
			for (j=k+1;j<lenw;j++)
			{
				c=wsl.at(j);
				if (c!=' '&&c!=','&&c!='.'&&c!='"'&&c!='-'&&c!='!'&&c!=40&&c!='?'&&c!=';'&&c!=41)tempW+=c;
				else
				{
					if(numW[index]==tempW)
					{
						wordI[index]++; // 次数自增
					}
					tempW="";// 清空已匹配的单词
				}
			}// 处理尾部
			if(tempW!="")
			{
				if(numW[index]==tempW)
				{
					wordI[index]++; // 次数自增
				}
				tempW="";// 清空已匹配的单词
			}
			if(FindNew) index++; // 指向下一个单词
		}
		k++;
	}// 处理尾部
	if (tempW!="")
	{
		FindNew=false;
		if(!CompareW(numW,tempW,index))
		{
			numW[index]=tempW; // 保存当前的单词
			wordI[index]=1;    // 标记出现次数为1次
			FindNew=true;
		}
		tempW="";  // 清空当前的单词
		for (j=k+1;j<lenw;j++)
		{
			c=wsl.at(j);
			if (c!=' '&&c!=','&&c!='.'&&c!='"'&&c!='-'&&c!='!'&&c!=40&&c!='?'&&c!=';'&&c!=41)tempW+=c;
			else
			{
				if(numW[index]==tempW)
				{
					wordI[index]++; // 次数自增
				} 
				tempW="";// 清空已匹配的单词
			}
		}
		if(tempW!="")
		{
			if(numW[index]==tempW)
			{
				wordI[index]++; // 次数自增
			}
			tempW="";// 清空已匹配的单词
		} 
		if(FindNew) index++; // 指向下一个单词
	}
	sort(numW,wordI,index);
    allword=index;
	for (i=0;i<allword;i++)
	{
		countww+=wordI[i];
		cout<<setw(15)<<numW[i]<<setw(15)<<wordI[i]<<setw(15)<<endl;//             查看编码表 
	}
	
	cout<<"单词总数："<<countww<<"个\t"<<"单词种类："<<allword<<" 种"<<endl;  //             查看单词 总数 与有多少种不同的单词 
} 


