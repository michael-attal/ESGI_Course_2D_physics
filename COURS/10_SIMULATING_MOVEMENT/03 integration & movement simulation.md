# Pourquoi parler de calcul ?  


Nous devons commencer par répondre à la question suivante : pourquoi parler de *calcul infinitésimal* (*calculus*) lorsque nous abordons la simulation physique (*physics simulation*) en temps réel, que l’on retrouve dans les moteurs de jeu vidéo ?  

---

La raison est la suivante : une simulation physique logicielle fonctionne en réalisant de petites **prédictions successives** basées sur les lois de la physique.  
Cela signifie que nous effectuons des prédictions en utilisant un outil mathématique appelé **intégration** (*numerical integration*), c’est-à-dire **le calcul intégral** appliqué pour estimer **la position future d’un objet**.  
Plus **le pas de temps** (*delta time*, $\Delta t$) de la simulation est petit, plus cette prédiction est précise ; inversement, un pas de temps plus grand augmente l’erreur de notre simulation.  

---

# Prédire le mouvement d’un objet  

Dans notre contexte, si un objet est situé à une position donnée et se déplace à une vitesse donnée dans une direction donnée, alors après un laps de temps très court il se trouvera à une nouvelle position.  

Cette prédiction est réalisée **à chaque image** de la simulation, **étape par étape**, car en informatique tout est **discret** : nous ne manipulons pas directement une fonction **continue**, mais une approximation discrète de son évolution au cours du temps.  

---

# La dérivation et le mouvement  

Nous devons alors relier ces notions à la **dérivation** (*differentiation*), appliquée aux fonctions du mouvement :  
– la **position** en fonction du temps  
– la **vitesse** en fonction du temps  

La dérivée représente le **taux de variation** (*rate of change*).  
Ainsi, **le taux de variation de la position par rapport au temps est la vitesse**.  

---

# La notion de dérivée  

À un instant donné $t$, le taux de variation de la position correspond à la **pente de la tangente** à la courbe position-temps.  

Mathématiquement, nous écrivons :  
$$
v = \frac{dp}{dt}
$$  
Le symbole $ dt $ est directement lié à notre **delta time** en simulation : lorsque $ dt \to 0 $, nous approchons la vitesse **instantanée**.  

---

# Position, vitesse, accélération  

La **vitesse** est la dérivée de la position.  
De même, **le taux de variation de la vitesse** est l’**accélération** :  
$$
a = \frac{dv}{dt}
$$  
Dans le cas d’une **accélération constante**, la vitesse varie **linéairement** au cours du temps.  

---

# Chaîne de dérivation  

Nous avons donc la relation suivante :  

Position → (dérivée) → Vitesse → (dérivée) → Accélération  

Ce schéma correspond à l’analyse **du mouvement d’un objet en chute libre** soumis à une accélération constante de $9{,}8\,\text{m/s}^2$.  

---

# L’intégration : opération inverse  

Si la dérivation nous fait descendre dans cette chaîne,  
**l’intégration** (*integration*) nous permet de faire le chemin inverse.  

Si l’accélération est connue, **intégrer l’accélération** au cours du temps nous donne la **vitesse**.  

---

# De l’accélération à la vitesse  

L’intégrale d’une **fonction constante** (accélération constante) donne une **fonction linéaire** (vitesse croissante).  
Cela correspond à l’intuition mathématique du calcul intégral.  

---

# De la vitesse à la position  

De même, **intégrer la vitesse** au cours du temps nous fournit la **position**.  
Cette opération d’intégration **numérique**, appliquée à chaque pas de temps de la simulation, constitue la base de **l’intégration d’Euler** (*Euler integration*), méthode simple et très utilisée en informatique graphique et en jeux vidéo.  

---

# Intégration d’Euler en simulation physique  

Ainsi :  
– dériver pour obtenir la vitesse à partir de la position  
– dériver pour obtenir l’accélération à partir de la vitesse  
– intégrer pour obtenir la vitesse à partir de l’accélération  
– intégrer pour obtenir la position à partir de la vitesse  

Ce cycle est répété **à chaque frame** de la simulation.  

---

# Synthèse : dérivation et intégration  

| Fonction | Dérivée | Interprétation |
|----------|---------|---------------|
| Position $p$ | $\frac{dp}{dt}$ | Vitesse |
| Vitesse $v$ | $\frac{dv}{dt}$ | Accélération |


| Fonction | Intégrale | Interprétation |
|----------|----------|---------------|
| Accélération $a$ | $\int a \, dt$ | Vitesse |
| Vitesse $v$ | $\int v \, dt$ | Position |

La dérivation analyse la variation,  
l’intégration reconstruit la fonction sous-jacente.  

---

# Liens avec la mécanique classique  

Les équations fondamentales d’un mouvement à accélération constante (que l’on étudie au lycée) découlent directement de ces principes :  

$$
p = p_0 + v_0t + \tfrac12at^{2}
$$  
$$
v = v_0 + at
$$  

Ces équations **proviennent** simplement de l’intégration **de l’accélération**, puis de la **vitesse**.  

---

Nous voyons donc que le calcul infinitésimal est **au cœur** de toute simulation physique réaliste : il établit le lien mathématique entre **accélération**, **vitesse** et **position** dans un monde simulé.  
