这个程序里面的循环挺好的，结构很有意思



#include <stdio.h>

int main()
{
     int n, number;
     int digit_counts[10] = { 0 }; // 用于存储每个数字（0-9）的出现次数

     printf( "请输入要处理的正整数的数量: " );
     if ( scanf_s( "%d", &n ) != 1 || n <= 0 )
     {
          printf( "输入无效。请输入一个正整数。\n" );
          return 1;
     }

     printf( "请输入 %d 个正整数，每个整数之间用空格或换行分隔:\n", n );
     for ( int i = 0; i < n; i++ )
     {
          if ( scanf_s( "%d", &number ) != 1 || number <= 0 )
          {
               printf( "输入无效。请确保输入的是正整数。\n" );
               return 1;
          }

          // 分析每个数字
          int temp = number;
          // 处理数字为0的情况
          if ( temp == 0 )
          {
               digit_counts[0]++;
          }
          while ( temp > 0 )
          {
               int digit = temp % 10;
               digit_counts[digit]++;
               temp /= 10;
          }
     }

     // 找出出现次数最多的数字
     int max_count = digit_counts[0];
     int max_digit = 0;
     for ( int i = 1; i < 10; i++ )
     {
          if ( digit_counts[i] > max_count )
          {
               max_count = digit_counts[i];
               max_digit = i;
          }
     }

     // 输出结果
     printf( "每个数字出现的次数如下:\n" );
     for ( int i = 0; i < 10; i++ )
     {
          printf( "数字 %d: %d 次\n", i, digit_counts[i] );
     }
     printf( "出现次数最多的数字是 %d，出现了 %d 次。\n", max_digit, max_count );

     return 0;
}
