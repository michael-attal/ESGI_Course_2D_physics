# Résolution de collisions : méthodes de projection et d’impulsion

Une fois qu’une collision entre deux cercles est détectée, l’étape suivante consiste à **résoudre la collision**.  
Il s’agit de décider comment réagir : soit en **corrigeant les positions** pour supprimer le chevauchement, soit en **appliquant des impulsions** pour simuler un rebond réaliste.

---

## Informations clés issues de la détection

Pour deux corps en collision, la détection fournit :  

- **Vecteur normal de collision** – direction le long de laquelle appliquer la réponse.  
- **Points de contact** – positions sur chaque corps où se produit la collision.  
- **Profondeur de pénétration** – amplitude du chevauchement.  

Ces informations guident la méthode de résolution.

---

## Méthode de projection

La **méthode de projection** résout les collisions en ajustant les positions des objets :  

1. Séparer les objets qui se chevauchent le long du vecteur normal.  
2. Utiliser la **profondeur de pénétration** pour déterminer le déplacement nécessaire.  
3. Prendre en compte la **masse de chaque corps** : plus un objet est massif, moins il doit être déplacé.  

Les déplacements pour chaque corps sont calculés par :  

$$
\text{déplacement}_A = \text{depth} \times \frac{m_B}{m_A + m_B}, \quad
\text{déplacement}_B = \text{depth} \times \frac{m_A}{m_A + m_B}
$$  

Avec \(m_A\) et \(m_B\) les masses des objets. Ceci assure une séparation réaliste en fonction de la masse.

---

### Notes d’implémentation

- Ajuster les positions directement avec le vecteur normal :  

$$
\vec{A}_{\text{new}} = \vec{A}_{\text{old}} - \vec{n} \cdot \text{déplacement}_A, \quad
\vec{B}_{\text{new}} = \vec{B}_{\text{old}} + \vec{n} \cdot \text{déplacement}_B
$$  

- Dans la plupart des moteurs physiques, il est plus efficace d’utiliser **l’inverse de la masse** \( \frac{1}{m} \) :  

$$
\text{déplacement}_A = \text{depth} \cdot \frac{\text{inv}_A}{\text{inv}_A + \text{inv}_B}, \quad
\text{déplacement}_B = \text{depth} \cdot \frac{\text{inv}_B}{\text{inv}_A + \text{inv}_B}
$$  

Cela permet de stocker uniquement l’inverse de la masse et simplifie les calculs.

---

## Méthode d’impulsion

La **méthode d’impulsion** modifie la **vitesse** des objets en collision plutôt que leur position :  

- Applique une **force instantanée** le long du vecteur normal.  
- Produit des collisions **élastiques réalistes** (effet de rebond).  
- L’amplitude de l’impulsion dépend de la profondeur de pénétration et des vitesses relatives.  

Alors que la méthode de projection est simple et intuitive, la méthode d’impulsion est largement utilisée dans les jeux pour des simulations dynamiques.

---

## Méthode de pénalité

Une approche moins courante est la **méthode de pénalité**, qui modifie l’**accélération** des objets pour résoudre la collision :  

- Considère le chevauchement comme une contrainte et applique des forces correctives.  
- Plus coûteuse en calcul et moins utilisée en temps réel.

---

## Synthèse pratique

1. **Projection** – ajustement des positions, simple, dépend de la masse.  
2. **Impulsion** – ajustement des vitesses, rebonds réalistes, très utilisée en jeux.  
3. **Pénalité** – ajustement des accélérations, rarement utilisée en temps réel.  

Pour deux cercles qui se chevauchent : commencer par la méthode de projection pour les séparer, puis éventuellement appliquer des impulsions pour un rebond réaliste.
