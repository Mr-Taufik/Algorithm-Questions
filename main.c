#include <math.h>
#include <stdio.h>

void prime( int x, int y, int *count, int *sum );

int main()
{
     int m, n;
     int count = 0;
     int sum = 0;

     printf( "Enter the m and n: " );
     if ( scanf( "%d %d", &m, &n ) != 2 )
     {
          printf( "Invalid input!\n" );
          return 1;
     }

     prime( m, n, &count, &sum );

     printf( "Sum of primes: %d, Count of primes: %d\n", sum, count );

     return 0;
}

void prime( int x, int y, int *count, int *sum )
{
     for ( int i = x; i <= y; i++ )
     {
          if ( i < 2 )
               continue; // 排除1和负数

          int isPrime = 1; // 假设是素数

          // 只需检查到sqrt(i)即可
          int limit = (int)sqrt( i );
          for ( int j = 2; j <= limit; j++ )
          {
               if ( i % j == 0 )
               {
                    isPrime = 0; // 不是素数
                    break;       // 不需要继续检查
               }
          }

          if ( isPrime )
          {
               ( *count )++;  // 素数数量加1
               ( *sum ) += i; // 素数和加上该素数
          }
     }
}
//素数判断： 使用 isPrime 标志来判断当前数字是否为素数。只有当数字 i 没有被 2 到 sqrt(i) 的任何数字整除时，它才是素数。
//sum 和 count 指针操作： 使用 *sum 和 *count 来修改主函数中的 sum 和 count 变量，因为你传递的是指针。