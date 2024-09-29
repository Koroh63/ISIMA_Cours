# Architecture Logicielle

### ROM

Contient le programme de démarrage de l'ordinateur ( BIOS ) 
CPU, RAM et ROM sont fonctionnel si un message et affiché au démarrage ( si rien alors KO )

En plus on rajoute des entrées-sorties ( broches qui passe de 1 à 0 )

Les autres : 
- entrées-sorties évoluées 
- etc 

### Processeur 
Parties importantes d'un processeurs : 

- ALU : Unité de calcul, elle définit la performance du processeur 
- Registre : petite mémoire interne pour stocker les calcul et les résultats volatile, parfois la mémoire est utilisé à la place.

L'ajout du multiplieur et de barrel shifter( décale les données ) en parallèle permet de ne pas ralentir l'ALU 

- Décodeur d'instruction : ordonnance les actions en fonction des instructions. Il commande l'intéreieur et l'extérieur du processeur 

### Mémoire 

SRAM : Avec 6 transistors permet de stocker longtemps mais à grand coût 

DRAM : Avec un transistor et 1 condensateur qui stocke, 3 fois moins couteux mais est plus volatile

### Les périphériques 

Silicium que l'on rajoute qui va simplifier le rôle du processeur 


### Les processeur ARM ( AMD )

Ils sont beaucoup plus rationnels dans leur structure 

## Programmation du processeur 

Format Thumb sur 16 bit ( prend moins de mémoire )
ou classique sur 32 bit ( plus d'instruction plus efficace)

### L'assembleur 

language associé directement au langage machine 

1 instriction machine = 1 ligne assembleur 



011 0 1 00001 111 010 -> 6857



001 00 011 00000100

MOV r3, #4 
