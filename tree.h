#include <iostream>
#include <stdlib.h>
#include <iomanip>

 
typedef struct//������� 
    {  
       char ch;  
       int data;  
       int p,lc,rc;  
    } Htree,*Hufftree; 
    
typedef char* Huffcode;
    
class Huffuman:public word//�������� 
{
	public:
	
	int s2;  
    int s1;
    int m;  
      
    void select (Hufftree &Ht,int n);//ѡ����СȨ�� 
	void Huffman(Hufftree &Ht,Huffcode Hc[],int *w,int n,string wold);//�����������ڱ���
	void decode(Hufftree &Ht,char b[]);//���� ,���ѽ����������ļ��� 
};

void Huffuman::select (Hufftree &Ht,int n)  

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


void Huffuman::Huffman(Hufftree &Ht,Huffcode Hc[],int *w,int n,string wold)//���������� 

{  
    int start;  //��ʼ 
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

    char c1;    
    fstream Filew("bianma.txt",ios::out);//��ȡ�ļ� 
	
	if(Filew.fail())
	{
		cout<<"�ļ���ʧ�ܡ�"<<endl;
		exit(0);
	}

	int k=0;
    string temp="";
    cout<<"\n\n\n"<<"���������������:"<<"\n\n\n";
	while(k<wold.length())
	{
		c1=wold.at(k);
		if (c1!=' '&&c1!=','&&c1!='.'&&c1!='"'&&c1!='-'&&c1!='!'&&c1!=40&&c1!='?'&&c1!=';'&&c1!=41)temp+=c1;//' 39 ( 40 )41  34"
		else
		{
			for(i=0;i<n;i++)
	       {
		      if(temp==numW[i]) 
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
   Filew.close();
} 

void Huffuman::decode(Hufftree &Ht,char b[])  

{  
    fstream Filej("jiema.txt",ios::out);//����¼������ĵ��� 
	if(Filej.fail())
	{
		cout<<"�ļ���ʧ�ܡ�"<<endl;
		exit(0);
	}
//  cout<<b<<endl<<endl<<endl;  
    cout<<"\n\n\n"<<"�������"<<"\n\n\n";
	int i,j=0; 
   	i=m; 
	while(b[j]!='#')  
	   {  
		  if(b[j]=='0')  
		    i=Ht[i].lc;  
		  else  
		    i=Ht[i].rc;  
		  if(Ht[i].lc==-1)  
		  {  
		    Filej<<numW[i-1]<<" ";
		    cout<<numW[i-1]<<" ";;//                                           �鿴����ɹ� 
			i=m;              //ÿ�������ͷ��ʼ
		  }  
		 j++;  
	  }  
     printf("\n");  
     Filej.close();
}  
 
