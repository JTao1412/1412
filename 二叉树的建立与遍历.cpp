#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
	char Data;
	BinTree Left,Right;
};

#define maxsize 20
struct QNode
{
	BinTree Data[maxsize];
	int front;
	int rear;
};
typedef struct QNode * Queue;

BinTree createTree()   //���Ľ���
 {  
	 BinTree t; 
     char ch,temp;  
     ch=getchar();  //���������ݽ�������
	 temp=getchar();
     if(ch=='*')  //�ж϶������Ƿ�Ϊ��
		t=NULL;
     else 
     {  
         t=(BinTree)malloc(sizeof(BinTree)); //������������
         t->Data=ch;  
         t->Left=createTree();  
         t->Right=createTree();  
	 }

	 return t;  
 }  

void AddQ(Queue PtrQ,BinTree item)
{
	if((PtrQ->rear+1)%maxsize==PtrQ->front)
	{
		printf("������");
		return;
	}
	PtrQ->rear=(PtrQ->rear+1)%maxsize;
	PtrQ->Data[PtrQ->rear]=item;
}

BinTree DeleteQ(Queue PtrQ)
{
	PtrQ->front=(PtrQ->front+1)%maxsize;
	return PtrQ->Data[PtrQ->front];
}

Queue CreatQueue()
{
	Queue q;
	q=(Queue)malloc(sizeof(QNode));
	q->front=0;
	q->rear=0;
	return q;
}
int IsEmpty(Queue BT)
{
	if(BT->rear==BT->front)
		return 1;
	else
		return 0;
}

void LevelOrderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;
	if(!BT) 
	return;
	Q=CreatQueue();
	AddQ(Q,BT);
	while(!IsEmpty(Q))
	{
		T=DeleteQ(Q);
		cout<<T->Data<<" ";
		if(T->Left)AddQ(Q,T->Left);
		if(T->Right)AddQ(Q,T->Right);
	}
	
}

int main()
{
	BinTree t;
	t=createTree();
	LevelOrderTraversal(t);
	return 0;
}

