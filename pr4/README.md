###### <center>1 Введение </center>
Цель работы: изучить как работать с двусвязным списком в СИ.

Задание:
1. Должны быть выполнены предыдущие работы
2. Прочитать про двусвязные списки на СИ
3. Написать программу
4. Настроить pipeline
5. Написать отчет по работе в разметке Markdown (README.md)
6. Залить на gitlab и убедиться, что pipeline проходит успешно
7. Защитить работу у преподавателя.


###### <center>2 Ход работы </center>

###### <center>2.1 Программа </center>

Задание: Необходимо реализовать функции для работы с двусвязным списком:
```
// инициализация пустого списка
void init(list *l);

// удалить все элементы из списка
void clean(list *l);

// проверка на пустоту списка
bool is_empty(list *l);

// поиск элемента по значению. вернуть NULL если элемент не найден
node *find(list *l, int value);

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value);

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value);

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, node *n, int value);

// вставка значения перед указанным узлом, вернуть 0 если успешно
int insert_before(list *l, node *n, int value);

// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_first(list *l, int value);

// удалить последний элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_last(list *l, int value);

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l);

// вывести все значения из списка в обратном порядке через пробел,
// после окончания вывода перейти на новую строку
void print_invers(list *l);

```
Ниже представлен код программы:
```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int value;          // значение, которое хранит узел
	struct node *next;  // ссылка на следующий элемент списка
	struct node *prev;  // ссылка на предыдущий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
	struct node *tail;  // конец списка
} list;


// инициализация пустого списка
void init(list *l){
	l->head = 0;
	l->tail = 0;
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

// поиск элемента по значению. вернуть NULL если элемент не найден
node *find(list *l, int value){
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
	back -> prev = l -> tail;
	if (l->head==NULL){
        back->prev=NULL;
        l->head = back;
        l->tail = back;
        }
    else{
    	l->tail->next=back;
    	back->prev=l->tail;
    	l->tail = back;
    }
    return 0;
};

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value){
	node *push;
	push = (node*)malloc(sizeof(node));
	push->value = value;
	push->next = l ->head;
	push -> prev = NULL;
	l -> head -> prev = push;
	l->head = push;
	return 0;
};

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, int value, int x){
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
ia->prev = ia1;
}
ia1->next = ia;
ia->next->prev = ia;

return 0;
}
};

// вставка значения перед указанным узлом, вернуть 0 если успешно
int insert_before(list *l, int x, int value){
	node *ia;
ia = (node*)malloc(sizeof(node));
ia->value = x;
ia->next = NULL;
node *ia1 = l->head;
int i = 1;
while(i < value - 1)
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
ia->prev = ia1;
}
ia1->next = ia;
ia->next->prev = ia;
return 0;
}
};

// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_first(list *l, int value){
node *rvf1 = l->head;
node *rvf;
while(rvf1)
{
if (rvf1->value == value)
{
if (rvf1->prev) {
rvf1->prev->next = rvf1->next;
}
if (rvf1->next) {
rvf1->next->prev = rvf1->prev;
}
rvf = rvf1->value;
if (rvf1->prev == NULL) {
l->head = rvf1->next;
}
if (rvf1->next == NULL) {
l->tail = rvf1->prev;
}
free(rvf1);
}
rvf = rvf1;
rvf1 = rvf->next;
}
return 0;
};

// удалить последний элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_last(list *l, int value){
node *rlb = l->tail;
node *rlb1;
while ((rlb->value != value)&&(rlb->prev != NULL))
	{
		rlb1 = rlb;
		rlb = rlb->prev;
	}
	if ((rlb->prev == NULL)&&(rlb->value != value))
		return 1;
	else  if ((rlb->prev == NULL)&&(rlb->value == value))
	{
	l -> head = rlb1;  
	}
	else if (rlb == l->tail)
	{
	l->tail = rlb->prev;  
	rlb1 = rlb->prev;
	rlb1 -> next = NULL;
	l->tail = rlb1;
	}
	else
	{
	rlb->prev -> next = rlb->next;
	}
	free(rlb);
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

// вывести все значения из списка в обратном порядке через пробел,
// после окончания вывода перейти на новую строку
void print_invers(list *l){
	node* prt = l->tail;
	while(prt)
	{
	printf("%d ", prt->value);
	prt = prt->prev;
	}
	printf("\n");
};


int main() {
list l;
long int a,b,c, m, t, j, x, z,bfr1,bfr2,rmvfrt,rmvfrt1,lst1,lst2;
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
print_invers(&l);
scanf("%d", &t);
push_front(&l, t);
print(&l);
scanf("%d", &j);
scanf("%d", &x);
insert_after(&l, j, x);
print_invers(&l);
scanf("%d", &bfr1);
scanf("%d", &bfr2);
insert_before(&l, bfr2, bfr1);
print(&l);
scanf("%d", &rmvfrt);
remove_first(&l,rmvfrt);
print_invers(&l);
scanf("%d", &rmvfrt1);
remove_last(&l,rmvfrt1);
print(&l);
return 0;
};
```
Ожидаемые результаты программы представлены в таблице 1.

Таблица 1 - Результаты работы программы.

Ввод | Вывод |
--- | --- |
 5 |  |
 1 2 3 2 4|  1 2 3 2 4  |  
2 5 1  | 1 0 1  |  
1  | 1 4 2 3 2 1  |  
7  | 7 1 2 3 2 4 1  |  
3 0  |   1 4 2 3 0 2 1 7 |  
5 8  | 7 1 2 0 8 3 2 4 1  |  
2  |  1 4 2 3 8 0 1 7 |  
1  |  7 1 0 8 3 2 4 |  

На рисунке 1 представлен результат работы программы.

Результат представлен на рисунке 1.

![](/pr4/progpr4.png)

<center>Рисунок 1 - Результат работы программы </center>

Как видно по рисунку 1, результат работы программы полностью совпадает с ожидаемым результатом который представлен в таблице 1.

После написания кода, он был загружен в основной репозиторий. Ниже приведен скриншот тестов pipeline.

![](/pr4/Pipeline.png)

<center>Рисунок 2 - Pipeline </center>

###### <center>Заключение</center>
В результате выполнения практической работы, получили навыки по построению на языке Си двусвязных списков.

###### <center>Список использованых источников</center>
1. [Документация по Markdown](https://docs.gitlab.com/ee/user/markdown.html)
2. [C: двусвязные списки.](https://ee.kpi.ua/~yv/edu/amp/book/c/22/2206.htm)
