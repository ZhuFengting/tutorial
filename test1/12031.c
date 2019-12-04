
#include <stdio.h>


void print(int N)
    { print(N-1);
      printf("n=%d",N);
}

int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<=a;i++)
        printf("Hello, World! \n");
    print(a);
    return 0;
}

