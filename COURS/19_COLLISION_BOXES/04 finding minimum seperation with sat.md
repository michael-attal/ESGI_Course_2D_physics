

# Intuition derrière l’implémentation du SAT

Voici l’intuition derrière l’algorithme SAT.  
Nous allons tester tous les axes pour trouver celui qui **sépare les deux objets**. Avant d’entrer dans le code, il est important de noter que différents programmeurs abordent le problème du SAT différemment.  
L’approche présentée ici se concentre sur la **valeur de séparation** entre deux corps rigides : les corps sont-ils en collision ou existe-t-il un espace (gap) entre eux ?

---
# Approche globale

1. **Boucler sur les sommets du polygone A** : calculer la normale (vecteur perpendiculaire) de chaque arête.  
2. **Boucler sur les sommets du polygone B** : projeter chaque sommet de B sur l’axe normal courant via le produit scalaire. Cela donne une valeur de séparation pour ce sommet le long de cet axe.  
3. Répéter ce processus pour toutes les normales de A et tous les sommets de B.  
4. Suivre la **séparation maximale** pendant tout le processus.  

- Si la **séparation finale est positive**, il n’y a pas de chevauchement (pas de collision).  
- Si elle est **négative**, il y a chevauchement (collision).  

Cette méthode fonctionne pour les triangles, boîtes et autres polygones convexes.

---
# Recette étape par étape

1. **Itérer sur les sommets de A** : calculer la normale de chaque arête.  
2. **Projeter les sommets de B** sur la normale via le produit scalaire.  
3. **Suivre la séparation minimale** pour cet axe.  
4. **Mettre à jour la séparation maximale globale** si la séparation minimale courante est supérieure à la précédente.  
5. **Répéter pour toutes les normales** de A, puis inverser les rôles (B → A) pour tester toutes les normales de B.

---
# Détails d’implémentation

- **Variable de séparation** : initialiser à \(-\infty\) pour suivre la plus grande séparation.  
- **Projection minimale** : initialiser à \(+\infty\) pour chaque axe afin de suivre la projection minimale des sommets de B.  
- **Produit scalaire** : pour projeter les sommets sur les normales, calculer \((V_B - V_A) \cdot \text{normale}\). Mettre à jour la valeur minimale sur cet axe.  
- **Mise à jour de la séparation maximale** : si la projection minimale pour l’axe courant est supérieure à la séparation actuelle, mettre à jour la variable de séparation.  
- **Vérification de collision** : séparation finale positive → pas de collision ; négative → chevauchement.

---
# Vérification bidirectionnelle

Il est essentiel de vérifier **A → B et B → A** pour tester toutes les normales des deux polygones.  
La fonction `isCollidingPolygonPolygon` compare les deux tests de séparation et retourne `true` si les deux indiquent un chevauchement, confirmant la collision.

---
# Résumé

Cette implémentation du SAT :  

- Calcule systématiquement la **séparation minimale** le long de toutes les normales des arêtes des deux polygones convexes.  
- Utilise le **produit scalaire** pour projeter les sommets sur les normales.  
- Suit les **valeurs minimales et maximales de séparation** pour déterminer de manière fiable la collision.  
- La sortie est une seule valeur : positive pour pas de collision, négative pour chevauchement.  
- Cette approche est **généralisable à tout polygone convexe**.

