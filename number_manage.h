
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

struct telnum{
    char name[11];
    char tel[13];//电话号码
};
struct telnum num[100];
int i;//定义全局变量，当前记录的条数

//1.菜单函数，，完成菜单的显示和选择
int menu();
//2.显示学生函数，参数是一个结构体，显示结构体的信息
 void shownum(struct telnum t);
//3.添加电话函数，完成一个电话号码的添加，返回一个结构体
struct telnum addnum();
//4.查找函数，用户输入一个名字，查找到这个用户的电话
void selectbyname();
//5.删除电话号码函数。用户输入一个名字，删除这个用户的电话号码
void delenum();
//6.保存信息功能，将所有电话号码保存到文件上
void savetofile();
//7.导入信息功能，从文本中读取以前的文件信息
void loadfromfile();
//8.主函数，完成各个函数的调用
//main()
