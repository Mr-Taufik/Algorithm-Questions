#include <stdio.h>
#include <stdlib.h> // 为了使用 abs()

int main()
{
     int number;
     int count = 0;

     printf( "请输入一个整数: " );
     if ( scanf( "%d", &number ) != 1 )
     {
          printf( "输入无效。\n" );
          return 1;
     }

     // 处理负数
     number = abs( number );

     // 特殊情况：当输入为0时，检查是否需要计数
     if ( number == 0 )
     {
          // 如果0中包含数字2？通常不包含，所以count保持为0
     }
     else
     {
          while ( number != 0 )
          {
               int digit = number % 10;

               if ( digit == 2 )
               {
                    count++;
               }

               number /= 10;
          }
     }

     printf( "数字中 '2' 出现的次数: %d\n", count );

     return 0;
}
