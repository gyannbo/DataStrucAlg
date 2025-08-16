//use fundamentals of data struc in c book
//non, utiliser plutot le intro to algo

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
