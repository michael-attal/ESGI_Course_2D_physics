# Approche itérative et contraintes pour améliorer la stabilité

---

## Problématique

- Moteur actuel : forte instabilité, jittering, objets se déplacent de manière saccadée.
- Objectif : améliorer la stabilité de la résolution de collisions et des forces appliquées.
- Contexte : 
  - Résolution actuelle : 100% du déplacement pour résoudre la pénétration.
  - Limitation : collisions multiples créent des conflits et des oscillations.

---

## Approche itérative (hack simplifié)

- Idée : ne pas résoudre 100% du déplacement immédiatement.
- Implémentation :
  - Résolution partielle (ex. 80% du déplacement requis pour la correction de position).
  - Répéter plusieurs fois l’itération (ex. 10 fois) pour que toutes les collisions convergent progressivement vers une solution plus stable.
- Avantages :
  - Réduit le jittering et les collisions conflictuelles.
- Inconvénients :
  - Coût processeur élevé (FPS impacté si beaucoup d’objets).
  - Méthode empirique, non optimale.

---

## Limitations et motivation pour les contraintes

- Itératif partiel : fonctionne, mais pas idéal pour des simulations complexes ou temps réel avec nombreux objets.
- Besoin d’une approche plus robuste et élégante.
- Les moteurs professionnels (Box2D, Bullet) utilisent :
  - **Contraintes physiques** (constraints) pour définir les relations entre corps rigides.
  - **Résolution itérative** pour respecter ces contraintes tout en améliorant la stabilité.
- Concepts clés :
  - Contrainte de position : distance minimale ou maximale entre objets.
  - Contrainte de contact : respecte les contacts et empêche la pénétration.
  - Résolution via systèmes linéaires et matrices pour solutions optimales.

---

## Prochaines étapes

- Étudier et implémenter la **résolution de contraintes** pour le mouvement rigide.
- Appliquer des itérations pour converger vers une solution stable.
- Introduire des notions de résolution de systèmes linéaires et matrices, fondamentales pour la physique 3D.
- Objectif à long terme : comprendre et appliquer les techniques professionnelles des moteurs physiques pour la 2D et la 3D.


