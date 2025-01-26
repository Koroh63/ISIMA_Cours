# QT 

Framework de dev d'application en C++ (wrapper python si besoin)
Orienté développement de client lourd.

Les classes Qt commencent par Q : utile pour la doc 

CMake est utilisé pour générer les executables 

QMainWindow : fenetre principale 
QWidget : représent un objet de l'interface 
QPushButton : Ajoute un bouton dans l'interface, on récupère le signal assez facilement
Il faut lui donner l'addresse du widget parents 
Pour utiliser le comportement du bouton on étend la classe Qpushbutton pour réécrire le comportement que l'on veut dans notre classe. 
pour lier l'emetteur et le récepteur on utilise *

```
connect
```
