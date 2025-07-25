#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct s_number {
	unsigned int length;
	int *numArray;
}Number;

bool	fillList(struct ListNode *list, Number *num)
{
	unsigned int i = 0;
	unsigned int remainLength = num->length;

	while(remainLength)
	{
		list->val = num->numArray[i];
		remainLength--;
		i++;
		if(remainLength >= 1)
		{
			list->next = malloc(sizeof(struct ListNode));
			list = list->next;
			continue;
		}
		list->next = NULL;
	}
	return (true);
}

void printList(struct ListNode *list)
{
	while(list)
	{
		printf("%d", list->val);
		list= list->next;
	}
	printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *resultList = malloc(sizeof(struct ListNode));
	resultList->val = 0;
	resultList->next = NULL;
	struct ListNode *temp = resultList;
	int opResult = 0;
	
	while(l1 || l2)
	{
		if (l1)				// encapsuler ca dans func
		{
			opResult += l1->val;
			l1 = l1->next;	
		}
		if (l2)
		{
			opResult += l2->val;
			l2 = l2->next;
		}
		temp->val = opResult % 10;
		opResult /= 10;
		if(l1 || l2 || opResult)
		{
			temp->next = malloc(sizeof(struct ListNode));
			temp = temp->next;
			temp->next = NULL;
		}
		if(opResult && !l1 && !l2)
			temp->val = opResult;
	}
	return(resultList);
}


int	main()
{
	int firstNumData[] = {2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9}; 
	int secondNumData[] = {5,6,4,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9,9,9,9}; 
	Number firstNum = { 
		.length = sizeof(firstNumData) / sizeof(int),
		.numArray = firstNumData
	};
	Number secondNum = { 
		.length = sizeof(secondNumData) / sizeof(int),
		.numArray = secondNumData
	};
	struct ListNode firstList = { 0, NULL};
	struct ListNode secondList = { 0, NULL};

	fillList(&firstList, &firstNum);
	fillList(&secondList, &secondNum);
	printList(addTwoNumbers(&firstList, &secondList));
	printList(&firstList);
	printList(&secondList);
	return (0);
}


// Had runtime error due to not initializing some struct member, be careful at all time when coding.
// Some algo error by one, on fillList, > 1 instead of >= 1,  be more careful next time.
// Code need to be more organized, to much repetition in addNumber function, not pretty.
