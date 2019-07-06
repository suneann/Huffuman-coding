#include <iostream>

#include <fstream>

#include <stdio.h>

#include <stdlib.h>

#include <iomanip>

#include <string.h>

#include "wordF.h"

#include "tree.h" 
 

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
    
    Huffuman a;
    
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

    a.Huffman(Ht,Hc,w,n,wold);

/*   for(i=0;i<n;i++)  
    {
    	cout<<setw(15)<<a.numW[i]<<"->"<<Hc[i+1]<<endl;//                       查看单词对应的编码 
    }
*/
/*******创建一个文件将编码后文本写进去*********/
	
/*	fstream Filew("bianma.txt");//读取文件 
	
	if(Filew.fail())
	{
		cout<<"文件打开失败。"<<endl;
		exit(0);
	}
*/	
        /**********找新单词***********/ 
/*    int k=0;
    string temp="";
    cout<<"\n\n\n"<<"经过哈夫曼编码后:"<<"\n\n\n";
	while(k<wold.length())
	{
		c=wold.at(k);
		if (c!=' '&&c!=','&&c!='.'&&c!='"'&&c!='-'&&c!='!'&&c!=40&&c!='?'&&c!=';'&&c!=41)temp+=c;//' 39 ( 40 )41  34"
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
   Filew.close();  */
/**************对密文文本进行解码**************/
	
	 i=0;
	 int j=0; 
	 i=a.m; 
     ifstream Filer("bianma.txt");//读取文件 

     if(File.fail())

    {
	    cout<<"文件打开失败。"<<endl;
	
     	exit(0);
    }
    Filer.getline(b,999999);
    Filer.close();
    
    a.decode(Ht,b); //解码
	
	 
/*	  while(b[j]!='#')  
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
			i=a.m;              //每次译码从头开始
		  }  
		 j++;  
	  }  
    printf("\n");  */

    
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
    char a1,b1,c;
    int k=0;
    int k1=0;
    int pipei=0;
    long int o=0;
    string temp="";
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

