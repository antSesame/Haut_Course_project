#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<windows.h>
#pragma comment(lib,"winmm.lib")
#define I 20
#define R 340
char password[9];
//物品结构体 
struct node{	
	int num;
	char name[20];
	char auther[20];
	char type[20];
	char where[30]; 
	char date[20];
	char Tedian[30]; 
	struct node  *next;
};
//用户结构体 
struct User
{
	char Xingming[20];
	char card[20];
	char pass[20];
	struct User *next;
}; 
void menu();//主界面
void save(struct node *head);//文件录入函数 
struct node * read(struct node *pl);//文件读出函数（
void input();//录入信息函数
void insert(struct node *head);//插入信息函数
void modify(struct node *head);//修改信息函数
void search(struct node *head );//查询信息函数
void rankbynum( struct node *head);//排序函数
void swap(struct node *p1,struct node *p2);//交换函数，用于排序功能中
void showall(struct node *pl);//遍历函数，用于浏览信息
int deletething(struct node *head);//删除信息函数
int  ad();//打开界面 
void checkfirst();//密码初始化 
void login();//登陆 
void update();//修改密码 
void dongtai();
int bc();//管理员选择界面 
void jiemian();//管理用户界面 
void inputU();//用户录入 
void second();//用户界面 
void Yonghu(struct User *head);//用户录入文件函数 
struct User * readU(struct User *pl );//用户文件读取函数 
void insertY(struct User *head);//添加用户 
int  deleteUser(struct User *head); //删除用户 
void showallUser(struct User *p1);//浏览用户 
void modifyUser(struct User *head);//修改用户信息 
void searchU(struct User *head);// 查询用户信息 
void AD();//对物品信息的管理 
void BC();//对用户信息的管理
void EF();//用户的功能实现 
void loginU(struct User *head);//用户登录
void Usearch(struct node *head);//用户查询
void Ushowall(struct node *pl);//用户浏览 (日期按时间先后的顺序） 
void Partshowall(struct node *pl);//部分遍历 
void Tongji(struct node *pl);
void Tongji(struct node *pl)
{
	int a=0,b=0,c=0,d=0,e=0,f=0;
	struct node *p;
	p=pl;
	int max;
		while(p!=NULL){	
			if(strstr(p->type,"卡")>0) 
			a++;
		    if(strstr(p->type,"书")>0) 
		    b++;
			if(strstr(p->type,"现金")>0)  
			c++;
			if(strstr(p->type,"电子设备")>0)  
			d++;
			if(strstr(p->type,"钥匙")>0) 
			e++; 
			if(strstr(p->type,"交通工具")>0)  
			f++; 
			p=p->next;
		}
		max=a;
		if(b>max)		
		max=b;	
		if(c>max)
		max=c;
		if(d>max)
		max=d;
		if(e>max)
		max=e;
		if(f>max)
		max=f;
		printf("\n"); 
		if(a==max)
		printf("*请同学注意对卡的保存，最近丢失卡的现象较严重*\n");
		if(b==max)
		printf("*请同学注意对书的保存，最近丢失书的现象较严重*\n");
		if(c==max)
		printf("*请同学注意对现金的保存，最近丢失现金的现象较严重*\n");
		if(d==max)
		printf("*请同学注意对电子设备的保存，最近丢失电子设备的现象较严重*\n");
		if(e==max)
		printf("*请同学注意对钥匙的保存，最近丢失钥匙的现象较严重*\n");
		if(f==max)
		printf("*请同学注意对交通工具的保存，最近丢失交通工具的现象较严重*\n"); 		
}
int main(void)
{
//	PlaySound ("1.wav",NULL,SND_LOOP | SND_ASYNC);
	int choice,x,y;
    struct node *head;
    struct User *headU;
	head=NULL;
	headU=NULL;
	dongtai();
	system("color 3");
	  x=ad();
	switch(x){ 
		case 1:
			system("cls");
			checkfirst();
			login();//登陆 
            system("cls"); 
            y=bc();
            
    switch(y){
     	    case 1:
             BC();
 	     	case 2:
 	     	AD();
 	     	case 3:
			update();
			exit(0);
	        }
     	case 2:
	        EF();   
        case 3:
        	
            system("cls");
            printf("\n\n\n\n\t\t\t\t谢谢使用！\n\t\t\t");
	        return 0;		 
}}
//用户的功能 
void EF()
{ 
	int choice;
    struct node *head;
    struct User *headU;
	head=NULL;
	headU=NULL;
        system("cls");
		headU=readU(headU);
		if(headU==NULL)
		printf("请先录入！！！\n");	
		else 
		loginU(headU);
	 while(1)
		{   
		    second();
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
		 system("cls");
		head=read(head);
		if(head==NULL)
		printf("请先录入！！！\n");	
		else 
		 Usearch(head);
				 break;
				 
				 case 2:
				 	system("cls");
				 	head=read(head);
		            if(head==NULL)
		            printf("请先录入！！！\n");
		            else
			        Ushowall(head);
				 	break; 
					  	   
		        	case 0:
				 	system("cls");
					printf("\n\n\n\n\t\t\t\t谢谢使用！\n\t\t\t");
					exit(0);	
				    default :
					printf("输入错误请重新输入\n");
					break;
			}
		 } 

 }
