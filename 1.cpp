 //这是一个用来给用户自测四则运算的程序
//需要用户自行输入题量，并填写答案，结果会显示正确题数


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//界面优化
void Menu()
{
	printf("---------------------------------------------------------------------------------\n");
	printf("*****************Please enter number to chioce your language:****************\n");
	printf("*******      1:Chinese  2:English  3:Japanese  4:Franch  5:German       **********\n");
	printf("---------------------------------------------------------------------------------\n\n");

}
//文本控制
void lang(int a,int b)
{
	FILE *p;
	if(a==1) p=fopen("Chinese.txt","r");
	if(a==2) p=fopen("English.txt","r");
	if(a==3) p=fopen("Japanese.txt","r");
	if(a==4) p=fopen("Franch.txt","r");
	if(a==5) p=fopen("German.txt","r");
	int line=1;
	char StrLine[100];
	while(!feof(p))
	{
		if(line==b)
		{
			fgets(StrLine,100,p);
			printf("\n%s",StrLine);
		}
		fgets(StrLine,100,p);
		line++;
	}
	fclose(p);
	
}

//结构体，编号，运算符，级别
struct symble
{
	int _num;
	char _sym;
	int level;
}sym[4]={{0,'+',1},{1,'-',1},{2,'*',2},{3,'/',2}};

//结构体，前面的是分子，后面的是分母
struct frac
{
	int member;
	int deno;
};


//复杂运算函数，除了除法
int complex(int num,int a,int b)
{
	switch (num) 
	{
case 0:return a+b;
	break;
case 1:return a-b;	
	break;
case 2:return a*b;
	break;
	}
}





//输出函数
frac print_1(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)     
	{ 
		result.member=complex(sym[c_3]._num,complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),th),fo);
		result.deno=0;
	}
	else
	{
		if(sym[c_2].level==1) {result.member=complex(sym[c_2]._num,on,tw*complex(sym[c_3]._num,th,fo)); result.deno=tw;}
		else if(sym[c_3].level==1)
		{
			if(sym[c_1]._num==3 && sym[c_2]._num==3) {result.member=complex(sym[c_3]._num,on,tw*th*fo); result.deno=th*fo;}
			else if(sym[c_1]._num==3 && sym[c_2]._num==2) {result.member=complex(sym[c_3]._num,on*th,fo*tw); result.deno=tw;}
			else {result.member=complex(sym[c_3]._num,on*tw,fo); result.deno=th;}
		}
		else
		{
			if(sym[c_1]._num==3)
			{
				if(sym[c_2]._num==3)
				{
					if(sym[c_3]._num==3) {result.member=on; result.deno=tw*th*fo;}
					else {result.member=on*fo; result.deno=tw*th;}
				}
				else
				{
					if(sym[c_3]._num==3) {result.member=on*th; result.deno=tw*fo;}
					else {result.member=on*th*fo; result.deno=tw;}
				}
			}
			else
			{
				if(sym[c_2]._num==3)
				{
					if(sym[c_3]._num==3) {result.member=on*tw; result.deno=th*fo;}
					else {result.member=on*tw*fo; result.deno=th;}
				}
				else {result.member=on*tw*th; result.deno=fo;}
			}
		}
	}
	return result;
}

