# Qu'en est-il du Déterminisme ?

---

Nous venons d’implémenter une technique de **time step** qui garantit que nos objets se déplacent en fonction du temps réel, même si le FPS varie.  
Nous utilisons le concept de **delta-time**, qui garde la trace du temps écoulé depuis la dernière étape de simulation.  
Nous multiplions ensuite le mouvement des objets par ce delta, obtenant ainsi un **mouvement indépendant du framerate**.  

---

Cette technique s’appelle **Variable Delta-Time** et c’est probablement la méthode la plus simple pour implémenter un time step contrôlé dans les jeux.  
On parle de "variable" car la valeur de notre delta change à chaque frame.  

---

## Limite du Variable Delta-Time : Non-déterminisme

Un problème de cette approche est que la simulation devient **non-déterministe**.  
Le **déterminisme** signifie que chaque exécution avec les mêmes entrées donne exactement le même résultat.  
Dans les programmes déterministes, il est beaucoup plus facile de reproduire et corriger des bugs.  

---

Les machines numériques sont naturellement déterministes, mais le **monde réel** peut introduire du non-déterminisme : latence réseau, horloge système, planification des threads par le système d’exploitation.  

Avec le **Variable Delta-Time**, le temps exact entre deux frames dépend du processeur, du système d’exploitation, etc.  
Ainsi, la simulation devient non-déterministe : chaque exécution peut produire des comportements différents des objets.  

---

## Quand le Déterminisme est Nécessaire

Dans la plupart des jeux, le non-déterminisme est acceptable.  
Mais certains jeux nécessitent du **déterminisme** pour garantir un comportement identique à chaque exécution.  

---

Une solution simple pour atteindre le déterminisme est d’utiliser un **Constant Delta-Time** :  
- Forcer un FPS fixe, par exemple 60 FPS → chaque frame prend exactement 16 ms.  
- Cette méthode est simple et économique pour garantir le déterminisme.  

Cependant, le **Constant Delta-Time** a un inconvénient :  
- Le jeu peut devenir trop rapide si le FPS est trop élevé.  
- Il peut devenir trop lent si le FPS est trop bas.  

---

## Récapitulatif et Options de Mise à Jour

Certains moteurs de jeu proposent plusieurs types de mise à jour :  
- **Update(deltaTime)** : s’exécute une fois par frame avec le delta actuel fourni.  
- **FixedUpdate()** : s’exécute avec un framerate fixe.  

Il existe des méthodes plus avancées pour implémenter un time step contrôlé ([Gaffer on Games](https://gafferongames.com/post/fix_your_timestep/)), mais pour l’instant nous continuons avec le **Variable Delta-Time** pour ajuster le mouvement de nos objets.  

Cette discussion sur le time step et le contrôle du temps de jeu est fondamentale et sera revisitée tout au long du cours.  
