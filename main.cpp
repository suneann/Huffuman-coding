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
/************¼��������Ϣ�������е��ʽ��д���************/ 
   const long int len=99999;

   char str[len],ren[len],b[len];

   ifstream File("word3000.txt");//��ȡ�ļ� 

   if(File.fail())

   {
	    cout<<"�ļ���ʧ�ܡ�"<<endl;
	
    	exit(0);
   }
    File.getline(str,99999); 

    File.close();
    
    cout<<"\n\n"<<"ԭ��:"<<"\n\n"; 
 
    cout<<str<<endl<<endl<<endl; //                                             �鿴ԭ�ļ� 
    
    Huffuman a;
    
	string wold=str;

	a.CalToWord(wold,wold.length());

/******************��ʼ����******************/ 
    Hufftree Ht;  

    Huffcode *Hc;  

    int w[3500];  

    int i,n;
    
    n=a.allword;//Ҫ������ַ����� 

    Hc=(Huffcode*)malloc(n*sizeof(Huffcode));

//����Ҫ������ַ���Ƶ��

    for (i=0;i<n;i++)  

        w[i]=a.wordI[i];

    a.Huffman(Ht,Hc,w,n,wold);

/*   for(i=0;i<n;i++)  
    {
    	cout<<setw(15)<<a.numW[i]<<"->"<<Hc[i+1]<<endl;//                       �鿴���ʶ�Ӧ�ı��� 
    }
*/
/*******����һ���ļ���������ı�д��ȥ*********/
	
/*	fstream Filew("bianma.txt");//��ȡ�ļ� 
	
	if(Filew.fail())
	{
		cout<<"�ļ���ʧ�ܡ�"<<endl;
		exit(0);
	}
*/	
        /**********���µ���***********/ 
/*    int k=0;
    string temp="";
    cout<<"\n\n\n"<<"���������������:"<<"\n\n\n";
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
		      	
		         Filew<<Hc[i+1];//����������ı� 
		         cout<<Hc[i+1];//                                          �鿴ȫ�ı����Ľ�� 
	          }
	       }
			temp="";  // ��յ�ǰ�ĵ���
	    }
	    k++;
   }
   Filew<<"#";
   Filew.close();  */
/**************�������ı����н���**************/
	
	 i=0;
	 int j=0; 
	 i=a.m; 
     ifstream Filer("bianma.txt");//��ȡ�ļ� 

     if(File.fail())

    {
	    cout<<"�ļ���ʧ�ܡ�"<<endl;
	
     	exit(0);
    }
    Filer.getline(b,999999);
    Filer.close();
    
    a.decode(Ht,b); //����
	
	 
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
		    cout<<a.numW[i-1]<<" ";;//                                           �鿴����ɹ� 
			i=a.m;              //ÿ�������ͷ��ʼ
		  }  
		 j++;  
	  }  
    printf("\n");  */

    
/******************������̽���*******************/ 
/*******************ƥ��ȼ���********************/ 

 char y[wold.length()];
  
 ifstream File2("jiema.txt");//��ȡ�ļ� 

   if(File2.fail())

   {
	    cout<<"�ļ���ʧ�ܡ�"<<endl;
	
    	exit(0);
   }
    File2.getline(y,999999); 

    File2.close();

    string woldb=y;
/*    cout<<wolda<<"**********************";//����� 
/*    cout<<woldb<<"*********************";//����� 
    
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
			tempa="";  // ��յ�ǰ�ĵ���
			tempb="";
	    }
	    u++;
    }

    cout<<"ƥ���ʣ�"<<(double)pipei/o<<endl;
	
*///������� ���� ���ƥ��� ������̫�� 

/********************���������ĸ���ƥ���***********************/ 
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
   
   cout<<"\n\n\n"<<"��ԭ�ĵ�ƥ���ʣ�"<<((double)pipei/o)*100<<"%"<<endl;//                        �鿴ƥ���� 
   return 0;
}

