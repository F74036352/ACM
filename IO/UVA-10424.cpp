#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	char name1[100]={'\0'};
	char name2[100]={'\0'};
	int number=0;
	int number1=0;
	float answer=0;
	while(gets(name1)!=0)
	{
		gets(name2);
		number=0;
		number1=0;
		answer=0;
		//scanf("%s",name2);
		/*if(name1[25]!='\0' || name2[25]!='\0')
		{
			printf("0.00 %%\n");
			break;
		}*/	
		for(int i=0;i<100;++i)
		{
			if(name1[i]=='a'||name1[i]=='A')
			{
				number+=1;
			}
			else if(name1[i]=='b'||name1[i]=='B')
                        {
							number+=2;
				        }
			else if(name1[i]=='c'||name1[i]=='C')
                        {
				number+=3;
                        }
			else if(name1[i]=='d'||name1[i]=='D')
                        {
				number+=4;
                        }
			else if(name1[i]=='e'||name1[i]=='E')
                        {
				number+=5;
                        }
			else if(name1[i]=='f'||name1[i]=='F')
                        {
				number+=6;
                        }
			else if(name1[i]=='g'||name1[i]=='G')
                        {
				number+=7;
                        }
			else if(name1[i]=='h'||name1[i]=='H')
			                        {
							number+=8;
			                        }
			else if(name1[i]=='i'||name1[i]=='I')
			                        {
							number+=9;
			                        }
			else if(name1[i]=='j'||name1[i]=='J')
			                        {
							number+=10;
			                        }
			else if(name1[i]=='k'||name1[i]=='K')
			                        {
							number+=11;
			                        }
			else if(name1[i]=='l'||name1[i]=='L')
			                        {
							number+=12;
			                        }
			else if(name1[i]=='m'||name1[i]=='M')
			                        {
							number+=13;
			                        }
			else if(name1[i]=='n'||name1[i]=='N')
			                        {
							number+=14;
			                        }
			else if(name1[i]=='o'||name1[i]=='O')
			                        {
							number+=15;
			                        }
			else if(name1[i]=='p'||name1[i]=='P')
			                        {
							number+=16;
			                        }
			else if(name1[i]=='q'||name1[i]=='Q')
			                        {
							number+=17;
			                        }
			else if(name1[i]=='r'||name1[i]=='R')
			                        {
							number+=18;
			                        }
			else if(name1[i]=='s'||name1[i]=='S')
			                        {
							number+=19;
			                        }
			else if(name1[i]=='t'||name1[i]=='T')
			                        {
							number+=20;
			                        }
			else if(name1[i]=='u'||name1[i]=='U')
			                        {
							number+=21;
			                        }
			else if(name1[i]=='v'||name1[i]=='V')
                        {
				number+=22;
                        }
			else if(name1[i]=='w'||name1[i]=='W')
                        {
				number+=23;
                        }
			else if(name1[i]=='x'||name1[i]=='X')
                        {
				number+=24;
                        }
			else if(name1[i]=='y'||name1[i]=='Y')
                        {
				number+=25;
                        }
			else if(name1[i]=='z'||name1[i]=='Z')
                        {
				number+=26;
                        }
			else
			{
				number=number;
			}                        	
		}//name1
		/*///////name2/////////*/
		for(int i=0;i<100;++i)
		{
			if(name2[i]=='a'||name2[i]=='A')
			{
				number1+=1;
			}
			else if(name2[i]=='b'||name2[i]=='B')
                        {
				number1+=2;
		         }
			else if(name2[i]=='c'||name2[i]=='C')
                        {
				number1+=3;
                        }
			else if(name2[i]=='d'||name2[i]=='D')
                        {
				number1+=4;
                        }
			else if(name2[i]=='e'||name2[i]=='E')
                        {
				number1+=5;
                        }
			else if(name2[i]=='f'||name2[i]=='F')
                        {
				number1+=6;
                        }
			else if(name2[i]=='g'||name2[i]=='G')
                        {
				number1+=7;
                        }
			else if(name2[i]=='h'||name2[i]=='H')
                        {
				number1+=8;
                        }
			else if(name2[i]=='i'||name2[i]=='I')
                        {
				number1+=9;
                        }
			else if(name2[i]=='j'||name2[i]=='J')
			                        {
							number1+=10;
			                        }
			else if(name2[i]=='k'||name2[i]=='K')
			                        {
							number1+=11;
			                        }
			else if(name2[i]=='l'||name2[i]=='L')
			                        {
							number1+=12;
			                        }
			else if(name2[i]=='m'||name2[i]=='M')
			                        {
							number1+=13;
			                        }
			else if(name2[i]=='n'||name2[i]=='N')
			                        {
							number1+=14;
			                        }
			else if(name2[i]=='o'||name2[i]=='O')
			                        {
							number1+=15;
			                        }
			else if(name2[i]=='p'||name2[i]=='P')
			                        {
							number1+=16;
			                        }
			else if(name2[i]=='q'||name2[i]=='Q')
			                        {
							number1+=17;
			                        }
			else if(name2[i]=='r'||name2[i]=='R')
			                        {
							number1+=18;
			                        }
			else if(name2[i]=='s'||name2[i]=='S')
			                        {
							number1+=19;
			                        }
			else if(name2[i]=='t'||name2[i]=='T')
			                        {
							number1+=20;
			                        }
			else if(name2[i]=='u'||name2[i]=='U')
			                        {
							number1+=21;
			                        }
			else if(name2[i]=='v'||name2[i]=='V')
                        {
				number1+=22;
                        }
			else if(name2[i]=='w'||name2[i]=='W')
                        {
				number1+=23;
                        }
			else if(name2[i]=='x'||name2[i]=='X')
                        {
				number1+=24;
                        }
			else if(name2[i]=='y'||name2[i]=='Y')
                        {
				number1+=25;
                        }
			else if(name2[i]=='z'||name2[i]=='Z')
                        {
				number1+=26;
                        }
            else
			{
				number1=number1;
			} 
		}/*name2*/
                        //cout<<"number:"<<number<<"number1:"<<number1<<endl;
int tmp1=0;
int tmp2=0;
int tmp3=0;
int tmp4=0;

while(number>=10)
{
	tmp1=tmp1+number%10;
	number=number/10;
}
tmp1=tmp1+number;
//cout<<"tmp1:"<<tmp1<<endl;

while(tmp1>=10)
{
	tmp3=tmp3+tmp1%10;
	tmp1=tmp1/10;
}
tmp3=tmp3+tmp1;
//cout<<"tmp3:"<<tmp3<<endl;
while(number1>=10)
{
	tmp2=tmp2+number1%10;
	number1=number1/10;
}
tmp2=tmp2+number1;
//cout<<"tmp2:"<<tmp2<<endl;
while(tmp2>=10)
{
	tmp4=tmp4+tmp2%10;
	tmp2=tmp2/10;
}
tmp4=tmp4+tmp2;
//cout<<"tmp4:"<<tmp4<<endl;
float a=(float)tmp3;
float b=(float)tmp4;
//cout<<a<<" "<<b<<endl;
answer=a/b;
//printf("%f\n",answer);
answer=answer*100;
if(answer<=100)
{
	printf("%.2f %%\n",answer);
	//cout<<answer<<endl;
}
else if(answer>100)
{
	answer=b/a;
	answer=answer*100;
	printf("%.2f %%\n",answer);
//cout<<answer<<endl;
}
else
{
	printf("0.00 %%\n");
}
for(int i=0;i<100;++i)
{
	name1[i]='\0';
	name2[i]='\0';
}
	}
return 0;






}
