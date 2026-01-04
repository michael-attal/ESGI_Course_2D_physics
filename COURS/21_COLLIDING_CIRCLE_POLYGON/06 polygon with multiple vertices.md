# Extension du moteur physique aux polygones complexes

---

## Contexte

Le moteur physique fonctionne déjà pour les cercles et les boîtes (polygones à quatre vertices). L’objectif maintenant est d’étendre cette fonctionnalité aux **polygones convexes plus complexes**, avec plus de quatre vertices, tout en conservant la détection et la résolution des collisions.

---

## Ajout d’un mode debug

- Un booléen `debug` est ajouté pour activer ou désactiver l’affichage des informations de contact (normales, points de départ et d’arrivée).
- Activation via la touche `D` : bascule entre mode debug activé et désactivé.
- L’affichage du mode debug permet de vérifier visuellement les informations de collision sans surcharger l’écran.

---

## Gestion des polygones

### Classe PolygonShape

1. **Constructeur** :
   - Initialise les **vertices locaux** et les **vertices mondiaux** à partir du paramètre passé (`vector` de `vectors`).
   - Permet d’avoir une représentation correcte du polygone dès sa création.
2. **Mise à jour des vertices** :
   - La fonction `updateVertices` transforme les vertices locaux en vertices mondiaux via translation et rotation.
3. **Moment d’inertie** :
   - Pour l’instant, un nombre fixe est utilisé (`5000`) comme valeur temporaire.
   - Calcul correct du moment d’inertie pour un polygone sera nécessaire pour une physique réaliste.

### Création dynamique

- Les polygones sont créés via un clic souris, similaire aux cercles.
- Les propriétés physiques :
  - Masse : 2.0
  - Restitution : 0.1
  - Friction : 0.7
- L’utilisateur doit fournir un **array de vertices** représentant le polygone convex.

---

## Recommandations pour les vertices

1. **Origine** : le centre de masse du polygone doit correspondre à l’origine `(0,0)` dans l’espace local.
2. **Ordre** : les vertices doivent être définis dans un **sens antihoraire** pour garantir des calculs corrects de normales et de produits vectoriels.

---

## Fonctionnement attendu

- Les polygones complexes doivent :
  - Coller aux mêmes règles que les boîtes pour la collision et la résolution.
  - Réagir correctement à la gravité et aux forces appliquées.
  - Afficher les informations de contact lorsque le mode debug est activé.
- Le moteur physique reste robuste pour les collisions entre tous types de corps rigides convexes.

---

## Exercices proposés

- Créer un polygone convexe personnalisé en définissant les vertices.
- Tester la chute et les collisions avec d’autres corps rigides.
- Vérifier la rotation et le comportement en fonction du moment d’inertie temporaire.
- Observer les normales et les points de contact en mode debug pour s’assurer de la cohérence des calculs.