// 对用户信息的管理
void BC()
{
	struct User *headU;
	headU=NULL;
		int choice;
	    while(1)
		{	
           jiemian();			
     		scanf("%d",&choice);
     		switch(choice)
			{
     			case 1:
     			inputU();
     			break; 
     			case 2:
				headU=readU(headU);
			    if(headU==NULL)
				printf("请先录入！！！\n");					
			    else 
				insertY(headU);
				break;
			    case 3:	
				headU=readU(headU);
			    if(headU==NULL)
				printf("请先录入！！！\n");					
			    else 
				deleteUser(headU);
				break;	
				case 4:
				headU=readU(headU);
			    if(headU==NULL)
				printf("请先录入！！！\n");					
			    else 
			    modifyUser(headU);
			    break;
				case 5:
				headU=readU(headU);
			    if(headU==NULL)
				printf("请先录入！！！\n");					
			    else 
				searchU(headU);
				break;
				case 6:
				headU=readU(headU);
			    if(headU==NULL)
				printf("请先录入！！！\n");					
			    else 
				showallUser(headU);	
				break; 
			    case 0:
			system("cls");
			printf("                   谢谢使用！\n"); 
			exit(0);//退出系统
			    default:
			    	system("cls");
				printf("输入有误，请重新输入\n") ; 
			
			}
		
 	    }
 }
 //对物品信息的管理 
void AD()
{
	struct node *head;
	head=NULL;
	int choice;
	while (1){ 
		menu();
		scanf("%d",&choice);
		switch(choice){	
		case 1:
			system("cls");
			input();
			break;		
		case 2:
			system("cls");
			head=read(head);
			if(head==NULL)
				printf("请先录入！！！\n");	
			else
			     				
				 insert(head);
			break;		
		case 3:
			head=read(head);
			if(head==NULL)
				printf("请先录入！！！\n");					
			else
			    
				deletething(head);
                  
			break;											
		case 4:
	        head=read(head);
			if(head==NULL)
				printf("请先录入！！！\n");					
			else 
			   
				modify(head);
			break;			
		case 5:
			system("cls");
			  head=read(head);
			if(head==NULL)
				printf("请先录入！！！\n");					
			else 
			  
				search(head);
				 
			break;											
		case 6:
			system("cls");
			head=read(head);
			if(head==NULL)
				printf("请先录入！！！\n");					
			else  
			   
				rankbynum(head);//排序
				 
			break;												
		case 7:
			system("cls");
			 head=read(head);
			if(head==NULL)
				printf("请先录入！！！\n");					
			else 
			   	
				showall(head);//遍历
				
			break;						
		case 0:
			system("cls");
			printf("                   谢谢使用！\n"); 
			exit(0);//退出系统
		default:
			system("cls");
			printf("输入有误！");
		}	
	}

} 
void loginU(struct User *head)//用户登录
{
int i,n=3;
char a[20];
char b[20];
int flag=0;
struct User *p;
p=head;
printf("请先登陆\n"); 
printf("请输入学号：");
		scanf("%s",a);
		while(p!=NULL){	
			if(strcmp(p->card,a)==0&&n>0){
					flag=1;
			printf("请输入密码(三次输入错误请重新登陆)\n");
			for(i=0;i<8&&((b[i]=getch())!=13);i++)
			    putch('*');
		     	b[i]='\0';
			    if(strcmp(p->pass,b)==0)
				 {
				system("cls"); 
				 printf("登陆成功\n");
				 break; 
				 } 
			    else
			    printf("密码错误\n");
			    n--; 
			}	
			else
			p=p->next;
		}
		if(flag==0) {
		printf("对不起，找不到您要查询的用户，请核对信息后重新查询。\n");
		exit(1);
		}
		if(!n)
	{
		printf("请退出，你的三次输入错误\n");
		getch();
		exit(1);
	}			
}

//管理员登陆函数 
void login()
{
	int i,n=3;
	char a[9];
	do{
		printf("请输入密码");
		for(i=0;i<8&&((a[i]=getch())!=13);i++)
		putch('*');
		a[i]='\0';
		if(strcmp(a,password))
		{
			printf("\n密码错误!\n"); 
			n--;
		 } 
		 else
		
		 break;
		 
	}while(n>0);
	if(!n)
	{
		printf("请退出，你的三次输入错误\n");
		getch();
		exit(1);
	}
}
//打开界面 
int  ad()
{	
    int x;
    printf(" _____________________________ \n");
	printf("|欢迎使用校园失物招领管理系统 |\n");
	printf("|_____________________________|\n");
	printf("  |     1.管理员模式        |\n");
	printf("  |_________________________|\n");
	printf("  |     2.用户模式          |\n");
	printf("  |_________________________|\n");
	printf("  |     3.退出系统          |\n"); 
	printf("  |_________________________|\n");
	scanf("%d",&x);
	return x;
 }  
int bc()//管理员管理模块选择界面 
{
	int y;
	printf("____________________\n");
	printf("|1.对用户的管理     |\n");
	printf("|___________________|\n");
	printf("|2.对物品信息的管理 |\n"); 
	printf("|___________________|\n");
	printf("|3.修改密码         |\n");
	printf("|___________________|\n");
	scanf("%d",&y);
	return y;
}
//用户查询界面 
void second() 
{
	    struct node *head;
	    head=NULL;
		head=read(head);
		if(head==NULL)
		printf("请先录入！！！\n");	
		else
		Tongji(head);
	printf(" _______________________________________________________\n");
	printf(" |                     *用户查询界面*                  |\n"); 
	printf(" |_____________________________________________________|\n"); 
	printf(" |     1:查询物品信息      |      2:浏览所有物品的信息 |\n");
	printf(" |_________________________|___________________________|\n"); 
	printf(" |     0:退出系统          |                           |\n");
	printf(" |_________________________|___________________________|\n"); 
	printf(" | 小贴士：序号在1-1000的物品请去5101查找，其余的在5102|  \n");
    printf(" |_____________________________________________________|\n");
}
//对用户的管理界面 
void jiemian()
{
	printf("_____________________________________\n");
	printf("|1:录入用户信息   |   2:增添用户信息|\n");
	printf("|_________________|_________________|\n");
	printf("|3:删除用户信息   |   4:修改用户信息|\n");
	printf("|_________________|_________________|\n");
	printf("|5:查询用户信息   |   6:浏览用户信息|\n");
	printf("|_________________|_________________|\n");
	printf("|0:退出系统       |                 |\n");
	printf("|_________________|_________________|\n");
 } 
