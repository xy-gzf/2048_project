#pragma once

#define SIDE 4
#define DATA 16
typedef struct Node
{
	int data[DATA];
	int length;
}Node,*NodePtr;

void Addnumber();
void Init2048(NodePtr sizestrlen);
void Sidelength(NodePtr sizestrlen);

void Wword(NodePtr sizestrlen);
void Sword(NodePtr sizestrlen);
void Aword(NodePtr sizestrlen);
void Dword(NodePtr sizestrlen);
int Exit2048(NodePtr sizestrlen);

void Show(NodePtr sizestrlen);

