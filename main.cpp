#include <iostream>

#include <fstream>

#include <stdio.h>

#include <stdlib.h>

#include <iomanip>

#include <string.h>

#include "wordF.h"

using namespace std;

int s2;  

int s1;
  
int m;  

double a;//统计字符数 

typedef struct
 
 {  
 
    char ch;  

    int data;  

    int p,lc,rc;  

 } Htree,*Hufftree;  

typedef char* Huffcode;  

void select (Hufftree &Ht,int n)  

{  

    char *cd;  

    int min1,min2;  

    min1=min2=32765;  

        s1=s2=0;  

    int i;  

    for (i=1;i<=n;i++)  

    {  

        if (!Ht[i].p)  

            if (Ht[i].data<min1)  

        {  

            min2=min1;  

            s2=s1;  

            min1=Ht[i].data;  

            s1=i;  

        }  

        else if (Ht[i].data<min2)  

        {  

            s2=i;  

            min2=Ht[i].data;  

        }  

    }  

}  

void Huffman(Hufftree &Ht,Huffcode Hc[],int *w,int n)//构建二叉树 

{  

    int start;  //开始 

    char *cd;  

    int i,c,f;  

    if (n<1)  

        return;  

    m=2*n-1;  

    Ht=(Htree*)malloc ((m+1)*sizeof(Htree));  

     for (i=1;i<=n;i++)  

      {  

        Ht[i].data=w[i-1];  

        Ht[i].p=0;  

        Ht[i].lc=-1;  

        Ht[i].rc=-1;  

      }  

     for(i=n+1;i<=m;i++)  

      {  

         Ht[i].data=0;  

         Ht[i].lc=-1;  

         Ht[i].rc=-1;  

         Ht[i].p=0;  

      }  

     for (i=n+1;i<=m;++i)  

     {  

        select(Ht,i-1);  

        Ht[s1].p=i;  

        Ht[s2].p=i;  

        Ht[i].lc=s1;  

        Ht[i].rc=s2;  

        Ht[i].data=Ht[s1].data+Ht[s2].data;  

     }  
        cd=(char *)malloc (n*sizeof(char));  

        start=0;  

        cd[n-1]='\0';  

        for (i=1;i<=n;i++)  

        {  

            start=n-1;  

        for(c=i,f=Ht[i].p;f!=0;c=f,f=Ht[f].p)  

        {  

            if (Ht[f].lc==c)  

                cd[--start]='0';  

            else  

                 cd[--start]='1';  

        }  

        Hc[i]=(char*)malloc((n-start)*sizeof(char));  

        strcpy (Hc[i],&cd[start]);  
        }  
}  
 

