# Introduction à la physique des moteurs de jeu – Projet pratique

Dans ce projet, nous avons expérimenté avec un moteur physique simple, en ajoutant divers objets rigides (rigid bodies) pour observer leur comportement dans une simulation. L'objectif n'était pas d'obtenir une solution parfaite, mais de comprendre le fonctionnement et les limites d'un moteur physique. #physics/engines, #esgi/course

## Configuration de la scène

La scène est composée de différents objets rigides : cercles, rectangles et polygones, disposés de manière à tester la stabilité et l'interaction entre eux. Un fond a été ajouté en utilisant une SDL surface pour visualiser correctement les objets. Parmi les objets, certains utilisent des textures issues du jeu *Angry Birds* pour plus de réalisme. #scene/setup, #rigid-bodies, #textures

Parmi les objets ajoutés :

- **Bird** : un cercle avec texture spécifique (`bird_rad.png`)  
- **Sol et murs** : des rectangles pour limiter la scène  
- **Stack de boxes** : pour tester l'empilement et les collisions  
- **Structure en bois** : un ensemble de rectangles pour tester la stabilité  
- **Polygone** : un triangle pour observer le comportement des formes à sommets multiples  
- **Pyramide de boxes** : empilement en forme pyramidale pour tester la stabilité des objets multiples  
- **Chaîne d’objets** : reliée par des joints, simulant un pont ou une connexion flexible  

Cette diversité permet d'observer le comportement des objets dans des configurations variées, et de tester les contraintes (joints) et interactions physiques. #objects/setup, #constraints/joints

## Ajustements pour la stabilité

Lors des tests, certaines structures présentaient un léger jitter ou instabilité. Pour améliorer la stabilité :

- Augmentation du nombre d'itérations dans le solveur de contraintes (de 5 à 8-9)  
- Observation des effets sur la pyramide de boxes et sur la chaîne d’objets  

Ces ajustements ont permis de réduire les déformations et de maintenir la plupart des structures en place, même si un léger mouvement subsiste. #stability/adjustments, #constraints/iterations

## Techniques avancées à explorer

Bien que l'implémentation soit terminée pour ce cours, plusieurs techniques avancées peuvent améliorer la simulation :

1. **Contact caching** : permet de mettre en sommeil (sleep) les objets rigides qui ne bougent plus, réduisant les calculs inutiles et les petits jitter.  
2. **Broad phase / Narrow phase** : division de la détection de collision en deux étapes pour améliorer les performances et la précision.  
3. **Tunneling / Continuous collision detection** : évite que des objets rapides traversent d'autres objets sans détecter de collision.  

Ces sujets feront l'objet de courtes conférences bonus pour comprendre leur utilité et observer des exemples de code sans les implémenter directement. #advanced-techniques, #collision-detection, #optimization

## Conclusion

Pour ce projet d'introduction à la physique des moteurs de jeu, nous avons couvert :

- L'ajout et la configuration d'objets rigides  
- Les contraintes et la résolution de collisions itérative  
- Les effets de la gravité et de la stabilisation des structures  
- Une réflexion sur les techniques avancées pour améliorer la simulation  

L'objectif principal était d'explorer le comportement des objets dans une simulation physique, d'observer les limitations et de préparer le terrain pour des améliorations futures. Bien que la simulation ne soit pas parfaite, elle illustre efficacement les principes de base des moteurs physiques. #conclusion, #physics/engines, #esgi/course
