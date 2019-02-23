#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ADT_Eile.h"
#include "ADT_Tipas.h"

struct Queue CreateMyQueue (void)
{
  struct Queue MyQueue;

  MyQueue.Tail = MyQueue.Head = 0;
  MyQueue.Size = 0;

  return MyQueue;
}


struct QueueNode* CreateMyQueueNode (QueueElement MyData)
{
  struct QueueNode* MyNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
  MyNode -> Next = MyNode -> Previous = 0;
  MyNode -> Data = MyData;

  return MyNode;
}


void PushToQueue (struct Queue* MyQueue, QueueElement MyData)
{
  if (MyQueue -> Size == 0)
  {
    MyQueue -> Tail = MyQueue -> Head = CreateMyQueueNode (MyData);
    MyQueue -> Size += 1;
  }
  else
  {
    MyQueue -> Tail -> Next = CreateMyQueueNode (MyData);
    MyQueue -> Tail -> Next -> Previous = MyQueue -> Tail;
    MyQueue -> Tail = MyQueue -> Tail -> Next;
    MyQueue -> Size += 1;
  }
}


QueueElement PopFromQueue (struct Queue* MyQueue)
{
  struct QueueNode* FirstElement = MyQueue -> Head;

  QueueElement Element = FirstElement -> Data;

  if (-- MyQueue -> Size != 0)
  {
    MyQueue -> Head = FirstElement -> Next;
  }

  free (FirstElement);

  return Element;
}


QueueElement GetHeadValue (struct Queue* MyQueue)
{
  return MyQueue -> Head -> Data;
}


bool IsQueueEmpty (struct Queue* MyQueue)
{
  return MyQueue -> Size == 0;
}


int QueueSize (struct Queue* MyQueue)
{
  return MyQueue -> Size;
}


void DestroyQueue (struct Queue* MyQueue)
{
  while (MyQueue -> Size)
  {
    PopFromQueue (MyQueue);
  }
}
