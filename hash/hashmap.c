#define _GNU_SOURCE	     // needed for reentrant version of this library
#include <search.h>
#include <stdlib.h>
#include <stdio.h>


#define NUMBOFKEYS 111

int main()
{
	char *tab[] = {"1234", "2222" ,"44" ,"3" ,"554" ,"66152", "4432" ,"5"};
	unsigned int size = sizeof(tab) / sizeof(tab[0]);	

// char buffer because need to work with strings as data, not int. Using sprintf as an itoa //
	char stringmem[100];
	ENTRY * retval = NULL;

//	initialising the struct, otherwise segfault/valgrind error, still dont fully understand why this line works, because //
//	i wasnt supposed to access this struct members as said in the lib doc //
	struct hsearch_data htab = { 0 };
	hcreate_r(NUMBOFKEYS, &htab);
	int i = 0;

	while ( i < size)
	{

		// needed to convert to int the string data in order to modulo number of keys //
		sprintf(stringmem, "%d", atoi(tab[i]) % NUMBOFKEYS); 

		//  using a compound literal to loop on ENTER data in hashtable //
		hsearch_r((ENTRY){ stringmem, tab[i]}, ENTER, &retval, &htab);

		// SHOULD DO ANOTHER WHILE HERE, DOESNT MAKE SENSE THIS WAY
		hsearch_r((ENTRY){ stringmem, tab[i]}, FIND, &retval, &htab);
		printf("%s\n", retval->data);
		printf("%s\n", retval->key); 
		i++;
	}
	hdestroy_r(&htab);
	return (0);
}

// 4-9-25
// Ce qui a fait fonctionner cette lib:
// 		-initialiser la struct htab a 0 via le = { 0 }
// 		-avoir la data en strings
// 		-comme je pensais je pouvais avoir la struct keys/data en compound literal`

//utiliser intro to algo pour comprendre les hashtables
//
// j'ai un peu compris le principe de l'utilisation de la hash table sur two sum:
// on met dans la hashtable les nombres qu'on nous donne, et ensuite c'est sur le lookup qu'on va gagner beaucoup
// de temps. On calcule d'abord vis à vis du chiffre qu'il faudrait pour atteindre la bonne somme selon le numéro
// de l'index sur lequel on est, et ensuite on regarde sur la hashtable (donc en O(1)) plutot que passer linéairement
// sur chaque éléments de l'index.
// je pense que pour ce problème je n'ai pas besoin de faire de hash fonction et je peux juste mettre les nombres.
// Non, avec les contraintes on est obligé de faire avec une hash fonction parce que sinon c"est beaucoup trop grand


// faire chaque version de la hash function, division, multiplication, et la 3e, et aussi comprendre lhistoire des less significant
// bits sur la premiere version etc.. et ensuite faire twosum en version hachée


// do division method, multiplication method, and universal hashing avaec des keys statiques


// je sais pas si je vais réussir tout de suite à faire le universal hashing car faut vraiment bien comprendre les
// math pour pas se planter sur la deuxieme table de hachage, ça va me prendre du temps.
//
//
// Aussi noter la technique pour avoir ce qu'il y a après la virugule: mod 1, et comprendre pourquoi il y a les rounding
// error sur les float


// On va plutot essayer de faire avec la libc déjà, donc avec hcreate
// regarder pour le crc32 pour faire une hash fonction maison


// https://stackoverflow.com/questions/190229/where-is-the-itoa-function-in-linux
//  http://www.burtleburtle.net/bob/hash/doobs.html
// https://www.reddit.com/r/programminghorror/comments/uitjxl/hsearch_why_is_this_crap_in_libc/
// pour l'instant on va juste faire au plus simple, on additionne tous les chars de la string. On verra après pour faire des meilleures
// hash func.


//----------
//4-9-25
//
//finir hash func
//faire fonctioinner hsearch
//essayer de faire fonctionner sans hash fonction, juste avec les numéros dans des strings avec modulo nb keys etc...
//
//
//
//
//
//


// pour la prochaine fois, faire fonctionner le probleme de leetcode avec le bout de code fonctionnel que j'ai fait

// ensuite il faudra essayer de faire les techniques du livres, toutes les tester

// au passage, je pense vraiment que pour devenir bon, il faut juste ponçer le livre des algos de a a z et tous les autres
// truc de base des autre concepts, os, compi etc, et sur 10 ans je peux devenir bon

