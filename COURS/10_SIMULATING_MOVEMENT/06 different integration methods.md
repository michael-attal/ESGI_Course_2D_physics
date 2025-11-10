# Techniques d’intégration  

Dans le cadre de la simulation numérique, l’intégration nous permet de passer des taux de changement (accélérations, vitesses) aux valeurs effectives (vitesses, positions) au fil du temps.  
Nous allons ici présenter les principales techniques utilisées dans les moteurs physiques en temps réel.  

---

## Différentes techniques d’intégration  

La méthode d’Euler est la plus simple : elle met à jour la position et la vitesse à chaque pas de temps à partir du taux de changement actuel.  
Cependant, plusieurs autres techniques existent, chacune offrant un compromis entre **précision**, **stabilité** et **performance**.  

En observant un graphe de position continue (fonction idéale) et de prédictions faites par différentes méthodes, on constate que certaines techniques se rapprochent davantage de la solution exacte que d’autres.  
Les écarts accumulés à chaque pas de temps montrent que la précision varie selon la technique choisie.  

---

## Focus sur l’intégration d’Euler  

Pour rester pragmatique, nous allons utiliser **l’intégration d’Euler** dans notre moteur physique.  
C’est la plus simple et la plus répandue dans les moteurs de jeux 2D et 3D.  
Elle est totalement exacte seulement si la dérivée est constante sur le pas de temps, ce qui n’est pas le cas ici.  

---

### Avantages et limites  

- **Avantage** : simple à implémenter et peu coûteuse en calcul.  
- **Limite** : précision limitée et accumulation d’erreurs pour des pas de temps trop grands ou des dérivées très variables.  

---

## Intégration implicite d’Euler  

L’**Euler implicite** consiste à utiliser la valeur prédite pour calculer le pas suivant, ce qui améliore légèrement la stabilité.  
Elle reste suffisante pour la majorité des applications de jeu en temps réel.  

---

## Intégration de Verlet  

La méthode de **Verlet** est plus précise que l’Euler implicite et demande moins de mémoire pour de nombreux objets simulés.  
Elle est souvent utilisée pour simuler des systèmes de particules liés par des contraintes (ex. toiles d’araignées, tissus, maillages déformables).  

---

## Méthode de Runge-Kutta (RK4)  

La famille **Runge-Kutta**, et notamment **RK4**, améliore la précision en évaluant plusieurs dérivées à chaque pas de temps pour réduire l’erreur cumulée.  
Cette méthode est plus coûteuse en calcul mais plus fiable pour des simulations nécessitant une grande précision.  

---

## Synthèse et prochaines étapes  

Pour notre moteur physique, nous utiliserons **Euler implicite** : simple, rapide et suffisant pour nos besoins en 2D.  
Dans le futur, après avoir implémenté les collisions, la rotation et d’autres forces, nous pourrons comparer avec Verlet ou RK4 pour observer l’impact sur précision et stabilité.  

Nous allons maintenant réorganiser notre code :  
séparer les responsabilités, placer les calculs dans les bonnes classes et profiter pleinement de la programmation orientée objet avant de continuer avec les forces et collisions.  
