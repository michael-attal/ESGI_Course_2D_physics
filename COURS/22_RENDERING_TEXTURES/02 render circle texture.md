# Ajout de textures et gestion des entrées souris

---

## Gestion des entrées pour créer différentes formes

- Modification de la fonction d’entrée pour gérer les deux boutons de la souris :
  - **Bouton gauche** : création d’un cercle avec texture `basketball.png`.
  - **Bouton droit** : création d’une boîte avec texture `crate.png`.
- Paramètres définis pour les corps :
  - Cercle : rayon 30, masse 1.0, restitution 0.5.
  - Boîte : restitution 0.2.

---

## Rendu des textures

- Dans la fonction `render` :
  - **Si mode debug désactivé** et **texture disponible** :
    - Appel à `Graphics::drawTexture` avec :
      ```cpp
      x, y, width = radius*2, height = radius*2, rotation, SDL_Texture*
      ```
      pour les cercles.
    - Pour les boîtes : largeur et hauteur depuis la forme du corps.
  - **Sinon** : rendu classique wireframe :
    - Cercle : contour du cercle.
    - Boîte : contour du polygone.
    - Polygone : remplissage en mode solide si texture non disponible.

---

## Gestion du mode debug

- Permet de basculer entre :
  - Affichage des textures.
  - Affichage des formes en wireframe avec informations de contact.

---

## Extension possible

- Charger différentes textures pour les cercles :
  - Basketball : masse légère, restitution élevée → rebonds visibles.
  - Bowling ball : masse lourde, restitution faible → rebonds plus faibles.
- Permet de visualiser l’effet de la masse et de l’élasticité sur la simulation.

---

## Gestion de la mémoire

- Les textures SDL sont des pointeurs dynamiques.
- Pour éviter les **fuites mémoire** :
  - Dans le destructeur de `Body` :
    ```cpp
    SDL_DestroyTexture(texture);
    ```
- Cette pratique garantit la libération explicite des ressources allouées.

---

## Conclusion

- Les textures sont maintenant intégrées pour cercles et boîtes.
- Le rendu est plus réaliste visuellement tout en conservant la physique intacte.
- Les bonnes pratiques C++ sont respectées pour la libération de la mémoire.
