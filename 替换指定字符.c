#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000 // 定义最大字符串长度

// 函数声明
void replace_characters( char *str );

int main()
{
     char str[MAX_LENGTH];

     // 提示用户输入字符串
     printf( "请输入一个字符串（最多 %d 个字符）：\n", MAX_LENGTH - 1 );
     if ( fgets( str, sizeof( str ), stdin ) == NULL )
     {
          printf( "输入错误。\n" );
          return 1;
     }

     // 移除换行符（如果有的话）
     size_t len = strlen( str );
     //的作用是计算字符串 str 的长度，并将结果存储在变量 len 中
     //它用于计算传入的 C 风格字符串（即以空字符 '\0' 结尾的字符数组）的长度，不包括终止的空字符。
     //返回值：返回一个 size_t 类型的值，表示字符串的长度（即字符的数量）
     //size_t 是一种无符号整数类型   len 是一个变量，用于存储字符串的长度

     if ( len > 0 && str[len - 1] == '\n' )
     {
          str[len - 1] = '\0';
     }

     // 执行字符替换
     replace_characters( str );

     // 输出结果
     printf( "替换后的字符串为：\n%s\n", str );

     return 0;
}

// 函数定义：替换指定字符
void replace_characters( char *str )
{
     for ( int i = 0; str[i] != '\0'; i++ )
     {
          switch ( str[i] )
          {
          case 'A':
               str[i] = 'Z';
               break;
          case 'B':
               str[i] = 'Y';
               break;
          case 'C':
               str[i] = 'X';
               break;
               // 如果需要处理小写字母，可以取消下面的注释

          case 'a':
               str[i] = 'z';
               break;
          case 'b':
               str[i] = 'y';
               break;
          case 'c':
               str[i] = 'x';
               break;

          default:
               // 不进行替换
               break;
          }
     }
}
