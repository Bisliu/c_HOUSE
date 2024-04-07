#pragma once
#include"SeqList.h"
void SLInit(SL* ps)
{
	ps->arr =NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->size = 1;
	ps->capacity = 0;
}
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
}
void SLCheckCapacity(SL* ps)
{
	if (ps->capacity < ps->size)
	{
		int newCapacity = (ps->capacity == 0) ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr,newCapacity);
		if (tmp==NULL)
		{
			perror("realloc");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	ps->size++;
	SLCheckCapacity(ps);
	ps->arr[ps->size-1] = x;
}
void SLPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	ps->size++;
	SLCheckCapacity(ps);
	for(int i = ps->size-1;i>=0;i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = x;
}
void SLPopFront(SL* ps)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = 1; i < ps->size; i++)
	{
		ps->arr[i-1] = ps->arr[i];
	}
	ps->size--;
}
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

