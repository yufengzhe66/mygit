//类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
//编译阶段

//解决方式1：直接包含.cpp源文件
//#include "person.cpp"

//解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
#include "person.hpp"


//总结：主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp

void test11()
{
	person<string, int>p("Tom", 20);
	p.show();
}


