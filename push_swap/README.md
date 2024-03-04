# Push_Swap: Le tremplin vers les algorithmes :D

## Description du projet
Ce projet vise principalement à découvrir le monde des algos, d'une première vue
il apparaît simple aussi qu'intéressant. Il s'agit de trier des valeurs dans un stack (du plus petit au plus grand). Un stack en français est une pile, signifiant tout simplement une structure de données fondée sur le principe LIFO "Last in first out", pour plus d'infos: https://fr.wikipedia.org/wiki/Pile_(informatique)

## Compilation du programme Push_Swap
Pour construire le programme, il suffit d'exécuter la commande ```make``` sur votre Shell préféré, bien qu'après avoir cloné ce répertoire sur votre machine, pour ce faire,
exécutez la commande ci-dessous sur votre Shell. <br>
```
$> git clone https://github.com/achahid19/1337_projects.git
```
Ensuite, changez le répertoire vers push_swap et exécutez la commande ```make```
```
$> cd push_swap
```
N.B: Ce programme a été codé sur une machine Linux, si un problème est survenu lors de la compilation sur d'autres OS, merci de me contacter. <br>

## Compilation du programme Checker
Le programme du Checker est construit pour vérifier les actions appliquées par le programme push_swap pour faire trier les valeurs sur le stack. Ces opérations ou actions (une liste d'actions est communiquée sur la partie Liste des actions) sont vérifiées de manière exhaustive sur la pile, afin de s'assurer que l'algorithme appliqué par le programme push_swap est validé pour trier tous les valeurs sur la pile, si c'est le cas le programme Checker affichera un 'OK' sur votre Shell. Plus de détails sont discutés sur la partie Exécution du programme.
Pour compiler le programme Checker, veuillez exécuter la commande suivante:
```
make bonus
```

## Execution du programme:
Maintenant que les deux programmes sont sur votre répertoire, c'est le temps de les faire tourner.
- Push_Swap execution: <br>
Il nous faudra le nom du programme écrit de cette manière "./push_swap" + les arguments, les arguments c'est ceux qui contiennent les valeurs à trier. Donc la formule est comme suit:<br>
<strong>./push_swap "1 -1 0 100 2" ou ./push_swap "-5 48 39 -100 3 4" "0 -2" "1" ...</strong>
```
$> ./push_swap $ARG
```
Remplacer $ARG par les valeurs désirées.
N.B: le programme affichera un nombre d'actions appliquées sur le stack afin de le trier,
à savoir que ces actions sont expliquées sur la partie Liste des actions.
- Checker execution:
Le but du Checker est de recevoir les instructions de la part du programme push_swap, après les appliquer sur la pile et enfin vérifier si elle est bien triée ou pas.
```
$> $ARG="-1 2 -100 0 -4 1000 1002"; ./push_swap $ARG | ./checker $ARG
```
Après avoir exécuté la commande ci-dessus, un message sera affiché sur le terminal, alors il y aura deux possibilités soit un 'OK' ou 'KO', mais qu'est-ce que cela signifie chacun d'eux !<br>
-'OK': la pile est bien triée comme il faut ✅ <br>
-'KO': À la prochaine cher ami ❌

## Liste des actions
| Actions				| Description
|-----------------------|---------------------------------------------------------------------------------------------------------------
| sa (swap a)			| Échange les deux premiers éléments en haut de la pile a. Ne fait rien s'il n'y a qu'un seul élément ou aucun.
| sb (swap b)			| Échange les deux premiers éléments en haut de la pile b. Ne fait rien s'il n'y a qu'un seul élément ou aucun.
| ss 					| sa et sb en même temps
| pa (push a)			| Prend le premier élément en haut de la pile b et le place en haut de la pile a. Ne fait rien si b est vide.
| pb (push b)			| Prend le premier élément en haut de la pile a et le place en haut de la pile b. Ne fait rien si a est vide.
| ra (rotate a)			| Décale tous les éléments de la pile a vers le haut de 1. Le premier élément devient le dernier.
| rb (rotate b)			| Décale tous les éléments de la pile b vers le haut de 1. Le premier élément devient le dernier.
| rr					| ra et rb en même temps.
| rra (reverse rotate a)| Décale tous les éléments de la pile a vers le bas de 1. Le dernier élément devient le premier.
| rrb (reverse rotate b)| Décale tous les éléments de la pile b vers le bas de 1. Le dernier élément devient le premier.
| rrr					| rra et rrb en même temps.

## Algorithme