int main()
{ 
/************录入文章信息，对其中单词进行处理************/ 
   const long int len=99999;

   char str[len],ren[len],b[len];

   ifstream File("word3000.txt");//读取文件 

   if(File.fail())

   {
	    cout<<"文件打开失败。"<<endl;
	
    	exit(0);
   }
    File.getline(str,99999); 

    File.close();
    
    cout<<"\n\n"<<"原文:"<<"\n\n"; 
 
    cout<<str<<endl<<endl<<endl; //                                             查看原文件 
    
    word a;
    
	string wold=str;

	a.CalToWord(wold,wold.length());

/******************开始编码******************/ 

    Hufftree Ht;  

    Huffcode *Hc;  

    int w[3500];  

    int i,n;
    
    n=a.allword;//要编码的字符个数 

    Hc=(Huffcode*)malloc(n*sizeof(Huffcode));

//输入要编码的字符的频率

    for (i=0;i<n;i++)  

        w[i]=a.wordI[i];

    Huffman(Ht,Hc,w,n);

   for(i=0;i<n;i++)  
    {
 //   	cout<<setw(15)<<a.numW[i]<<"->"<<Hc[i+1]<<endl;//                       查看单词对应的编码 
    }
/*******创建一个文件将编码后文本写进去*********/
	char s[len],c;
	
	fstream Filew("bianma.txt");//读取文件 
	
	if(Filew.fail())
	{
		cout<<"文件打开失败。"<<endl;
		exit(0);
	}
        /**********找新单词***********/ 
    int k=0;
    string temp="";
    cout<<"\n\n\n"<<"经过哈夫曼编码后:"<<"\n\n\n";
	while(k<wold.length())
	{
		c=wold.at(k);
		if (c!=' '&&c!=','&&c!='.'&&c!=34&&c!='-'&&c!='!'&&c!=40&&c!='?'&&c!=';'&&c!=41)temp+=c;//' 39 ( 40 )41  34"
		else
		{
			for(i=0;i<n;i++)
	       {
		      if(temp==a.numW[i]) 
		      {
		      	
		         Filew<<Hc[i+1];//将编码存入文本 
		         cout<<Hc[i+1];//                                          查看全文编码后的结果 
	          }
	       }
			temp="";  // 清空当前的单词
	    }
	    k++;
   }
   Filew<<"#";
   Filew.close();
/**************对密文文本进行解码**************/
	
	i=0;
	int j=0; 
	
	 i=m; 
     ifstream Filer("bianma.txt");//读取文件 

     if(File.fail())

    {
	    cout<<"文件打开失败。"<<endl;
	
     	exit(0);
    }
    Filer.getline(b,999999);
    Filer.close();
    
    fstream Filej("jiema.txt");//用来录入解码后的单词 
	
	if(Filej.fail())
	{
		cout<<"文件打开失败。"<<endl;
		exit(0);
	}
//    cout<<b<<endl<<endl<<endl;  
      cout<<"\n\n\n"<<"经解码后："<<"\n\n\n";
	  while(b[j]!='#')  
	   {  
		  //printf("%c ",b[j]);

		  if(b[j]=='0')  
		    i=Ht[i].lc;  
		  else  
		    i=Ht[i].rc;  
		  
		  if(Ht[i].lc==-1)  
		  {  
		    Filej<<a.numW[i-1]<<" ";
		    cout<<a.numW[i-1]<<" ";;//                                           查看解码成果 
			i=m;              //每次译码从头开始
		  }  
		 j++;  
	  }  
    printf("\n");  
    Filej.close();
    
/******************解码过程结束*******************/ 
/*******************匹配度计算********************/ 

 char y[wold.length()];
  
 ifstream File2("jiema.txt");//读取文件 

   if(File2.fail())

   {
	    cout<<"文件打开失败。"<<endl;
	
    	exit(0);
   }
    File2.getline(y,999999); 

    File2.close();

    string woldb=y;
/*    cout<<wolda<<"**********************";//检查用 
/*    cout<<woldb<<"*********************";//检查用 
    
 /*   long int pipei=0;
    long int o=0;
    char a1,b1;
    string tempa="",tempb="";
 
    long int u=0,v=0;
	while(u<wold.length())
	{
		a1=wolda.at(u);
		if (a1!=' '&&a1!=','&&a1!='.'&&a1!=34&&a1!='-'&&a1!='!'&&a1!=40&&a1!='?'&&a1!=';'&&a1!=41)tempa+=a1;//' 39 ( 40 )41  34"
		else
		{
		   b1=woldb.at(u);
		   if (b1!=' '&&b1!=','&&b1!='.'&&b1!=34&&b1!='-'&&b1!='!'&&b1!=40&&b1!='?'&&b1!=';'&&b1!=41)tempb+=b1;
	       else
	       {
	       	o++;
	       	if(tempa==tempb)
	       	{
	       		pipei++;
	       	}
	       } 
			tempa="";  // 清空当前的单词
			tempb="";
	    }
	    u++;
    }

    cout<<"匹配率："<<(double)pipei/o<<endl;
	
*///遍历逐个 单词 检查匹配度 （好像不太行 

/********************遍历逐个字母检查匹配度***********************/ 
    char a1,b1;
    k=0;
    int k1=0;
    int pipei=0;
    long int o=0;
    temp="";
    string tempb="";
	while(k<wold.length())
	{
		c=wold.at(k);
		if ((c>=65&&c<=90)||(c>=97&&c<=122))//' 39 ( 40 )41  34"
		{
			o++;
		//	cout<<c<<"####";
			while(k1<woldb.length())
	       {
		      b1=woldb.at(k1);
		      if (b1!=32)
			  {
		//	  	cout<<b1<<"##";
		        if(c==b1)
		    	{
		    		pipei++;
		    		break;
		    	}
		    	k1++;
		      }
		      else
				{k1++;}
		     
           }  
           k++;
         } 
         else{k++;}
		 	    
   } 
   
   cout<<"\n\n\n"<<"与原文的匹配率："<<((double)pipei/o)*100<<"%"<<endl;//                        查看匹配率 
   return 0;
}

