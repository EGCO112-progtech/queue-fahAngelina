

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"
int main(int argc, char **argv) {
  NodePtr headPtr = NULL;
  NodePtr tailPtr = NULL;
  /* For struct Queue*/
  Queue q;
  q.headPtr = NULL;
  q.tailPtr = NULL;
  q.size = 0;

  int i, x, cash, j=1;
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "x") == 0){
      printf("Customer no.%d\n",j++);
      x = dequeue_struct(&q); 
    //printf("%d",x);
    if (x > 0) {
      printf("You have to pay %d\n", x);

      do {
        printf("Cash: ");
        scanf("%d", &cash);
      } while (cash < x);
      if (cash > x)
        printf("Change is:%d\n", cash - x);
      printf("Thank you\n");
      printf("=========================================\n");

    }
      }
    else {
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i + 1]));
      i++;
    }
    }
    if (q.size > 1)
      printf("There are %d ppl left in the queue.\n", q.size);
    else if(q.size == 1)
      printf("There is %d ppl left in the queue.\n", q.size);
    else if(q.size < 1)
      printf("There is on ppl left in the queue.\n");
    // printf("dequeing %d\n", x);

    printf("Clearing all nodes\n");
    while (q.size > 0)
      dequeue_struct(&q);
    return 0;
  
}