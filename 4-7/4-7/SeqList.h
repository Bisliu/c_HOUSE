﻿#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLDataType;
// 动态顺序表 -- 按需申请
typedef struct SeqList
{
	SLDataType* arr;//数据数组
	int size; // 有效数据个数
	int capacity; // 空间容量
}SL;
//初始化和销毁
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);
//扩容
void SLCheckCapacity(SL* ps);
//头部插⼊删除 / 尾部插⼊删除
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
//指定位置之前插⼊/删除数据
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
int SLFind(SL* ps, SLDataType x);