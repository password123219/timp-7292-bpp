#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
} list;


// инициализация пустого списка
void init(list *l){
    l->head = NULL;
};

// удалить все элементы из списка
void clean(list *l){
node* cln = l->head;
node* cln1;
while (cln->next != NULL){
cln1 = cln;
cln = cln->next;
free(cln1);
}
free(cln);
init(l);
};

// проверка на пустоту списка
bool is_empty(list *l){
  bool empty = false;
  if(l->head == NULL)
  {
  empty = true;
  return empty;
  }
};

// поиск элемента по значению. вернуть NULL если эжемент не найден
node *find(list *l, int value)
{
bool fnd;
fnd = false;
node* fnd1 = l->head;
while(fnd1 != NULL)
{
if(fnd1->value == value)
{
fnd = true;
}
fnd1 = fnd1->next;
}
if(fnd == false)
{
printf("%d ", 0);
}
else
{
  printf("%d ", 1);
}
};

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value){
  node* back;
  back = (node*)malloc(sizeof(node));
  back->value = value;
  back->next = NULL;
  if (l->head == NULL)
    l->head = back;
  else{
    node* p = l->head;
    while (p->next != NULL){
      p = p->next;
    }
    p->next = back;
    }
    return 0;
};

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value){
node *push;
push = (node*)malloc(sizeof(node));
push->value = value;
push->next = l->head;
l->head = push;
return 0;
};

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, int value, int x)
{
node *ia;
ia = (node*)malloc(sizeof(node));
ia->value = x;
ia->next = NULL;
node *ia1 = l->head;
int i = 1;
while(i < value)
{
ia1 = ia1->next;
i++;
}
if (value == 0)
{
ia->next = l;
l = ia;
}
else
{
if (ia1->next != NULL)
{
ia->next = ia1->next;
}
ia1->next = ia;
return 0;
}
};

// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_node(list *l, int value){
node* rnd = l->head;
node* rnd1;
while ((rnd->value != value)&&(rnd->next != NULL))
{
rnd1 = rnd;
rnd = rnd->next;
}
if ((rnd->next == NULL)&&(rnd->value != value))
  return 1;
else  if ((rnd->next == NULL)&&(rnd->value == value))
{
rnd1->next = NULL;  
}
else if (rnd == l->head)
{
l->head = rnd->next;  
}
else
{
rnd1->next = rnd->next;
}
free(rnd);
return 0;
};

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l){
node* prt = l->head;
while(prt)
{
printf("%d ", prt->value);
prt = prt->next;
}
printf("\n");
};


int main() {
list l;
int a,b,c, m, t, j, x, z;
init(&l);
scanf("%d", &a);
for (int i = 1; i <= a; i++)
{
scanf("%d", &c);
push_back(&l, c);
}
print(&l);
scanf("%d",&b);
find(&l, b);
scanf("%d",&b);
find(&l, b);
scanf("%d",&b);
find(&l, b);
printf("\n");
scanf("%d", &m);
push_back(&l, m);
print(&l);
scanf("%d", &t);
push_front(&l, t);
print(&l);
scanf("%d", &j);
scanf("%d", &x);
insert_after(&l, j, x);
print(&l);
scanf("%d", &z);
remove_node(&l, z);
print(&l);
return 0;
};