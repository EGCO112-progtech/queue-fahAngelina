#define PRICE1 100
#define PRICE2 20
#define PRICE3 50

typedef struct {
  NodePtr headPtr, tailPtr;
  int size;
} Queue;

void enqueue_struct(Queue *q, int x, int y) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node) { // for homework

    new_node->order_number = x;
    new_node->qty = y;
    new_node->nextPtr = NULL; //ได้nodeมาใหม่

    if (q->headPtr == NULL)
      q->headPtr = new_node;
    else
      q->tailPtr->nextPtr = new_node;

    q->tailPtr = new_node;
    q->size++;
    /*Finish enqueue */
  }
}

int dequeue_struct(Queue *q) {
  NodePtr t = q->headPtr;
  int price;
  if (q->size > 0) {
    switch (t->order_number) {
    case 1:
      printf("Raman\n");
      price=PRICE1*t->qty;
      break;
    case 2:
      printf("Somtum\n");
      price=PRICE2*t->qty;
      break;
    case 3:
      printf("Fried Chicken\n");
      price=PRICE3*t->qty;
      break;
    default: printf("No food\n");
       price=0;
    }
  
  
  /*if (t) { // if(q->size>0)
    int value = t->data;
  */
  q->headPtr = t->nextPtr;
  if (q->headPtr == NULL)
    q->tailPtr = NULL;
  q->size--;
  free(t);
  return price;
    }
printf("Empty queue\n");
return 0;
}
