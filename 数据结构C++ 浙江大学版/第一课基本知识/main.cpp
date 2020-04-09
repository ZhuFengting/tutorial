#include <iostream>
#include "math.h"
#include "time.h"
/*函数n可以顺序打印出来*/

class test{
public:
    void PrintN(int n);
    void PrintNN(int n);
    double f(double a[], double x,int n);
    double ff(double a[], double x,int n);
    double max_list1(double a[],int n);
    double max_list2(double a[],int n);

};


//最大子列和问题
//分别利用i和j控制左端和右端
/***最简单的方法，求出每一个子列然后求和***/
double test::max_list1(double *a,int n) {
    double max=0;
    for(int i = 0; i <n; i++){          //控制右侧
        double sum=0;
        for(int j = i;j <n; j++){       //控制左侧
            sum+=a[j];
            if(sum>max)
                max=sum;
        }
    }
    return max;
}

//分而治知　没有理解
double test::max_list2(double *a, int n) {
    
}

void test::PrintN(int n) {
    for(int i=0;i<=n;i++)
        printf("%d\n",i);
}

/*递归的步骤*/
//递归第一个步骤：明确函数要做什么
//递归第二个步骤：明确递归的结束（退出递归）条件
//递归的第三个步骤：找到函数的等价关系式

void test::PrintNN(int n) {
    if(n){
        PrintNN(n-1);
        printf("%d\n",n);
    }
}


//例题三 笨写法 写程序计算多项式在x点的值
double test::f(double a[], double x,int n){
    double sum = a[0];
    for(int i=1;i<=n;i++){
        sum+=a[i]*pow(x,i);
    }
    return sum;
}
//秦九韶算法
double test::ff(double a[],double x,int n){
    double sum=a[n];
    for(int i=n;i>=0;i--)
        sum=a[i-1]+sum*x;
    return  sum;
}


clock_t start,stop;
double duration;
int main() {
    std::cout << "Hello, World!" << std::endl;
    test method;
    double a[10];
    double result;
    for(int i=0;i<10;i++){
        a[i]=(double)i;
    }

    start = clock();
    for(int j=0;j<10000;j++)             //多次时间进行计算
       result=method.ff(a,1.1,9);
    stop = clock();
    duration = (stop-start);
    std::cout<<"时间是"<<duration<<std::endl;
    return 0;
}