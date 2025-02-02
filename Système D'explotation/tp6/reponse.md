# TP Noté Système d'exploitation 

## Exercice 1 

### 1. 

a : fichier regulier
b : fichier regulier
c : liens symbolique
d : répertoire
e : fichier reguliers
f : pipe
g : liens symbolique
i : répertoire
j : liens symbolique

### 2. 

e : On peut lire si On fait partie du groupe propriétaire ou on est propriétaire.
f : On ne peut écrire dans f que si on est propriétaire du fichier 
b : personne ne peut executer b 
i : Tout le monde peut créer un fichier 

### 3.

La taille du fichier 

### 4.

Le nombre de liens sur le fichier 

### 5. 

Oui car d est un répertoire 

### 6. 

On lit le contenu de h 

### 7. 

On exexcute alors b 

### 8.

touch a 
chmod 751 a 
touch b 
chmod 664 b
ln -s b c 
chmod 777 c 
mkdir d 
chmod 755 d 
touch e 
chmod 755 e 
mkfifo -m 644 f
chmod 644 f 
ln -s b g 
chmod 777 g 
mkdir i 
chmod 757 i
ln -s h j 
chmod 777 j

## Exercice 2 :

### 1. 

true renvoie le code de retour 0 ( succès ) et false renvoie 1 ( échec )

### 2. 
- test -e fichier.txt   # test si le fichier existe 
- test -d repertoire    # test si le fichier existe et est un répertoire 
- test -p pipe          # test si le fichier existe et est un tube 

### 3. 

Le code de retour est défini par la dernière commande du tube

### 4. 

On peut récupérer le tableau des code de retour du pipe avec la variable de shell echo $PIPESTATUS

## Exercice 3 : 

### 1. 2. 3. et 4. 
Voir race .sh 

### 5.
kill -18 pour arrêter le process

### 6.
kill -19 pour le reprendre 


## Exercice 4 : 

### 1. 
Voir tee.sh

### 2. et 3. 

Voir surround.sh