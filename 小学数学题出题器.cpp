#include<stdio.h>
#include<time.h>
#include<windows.h>
void CreateMath(int mathmap[][4],int quantity_max,int number_max);
void OutputAnswers(int Math[][4],int quantity_max);
int main()
{
	int qmax,nmax;
	char t;
	printf("输入题目数量和最大值：");
	scanf("%d%d",&qmax,&nmax);
	int mathmap[qmax][4];
	printf("题目输出中：\n");
	CreateMath(mathmap,qmax,nmax);
	printf("输出参考答案？Y/N");
	fflush(stdin);
	t=getchar();
	if(t=='Y'||t=='y')
	{
		printf("解答：\n");
		OutputAnswers(mathmap,qmax);
	}
	return 0;
}
void CreateMath(int mathmap[][4],int quantity_max,int number_max)
{
	int a,b,calc,ans,temp;
	bool same[4],issame=0;
	srand(time(NULL));
	for(int i=0;i<quantity_max;i++)
	{
		if(issame||(mathmap[i-1][2]==3&&mathmap[i-1][2]==1))i--;
		a=rand()%number_max;
		b=rand()%number_max;
		calc=rand()%4;
		mathmap[i][1]=calc;
		if(calc==0)
		{
			mathmap[i][0]=a;
			mathmap[i][2]=b;
			mathmap[i][3]=a+b;
		}
		if(calc==2)
		{
			mathmap[i][0]=a;
			mathmap[i][2]=b;
			mathmap[i][3]=a*b;
		}
		if(calc==1||calc==3)
			if(b>a)
			{
				temp=a;
				a=b;
				b=temp;
			}
		if(calc==1)
		{
			mathmap[i][0]=a;
			mathmap[i][2]=b;
			mathmap[i][3]=a-b;
		}
		if(calc==3)
		{
			if(b==0)b=a-1;
			while(a%b!=0)
			{
				temp=b;
				if(b>0)b--;
				if(b==0)
				{
					a++;
					b=temp;
				}
			}
			mathmap[i][0]=a;
			mathmap[i][2]=b;
			mathmap[i][3]=a/b;
		}
		for(int j=0;j<i;j++)
		{
			for(int k=0;k<4;k++)
				same[k]=(mathmap[j][k]==mathmap[i][k]);
			issame=same[0]&&same[1]&&same[2]&&same[3];
			if(issame)break; 
		}
	}
	for(int i=0;i<quantity_max;i++)
	{
		printf("%d",mathmap[i][0]);
		switch(mathmap[i][1])
		{
			case 0:printf("+");break;
			case 1:printf("-");break;
			case 2:printf("×");break;
			case 3:printf("÷");break;
		}
		printf("%d=",mathmap[i][2]);
		if((i+1)%8==0)printf("\n");
		else printf("  ");	
	}
}
void OutputAnswers(int mathmap[][4],int quantity_max)
{
	for(int i=0;i<quantity_max;i++)
	{
		printf("%d",mathmap[i][0]);
		switch(mathmap[i][1])
		{
			case 0:printf("+");break;
			case 1:printf("-");break;
			case 2:printf("×");break;
			case 3:printf("÷");break;
		}
		printf("%d=%d",mathmap[i][2],mathmap[i][3]);
		if((i+1)%8==0)printf("\n");
		else printf("  ");
	}
}
