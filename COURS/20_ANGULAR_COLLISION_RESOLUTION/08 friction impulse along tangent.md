# Résolution combinée des impulsions normale et tangentielle

---

## Contexte

Après avoir implémenté l’impulsion le long de la normale pour la collision, il est possible d’ajouter une **impulsion tangentielle** $J_T$ pour simuler à la fois :

- La rotation des corps (moment angulaire)
- Les effets de friction entre les objets

Cette approche fonctionne pour les cercles et les boîtes, et permet une simulation plus réaliste des interactions.

---

## Implémentation

1. **Coefficients physiques**  

   Chaque corps possède désormais :

   - Un coefficient de **restitution** $e$ (rebond)
   - Un coefficient de **friction** $f$

   Pour chaque collision, on utilise le **minimum** des coefficients des deux corps :

   $$
   f_{\text{collision}} = \min(f_A, f_B), \quad e_{\text{collision}} = \min(e_A, e_B)
   $$

---

2. **Vecteurs au point de contact**  

   - $\mathbf{R}_A$, $\mathbf{R}_B$ : vecteurs du centre de masse au point de contact pour les corps A et B
   - $\mathbf{V}_A$, $\mathbf{V}_B$ : vitesses au point de contact
   - $\mathbf{V}_{\text{rel}} = \mathbf{V}_A - \mathbf{V}_B$ : vitesse relative

---

3. **Impulsion normale $J_n$**  

   - Calcul de la vitesse relative le long de la normale :  

     $$
     V_{\text{rel,n}} = \mathbf{V}_{\text{rel}} \cdot \mathbf{n}
     $$

   - Impulsion :  

     $$
     J_n = \text{formule complète précédente, utilisant } \mathbf{n}
     $$

---

4. **Impulsion tangentielle $J_T$**  

   - Définir le vecteur tangent $\mathbf{t}$ perpendiculaire à $\mathbf{n}$  
   - Vitesse relative tangentielle :  

     $$
     V_{\text{rel,t}} = \mathbf{V}_{\text{rel}} \cdot \mathbf{t}
     $$

   - Impulsion tangentielle :  

     $$
     J_T = f_{\text{collision}} \times \text{formule complète, utilisant } \mathbf{t} \text{ au lieu de } \mathbf{n}
     $$

   - Vecteur final :  

     $$
     \mathbf{J}_T = J_T \mathbf{t}
     $$

---

5. **Combinaison et application des impulsions**

   - Impulsion totale :  

     $$
     \mathbf{J} = \mathbf{J}_n + \mathbf{J}_T
     $$

   - Application sur les corps :  

     $$
     \begin{aligned}
     \mathbf{v}_A &+= \frac{\mathbf{J}}{m_A}, & \omega_A &+= \frac{\mathbf{R}_A \times \mathbf{J}}{I_A} \\
     \mathbf{v}_B &-= \frac{\mathbf{J}}{m_B}, & \omega_B &-= \frac{\mathbf{R}_B \times \mathbf{J}}{I_B}
     \end{aligned}
     $$

---

## Résultats attendus

- Rotation visible des **cercles** lors des collisions
- Rotation et friction simulée pour les **boîtes**
- Comportement réaliste du rebond et de l’arrêt des corps en interaction
- L’ajout du coefficient de friction $f$ permet de contrôler l’intensité de la rotation tangentielle

---

## Remarques

- Cette approche combine directement les effets **normaux** et **tangents** pour simplifier l’application des forces
- On pourrait également appliquer séparément $J_n$ et $J_T$, mais la somme vectorielle offre une solution plus simple
- Quelques artefacts visuels (stuttering, jitter) peuvent apparaître pour des collisions très rapprochées

#tags: physics-engine/collision, physics-engine/friction, physics-engine/impulse, physics-engine/2d, physics-engine/angular-momentum