//对物品的信息的管理界面 
void  menu()
{
	printf("_____________________________________\n");
	printf("|1:录入物品信息   |   2:增添物品信息|\n");
	printf("|_________________|_________________|\n");
	printf("|3:删除物品信息   |   4:修改物品信息|\n");
	printf("|_________________|_________________|\n");
	printf("|5:查询物品信息   |   6:给物品排序  |\n");
	printf("|_________________|_________________|\n");
	printf("|7:浏览物品信息   |   0:退出系统    |\n");
	printf("|_________________|_________________|\n");
	printf("        请输入您的选择：");
}
//对用户的查询函数(其中按学号可进行模糊查询，以便于查询一个班级的学生用户信息） 
void searchU(struct User *head)
{
	struct User *p;
	int n;
	char Xingming[20];
	char card[20];
	char pass[20]; 
	int flag=0;
	p=head;
	printf("__________________________________\n");
	printf("|1:按姓名查询    |   2:按学号查询|\n");
	printf("|________________|_______________|\n");
	printf("|3:按密码查询    |   0:取消      |\n"); 
	printf("|________________|_______________|\n");
    printf("请输入您的选择：\n");
	scanf("%d",&n);
	switch(n){
	case 1:
		printf("请输入姓名：");
		scanf("%s",Xingming);
		while(p!=NULL){	
			if(strcmp(p->Xingming,Xingming)==0){
				printf(" _____________________________________\n");
				printf("|姓名     |     学号      |     密码  |\n");
				printf("|_________|_______________|___________|\n");
				printf("|%5s   | %8s  |%8s   |\n",p->Xingming,p->card,p->pass);
				printf("|_________|_______________|___________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的用户，请核对信息后重新查询。\n");
		}
		break;
	case 2:
		printf("请输入学号：");
		scanf("%s",card);
		while(p!=NULL){	
			if(strstr(p->card,card)>0){
				printf(" _____________________________________\n");
				printf("|姓名     |     学号      |     密码  |\n");
				printf("|_________|_______________|___________|\n");
				printf("|%5s   | %8s  |%8s   |\n",p->Xingming,p->card,p->pass);
				printf("|_________|_______________|___________|\n");
			flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的用户，请核对信息后重新查询。\n");
		}
		break;
	case 3:
		printf("请输入密码");
		scanf("%s",pass);
		while(p!=NULL){	
			if(strcmp(p->pass,pass)==0){
				printf(" _____________________________________\n");
				printf("|姓名     |     学号      |     密码  |\n");
				printf("|_________|_______________|___________|\n");
				printf("|%5s   | %8s  |%8s   |\n",p->Xingming,p->card,p->pass);
				printf("|_________|_______________|___________|\n");
			flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的用户，请核对信息后重新查询。\n");
		}
		break;	
	
}}
//用户查询函数（其中分为三类查询，分类查询：按类型、精确查询：按时间  模糊查询：按名称，地点，类型，时间段 ）
//查询到的是部分信息 
void Usearch(struct node *head)
	{   
	struct node *p;
	int n;
	char name[20]; 
	char type[20];
	char where[20];
	char date[20]; 
	char date1[20];
	char date2[20]; 
	int flag=0;
	p=head;
	
	printf("________________________________________\n");
	printf("|1:按名称查询      |     2:按类型查询  |\n");
	printf("|__________________|___________________|\n");
	printf("|3:按地点查询      |     4:按时间段查询|\n");
	printf("|__________________|___________________|\n");
	printf("|5:按时间查询      |     0:取消        |\n");       
	printf("|__________________|___________________|\n");
	printf("请输入您的选择:\n");
	scanf("%d",&n);
	switch(n){
	
	case 1:
		system("cls");
		printf("请输入名称：");
		scanf("%s",name);
		while(p!=NULL){	
			if(strstr(p->name,name)>0){	 	
		printf("________________________________________________________________\n");
		printf("|序号    |    名称   |   类别     |   地点         |    时间    |\n");
		printf("|________|___________|____________|________________|____________|\n");
		printf("|%-4d    | %-8s  |%-10s  |%-16s|%-10s  |\n",p->num,p->name,p->type,p->where,p->date);
	    printf("|________|___________|____________|________________|____________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}
		break; 
	
	case 2:
		system("cls");
		printf("请输入类型：");
		scanf("%s",type);
		while(p!=NULL){	
			if(strstr(p->type,type)>0){
			
			printf("________________________________________________________________\n");
		printf("|序号    |    名称   |   类别     |   地点         |    时间    |\n");
		printf("|________|___________|____________|________________|____________|\n");
		printf("|%-4d    | %-8s  |%-10s  |%-16s|%-10s  |\n",p->num,p->name,p->type,p->where,p->date);
	    printf("|________|___________|____________|________________|____________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}		
		break;
	case 3:
		system("cls");
		printf("请输入地点：");
		scanf("%s",where);
		while(p!=NULL){	
			if(strstr(p->where,where)>0){
		printf("________________________________________________________________\n");
		printf("|序号    |    名称   |   类别     |   地点         |    时间    |\n");
		printf("|________|___________|____________|________________|____________|\n");
		printf("|%-4d    | %-8s  |%-10s  |%-16s|%-10s  |\n",p->num,p->name,p->type,p->where,p->date);
	    printf("|________|___________|____________|________________|____________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}
		break;
	case 4:
			system("cls");
		printf("请输入时间起始时间(2016.01.01)：\n");
		scanf("%s",date1);
		printf("请输入结束时间：\n");
		scanf("%s",date2);
		while(p!=NULL){	
			if(strcmp(p->date,date1)>=0&&strcmp(p->date,date2)<=0){
		printf("________________________________________________________________\n");
		printf("|序号    |    名称   |   类别     |   地点         |    时间    |\n");
		printf("|________|___________|____________|________________|____________|\n");
		printf("|%-4d    | %-8s  |%-10s  |%-16s|%-10s  |\n",p->num,p->name,p->type,p->where,p->date);
	    printf("|________|___________|____________|________________|____________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}	
		break;
		case 5:	
		system("cls");
		 printf("请输入时间(例如2016.01.01)：");
		scanf("%s",date);
		while(p!=NULL){	
			if(strcmp(p->date,date)==0){
		printf("________________________________________________________________\n");
		printf("|序号    |    名称   |   类别     |   地点         |    时间    |\n");
		printf("|________|___________|____________|________________|____________|\n");
		printf("|%-4d    | %-8s  |%-10s  |%-16s|%-10s  |\n",p->num,p->name,p->type,p->where,p->date);
	    printf("|________|___________|____________|________________|____________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}
		break;
	case 0:
		break;
	default:
		printf("输入有误！\n");
		break;
	}
}
//管理员查询函数（可查询到物品的全部信息 ） 
void search(struct node *head )
{   
	struct node *p;
	int num,n;
	char name[20]; 
	char auther[20];
	char type[20];
	char where[20];
	char date[20];
	char date1[20];
	char date2[20];
	int flag=0;
	p=head;
	printf("______________________________________\n");
	printf("|1:按序号查询    |    2:按名称查询   |\n");
	printf("|________________|___________________|\n"); 
	printf("|3:按姓名查询    |    4:按类型查询   |\n");
	printf("|________________|___________________|\n"); 
	printf("|5:按地点查询    |    6:按时间查询   |\n");
	printf("|________________|___________________|\n"); 
	printf("|7:按时间段查询  |    0:取消         |\n");
	printf("|________________|___________________|\n");
	printf("请输入您的选择：\n");
	scanf("%d",&n);
	switch(n){
	case 1:
		printf("请输入序号：");
		scanf("%d",&num);
		while(p!=NULL){	
			if(p->num==num){ 
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}
		break;
	case 2:
		printf("请输入名称：");
		scanf("%s",name);
		while(p!=NULL){	
			if(strstr(p->name,name)>0){
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}
		break;
	case 3:
		printf("请输入名字");
		scanf("%s",auther);
		while(p!=NULL){	
			if(strcmp(p->auther,auther)==0){
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}
		break;
	case 4:
		printf("请输入类型：");
		scanf("%s",type);
		while(p!=NULL){	
			if(strstr(p->type,type)>0){
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}		
		break;
	case 5:
		printf("请输入地点：");
		scanf("%s",where);
		while(p!=NULL){	
			if(strstr(p->where,where)>0){
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}
		break;
	case 6:
		printf("请输入时间(例如:2016.01.01)：");
		scanf("%s",date);
		while(p!=NULL){	
			if(strcmp(p->date,date)==0){
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}	
		break;
		case 7:
			printf("请输入时间起始时间(例如:2016.01.01)：\n");
		scanf("%s",date1);
		printf("请输入结束时间：\n");
		scanf("%s",date2);
		while(p!=NULL){	
			if(strcmp(p->date,date1)>=0&&strcmp(p->date,date2)<=0){
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				flag=1;
			}
			p=p->next;
		}
		if(flag==0) {
			printf("对不起，找不到您要查询的物品，请核对信息后重新查询。\n");
		}	
		break;
	case 0:
		break;
	default:
		printf("输入有误！\n");
		break;
	}
}
//排序函数（采用冒泡查询） 
void rankbynum( struct node *head)
{
	struct node *p,*p1,*p2;
	int i,j,choice;
	int n=0;
	p=head;
	
	while(p->next!=NULL){ 
		n++;
		p=p->next;
	}			// 统计链表中元素个数
	printf("_____________________________________\n");
	printf("|1:按编号排序   |   2:按时间排序    |\n");
	printf("|_______________|___________________|\n");
	printf("|0:取消         |                   |\n");
	printf("|_______________|___________________|\n");
	printf("请输入您的选择:\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		for(i=1;i<n;i++){
		  p1=head;		
			for(j=0;j<n-i;j++){
				p2=p1->next;
				if((p1->num)>(p2->num)){		//按照编号来排序
					swap(p1,p2);
				}
			p1=p1->next; //利用冒泡排序法来排序
			}
		}	
		showall(head);
		break;
	case 2:
		 for(i=1;i<n;i++){
		  p1=head;		
			for(j=0;j<n-i;j++){
				p2=p1->next;
				if(strcmp(p1->date,p2->date)<0){		//按照编号来排序
					swap(p1,p2);
				}
			p1=p1->next; //利用冒泡排序法来排序
			}
		}	
		showall(head);
		break; 
	case 0:
		break;
	default:
		printf("输入有误\n");
	}
}
//交换函数（用于排序） 
void swap(struct node *p1,struct node *p2)
{
	int k;
	
	char a[20];
	
	k=p1->num;
	p1->num=p2->num;
	p2->num=k;
    strcpy(a,p1->name);
    strcpy(p1->name,p2->name);
	strcpy(p2->name,a);
	strcpy(a,p1->where);
	strcpy(p1->where,p2->where);
	strcpy(p2->where,a);
	strcpy(a,p1->auther);
	strcpy(p1->auther,p2->auther);
	strcpy(p2->auther,a);
	strcpy(a,p1->type);
	strcpy(p1->type,p2->type);
	strcpy(p2->type,a);
	strcpy(a,p1->date);
	strcpy(p1->date,p2->date);
	strcpy(p2->date,a);
	strcpy(a,p1->Tedian);
	strcpy(p1->Tedian,p2->Tedian);
	strcpy(p2->Tedian,a);
}
//修改用户信息（可选择性修改） 
void modifyUser(struct User *head)
{
	int n;
	char card[20];
	struct User *p;
	int flag=0;
	printf("请输入您要修改的学号:");
	scanf("%s",card);
	p=head;
		while(p!=NULL){
		if(strcmp(p->card,card)==0){
			do{
				printf("_____________________________\n");
				printf("|1:修改姓名   |   2:修改学号|\n");
				printf("|_____________|_____________|\n");
				printf("|3:修改密码   |   0:取消    |\n");
				printf("|_____________|_____________|\n");
				printf("请输入您的选择：\n");
		        flag=1;
				scanf("%d",&n);
				switch(n){
				case 1:
					printf("请重新输入姓名：");
					scanf("%s",p->Xingming);
					getchar();	
					break;
				case 2:
					printf("请重新输入学号：");
					scanf("%s",p->card);  
					break;
				case 3:
					printf("请重新输入密码：");
					scanf("%s",p->pass); 
					break;
				case 0:
					break;
				default:
				printf("输入错误！\n");
				}
			}while(n!=0);
		}
		p=p->next;
	}
    if(flag==0)
	printf("未找到！！！\n");
    Yonghu(head); 
}
//修改物品的信息（可选择性修改） 
void modify(struct node *head)
{	
	int number,n;
	struct node *p;
	int flag=0;

	printf("请输入您要修改的序号：");
	scanf("%d",&number);
	p=head;
	while(p!=NULL){
		if(p->num==number){
			do{
			    
				printf("_______________________________\n");
				printf("|1:修改名称    |    2:修改姓名|\n");
				printf("|______________|______________|\n");
				printf("|3:修改类型    |    4:修改地点|\n");
				printf("|______________|______________|\n");
				printf("|5:修改时间    |    6:修改编号|\n");
				printf("|______________|______________|\n");
				printf("|7:修改特点    |    0:取消    |\n");
				printf("|______________|______________|\n");
				printf("        请输入您的选择：");
		        flag=1;
				scanf("%d",&n);
				switch(n){
				case 1:
					printf("请重新输入名称：");
					scanf("%s",p->name);
					getchar();	
					break;
				case 2:
					printf("请重新输入姓名：");
					scanf("%s",p->auther);  
					break;
				case 3:
					printf("请重新输入类型：");
					scanf("%s",p->type); 
					break;
				case 4:	
					printf("请重新输入地点：");
					scanf("%s",p->where);	
					break;
				case 5:
					printf("请重新输入时间：");
					scanf("%s",p->date);
					break;
				case 6: 
				    printf("请重新输入编号  ");
					scanf("%d",&p->num) ;
					break;
				case 7:
					printf("请重新输入特点");
					scanf("%s",p->Tedian);
					break;
				case 0:
					break;
				default:
				printf("输入错误！\n");
				}
			}while(n!=0);
		}
		p=p->next;
	}
    if(flag==0)
	printf("未找到！！！\n");
	save(head);
}

//删除用户信息 
int  deleteUser(struct User *head)
{
	int x=0;
	struct User *p,*q;                
	char pass[20];           
	char card[20];           
	int n,count=0;
	int flag=0;
	p=head;
	q=p;
	printf("_________________________________\n");
	printf("|1:按密码删除    |  2:按学号删除|\n");
	printf("|________________|______________|\n");
	printf("|0:取消          |              |\n");
	printf("|________________|______________|\n");
	printf("请输入您的选择：\n");
	scanf("%d",&n);
	switch(n){	
	case 1: 
		printf("请输入要删除的密码：");
		scanf("%s",pass);
	while(p){
		if(strcmp(p->pass,pass)==0)
		{
			flag=1;
			system("cls");
	printf("%s的信息如下\n",pass);
	printf(" _____________________________________\n");
	printf("|姓名     |     学号      |     密码  |\n");
	printf("|_________|_______________|___________|\n");
	printf("|%-8s |%-12s   |%-6s     |\n",p->Xingming,p->card,p->pass);
    printf("|_________|_______________|___________|\n");
				fflush(stdin);
				printf("按任意键继续");
			getchar();
			if(p==head)
			head=p->next;
			else
			q->next=p->next;
			free(p);
			Yonghu(head);
			printf("删除成功\n"); 
		return 0;
		}
		else
		{
		q=p;
		p=p->next;}}
		if(!flag)
	{
			printf("未找到\n");
		getchar();}
		break;
	case 2:
	printf("请输入要删除的学号：");
		scanf("%s",card);
	while(p){
		if(strcmp(p->card,card)==0)
		{
			flag=1;
			system("cls");
			printf("%s的信息如下：\n",p->Xingming);
	printf(" _____________________________________\n");
	printf("|姓名     |     学号      |     密码  |\n");
	printf("|_________|_______________|___________|\n");
	printf("|%-8s |%-12s   |%-6s     |\n",p->Xingming,p->card,p->pass);
    printf("|_________|_______________|___________|\n");
			fflush(stdin);
			printf("按任意键继续");
			getchar();
			if(p==head)
			head=p->next;
			else
			q->next=p->next;
			free(p);
			Yonghu(head);
			printf("删除成功\n"); 
		return 0;
		}
		else
		{
		q=p;
		p=p->next;}}
		if(!flag)
	{
			printf("未找到\n");
		getchar();
		}
     break;}

} 
//删除物品信息 
int  deletething(struct node *head)
{
	int x=0;
	struct node *p,*q;
	int num;                 
	char name[20];           
	char auther[20];         
	char type[20]; 
	char where[20];                   
	char press[20];          
	char date[20]; 
	char date1[20];
	char date2[20];   
	int n,count=0;
	int flag=0;	
	
	p=head;
	q=p;
	printf("____________________________________\n");
	printf("|1:按序号删除    |    2:按名称删除 |\n");
	printf("|________________|_________________|\n");
	printf("|3:按姓名删除    |    4:按类型删除 |\n");
	printf("|________________|_________________|\n");
	printf("|5:按地点删除    |    6:按时间删除 |\n");
	printf("|________________|_________________|\n");
	printf("|0:取消          |                 |\n");
	printf("|________________|_________________|\n");
	printf("请输入您的选择：\n");
	scanf("%d",&n);
	switch(n){
		
	case 1:
		printf("请输入要删除序号：\n");
		scanf("%d",&num);
	while(p!=NULL){
		if(p->num==num)
		{
			flag=1;
			system("cls");
			printf("：%d的信息如下：\n",p->num);
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				getchar();
				printf("按任意键继续");
			getchar();
			
			if(p==head)
			head=p->next;
			else
			q->next=p->next;
			free(p);
			save(head);
			printf("删除成功\n"); 
		return 0;
		}
		
		else{
		
		q=p;
		p=p->next;}
		}
		if(!flag)
	{
			printf("未找到\n");
		getchar();
		} 
	     break;
	case 2:
		printf("请输入要删除的名称：");
		scanf("%s",name);
	while(p){
		if(strcmp(p->name,name)==0)
		{
			flag=1;
			system("cls");
			printf("%s的信息如下：",p->name);
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				fflush(stdin);
				printf("按任意键继续");
			getchar();
			
			if(p==head)
			head=p->next;
			else
			q->next=p->next;
			free(p);
			save(head);
			printf("删除成功\n"); 
		return 0;
		}
		else
		{
		q=p;
		p=p->next;}}
		if(!flag)
	{
			printf("未找到\n");
		getchar();}
		break;
	case 3:
	printf("请输入要删除的姓名：");
		scanf("%s",auther);
	while(p){
		if(strcmp(p->auther,auther)==0)
		{
			flag=1;
			system("cls");
			printf("%s的信息如下：",p->auther);
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
			fflush(stdin);
			printf("按任意键继续");
			getchar();
			if(p==head)
			head=p->next;
			else
			q->next=p->next;
			free(p);
			save(head);
			printf("删除成功\n"); 
		return 0;
		}
		
		else
		{
		q=p;
		p=p->next;}}
		if(!flag)
	{
			printf("未找到\n");
		getchar();
		}
     break;
	case 4:
	printf("请输入要删除的类别：");
		scanf("%s",type);
	while(p){
		if(strcmp(p->type,type)==0)
		{
			flag=1;
			system("cls");
			printf("：%s的信息如下：",p->type);
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
			fflush(stdin);
			printf("按任意键继续");
			getchar();
			if(p==head)
			head=p->next;
			else
			q->next=p->next;
			free(p);
			save(head);
			printf("删除成功\n"); 
		return 0;
		}
		else
		{
		q=p;
		p=p->next;}}
		if(!flag)
	{
			printf("未找到\n");
		getchar();
		}
	break;	
	case 5:
			printf("请输入要删除地点：\n");
		scanf("%s",where);
	while(p!=NULL){
		if(strcmp(p->where,where))
		{
			flag=1;
			system("cls");
			printf("：%s的信息如下：\n",p->where);
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
				getchar();
				printf("按任意键继续");
			getchar();
			
			if(p==head)
			head=p->next;
			else
			q->next=p->next;
			free(p);
			save(head);
			printf("删除成功\n"); 
		return 0;
		}
		
		else{
		
		q=p;
		p=p->next;}
		}
		if(!flag)
	{
			printf("未找到\n");
		getchar();
		} 
	     break;
	case 6:
	printf("请输入要删除时间：");
		scanf("%s",date);
	while(p){
		if(strcmp(p->date,date)==0)
		{
			flag=1;
			system("cls");
			printf("%s的信息如下：",p->date);
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");
			fflush(stdin);
			printf("按任意键继续");
			getchar();
			if(p==head)
			head=p->next;
			else
			q->next=p->next;
			free(p);
			save(head);
			printf("删除成功\n"); 
		return 0;
		}
		
		else
		{
		q=p;
		p=p->next;}
		}
		if(!flag)
	{
			printf("未找到\n");
		getchar();
		}
		break; 	
	case 0:
		break;
	default:
		printf("输入有误！");
		break;
	return 0;}}
//遍历用户信息 
void showallUser(struct User *pl)
{
	struct User *p;
	printf(" _____________________________________\n");
	printf("|姓名     |     学号      |     密码  |\n");
	printf("|_________|_______________|___________|\n");
	for(p=pl;p->next!=NULL;p=p->next)
    {
	printf("|%-8s |%-12s   |%-6s     |\n",p->Xingming,p->card,p->pass);
    printf("|_________|_______________|___________|\n");}
}

//用户遍历物品信息 
void Ushowall(struct node *head)
{
	struct node *p,*p1,*p2;
	int i,j,choice;
	int n=0;
	p=head;
	
	while(p->next!=NULL){ 
		n++;
		p=p->next;
	}			// 统计链表中元素个数
	
	for(i=1;i<n;i++){
		  p1=head;		
			for(j=0;j<n-i;j++){
				p2=p1->next;
				if(strcmp(p1->date,p2->date)<0){		//按照编号来排序
					swap(p1,p2);
				}
			p1=p1->next; //利用冒泡排序法来排序
			}
		}	
	Partshowall(head);
}
//部分信息的遍历 
void Partshowall(struct node *pl)
{
	struct node *p;
	printf("________________________________________________________________\n");
	printf("|序号    |    名称   |   类别     |   地点         |    时间    |\n");
	printf("|________|___________|____________|________________|____________|\n");
	for(p=pl;p->next!=NULL;p=p->next)
	{
	printf("|%-4d    | %-8s  |%-10s  |%-16s|%-10s  |\n",p->num,p->name,p->type,p->where,p->date);
	printf("|________|___________|____________|________________|____________|\n");
	}
}
//管理员对信息的遍历（全部信息） 
void showall(struct node *pl)
{
	struct node *p;
printf("______________________________________________________________________________________________\n");
printf("|序号    |   名称   |   姓名   |   类别    |    地点        |     时间       |       特点     |\n");
printf("|________|__________|__________|___________|________________|________________|________________|\n");
	for(p=pl;p->next!=NULL;p=p->next)
{
printf("|%-4d    |%-8s  |%-8s  | %-10s|%-16s|%-10s      |%-16s|\n",p->num,p->name,p->auther,p->type,p->where,p->date,p->Tedian);
printf("|________|__________|__________|___________|________________|________________|________________|\n");}
}
//用户录入 
void inputU()
{
	struct User *p1,*head;
	head=NULL;
	printf("注意：当姓名为0时输入结束\n\n");
	p1=(struct User *)malloc(sizeof(struct User));   //为链表的节点申请内存空间
	head=p1;
	while(strcmp(p1->Xingming,"0")!=0){
		printf("请输入姓名：");	
		scanf("%s",p1->Xingming);
		if(strcmp(p1->Xingming,"0")==0)
			break;
		printf("请输入学号：");
		scanf("%s",p1->card);
		printf("请输入密码：");
		scanf("%s",p1->pass);
		printf("该信息已经录入完毕，请录入下一用户信息\n");
		p1->next=(struct User *)malloc(sizeof(struct User));
		p1=p1->next;		
	}
	p1->next=NULL;
	printf("用户信息录入输入结束！\n");	
	Yonghu(head);
}
//物品录入 
void input()
{
	struct node *p1,*head;
	head=NULL;
	
	printf("注意：当序号为负数时输入结束\n\n");
	p1=(struct node *)malloc(sizeof(struct node));   //为链表的节点申请内存空间
	head=p1;
	while(p1->num!=0){
		printf("请输入序号：");	
		scanf("%d",&p1->num);
		if(p1->num<0)
			break;
		printf("请输入名称：");
		scanf("%s",p1->name);
		printf("请输入姓名：");
		scanf("%s",p1->auther);
		printf("请输入类型：");
		scanf("%s",p1->type);
		printf("请输入地点：");
		scanf("%s",p1->where);
		printf("请输入时间：");
		scanf("%s",&p1->date);
		printf("请输入特点：");
		scanf("%s",p1->Tedian); 
		printf("该信息已经录入完毕，请录入下一物品，当序号为负数时结束。\n");
		p1->next=(struct node *)malloc(sizeof(struct node));
		p1=p1->next;		
	}
	p1->next=NULL;
	printf("物品录入输入结束！\n");	
	save(head);
}

//把用户写入文件 
void Yonghu(struct User *head)
{
	FILE *fp;
	struct User *pl;

	if((fp=fopen("c.txt","w"))==NULL){
		 printf("can not open file");
		 exit(0);
	}
	pl=head;
	while(pl->next!=NULL){
		fprintf(fp,"%s  %s  %s\n",pl->Xingming,pl->card,pl->pass);
	    pl=pl->next;
	}
	fclose(fp);	
} 
//写入文件函数
void save(struct node *head)          
{
	FILE *fp;
	struct node *pl;

	if((fp=fopen("a.txt","w"))==NULL){
		 printf("can not open file");
		 exit(0);
	}
	pl=head;
	while(pl->next!=NULL){
		fprintf(fp,"%d  %s  %s  %s  %s  %s  %s\n",pl->num,pl->name,pl->auther,pl->type,pl->where,pl->date,pl->Tedian);
	    pl=pl->next;
	}
	fclose(fp);
}
//用户读取文件 
struct User * readU(struct User *pl )
{
	FILE *fp;
	struct User *head,*tail=NULL;
	head=NULL;

	if((fp=fopen("c.txt","r"))==NULL){
		printf("Can not open file");
		exit(0);
	}
	while(!feof(fp))
	{
		pl=(struct User * )malloc(sizeof(struct User));
		fscanf(fp,"%s%s%s",pl->Xingming,pl->card,pl->pass);
		if(head==NULL)
			head=pl;
		else
			tail->next=pl;
		tail=pl;
	}
	tail->next=NULL;
	if(fclose(fp)){
		printf("can not close the file\n");
		exit(0);
	}

	return head;
}
//文件读取函数
struct node * read(struct node *pl)
{
	FILE *fp;
	struct node *head,*tail=NULL;
	head=NULL;

	if((fp=fopen("a.txt","r"))==NULL){
		printf("Can not open file");
		exit(0);
	}
	while(!feof(fp))
	{
		pl=(struct node * )malloc(sizeof(struct node));
		fscanf(fp,"%d%s%s%s%s%s%s",&pl->num,pl->name,pl->auther,pl->type,pl->where,pl->date,pl->Tedian);
		if(head==NULL)
			head=pl;
		else
			tail->next=pl;
		tail=pl;
	}
	tail->next=NULL;
	if(fclose(fp)){
		printf("can not close the file\n");
		exit(0);
	}

	return head;
}
//增加用户 
void insertY(struct User *head)
{
	struct User *p,*p1;
	int n=0;
	p=head;
	while(p->next!=NULL) p=p->next;		//找到链表的尾指针
	printf("注意：当姓名为0时输入结束\n\n");
	p1=(struct User *)malloc(sizeof(struct User));   
	p1=p;
	do{
		printf("请输入姓名：");	
		scanf("%s",p1->Xingming);
		if(strcmp(p1->Xingming,"0")==0)
			break;
		printf("请输入学号：");
		scanf("%s",p1->card);
		printf("请输入密码：");
		scanf("%s",p1->pass);
		printf("该信息已经录入完毕，请录入下一用户。\n");
		p1->next=(struct User *)malloc(sizeof(struct User));
		p1=p1->next;
	}while(1);	
	p1->next=NULL;
	printf("录入输入结束！\n");	
    Yonghu(head);
}
//增加物品 
void insert(struct node *head)
{
	struct node *p,*p1;
	int n=0;
	p=head;
	while(p->next!=NULL) p=p->next;		//找到链表的尾指针
	printf("注意：当序号为负数时输入结束\n\n");
	p1=(struct node *)malloc(sizeof(struct node));   
	p1=p;
	do{
		printf("请输入序号：");	
		scanf("%d",&p1->num);
		if(p1->num<0)
			break;
		printf("请输入名称：");
		scanf("%s",p1->name);
		printf("请输入姓名：");
		scanf("%s",p1->auther);
		printf("请输入类型：");
		scanf("%s",p1->type);
		printf("请输入地点：");
		scanf("%s",p1->where);
		printf("请输入时间：");
		scanf("%s",p1->date);
		printf("请输入特点：");
		scanf("%s",p1->Tedian);
		printf("该信息已经录入完毕，请录入下一物品。\n");
		p1->next=(struct node *)malloc(sizeof(struct node));
		p1=p1->next;
	}while(1);	
	p1->next=NULL;
	printf("录入输入结束！\n");	
	save(head);
}

	void dongtai()	
{
int i,j,e;
int a;
long time;
system("title 管理系统");
for(i=1,a=I;i<I/2;i++,a--)
{
for(j=(int) ( I-sqrt(I*I-(a-i)*(a-i)) );j>0;j--)
printf(" ");
for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++)
printf("*");
for(j=(int)
( 2*( I-sqrt(I*I-(a-i)*(a-i)) ) );
j>0;j--)
printf(" ");
for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++)
printf("*");
printf("\n"); }
for(i=1;i<80;i++)
{
if(i==25)
{
printf("    人人为我，我为人人!!   ");
i+=28;
}
printf("*");
}
printf("\n");
for(i=1;i<=R/2;i++)
{
if(i%2||i%3)
continue;
for(j=(int) 
( R-sqrt(R*R-i*i) );j>0;j--)
printf(" ");
for(e=1;e<=2*( sqrt(R*R-i*i) - (R-2*I) );e++)
printf("*");
printf("\n");
}
for(; ; )
{
system("color a");
for(time=0;time<89999999;time++);
 system("color b");
for(time=0;time<89999999;time++); system("color c");
 for(time=0;time<89999999;time++); system("color d");
 for(time=0;time<89999999;time++); system("color e");
 for(time=0;time<89999999;time++); system("color f");
for(time=0;time<89999999;time++);
 system("color 0");
  for(time=0;time<89999999;time++);
  system("color 1");
   for(time=0;time<89999999;time++);
  system("color 2"); 
   for(time=0;time<89999999;time++);
   system("color 3"); 
   for(time=0;time<89999999;time++);
  system("color 4");
  for(time=0;time<89999999;time++); 
   system("color 5");
  for(time=0;time<89999999;time++); 
 system("color 6");
   for(time=0;time<89999999;time++);
   system("color 7");
	for(time=0;
	time<89999999;time++);
	 system("color 8");
	 for(time=0;time<89999999;time++); 
	 system("color 9");
	 for(time=0;time<8999999;time++); 
	 system("color db");
   for(time=0;time<8999999;time++);
	  system("color ac");
	  for(time=0;time<89999999;time++); system("color 8d");
	  for(time=0;time<89999999;time++); system("color be");
	 
	  system("cls");
	   break;}}
	   
//初始化函数 
void checkfirst()
{
	FILE *fp2,*fp1;
	char a[9];
	int i;
	if((fp2=fopen("d.txt","r"))==NULL)
		{
		  strcpy(a,"12345678");
		 i=0;
		 while(a[i])
		 {
		 	fputc(a[i],fp1);
		 	i++;
		 }
		 	fclose(fp1);
		  } 
		  else
		  {
		  	i=0;
		  	while(!feof(fp2)&&i<8)
		  	a[i++]=fgetc(fp2);
		  	a[i]='\0';
          if(i>=8)
		  	i--;
		  	while(a[i]!=-1&&i>=0)
		  	i--;
		  	a[i]='\0'; 
		  	strcpy(password,a);
		  }

}
 
//修改密码函数 
void update()
{
	char a[9],a1[9],ch;
	int i;
	FILE *fp1;
	system("cls");
	printf("\n请输入旧密码：\n");
	for(i=0;i<8&&((a[i]=getch())!=13);i++)
    putch('*');
    a[i]='\0';
    if(strcmp(password,a)!=0)
    {
    	printf("\n密码错误，请按任意键退出！\n");
    	getch();
    	return ;
	}
	do{
		printf("\n设置新密码，请不要超过8位：\n"); 
		for(i=0;i<8&&((a[i]=getch())!=13);i++)
		putch('*');
		a[i]='\0'; 
		printf("\n");
		printf("请再确认密码：\n");
	    for(i=0;i<8&&((a1[i]=getch())!=13);i++)
	    putch('*');
		a1[i]='\0';
		if(strcmp(a,a1)!=0)
		printf("\n两次密码输入不一致，请重新输入！\n\n");
		else
		break;
	}while(1);
	if((fp1=fopen("d.txt","w"))==NULL)
	{
		printf("\n系统创建失败，按任意键退出！");
		getch();
		exit(1); 
	}
	i=0;
	while(a[i])
	{
		fputc(a[i],fp1);
		i++; 
	}
	fclose(fp1);
	printf("\n密码修改成功，按任意键退出!\n");
	getch();
	return ; 
}
