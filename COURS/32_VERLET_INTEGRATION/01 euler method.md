## Intégration numérique et simulation physique  
### Cours ESGI – Complément / Bonus

Cette séance constitue un **complément de cours** visant à approfondir les notions d’**intégrateurs numériques** (*numerical integrators*) et, plus largement, de **méthodes numériques** (*numerical methods*) utilisées en simulation physique et en programmation graphique temps réel. L’objectif n’est pas d’entrer dans une formalisation mathématique exhaustive, mais de fournir une **intuition opérationnelle** utile pour le développement de moteurs physiques et de simulations interactives.

Nous commencerons par revenir sur l’**intégration d’Euler** (*Euler integration*), puis nous évoquerons brièvement d’autres méthodes classiques comme l’intégration du point milieu (*midpoint integration*) et les méthodes de **Runge–Kutta** (*Runge–Kutta methods*), avant de nous concentrer sur l’**intégration de Verlet** (*Verlet integration*), très utilisée dans les systèmes de particules et les simulations à contraintes.

---

## Rappel physique : mouvement à accélération constante

En physique classique, le mouvement d’un objet soumis à une **accélération constante** (*constant acceleration*), comme une pomme en chute libre, est décrit par une fonction continue reliant la **position** au **temps**. Cette relation est donnée par une équation analytique exacte, connue depuis le lycée, qui permet de calculer la position à tout instant.

Cette description repose sur des **fonctions continues**, définies sur l’ensemble des nombres réels, sans discontinuité. Or, cette continuité n’existe pas en informatique.

---

## Problème fondamental en informatique : le temps discret

Un ordinateur ne manipule pas des phénomènes continus. Toute simulation repose sur un **temps discret** (*discrete time*), découpé en pas de temps (*time steps*), généralement associés aux images affichées par seconde (*frames per second*).  
La simulation évolue donc selon une suite de temps :  
`t₀, t₁, t₂, t₃, …`

À chaque pas de temps, le système doit **estimer** l’état suivant (position, vitesse, etc.) à partir de l’état courant. Cette estimation repose nécessairement sur des **méthodes numériques**, ce qui introduit des **erreurs d’approximation** (*approximation errors*). Plus le pas de temps (*delta time*) est grand, plus ces erreurs sont importantes.

---

## Principe des méthodes d’intégration numérique

Les méthodes d’intégration numérique consistent à **approximer l’évolution d’une grandeur** (position, vitesse) à partir de ses dérivées (vitesse, accélération).  
Dans le cas du mouvement :
- la **vitesse** est la dérivée de la position,
- l’**accélération** est la dérivée de la vitesse.

L’ordinateur ne calcule pas ces dérivées de manière analytique : il les **approxime localement**, pas de temps après pas de temps, ce qui explique l’apparition d’erreurs cumulatives.

---

## Intégration d’Euler (Euler Integration)

L’**intégration d’Euler explicite** (*explicit Euler integration*) est la méthode la plus simple et la plus intuitive. À chaque pas de temps, elle procède en deux étapes :

1. Mise à jour de la position à partir de la vitesse courante  
   $$
   x_{n+1} = x_n + v_n \cdot \Delta t
   $$

2. Mise à jour de la vitesse à partir de l’accélération  
   $$
   v_{n+1} = v_n + a_n \cdot \Delta t
   $$

L’accélération est calculée à partir des forces appliquées au système, selon la loi de Newton :
$$
a = \frac{F}{m}
$$

Cette méthode est **simple à implémenter**, peu coûteuse en calcul, et largement utilisée pour des prototypes ou des simulations simples.

---

## Implémentation pratique (JavaScript / p5.js)

Dans une implémentation typique orientée objet :
- chaque **particule** stocke sa position, sa vitesse et sa masse,
- à chaque frame :
  - on calcule les forces,
  - on en déduit l’accélération,
  - on applique l’intégration d’Euler pour mettre à jour position et vitesse.

Le pas de temps (*delta time*) est généralement fourni par le moteur (par exemple en millisecondes dans *p5.js*), puis converti en secondes pour assurer la cohérence physique.

---

## Limite majeure de l’intégration d’Euler : gain d’énergie

Un point crucial à comprendre est que l’intégration d’Euler **ne conserve pas l’énergie du système**. Dans de nombreux cas (rebonds, contraintes), elle tend à **ajouter artificiellement de l’énergie** au fil du temps.

En pratique, cela se manifeste par :
- des objets qui rebondissent de plus en plus haut,
- une instabilité croissante de la simulation,
- un comportement non physique à long terme.

Ce phénomène n’est pas un bug d’implémentation, mais une **propriété numérique intrinsèque** de la méthode d’Euler explicite.

---

## Vers des intégrateurs plus stables : Verlet

Ces limites motivent l’usage d’intégrateurs alternatifs, notamment l’**intégration de Verlet**, qui :
- améliore la **stabilité numérique** (*numerical stability*),
- limite la dérive énergétique,
- est particulièrement adaptée aux **systèmes à contraintes**, aux **ressorts**, et aux **chaînes de particules**.

C’est pour cette raison que l’intégration de Verlet est largement utilisée dans :
- les moteurs physiques simplifiés,
- les simulations de tissus, cordes, cheveux,
- les systèmes de particules interactifs.

La suite du cours consistera à comparer concrètement ces intégrateurs et à comprendre **dans quels contextes choisir l’un plutôt que l’autre**.

---  
