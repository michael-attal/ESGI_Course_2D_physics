# Introduction aux dérivées

Le **calcul différentiel et intégral** constitue la branche des mathématiques qui étudie principalement les fonctions **continues** et leur **variation**.  
Il s’agit d’analyser le taux de changement d’une fonction définie sur les **nombres réels**, un ensemble mathématique **continu**.

---

# Continuité et nombres réels

La droite des nombres réels est **continue** : quelle que soit l’échelle d’observation, il n’existe aucun “trou” entre deux réels.  
Cette continuité est un fondement de nombreux modèles mathématiques décrivant le mouvement ou la variation dans le monde physique.

---

# Exemple : objet soumis à une accélération constante

Considérons un objet en chute libre soumis à la gravité terrestre, avec une accélération constante de :

$$a = 9.8 \, m/s^2$$

La position $P(t)$ de l’objet évolue de manière **continue**, formant une **courbe** lorsque représentée en fonction du temps.

---

# Simulation logicielle : du continu vers le discret

Dans une simulation numérique, nous ne pouvons pas travailler avec un continuum infini de valeurs.  
Nous devons **échantillonner** le temps : chaque frame représente une estimation de l’état du système à un instant discret.  
Ainsi, position, vitesse et accélération sont calculées **pas à pas**, à intervalles réguliers ($\Delta t$).

---

# Le monde réel : continu ou discret ?

La question n’est pas triviale.  
Historiquement, la physique modélise l’espace et le temps comme **continus**.  
Mais l’étude de la matière à des échelles subatomiques révèle une **structure discrète** (atomes, quarks, etc.).  
Certaines théories physiques suggèrent même que le temps serait **quantifié**, donc fondamentalement discret.

---

# Mathématiques continues et simulation

En simulation, nous utilisons donc des **outils mathématiques continus** (calcul différentiel et intégral) pour prédire l’évolution du système, tout en l’approximent à l’aide de **discrétisation numérique**.

Le calcul différentiel s’intéresse à la **variation instantanée** :  
> Comment évolue une quantité à un moment donné ?

---

# Le taux de variation : vitesse et pente

À un instant précis, comme $t = 4.264 \, s$, la vitesse correspond à la **pente** de la courbe position/temps.  
Cette pente n’est pas constante : elle dépend du mouvement et doit être **estimée** à chaque intervalle de temps dans une simulation.

---

# Approximation par différences finies

Pour un intervalle $[t_i, t_{i+1}]$, une approximation de la vitesse peut être obtenue par :

$$
v \approx \frac{P(t_{i+1}) - P(t_i)}{t_{i+1} - t_i}
$$

Plus $\Delta t$ est **grand**, plus l’erreur d’approximation est importante.  
Réduire $\Delta t$ améliore la précision : c’est exactement le lien avec la **fréquence d’update** dans un moteur de jeu.

---

# Principe fondamental du calcul différentiel

Si l’on **réduit** $\Delta t$ jusqu’à tendre vers zéro :

$$
v(t) = \lim_{\Delta t \to 0} \frac{P(t+\Delta t) - P(t)}{\Delta t}
$$

Nous obtenons alors la **dérivée** : le taux de variation parfait de la position.

---

# Calcul intégral : l’aire sous la courbe

Inversement, l’intégration répond à une autre question :  
> Quelle est la somme cumulée des variations au cours du temps ?

Une estimation numérique de la **surface sous la courbe vitesse/temps** donne la **position**.  
Là encore, plus les intervalles sont petits, plus le résultat est précis.

---

# Vers la solution exacte

En faisant tendre la largeur des intervalles vers zéro, l’approximation devient :

$$
P(t) = P(0) + \int_0^t v(\tau) \, d\tau
$$

Nous obtenons alors la **position exacte** issue de l’intégration.

---

# Synthèse : dériver et intégrer

Le calcul repose sur deux opérations majeures :

| Concept | Interprétation physique | Relation mathématique |
|--------|------------------------|----------------------|
| **Dérivation** | Trouver le taux de variation (ex : vitesse) | $$v = \frac{dP}{dt}$$ |
| **Intégration** | Cumuler la variation (ex : position) | $$P = \int v \, dt$$ |

---

Ces deux mécanismes sont au cœur de **toute** simulation physique :

> Accélération → (intégration) → vitesse → (intégration) → position

Réduire $\Delta t$ dans une simulation revient à **mieux approcher** le comportement continu du phénomène réel.
