# Impulsion tangentielle et rotation dans les collisions

---

## Contexte

Après avoir correctement appliqué l’impulsion le long de la **normale** lors des collisions entre corps rigides, on observe que :

- Pour des collisions **boîte-boîte**, la rotation des objets est correctement mise à jour grâce à l’impulsion appliquée au point de contact.
- Pour des collisions **cercle-cercle**, l’application de la même formule **ne produit pas de changement de rotation**.  
  Ceci est dû au fait que l’impulsion appliquée le long de la normale passant par le centre du cercle ne génère pas de moment angulaire.

---

## Solution proposée : impulsion tangentielle

Pour résoudre ce problème, on introduit une **impulsion tangentielle** $J_T$ :

- Direction : **perpendiculaire à la normale** de collision
- Application : au **point de contact**, elle génère un **moment angulaire** sur les cercles
- Effet : simule un comportement similaire à la **friction**, tout en permettant la rotation

### Définition vectorielle

Si $\mathbf{n}$ est le vecteur normal de collision, on définit le vecteur tangent $\mathbf{t}$ :

$$
\mathbf{t} \cdot \mathbf{n} = 0
$$

- $\mathbf{t}$ est perpendiculaire à $\mathbf{n}$, orienté contre le mouvement relatif
- L’impulsion tangentielle s’applique à la fois sur les corps A et B

### Calcul de l’impulsion tangentielle

Formule similaire à l’impulsion normale, mais projetée sur $\mathbf{t}$ :

$$
J_T = -\frac{\mathbf{V}_{\text{rel}} \cdot \mathbf{t}}{\frac{1}{m_A} + \frac{1}{m_B} + \frac{(\mathbf{R}_A \times \mathbf{t})^2}{I_A} + \frac{(\mathbf{R}_B \times \mathbf{t})^2}{I_B}}
$$

- $\mathbf{V}_{\text{rel}}$ : vitesse relative au point de contact
- $\mathbf{R}_A, \mathbf{R}_B$ : vecteurs du centre de masse au point de contact
- $I_A, I_B$ : moments d’inertie
- $m_A, m_B$ : masses

### Application aux corps

- Mise à jour de la **vitesse linéaire** :

$$
\Delta \mathbf{v} = \frac{J_T \mathbf{t}}{m}
$$

- Mise à jour de la **vitesse angulaire** :

$$
\Delta \omega = \frac{\mathbf{R} \times (J_T \mathbf{t})}{I}
$$

---

## Points clés

1. L’impulsion normale $J$ gère la réaction linéaire et le rebond selon la restitution.
2. L’impulsion tangentielle $J_T$ permet :
   - La rotation des cercles lors des collisions cercle-cercle
   - La simulation d’une **friction** entre corps
3. Pour une simulation complète :
   - On peut définir un **coefficient de friction** pour chaque corps
   - Le coefficient de friction global pour la collision peut être une combinaison des deux (par exemple : minimum ou moyenne)
4. Le calcul de $J_T$ suit la même logique que $J$ mais en projetant sur le vecteur tangent $\mathbf{t}$.

---

## Implémentation pratique

- Déterminer le vecteur normal $\mathbf{n}$ et tangent $\mathbf{t}$ pour chaque collision
- Calculer $J_T$ avec la formule ci-dessus
- Appliquer $J_T$ aux corps A et B au point de contact, en mettant à jour linéaire et angulaire

- **Effet attendu** : les cercles devraient **tourner** lors des collisions, reproduisant un comportement proche de la friction réelle.

#tags: physics-engine/collision, physics-engine/tangential-impulse, physics-engine/2d, physics-engine/angular-momentum
