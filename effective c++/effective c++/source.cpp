//#define _CRT_SECURE_NO_WARNINGS
#include "HeadFile.h"



double arctan_angle(double num)
{
    double result_radians = atan(num);
    double Ret = result_radians * (180.0 / 3.14159265);  // 转换为度数
    return Ret;
}

int main()
{
    double ret = arctan_angle(0.14);

	repvirfunc_FuncPtrtest();


    return 0;
}