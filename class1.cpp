//#include<iostream>//IO流
////#include<iostream.h>是一个老版，这里面没有“命名空间”d
//// 命名空间：作用是命名隔离、解决命名冲突，
//using namespace std
//
////同一个域不能定义相同的变量
////就近原则
////::域作用限定符
//
//namespace my{
//    int a = 10;
//}
//
//namespace your{
//    int a = 20;
//}
//
////展开成全局变量
//using namespace your;
//
//int a = 1;
//
////命名空间可以嵌套使用
//int main(){
//    //   <<这个是操作符（运算符）
//    //   这是一个好的编程习惯，可以防止命名冲突
//    std::count<<"hello world"<<std::endl;
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
////函数重载：C++中允许函数名相同，函数参数不同
////C++是如何支持重载？
//void f1(int i){
//    cout<<i<<endl;
//}
//void f1(char c){
//    cout<<c<<endl;
//}
//int mian(){
//    int i;
//    cin>>i;
//    cout<<i<<endl;
//    //C++中能够自动识别数据类型
//    //cout保留小数点后5位；
//    //printf保留小数点后6位。
//    int *p = &i;
//    cout<<p<<endl;
//    //保留小数点后2位,此时使用printf比较简单
//    printf("%.2d\n",i);
//    return 0;
//}

//#include<stdio.h>
//
//
//void f1(char c,const char* p){
//    ;
//}
//void f1(int i){
//    ;
//}
//int main(){
//    return 0;
//}


//#include<iostream>
//using namespace std;
//
//
////缺省参数--半缺省 
////半缺省：必须从右往左进行缺省
////ADD（int a,int b = 1, int c = 1）
////可以理解为备胎
//int ADD(int a = 1; int b = 1){
//    return a+b;
//}
//
//int main(){
//    cout<<ADD(1,2)<<endl;
//    cout<<ADD()<<endl;
//    cout<<ADD(10)<<endl;
//    return 0;
//}


//#include<iostream>
//using namespace std;
//int main(){
//    int a;
//    //引用
//    int& b = a;
//    int& c = a;
//    int& d = b;
//    //别名的效果
//    d = 10;
//    c = 2;
//    //引用必须初始化
//    return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main{
//    //const引用
//    const int a = 10;
//    const int& b = a;
//    int c = 10;
//    int& d = c;
//
//    //f 引用的是临时变量（临时变量具有常性）
//    double e = 1.1111;
//    const int& f = e;
//    return 0;
//}



//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
////void Swap(int a,int b);
////void Swap(int *pa,int* pb);
////传引用
//void Swap(int& ra,int& rb){
//    int c = ra;
//    ra = rb;
//    rb = c;
//}
////引用做参数：1.提高效率；2.里面改变，外面可以看到
//int main(){
//    int x1 = 1,x2 = 2;
//    cout<<x1<<endl;
//    cout<<x2<<endl;
//    //Swap(&x1,&x2);
//    Swap(x1,x2);
//    printf("%d\n",x1);
//    printf("%d\n",x2);
//    return 0;
//}



////传值返回
//int ADD(int a,int b);
////传引用返回       -》提高效率
//int& ADD(int a,int b);
////关系：出了作用域变量还在，使用引用返回（最好）；
////出了作用域不再，使用传值返回
////出量作用域变量不再，还使用引用，会发生错误









