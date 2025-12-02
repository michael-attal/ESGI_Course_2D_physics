# Introduction  

Depuis que nous utilisons la programmation pour enseigner les concepts mathématiques, il est pédagogique d’exposer aux étudiants les notations diverses employées en calcul différentiel.  
Cela permet de relier les notations formelles aux implémentations numériques et aux simulations.  

---

# Notation de Leibniz  

Lorsque l’on parle du taux de variation d’une quantité $x$ par rapport au temps, la notation usuelle est :  
$$
\frac{dx}{dt}
$$  

Cette écriture — appelée **notation de Leibniz** — explicite clairement la variable indépendante ($t$) et la variable dépendante ($x$).  
Elle facilite la compréhension dans un contexte algorithmique, notamment lors de la discrétisation temporelle.  

---

# Généralisation de la différentiation  

La différentiation est un concept général et n’implique pas nécessairement le temps.  
On peut écrire :  
$$
\frac{dx}{dy}
$$  
lorsque la variable indépendante est une autre grandeur $y$.  

Le sens physique et l’interprétation numérique de $x$ et $y$ dépendent du problème étudié :  
- $x$ = position, $y$ = temps  
- $x$ = température, $y$ = position spatiale  

---

# Exemple : premières et secondes dérivées  

Exemple (première et deuxième dérivées, notation de Leibniz) :  

![[medias/leibniz-notation.png]]

---

# Notation de Newton  

Une autre notation, très répandue en physique, est la **notation de Newton** (*dot notation*).  
Elle est commode lorsque la variable indépendante est le temps.  

- Dérivée première par rapport au temps : $\dot{x}$  
- Dérivée seconde par rapport au temps : $\ddot{x}$  

Cette écriture est compacte et fréquemment utilisée dans les équations du mouvement.  

---

# Comparaison : Leibniz et Newton  

Contexte physique :  
la dérivée première de la position $p$ est la vitesse $v$,  
et la dérivée seconde est l’accélération $a$.  

En notation de Leibniz :  
$$
v = \frac{dp}{dt}, \quad a = \frac{d^2p}{dt^2}
$$  

En notation de Newton :  
$$
v = \dot{p}, \quad a = \ddot{p}
$$  

![[medias/first-derivative-position.png]]

---

# Activité dirigée  

Rédigez la phrase suivante :  
> « La dérivée seconde de la position est l’accélération »  

en utilisant **les deux notations** (Leibniz et Newton).  

Ensuite :  
- pour un schéma temporel discrétisé, approximez numériquement $\ddot{p}(t)$ (par exemple, par **différences finies centrées**)  
- implémentez la formule en pseudo-code ou dans le langage de votre choix  
- discutez les **erreurs de troncature** et la **stabilité numérique**  
