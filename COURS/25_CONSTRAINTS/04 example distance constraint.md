# Résolution d'une contrainte de distance via une contrainte de vitesse

---

## Contexte

- Contraintes de **distance** : maintenir un écart constant entre deux objets.
- Exemple : une balle devant suivre la position de la souris $(x_\text{mouse}, y_\text{mouse})$.
- Distance souhaitée : $0$ (égalité, *equality constraint*).

---

## Paramètres du projet P5JS

- Position initiale de la balle : $x = 0$, $y = 0$.
- Facteur de biais (*bias factor*, $\beta$) : contrôle la rapidité de la correction.
- Amortissement (*damping*) : $0.1$, pour simuler la friction et réduire l'énergie de l'objet.
- Delta time : $dt = \Delta t$ ou $0.01$ si nul, pour assurer la stabilité de l'intégration.

---

## Définition de l'erreur de position

- Position de la balle : $\vec{p}_\text{ball}$
- Position de la souris : $\vec{p}_\text{mouse}$
- Erreur de position (*positional error*, $C$) :
  $$
  C = \vec{p}_\text{mouse} - \vec{p}_\text{ball}
  $$

---

## Résolution de la contrainte de vitesse

- Mise à jour de la vitesse de la balle :
  $$
  \vec{v} \mathrel{+}= \frac{-\beta}{dt} \, C
  $$
- Application de l'amortissement :
  $$
  \vec{v} \mathrel{*}= \text{damping}
  $$

- Intégration pour obtenir la nouvelle position :
  $$
  \vec{p}_\text{ball} \mathrel{+}= \vec{v} \cdot dt
  $$

---

## Effet du facteur de biais et de l'amortissement

- $\beta = 0.8$ : résolution rapide, mouvement presque instantané.
- $\beta = 0.2$ : résolution plus progressive, mouvement plus doux.
- L'amortissement réduit la vitesse à chaque étape, simulant la friction.
- La boucle itérative permet de **réduire progressivement l'erreur de position** jusqu'à ce que $C \to 0$.

---

## Conclusion

- La contrainte de distance est résolue via une **contrainte de vitesse** appliquée sur l'objet.
- Le facteur de biais $\beta$ contrôle la rapidité et la douceur de la correction.
- L'amortissement assure la stabilité et empêche l'oscillation infinie autour de la position cible.
- La correction est appliquée sur plusieurs étapes de simulation, formant un **feedback itératif**.

