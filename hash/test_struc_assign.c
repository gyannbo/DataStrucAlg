#include <stdio.h>




typedef struct exemple {
	int a;
	int b;
}Exemple;	

void	somePrintFunc(Exemple ex)
{
	printf("%d %d\n", ex.a, ex.b);
}

void	somePrintFuncTab(int *tab)
{
	printf("%d %d\n", tab[0], tab[1]);
}

int main()
{
	// this is called a compound literal apparently, two syntax possible :
	somePrintFunc((Exemple){10,  11});
	somePrintFunc((Exemple){.a = 10, .b =  11});
	somePrintFuncTab((int []){210, 3411});
	return (0);
}

	
