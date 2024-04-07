#include"SeqList.h"
SL sl;
void test()
{
	SLInit(&sl);
	SLPushBack(&sl,1);
	SLPushBack(&sl,2);
	SLPushFront(&sl, 10);
	SLPrint(&sl);
}

int main()
{
	test();
	return 0;
}