frac print_1_1(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_3]._num,complex(sym[c_1]._num,on,complex(sym[c_2]._num,tw,th)),fo);
		result.deno=0;
	}
    else
	{
		result.member=complex(sym[c_1]._num,complex(sym[c_3]._num,on,fo)*th,tw);
		result.deno=th;
	}
	return result;
}
frac print_1_2(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
		result.deno=0;
	}
	else
	{
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw)*fo,th);
		result.deno=fo;
	}
	return result;
}
frac print_1_3(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)     //                                    
{
	frac result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{	
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
		result.deno=0;
	}
	else
	{
		if(sym[c_1]._num==3 && sym[c_3]._num==3) {result.member=complex(sym[c_2]._num,on*fo,tw*th); result.deno=tw*fo;}
		else 
			if(sym[c_1]._num==3 && sym[c_3]._num==2) { result.member=complex(sym[c_2]._num,on,th*fo*tw); result.deno=tw;}
			else { result.member=complex(sym[c_2]._num,on*tw*fo,th); result.deno=fo;}
	}

	return result;
}
frac print_1_4(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)       //                                    
{
	frac result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_1]._num,on,complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo));
		result.deno=0;
	}
	else
	{
		if(sym[c_2]._num==3 && sym[c_3]._num==3) { result.member=complex(sym[c_1]._num,on*th*fo,tw); result.deno=fo*th;}
		else
			if(sym[c_2]._num==3 && sym[c_3]._num==2) { result.member=complex(sym[c_1]._num,on*th,tw*fo); result.deno=th;}
			else { result.member=complex(sym[c_1]._num,on*fo,tw*th); result.deno=fo;}
	}
	return result;
}
frac print_2(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)               // 
{
    frac result;
	printf("%d %c (%d %c %d) %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_3]._num,complex(sym[c_1]._num,on,complex(sym[c_2]._num,tw,th)),fo);
		result.deno=0;
	}
	else
	{
		if(sym[c_3].level==1) {result.member=complex(sym[c_3]._num,on,fo*complex(sym[c_2]._num,tw,th)); result.deno=complex(sym[c_2]._num,tw,th);}
		else
			if(sym[c_1]._num==3 && sym[c_3]._num==3) {result.member=on; result.deno=complex(sym[c_2]._num,tw,th)*fo;}
			else 
				if(sym[c_1]._num==3 && sym[c_3]._num==2) { result.member=on*fo;result.deno=complex(sym[c_2]._num,tw,th);}
				else {result.member=on*complex(sym[c_2]._num,tw,th); result.deno=fo;}
	}
	return result;
}
frac print_2_1(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)                            
{
    frac result;
	printf("%d %c (%d %c %d) %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_1]._num,on,complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo));
		result.deno=0;
	}
	else
	{
		result.member=complex(sym[c_1]._num,on*fo,complex(sym[c_2]._num,tw,th));
		result.deno=fo;
	}

	return result;
}
frac print_3(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	printf("%d %c (%d %c %d %c %d) = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_1]._num,on,complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo));
		result.deno=0;
	}
	else
	{
			result.member=on;
			result.deno=complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo);
	}
	return result;
}
frac print_4(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	printf("(%d %c %d) %c (%d %c %d) = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
		result.deno=0;
	}
	else
	{
		result.member=complex(sym[c_1]._num,on,tw);
		result.deno=complex(sym[c_3]._num,th,fo);
	}

	return result;
}
frac print_5(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)            //
{
	frac result;
	printf("%d %c %d %c (%d %c %d) = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
		result.deno=0;
	}
	else
	{
		if(sym[c_1]._num==3 && sym[c_2]._num==3) {result.member=on; result.deno=tw*complex(sym[c_3]._num,th,fo); }
		else
			if(sym[c_1]._num==3 && sym[c_2]._num==2) {result.member=on*complex(sym[c_3]._num,th,fo); result.deno=tw;}
			else { result.member=on*tw; result.deno=complex(sym[c_2]._num,th,fo);}
	}
	return result;
}
frac print_6(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)            //
{
    frac result;
	printf("(%d %c %d %c %d) %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_3]._num,complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),th),fo);
		result.deno=0;
	}
	else
	{
		if(sym[c_1]._num==3 && sym[c_3]._num==3) {result.member=complex(sym[c_2]._num,on,tw*th); result.deno=tw*fo;}
		else
			if(sym[c_1]._num==3 && sym[c_3]._num==2) {result.member=fo*complex(sym[c_2]._num,on,tw*th); result.deno=tw;}
			else { result.member=complex(sym[c_2]._num,on*tw,th); result.deno=fo;}
	}
	return result;
}
frac print_7(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)              //
{
	frac result;
	printf("(%d %c %d) %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_3]._num,complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),th),fo);
		result.deno=0;
	
	}
	else
	{
		if(sym[c_2]._num==3 && sym[c_3]._num==3) {result.member=complex(sym[c_1]._num,on,tw); result.deno=th*fo;}
		else 
			if(sym[c_2]._num==3 && sym[c_3]._num==2) {result.member=fo*complex(sym[c_1]._num,on,tw); result.deno=th;}
			else {result.member=th*complex(sym[c_1]._num,on,tw); result.deno=fo;}
	}
	return result;
}



//化简函数
frac judge(frac t)
{
	int x,y,z;
	if(t.deno!=0 && t.member!=0)
	{
		x=t.member>t.deno ? t.member : t.deno;
		y=t.member<=t.deno ? t.member : t.deno;
		while(y!=0)
		{
			z=x;
			x=y;
			y=z%y;
		}
		t.member=t.member/x;
		t.deno=t.deno/x;
		t.deno=(t.deno==1)? 0 : t.deno;
		return t;
	}
	else 
		if(t.member==0) {t.deno=0;  return t;}
    	else
	    	return t;

}

//加分函数
int sco(frac result)
{
	int me,de,answer;   //分子，分母，用户整数答案
	char ch;   //除号
	if(result.deno!=0)  //得数是分式
	{
		scanf("%d%c%d",&me,&ch,&de);
		if(me==result.member && de==result.deno && ch=='/')
		{
			printf("R\n");
			return(1);
		}
		else
		{
			printf("W\n");
			return(0);
		}
	}
	else               //得数是整数
	{
		scanf("%d",&answer);
		if(answer==result.member)
		{
			printf("R\n");
			return(1);
		}
		else
		{
			printf("W\n");
			return(0);
		}
	}
}

 

