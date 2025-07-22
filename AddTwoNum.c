#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

unsigned int MyPow(unsigned int num, short pow)
{
	unsigned int x = 1;

	while (pow--)
	{
		x *= num;
	}
	return x;
}


unsigned int ListToUint(struct ListNode *list)
{
	unsigned int num = 0;
	short power = 0;
	while (list)
	{
		num += (list->val * MyPow(10, power));
		power++;
		list = list->next;
	}
	return (num);
}




unsigned int	GetDigNum(unsigned int number)
{
	int result = 0;
	if (!number)
		return (1);
	while(number)
	{
		number /= 10;
		result++;
	}
	return result;
}
			
struct ListNode	*FillList(unsigned int number, unsigned int NumDig)
{
	struct ListNode *list;
	if (NumDig)
		list = malloc(sizeof(struct ListNode));
	else
		return (NULL);
	if (!list)
		exit(-1);
	list->val = number % 10;
	list->next = FillList((number / 10), (NumDig - 1));
	return (list);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	unsigned int first = ListToUint(l1);
	unsigned int second = ListToUint(l2);
	unsigned int result = first + second;

	printf("%d\n", first);
	printf("%d\n", second);
	return (FillList(result, GetDigNum(result)));
}

void TestListVal(struct ListNode *list)
{
	struct ListNode *temp;

	while(list)
	{
		printf("%d", list->val);
		temp = list;
		list = list->next;
		free(temp);
	}
	printf("\n");
}

int main()
{
	unsigned int FirstNum = 9;
	unsigned int SecondNum = 1999999999;
	struct ListNode *FirstList = FillList(FirstNum, GetDigNum(FirstNum));
	struct ListNode *SecondList = FillList(SecondNum, GetDigNum(SecondNum));
	struct ListNode *result;

	result = addTwoNumbers(FirstList, SecondList);
	TestListVal(FirstList);
	TestListVal(SecondList);
	TestListVal(result);
	return (0);
}


// JE DOIS REFAIRE AVEC UNE AUTRE METHODE QUI NE CONVERTI PAS EN INT LES NOMBRE MAIS FAIT DES OPERATIONS SUR LES LIST DIRECTEMENT

	// tests  GetDigNum //	
//	printf("%d\n",	GetDigNum(765));
//	printf("%d\n",	GetDigNum(0));
//	printf("%d\n",	GetDigNum(99920));

	

