# Transition from Particles to Rigid Bodies

Il est maintenant temps d’abandonner notre modèle fondé uniquement sur les particules pour entrer dans le domaine des **rigid bodies** (corps rigides).  
Jusqu’ici, nous avons travaillé avec des particules, pour lesquelles nous ignorions volontairement la **forme**, la **rotation**, et toute autre caractéristique géométrique.

Lorsque l’on observe un objet à grande distance, par exemple un missile vu depuis très loin, il est acceptable de **le modéliser comme une particule** :  
- aucune forme,  
- aucune rotation,  
- aucune dimension propre.

Mais dès que l’on **zoome**, cette abstraction devient insuffisante :  
- l’objet possède une **forme**,  
- des **dimensions**,  
- des **sommets (vertices)**,  
- un **centre de masse**.  

Le passage vers un modèle de **corps rigide** devient alors indispensable.

---

# Rigid Bodies Concepts

Nous introduisons les concepts fondamentaux des rigid bodies.  
Contrairement aux particules, un **corps rigide** :  
- possède une **géométrie explicite**,  
- possède un **angle de rotation**,  
- est centré autour d’un **centre de masse**,  
- **ne se déforme jamais**.

Notre ancienne classe `Particle` ne contenait que :  
- position,  
- vélocité,  
- accélération,  
- forces appliquées.

Un **rigid body** doit ajouter :  
- un **angle de rotation**,  
- une **forme** (circle, polygon, box).

Nous devons donc être capables de représenter la géométrie d’un corps rigide dans l’espace pour gérer mouvements, collisions et rotations.

---

# Applying Particle Formulas to Rigid Bodies

Bonne nouvelle : toutes les équations utilisées pour les particules restent valides pour les corps rigides.  
Elles s’appliquent simplement **au centre de masse du corps rigide**.

Un rigid body se compose d’un ensemble de points qui se déplacent ensemble sans jamais se déformer.  
Bien que les objets réels se déforment toujours un peu lors d’une collision, cette approximation permet une simulation rapide et cohérente pour les jeux.

Ce modèle garantit :  
- des intégrations simples,  
- des collisions plus faciles à gérer,  
- une géométrie constante.

---

# Shapes of Rigid Bodies

Les rigid bodies sont représentés à l’aide de **formes primitives**, standard dans les moteurs physiques 2D.

Nous utiliserons trois formes :

1. **Circle**  
2. **Polygon**  
3. **Box** (un polygone de quatre vertices)

Un système d’énumération (`ShapeType`) permet de distinguer :  
- BOX  
- POLYGON  
- CIRCLE  

Chaque forme possède ses paramètres :  
- rayon pour les cercles,  
- liste de sommets pour les polygones,  
- orientation éventuelle.

Des formes plus complexes sont possibles mais en pratique composées de ces primitives.  
Ce trio est suffisant pour un moteur d’apprentissage fiable.

---

# Renaming Particle Classes to Body Classes

Avant de poursuivre, nous devons faire évoluer la base de code.

L'ancienne structure :  
- `particle.h`  
- `particle.cpp`

Nous créons :  
- `body.h`  
- `body.cpp`

Nous remplaçons ensuite **toutes les occurrences** de “particle” par “body”.  
Pourquoi ?  
Parce que le centre de masse d’un rigid body se comporte exactement comme notre ancienne particule.

Ce remplacement inclut :  
- noms de fichiers,  
- include guards (`PARTICLE_H` → `BODY_H`),  
- classes (`Particle` → `Body`),  
- pluriels (`particles` → `bodies`).

Une fois cela fait, la compilation devrait réussir immédiatement : la logique n’a pas changé.

Les `Body` se comportent comme les anciennes particules, mais sont maintenant prêts à recevoir une **forme géométrique**.

---

# Updating Codebase

Résumé du processus :

1. **Renommer les fichiers**
   - `particle.h` → `body.h`
   - `particle.cpp` → `body.cpp`

2. **Search & Replace global**
   - `particle` → `body`
   - `Particle` → `Body`
   - `PARTICLE_H` → `BODY_H`

3. **Corriger les pluriels**
   - `particles` → `bodies`

4. **Recompiler**
   Une compilation réussie confirme que le changement est propre.

L’application utilise désormais `Body` avec le même comportement que les particules, mais prête pour les rigid bodies.

---

# Verifying Changes

Après compilation, vérifier que :  
- les include guards sont corrects,  
- les vecteurs s’appellent `bodies`,  
- les méthodes (`AddForce`, etc.) s’appliquent correctement à `Body`,  
- les attributs (position, vélocité, etc.) sont bien migrés.

À ce stade, un `Body` = une ancienne particule + la capacité future d’avoir une forme.

---

# Next Steps: Attaching Shapes

Nous allons maintenant pouvoir :

1. créer la classe `Shape`,  
2. implémenter les formes dérivées (`Circle`, `Polygon`, `Box`),  
3. attacher une forme à chaque `Body`,  
4. intégrer la rotation,  
5. transformer les vertices dans l’espace (local → global),  
6. préparer le système de collisions rigides.

C’est cette étape qui donnera enfin une **géométrie exploitable** aux corps rigides et permettra de construire un moteur physique 2D complet.

