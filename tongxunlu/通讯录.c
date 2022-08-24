#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 1000			 	//定值
#define max_id 12
#define max_name 20
#define max_sex 5
#define max_phone 12


enum Choose
{
    EXIT,        //0
    ADD,	     //1
    SHOW,		 //2
	DEL,	     //3
    MODIFY,	  	 //4
    SER,//5
	SER2		 //6
};


typedef struct PersonIn			//成员信息定义
{
	int id;						//编号
	char name[max_name];		//姓名
	char sex[max_sex];			//性别
	int age;					//年龄
	char phone[max_phone];		//电话号码
}PersonIn;

struct Contact
{
    struct PersonIn data[max];		//存放1000个信息
    int size;						//当前已有信息个数
};




void AddProject(struct Contact *some)
{
	if(some->size == max)
    {
        printf("通讯录已满，无法增加\n");
    }
    else
    {
        printf("请输入id:>");
        scanf("%d", &(some->data[some->size].id));
        printf("请输入名字:>");
        scanf("%s", some->data[some->size].name);
        printf("请输入年龄:>");
        scanf("%d", &(some->data[some->size].age));
        printf("请输入性别:>");
        scanf("%s", some->data[some->size].sex);
        printf("请输入电话:>");
        scanf("%s", some->data[some->size].phone);
 
        some->size++;
        printf("添加成功\n");
}
}


void  ShowProject(struct Contact *sp)
{
	int i = 0;
	int j = 0;


	if(0 == sp->size)
	{
		printf("暂无联系人\n");
	}
	else
	{	
	for (i = 0; i< sp->size - 1; i++)
	{
		for (j = 0; j< sp->size - i - 1; j++)
		{
			if (strcmp( sp->data[j].name, ( sp->data[j + 1]).name) > 0)
			{
                PersonIn tmp;
				tmp = sp->data[j];
				sp->data[j] = sp->data[j + 1];
				sp->data[j + 1] = tmp;
			}
		}
		printf("排序成功！\n");
	}
		for(i = 0;i<sp->size;i++)
		{
		printf("------------------------------------------------------------------------------------------\n");
		printf("\t%-8s\t%-8s\t%-9s\t%-9s\t%-18s\t\n","id","姓名","性别","年龄","电话号码");
		printf("------------------------------------------------------------------------------------------\n");
	
			printf("\t%-8d\t%-8s\t%-6s\t%-3d\t%-18s",
			sp->data[i].id,
			sp->data[i].name,
			sp->data[i].sex,
			sp->data[i].age,
			sp->data[i].phone);
			putchar(10);
		}
	}
}

//修饰FindByName函数，使其封装在程序内部，不暴露出去
static int FindByName(const struct Contact *ps, char name[max_name])
{
    int i = 0;
    for(i = 0; i < ps->size; i++)
    {
        if(0 == strcmp(ps->data[i].name, name))
        {
            return i;
        }
    }
    return -1;//找不到的情况
}


//删除指定的联系人
void DelProject(struct Contact *ps)
{
    char name[max_name];
    printf("请输入要删除人的名字:>");
    scanf("%s", name);
    //1.查找要删除的人在什么位置
    //找到了返回名字所在元素的下标
    //找不到返回 -1
    int pos = FindByName(ps, name);
    //2.删除
    //查询不到联系人
    if (pos == -1)
    {
        printf("查询不到要删除的联系人，请重试\n");
    }
    else
    {
        //删除数据
        int j = 0;
        for(j = pos; j < ps->size-1; j++)
        {
            ps->data[j] = ps->data[j + 1];
            //由于删除了这个数据，所以后面的数据会顶替上来
        }
        ps->size--;
        printf("删除成功\n");
    }
}

//修改指定联系人的信息
void Moidfyproject(struct Contact *ps)
{
    char name[max_name];
    printf("请输入要修改联系人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要修改联系人的信息不存在，请重试\n");
    }
    else
    {
	printf("请输入id:>");
        scanf("%d", &(ps->data[pos].id));
        printf("请输入名字:>");
        scanf("%s", ps->data[pos].name);
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[pos].age));
        printf("请输入性别:>");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[pos].phone);
        printf("修改完成\n");
    }
}

//查找指定的人的信息
void SearchProject_By_Name(const struct Contact *ps)
{
    char name[max_name];
    printf("请输入要查找人的名字:->");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要查找的人不存在,请重试\n");
    }
    else
    {
	printf("------------------------------------------------------------------------------------------\n");
	printf("\t%-8s\t%-8s\t%-9s\t%-9s\t%-18s\t\n","id","姓名","性别","年龄","电话号码");
	printf("------------------------------------------------------------------------------------------\n");
	printf("\t%-8d\t%-8s\t%-6s\t%-3d\t%-18s",
	ps->data[pos].id,
	ps->data[pos].name,
	ps->data[pos].sex,
	ps->data[pos].age,
	ps->data[pos].phone);
	putchar(10);
    }
}
void SearchProject_By_Id(const struct Contact* pc)//ID查找联系人
{
	
	int id;
	printf("请输入你要查找的id:->");
	scanf("%d",&id);
	int i = 0;
	int pos;
	for (i = 0; i < pc->size; i++)
	{
		if (id == pc->data[i].id) 
		{	pos = pc->data[i].id;
			break;}//找到返回
		else
		{pos = 0;}
	}
	if (pos == 0)
	{
		printf("没有这个联系人\n");
	}
	else
	{
printf("------------------------------------------------------------------------------------------\n");
		printf("\t%-8s\t%-8s\t%-9s\t%-9s\t%-18s\t\n","id","姓名","性别","年龄","电话号码");
printf("------------------------------------------------------------------------------------------\n");
		printf("\t%-8d\t%-8s\t%-6s\t%-3d\t%-18s",
			pc->data[i].id,
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].phone);
			putchar(10);
	}
}











void menu()
{	
	printf("******************************************************************************************\n");
	printf("\t1.添加用户	  2.显示用户\n");
	printf("\t3.删除用户	  4.修改用户\n");
	printf("\t5.查找用户(姓名)  6.查找用户(ID)\n");
	printf("\t\t0.退出系统\n");
	printf("******************************************************************************************\n");
}
//初始化通讯录的函数
void InitContact(struct Contact *ps)
{
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0;//设置通讯录最初有0个元素
}
int main()
{

    int input = 0;			//创建通讯录
    struct Contact set;		//包含：1000个元素的数和size
    //初始化通讯录
	InitContact(&set);
    do
    {
        menu();
        printf("请选择要使用的功能序号:->");
        scanf("%d", &input);
        switch(input)
        {
        case ADD:
            AddProject(&set);
            break;
        case SHOW:
            ShowProject(&set);
	    break;
        case DEL:
            DelProject(&set);
            break;
         case SER:
            SearchProject_By_Name(&set);
            break;
	case SER2:
            SearchProject_By_Id(&set);
            break;
        case MODIFY:
            Moidfyproject(&set);
            break;
        case EXIT:
            printf("退出通讯录\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    } while (input);
    return 0;
}
