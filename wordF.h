#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;


class word//������ 
{
	private:	    
//	    double chance[3500];//������ָ��ʣ��ò���    
	public:
		
		string numW[3500];//�������� 
		int wordI[3500];//Ƶ�� 
		
		static long int charnum;//�ַ����� 
		
		static int allword;// ͳ�������� 
		static int countww;//������ 
		
		void sort(string ws[3500],int wn[3500],int wordnums);//���� 
		bool CompareW(string word[3500],string targetw,int current);//���� 
		void CalToWord(string wsl,int lenw); //��ֵ��ͳ�� 
		friend class Huffuman;
};


int word::allword=0;//  �������� 
int word::countww=0;// ������
long int word::charnum=0;

void word::sort(string ws[3500],int wn[3500],int wordnums)//������Ƶ������ 
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

bool word::CompareW(string word[3500],string targetw,int current)//�����ظ� ���� 
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
	
	for (i=0;i<3500;i++)//��ʼ�� 
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
				numW[index]=tempW;// ���浱ǰ�ĵ���
                wordI[index]=1;    // ��ǳ��ִ���Ϊ1��
                FindNew=true;
			}
			tempW="";  // ��յ�ǰ�ĵ���
			for (j=k+1;j<lenw;j++)
			{
				c=wsl.at(j);
				if (c!=' '&&c!=','&&c!='.'&&c!='"'&&c!='-'&&c!='!'&&c!=40&&c!='?'&&c!=';'&&c!=41)tempW+=c;
				else
				{
					if(numW[index]==tempW)
					{
						wordI[index]++; // ��������
					}
					tempW="";// �����ƥ��ĵ���
				}
			}// ����β��
			if(tempW!="")
			{
				if(numW[index]==tempW)
				{
					wordI[index]++; // ��������
				}
				tempW="";// �����ƥ��ĵ���
			}
			if(FindNew) index++; // ָ����һ������
		}
		k++;
	}// ����β��
	if (tempW!="")
	{
		FindNew=false;
		if(!CompareW(numW,tempW,index))
		{
			numW[index]=tempW; // ���浱ǰ�ĵ���
			wordI[index]=1;    // ��ǳ��ִ���Ϊ1��
			FindNew=true;
		}
		tempW="";  // ��յ�ǰ�ĵ���
		for (j=k+1;j<lenw;j++)
		{
			c=wsl.at(j);
			if (c!=' '&&c!=','&&c!='.'&&c!='"'&&c!='-'&&c!='!'&&c!=40&&c!='?'&&c!=';'&&c!=41)tempW+=c;
			else
			{
				if(numW[index]==tempW)
				{
					wordI[index]++; // ��������
				} 
				tempW="";// �����ƥ��ĵ���
			}
		}
		if(tempW!="")
		{
			if(numW[index]==tempW)
			{
				wordI[index]++; // ��������
			}
			tempW="";// �����ƥ��ĵ���
		} 
		if(FindNew) index++; // ָ����һ������
	}
	sort(numW,wordI,index);
    allword=index;
	for (i=0;i<allword;i++)
	{
		countww+=wordI[i];
		cout<<setw(15)<<numW[i]<<setw(15)<<wordI[i]<<setw(15)<<endl;//             �鿴����� 
	}
	
	cout<<"����������"<<countww<<"��\t"<<"�������ࣺ"<<allword<<" ��"<<endl;  //             �鿴���� ���� ���ж����ֲ�ͬ�ĵ��� 
} 