//operation函数是用来决定生成什么算式的
int operation(int score)
{
	frac sum_int;   //定义结构
	srand((unsigned)time(0));   //随机数产生
	int one=rand()%10+1,two=rand()%10+1,three=rand()%10+1,four=rand()%10+1;
	int chioce_1=rand()%4,chioce_2=rand()%4,chioce_3=rand()%4;           //随机决定运算符
	if(sym[chioce_1].level==sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_3].level)    //级别都一样的情况
	{
		sum_int=judge(print_1(chioce_1,chioce_2,chioce_3,one,two,three,four));                
		score+=sco(sum_int);         
	}
	else if(sym[chioce_1].level>sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_3].level)  //二级，一级，一级的情况
	{
		switch(rand()%3) 
		{
		case 0:sum_int=judge(print_1(chioce_1,chioce_2,chioce_3,one,two,three,four));          
			break;
		case 1:sum_int=judge(print_2(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 2:sum_int=judge(print_3(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	else if(sym[chioce_2].level>sym[chioce_1].level&&sym[chioce_1].level==sym[chioce_3].level)  //一级，二级，一级的情况
	{
		switch(rand()%2)
		{
		case 0:sum_int=judge(print_1_1(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 1:sum_int=judge(print_4(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
		else if(sym[chioce_3].level>sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_1].level)  //一级，一级，二级的情况
	{
		switch(rand()%3)
		{
		case 0:sum_int=judge(print_1_2(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 1:sum_int=judge(print_2_1(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 2:sum_int=judge(print_6(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	else if(sym[chioce_1].level==sym[chioce_2].level&&sym[chioce_2].level>sym[chioce_3].level)  //二级，二级，一级的情况
	{
		switch(rand()%2)
		{
		case 0:sum_int=judge(print_1(chioce_1,chioce_2,chioce_3,one,two,three,four));         
			break;
		case 1:sum_int=judge(print_5(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	else if(sym[chioce_1].level>sym[chioce_2].level&&sym[chioce_1].level==sym[chioce_3].level)  //二级，一级，二级的情况
	{
		switch(rand()%3)
		{
		case 0:sum_int=judge(print_1_3(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 1:sum_int=judge(print_2(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 2:sum_int=judge(print_6(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	else if(sym[chioce_1].level>sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_3].level)  //一级，二级，二级的情况
	{
		switch(rand()%2)
		{
		case 0:sum_int=judge(print_1_4(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 1:sum_int=judge(print_7(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	return score;
}


//主函数
int main()
{
	int i;
	int number;//用户输入题数
	int Q,score;
	Menu();
	scanf("%d",&Q);
	for(;Q<1||Q>5;)
    {
    	printf("The language is beyond our ability, please try again.\n");
    	scanf("%d",&Q); 
    }
	do
	{
			score=0;  //计分
			/*printf("接下来，如果您的答案正确，将会输出R,否则会输出W\n");*/
			lang(Q,1);
			/*printf("请输入题数：");*/ 
			lang(Q,2);
			scanf("%d",&number);
			for(i=0;i<number;i++)
				score=operation(score);//运算函数
			/*printf("您答对%d题\n",score);  */
			lang(Q,3); 
			printf("%d",score);
			/*printf("答错%d题\n",number-score);*/
			lang(Q,4); 
			printf("%d",number-score);
			getchar();
			/*printf("继续请按任意键，结束请输入“e”：");*/
			lang(Q,5);
	    	if(getchar()=='e')//用户输入e可结束测试
		    	break;
	}while(1);
/*	if(Q=='C')
	{
		do
		{
			int score=0;  //计分
			printf("接下来，如果您的答案正确，将会输出R,否则会输出W\n");
			printf("请输入题数：");
			scanf("%d",&number);
			for(i=0;i<number;i++)
				score=operation(score);//运算函数
			printf("您答对%d题\n",score);
			printf("答错%d题\n",number-score);
			getchar();
			printf("继续请按任意键，结束请输入“e”：");
	    	if(getchar()=='e')//用户输入e可结束测试
		    	break;
		}while(1);
	}
	else
	{
		do
		{
			int score=0;  //计分
			printf("The next,if your answer is right, you will see R,otherwise, you will see W\n");
			printf("Please input number：");
			scanf("%d",&number);
			for(i=0;i<number;i++)
				score=operation(score);//运算函数
			printf("Correct answer’s number are：%d\n",score);
			printf("Wrong answer’s number are：%d\n",number-score);
			getchar();
			printf("Please press any key to continue,input 'e'to end：");
	    	if(getchar()=='e')//用户输入e可结束测试
		    	break;
		}while(1);
	}
	*/
	return 0;
}