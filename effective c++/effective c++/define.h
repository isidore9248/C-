#pragma once

class define
{
	static constexpr int MAX_SIZE = 10;	//只是declaration，不占用空间
	int score[MAX_SIZE];
};
constexpr int define::MAX_SIZE;	//definition，占用空间
//类常量的初始值是声明的时候就确定的，而不是在定义的时候

//在使用define定义类似函数时，用inline代替
//既可以获得宏的执行效率，又可以有普通函数一样的可预测性

/*
	#define CALLMAX(a,b) ((a)>(b)?(a):(b))	替换为如下
*/
template<typename T>
inline T callMax(T a, T b)
{
	return (a > b) ? a : b;
}
