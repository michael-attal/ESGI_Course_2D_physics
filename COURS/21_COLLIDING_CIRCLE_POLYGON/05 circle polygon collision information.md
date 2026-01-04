# Test de la détection et résolution de collisions avec polygones et cercles

---

## Contexte

Une fois les informations de contact correctement calculées, il est possible de tester le moteur physique complet dans l’application principale. L’objectif est de créer dynamiquement des cercles à l’aide de la souris et d’observer leur interaction avec différents objets fixes (sol, murs, boîtes).

---

## Étapes de l’implémentation

1. **Activation des corps physiques** : tous les objets fixes (sol, murs, etc.) sont activés.
2. **Création des cercles dynamiques** :
   - À chaque clic de souris, un nouveau cercle est généré avec :
     - Rayon : 30
     - Masse : 1.0
     - Restitution : 0.3 (modifiable)
     - Friction : 0.4 (modifiable)
   - Les cercles sont ajoutés à la liste des corps physiques.
3. **Application de la gravité** : un vecteur de force est appliqué à tous les corps pour simuler le poids.
4. **Résolution des collisions** :
   - Les informations de contact sont utilisées : profondeur de pénétration, vecteur normal, points de contact.
   - Les collisions sont résolues en appliquant un **impulse** aux corps concernés.

---

## Ajustement des propriétés physiques

- La restitution des objets peut être modifiée pour observer différents comportements de rebond.
- La friction permet de gérer l’interaction entre surfaces.

---

## Vérification du moteur physique

- Les cercles interagissent avec :
  - Les polygones fixes (boîtes)
  - D’autres cercles
- Les collisions et la résolution sont correctes pour chaque configuration.
- La normale de collision et la profondeur de pénétration sont cohérentes dans toutes les situations.

---

## Extension aux polygones plus complexes

- L’algorithme de détection et de résolution fonctionne pour :
  - Les polygones convexes quelconques
  - Les polygones à plus de quatre vertices
- L’utilisation de l’algorithme SAT (Separating Axis Theorem) assure que les collisions sont correctement détectées et résolues pour tous les polygones convexes.
- Les étapes de création manuelle d’un polygone plus complexe consistent à définir correctement les vertices, après quoi le moteur gère les collisions automatiquement.

---

## Conclusion

- La gestion des régions (A, B, C) est essentielle pour le calcul correct des collisions entre cercle et polygone.
- La résolution des collisions est robuste pour des objets dynamiques et statiques.
- L’extension à des polygones plus complexes permet de généraliser le moteur physique à tout polygone convexe.
