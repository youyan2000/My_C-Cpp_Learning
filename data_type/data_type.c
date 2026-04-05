#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("type: \t\t************size**************\n");

    printf("bool: \t\t所占字节数：%lu\t最大值：%d\t\t最小值：%d\n",
           sizeof(_Bool), 1, 0);

    printf("char: \t\t所占字节数：%lu\t最大值：%d\t\t最小值：%d\n",
           sizeof(char), CHAR_MAX, CHAR_MIN);

    printf("signed char: \t所占字节数：%lu\t最大值：%d\t\t最小值：%d\n",
           sizeof(signed char), SCHAR_MAX, SCHAR_MIN);

    printf("unsigned char: \t所占字节数：%lu\t最大值：%u\t\t最小值：%u\n",
           sizeof(unsigned char), UCHAR_MAX, 0);

    printf("short: \t\t所占字节数：%lu\t最大值：%d\t\t最小值：%d\n",
           sizeof(short), SHRT_MAX, SHRT_MIN);

    printf("unsigned short: \t所占字节数：%lu\t最大值：%u\t\t最小值：%u\n",
           sizeof(unsigned short), USHRT_MAX, 0);

    printf("int: \t\t所占字节数：%lu\t最大值：%d\t最小值：%d\n",
           sizeof(int), INT_MAX, INT_MIN);

    printf("unsigned int: \t所占字节数：%lu\t最大值：%u\t最小值：%u\n",
           sizeof(unsigned int), UINT_MAX, 0);

    printf("long: \t\t所占字节数：%lu\t最大值：%ld\t最小值：%ld\n",
           sizeof(long), LONG_MAX, LONG_MIN);

    printf("unsigned long: \t所占字节数：%lu\t最大值：%lu\t最小值：%u\n",
           sizeof(unsigned long), ULONG_MAX, 0);

    printf("long long: \t所占字节数：%lu\t最大值：%lld\t最小值：%lld\n",
           sizeof(long long), LLONG_MAX, LLONG_MIN);

    printf("unsigned long long: 所占字节数：%lu\t最大值：%llu\t最小值：%u\n",
           sizeof(unsigned long long), ULLONG_MAX, 0);

    printf("float: \t\t所占字节数：%lu\t最大值：%g\t最小值：%g\n",
           sizeof(float), FLT_MAX, FLT_MIN);

    printf("double: \t所占字节数：%lu\t最大值：%g\t最小值：%g\n",
           sizeof(double), DBL_MAX, DBL_MIN);

    printf("long double: \t所占字节数：%lu\t最大值：%Lg\t最小值：%Lg\n",
           sizeof(long double), LDBL_MAX, LDBL_MIN);

    printf("type: \t\t************size**************\n");

    return 0;
}
