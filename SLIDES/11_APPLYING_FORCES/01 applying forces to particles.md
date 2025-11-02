# Application des forces aux particules  

Nous allons maintenant voir comment appliquer des **forces** à nos particules dans un moteur physique.  
Jusqu’à présent, nous traitions uniquement l’**accélération constante**, ce qui relève de la **cinématique**.  

---

## De l’accélération constante à l’accélération variable  

Pour rendre nos simulations plus réalistes, l’accélération ne peut plus être considérée comme constante.  
Elle doit dépendre des **forces** appliquées à chaque particule.  

---

## Lois de Newton et rôle des forces  

- **Première loi (inertie)** : une particule reste au repos ou en mouvement uniforme sauf si une force agit sur elle.  
- Les particules accélèrent uniquement sous l’action de forces.  
- Plusieurs forces peuvent agir simultanément : gravité, vent, frottement, traînée, forces entre particules, etc.  

---

## Sources des forces  

Les forces peuvent provenir de différentes sources :

- **Forces externes** : gravité, vent, champs magnétiques.  
- **Forces internes** : attraction ou répulsion entre particules.  
- **Forces globales** : combinaison de plusieurs effets.  

---

## Concept de force résultante  

À chaque étape de simulation, nous nous intéressons à la **somme des forces** (*net force*), résultante de la somme de toutes les forces appliquées :  

$$
\vec{F}_{net} = \sum_i \vec{F}_i
$$  

Cette force est celle que nous utilisons pour calculer l’accélération.  

---

## Application des forces dans le moteur  

Chaque particule dispose d’une méthode `addForce(Vector2 force)` :

- Les forces sont des vecteurs, avec **direction** et **magnitude**.  
- On les cumule dans un attribut `sumForces` de la particule.  

---

## De la force à l’accélération  

D’après la **seconde loi de Newton** :  

$$
\vec{a} = \frac{\vec{F}_{net}}{m}
$$  

- L’accélération dépend donc de la force nette et de la **masse** de la particule.  
- Plus la masse est grande, plus l’accélération est faible pour une force donnée.  

---

## Rôle de la masse  

La masse joue un rôle crucial :

- **Masse grande →** difficile à accélérer.  
- **Masse petite →** facile à accélérer.  

Dans notre moteur, la masse devient un facteur central pour moduler la réaction des particules aux forces.  

---

## Étape de simulation  

Pour chaque **frame** :

1. Ajouter les forces (`addForce`) à la particule.  
2. Calculer l’accélération : $\vec{a} = \vec{F}_{net} / m$.  
3. Intégrer l’accélération pour obtenir la vitesse.  
4. Intégrer la vitesse pour obtenir la position.  
5. Réinitialiser `sumForces` pour la prochaine frame.  

---

## Accélération dynamique et effet de la masse  

- La dynamique dépend de l’accumulation des forces et de la masse de la particule.  
- Deux particules avec masses différentes réagiront différemment à la même force.  
- Exemple : une particule légère accélère rapidement sous l’effet du vent, une lourde beaucoup plus lentement.  

---

## Prochaines étapes  

Une fois l’application des forces testée avec le vent, nous pourrons introduire d’autres forces, comme la **force de gravité**.  
L’objectif est de rendre la simulation plus réaliste en combinant différentes forces.  
