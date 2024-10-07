int main(void){
    int a;
    for (int i=0; i<10; i++) {
        a = i;
    }
    
}

/*

int main(void){
    81de:       b580            push    {r7, lr}            : On met la valeur du registre et du frame pointer r7 dans la pile
    81e0:       b082            sub     sp, #8              : On réserve 8 octets pour 2 int a et i 
    81e2:       af00            add     r7, sp, #0          : r7 prend la valeur de sp pour marquer le début de la zone mémoire de la fonction
    int a;
    for (int i=0; i<10; i++) {
    81e4:       2300            movs    r3, #0              : On initialise i à 0 en utilisant r3
    81e6:       607b            str     r3, [r7, #4]        : On stock i en mémoire à 4 octects d'offset car c'est al taille d'un int
    81e8:       e004            b.n     81f4 <main+0x16>   : On saute au début de la boucle (point d'anchrage)
        a = i;
    81ea:       687b            ldr     r3, [r7, #4]        : On lit la valeur de i stocké précédemment en mémoire pour la remettre dans r3
    81ec:       603b            str     r3, [r7, #0]        : On stock la valeur de i dans a en zone mémoire
    for (int i=0; i<10; i++) {
    81ee:       687b            ldr     r3, [r7, #4]        : On lit la valeur de i depuis la mémoire 
    81f0:       3301            adds    r3, #1              : On l'incrémente au sein de r3 
    81f2:       607b            str     r3, [r7, #4]        : On remet i incrémenté de 1 en mémoire à sa place 
    81f4:       687b            ldr     r3, [r7, #4]        : On lit la valeur de i 
    81f6:       2b09            cmp     r3, #9              : On compare alors i avec notre fin de boucle 9 
    81f8:       ddf7            ble.n   81ea <main+0xc>    : Si la comparaison est vrai on retourne au début de la boucle grâce au point d'anchrage
    }
    
    81fa:       46c0            nop                     @ (mov r8, r8)  :Sinon on sort de la boucle
    81fc:       0018            movs    r0, r3              :r0 prend la valeur de i
    81fe:       46bd            mov     sp, r7              : On remet les sp et r7 au début de la zone mémoire
    8200:       b002            add     sp, #8              : On libère les 8 octects
    8202:       bc80            pop     {r7}                : On récupère le frame pointer de la fonctino appelante depuis la pile 
    8204:       bc02            pop     {r1}                : On récupère l'addresse de retour 
    8206:       4708            bx      r1                  : On renvoie l'addresse de retour

*/