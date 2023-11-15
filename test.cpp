#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
 //int main()

    //int i = 31;
    //printf("%x", i); //似乎输出类型转换对十六进制和八进制是有效的，但对实数和整数的转换不是有效的。
    //return 0;

//一定要先输入再用变量定义数组
//养成初始化的好习惯，有些数组需要使用遍历初始化
//最好不要直接应用循环参量
//下面可以继续进行测试
 //int main()
//{
  //  char a[10];
   // cin.get(a,10);
 //   cout << a;
   // return 0;
//}           // 创建字符数组时要给\0预留位置
//int main()
//{
 // char a;
 // char b[5];
 // cin >> a;
//  cin.get();       //需要加cin.get（）命令清空缓冲区。
 // cin.getline(b, 5);
 // cout << b;
 // return 0;
//}
#if 0
int cmp (const void* a, const void* b)    //快速排序库函数逆序输出。
{
  return -(*((int*)a) - *((int*)b));
}
int main()
{
   int n;
   cin >> n;
   int a[n];
   int i = 0;
   for (i = 0; i < n; i++)
   {
    cin >> a[i];
   }
   qsort(a,n,4,cmp);
   for (i = 0; i < n; i++)
   cout << a[i] <<" ";
   return 0;
}
#endif

#if 0                    // goto跳转到的语句行本来也会正常执行。
int main()
{
  int i = 0;
  for (i = 0; i < 5; i++)
  {
    if (i != 4)
  cout << i << " ";
  else
  goto std;
  std : cout << i << " ";
  }
  return 0;
}
#endif
#if 0
int main()
{
  char a[99];
  char b;
  scanf ("%c", &b);
  gets(a);
  printf ("%s", a);
  return 0;
}
#endif                           // Before using "gets" and "fgets", you need to clean buffer.
                                 // Optimizing sort algorithm : You can sort many arrays at the same time as long as you want.
                                 // This way is truly right. You don't need to use a sign like "flag" to continue difficult sorts again.
//int main()
//{
  //struct a1
  //{
   // int a;
   // int e;
   // char t;
    //float e1;
  //};
 // cout << sizeof(a1);
  //return 0;
//}                             //You can straightly use data type to compute its size.
int main()
{
  long long a = 0;
  a = 48 * pow(10, 15);
  cout << a;
  return 0;
}