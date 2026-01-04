## Mise en place du support des contacts multiples (multiple contact points)

Nous revenons d’abord sur l’état actuel du projet afin de clarifier le contexte technique avant la modification de l’architecture des collisions.

### État initial du projet et objectif du test

Dans la scène de test, le monde contient :
- plusieurs objets statiques (sol, mur gauche, mur droit),
- deux corps dynamiques (Body A et Body B),
- des rotations forcées à `(0, 0)` pour les deux corps afin de provoquer un cas de **faces parallèles**.

L’un des corps (par exemple l’objet d’indice 4) est déplacé directement à la souris. Le déplacement est purement positionnel : aucune force, aucune impulsion, aucune résolution de collision. L’objectif est uniquement **d’observer visuellement les points de contact retournés par la détection de collision**.

Pour permettre ce déplacement manuel, une modification est nécessaire dans `body.cpp` :
- la condition bloquant la mise à jour des objets statiques est temporairement contournée,
- les sommets (vertices) sont recalculés même pour un objet statique déplacé à la souris.

Cette modification n’est **pas conceptuelle**, elle est uniquement destinée au débogage et à la visualisation.

### Désactivation volontaire de la résolution des collisions

Dans `world.cpp`, au moment où une collision est détectée :
- un cercle est dessiné au point de contact,
- **toute la résolution des contraintes est commentée**.

Cette étape est cruciale : tant que l’on n’a pas une détection correcte des contacts, il est inutile (et trompeur) d’appliquer des impulsions. On observe donc uniquement la sortie brute de la collision detection.

À ce stade, le moteur ne retourne **qu’un seul point de contact**, ce qui permet de constater clairement le problème :  
dans le cas de faces parallèles, le point de contact est incorrect (instable, excentré).

### Problème identifié : un seul contact pour une collision qui en nécessite plusieurs

Dans une collision polygone–polygone (par exemple boîte sur boîte ou boîte sur sol), il peut exister :
- un seul point de contact (coin contre face),
- **deux points de contact simultanés** (face contre face).

Le moteur actuel ne retourne qu’un unique point correspondant à la pénétration maximale (logique classique du SAT naïf).  
Cette simplification est acceptable pour des cercles, mais **incorrecte pour des polygones**, car elle engendre :
- des impulsions appliquées alternativement à gauche et à droite,
- une instabilité visible (jitter, basculement progressif),
- des empilements de boîtes non stables.

La solution conceptuelle est donc claire :  
**la détection de collision doit pouvoir retourner plusieurs points de contact pour une même collision**.

### Redéfinition du rôle de la structure `Contact`

La structure `Contact` est désormais strictement **un conteneur de données**, et non plus un objet responsable de la résolution.

Dans `contact.h`, la structure conserve uniquement :
- `Body* bodyA`
- `Body* bodyB`
- `Vec2 start`
- `Vec2 end`
- `Vec2 normal` (toujours orientée de A vers B)
- `float depth`

Les éléments suivants sont supprimés :
- le constructeur spécifique,
- toute fonction de résolution de collision,
- le fichier `contact.cpp` devient inutile et peut être supprimé.

Un **contact = un point de collision**.  
Une collision peut produire **un ou plusieurs contacts**.

### Passage d’un contact unique à un vecteur de contacts

L’ensemble du pipeline de détection est modifié pour fonctionner avec :

```cpp
std::vector<Contact>& contacts
```

au lieu d’un simple `Contact&`.

Les changements concernent :

- `collision_detection.h`
    
- `collision_detection.cpp`
    
- toutes les fonctions de type :
    
    - circle–circle,
        
    - polygon–polygon,
        
    - polygon–circle.
        

Chaque fonction :

- reçoit un vecteur de contacts en paramètre,
    
- crée localement un objet `Contact`,
    
- remplit ses champs (corps, points, normale, profondeur),
    
- **ajoute ce contact au vecteur via `contacts.push_back(contact)`**.
    

À ce stade :

- les collisions cercle–cercle continuent de produire un seul contact,
    
- les collisions polygone–polygone produisent encore un seul contact,
    
- mais l’architecture est prête à en gérer plusieurs.
    

### Adaptation de `world.cpp` au nouveau modèle

Dans `world.cpp`, le moteur :

- crée un vecteur `std::vector<Contact> contacts`,
    
- appelle la détection de collision qui remplit ce vecteur,
    
- parcourt ensuite **tous les contacts retournés**.
    

Pour chaque contact :

- un marqueur visuel est dessiné,
    
- le contact peut être ajouté à la liste des contraintes de pénétration (quand la résolution sera réactivée).
    

Ainsi, le moteur est désormais capable de :

- visualiser plusieurs points de contact,
    
- appliquer ultérieurement des impulsions **réparties équitablement** sur tous les points.
    

### Portée de cette étape

Cette modification peut sembler lourde, mais elle est essentiellement **structurelle** :

- aucun nouvel algorithme complexe n’est encore introduit,
    
- aucune logique de SAT avancée n’est implémentée ici,
    
- il s’agit uniquement de préparer le terrain.
    

Cette étape constitue la **condition nécessaire** pour la suite :

- adaptation du SAT pour identifier des contacts multiples,
    
- extraction des points extrêmes sur les faces de référence,
    
- inspiration directe des approches utilisées dans Box2D.
    

### Enjeu pédagogique et physique

Le but final est la stabilité :

- une pile de boîtes doit rester immobile,
    
- les impulsions doivent être verticales et symétriques,
    
- la correction de pénétration doit être répartie sur tous les points pertinents.
    

Sans contacts multiples, toute tentative de stabilité est structurellement impossible.

La prochaine étape consistera donc à **modifier l’algorithme SAT** afin qu’il retourne non pas un point « optimal », mais **un ensemble cohérent de points de contact**, condition indispensable à un moteur physique robuste.
