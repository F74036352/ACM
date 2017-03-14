#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char start[10]={'\0'};
	char end[10]={'\0'};
	char text[500]={'\0'};
	//printf("%c\n",test-5);
	gets(start);
	while (strcmp(start,"ENDOFINPUT")!=0)
	{	
		if (strcmp(start, "START")==0)
        {	
				gets(text);
			
				for (int i=0;i<500;++i)
				{
					if ((int)text[i]<=90 && (int)text[i]>=70)
					{
						text[i]=text[i]-5;
					}
					else if ((int)text[i]<=69 && (int)text[i]>=65)
					{
						text[i]=text[i]+21;
					}					
				}
				puts(text);
				// printf("\n");
				// for (int i=0;i<500;++i)
				// {
				// 	printf("%c",text[i]);
				// }
				//puts(text);													
		}
		for (int i=0;i<10;++i)
		{
			end[i]='\0';
			start[i]='\0';
		}
		for (int i=0;i<500;++i)
		{
			text[i]='\0';
		}
		gets(end);	
		gets(start);		
		

		// if (strcmp(end,"END")==0)		
		// {
		// 	break;
		// }
	}









}