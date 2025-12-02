# Implémentation de la résolution de collisions avec la méthode de projection

La **méthode de projection** ajuste les positions des objets pour résoudre les collisions en supprimant les chevauchements.  
Cette méthode utilise les informations stockées dans la **structure de contact**, incluant les pointeurs vers les corps rigides en collision (A et B), le vecteur normal de collision, la profondeur de pénétration et les points de contact.

---

## Structure de contact

- **Pointeurs vers les objets** : `A` et `B`  
- **Vecteur normal de collision** : direction pour résoudre la pénétration  
- **Points de contact** : points de début et de fin de la collision  
- **Profondeur de pénétration** : amplitude du chevauchement  

Une méthode prototype `resolvePenetration` est ajoutée pour implémenter directement la méthode de projection dans `contact.cpp`.

---

## Calcul du déplacement

En utilisant l’**inverse de la masse** des objets, le déplacement de chaque corps est calculé par :  

$$
D_A = \text{depth} \cdot \frac{\text{inv}_A}{\text{inv}_A + \text{inv}_B}, \quad
D_B = \text{depth} \cdot \frac{\text{inv}_B}{\text{inv}_A + \text{inv}_B}
$$  

- `D_A` et `D_B` correspondent aux distances parcourues par chaque objet le long du vecteur normal de collision.  
- Les objets plus lourds sont déplacés moins que les plus légers, ce qui reflète un comportement physique réaliste.

---

## Mise à jour des positions

Les positions sont mises à jour directement le long du vecteur normal :  

$$
\vec{A}_{\text{new}} = \vec{A}_{\text{old}} - \vec{n} \cdot D_A, \quad
\vec{B}_{\text{new}} = \vec{B}_{\text{old}} + \vec{n} \cdot D_B
$$  

- `A` se déplace en sens opposé à `B` le long du normal.  
- La différence de masse détermine l’amplitude du déplacement de chaque objet.

---

## Intégration dans la simulation

- Parcourir tous les corps rigides et vérifier les collisions.  
- Remplir un **objet contact** pour chaque collision détectée.  
- Appeler `contact.resolvePenetration()` pour résoudre immédiatement les chevauchements.  
- Visualiser les informations de débogage (normales, points de contact) pour vérifier la précision.

---

## Exemple pratique

- Une **grande balle** (`mass = 10`) placée au centre de l’écran.  
- Des **petites balles** (`mass = 1`) apparaissent lors des clics de souris.  
- Lors de la collision, la **méthode de projection** sépare davantage les petites balles que la grande, reflétant la différence de masse.  
- Des masses égales entraînent des déplacements égaux en directions opposées.  
- Aucun chevauchement ne subsiste, et les collisions sont visuellement résolues.

---

## Synthèse

- La méthode de projection **projette les objets le long du vecteur normal** pour résoudre la pénétration.  
- Le déplacement est **dépendant de la masse** pour un comportement réaliste.  
- S’intègre directement dans la boucle de simulation via la structure de contact.  
- Le débogage visuel confirme la résolution correcte sans chevauchement.
