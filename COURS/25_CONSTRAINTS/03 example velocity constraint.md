
# Résolution d'une contrainte de vitesse : exemple pratique

---

## Configuration du projet P5JS

- Objet principal : une balle avec une position $(x, y)$ et une vitesse $v_y$ initialisée à $0$.
- Sol : objet avec position $y_\text{floor} = 500$.
- Gravité : accélération constante $g$.

### Initialisation

- Canvas en plein écran.
- Position initiale de la balle : $x = \text{width}/2$, $y = 10$.
- Boucle de dessin (*draw*) appelée à chaque frame.

---

## Intégration de la vitesse

- Delta time fourni par P5JS : $dt = \Delta t$.
- Mise à jour de la vitesse selon l'accélération :
  $$
  v_y \mathrel{+}= g \cdot dt
  $$
- Intégration pour obtenir la nouvelle position :
  $$
  y_\text{ball} \mathrel{+}= v_y \cdot dt
  $$

---

## Détection de violation de contrainte

- Vérification si la balle dépasse le sol :
  $$
  \text{si } y_\text{ball} \ge y_\text{floor} \text{ alors résoudre la contrainte de vitesse}
  $$

### Erreur de position

- Définition de l'erreur de position :
  $$
  C = y_\text{ball} - y_\text{floor}
  $$
  où $C$ est la distance entre la balle et le sol.

---

## Résolution de la contrainte de vitesse

- Formule de correction avec **facteur de biais** (*bias factor* $\beta$) :
  $$
  v_y = - \frac{\beta}{dt} \, C
  $$
- Paramètre $\beta \in [0,1]$ :
  - $\beta = 1$ : correction immédiate.
  - $\beta \ll 1$ : correction progressive, effet plus doux.

- Boucle de rétroaction :
  1. Calcul de $C$.
  2. Mise à jour de $v_y$ selon $v_y = - (\beta / dt) \, C$.
  3. Intégration pour obtenir $y_\text{ball}$.
  4. Répéter à chaque étape de simulation jusqu'à ce que la contrainte soit respectée.

---

## Effet du facteur de biais

- $\beta = 0.2$ : résolution douce, la balle s'ajuste progressivement.
- $\beta = 1.0$ : résolution immédiate, la balle se positionne instantanément sur le sol.
- Cette approche permet de contrôler la **stabilité et la douceur** de la simulation.

---

## Conclusion

- La contrainte de vitesse permet de résoudre les contraintes de position de manière progressive.
- Le **bias factor** (ou *Baumgart stabilization*) contrôle la rapidité de l'ajustement.
- La correction est appliquée sur plusieurs étapes de simulation, créant un effet de **feedback itératif**.
- Cette méthode peut être généralisée à d'autres contraintes, par exemple pour maintenir une **distance constante** entre deux objets.

