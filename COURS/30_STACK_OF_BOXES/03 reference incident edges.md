## Contacts multiples et amélioration du SAT : référence, incident et clipping

Lors de la séance précédente, nous avons identifié un cas fondamental en physique des collisions :  
une collision peut produire **plusieurs points de contact simultanés**, notamment lorsque deux faces sont parallèles.  
Dans ce contexte, résoudre les pénétrations **séquentiellement** (un point après l’autre) conduit à une solution instable et déséquilibrée.  

Pour garantir la stabilité, toutes les pénétrations associées à une même collision doivent être **résolues ensemble**, à l’aide d’impulsions cohérentes et alignées.

La question centrale devient alors :  
**comment modifier l’algorithme SAT afin d’obtenir les bons points de contact ?**

### S’appuyer sur une solution éprouvée : Box2D et les Sequential Impulses

Plutôt que d’inventer une nouvelle approche, nous allons nous appuyer sur une méthode reconnue et éprouvée :  
les **Sequential Impulses** de Box2D.

Cette approche est décrite dans un document de référence rédigé par **Erin Catto**, présenté à la GDC 2006 :  
*Fast and Simple Physics using Sequential Impulses*.

Ce document :
- explique la motivation physique derrière les impulsions,
- présente une approche itérative pour résoudre les contraintes,
- introduit une gestion robuste des contacts multiples.

Le projet **Box2D Lite**, disponible sur le dépôt GitHub d’Erin Catto, constitue une implémentation pédagogique simplifiée du moteur Box2D, particulièrement adaptée à l’apprentissage de la physique temps réel en 2D.

Conceptuellement, cette méthode reste proche de ce que nous faisons déjà :
- résolution itérative,
- corrections successives,
- convergence vers une solution stable.

### Ce que nous faisons déjà… et ce qui manque encore

Dans notre moteur actuel, nous disposons déjà de plusieurs éléments décrits dans le document :
- la position des points de contact,
- la normale de collision,
- la profondeur de pénétration,
- l’utilisation du **Separating Axis Theorem (SAT)** pour les collisions boîte–boîte.

Nous trouvons correctement :
- l’axe de pénétration minimale,
- le point correspondant à la meilleure pénétration.

Cependant, deux étapes essentielles manquent encore :
1. **Identifier la face incidente sur l’autre corps rigide**,
2. **Effectuer une opération de clipping entre deux segments**.

C’est précisément cette étape de clipping qui permet :
- de corriger les points de contact aberrants (ex. contact décalé sur le sol),
- d’obtenir **plusieurs points de contact cohérents** dans le cas face–face.

### Référence et incident : notions fondamentales

Avant de parler de clipping, il est indispensable de comprendre deux concepts clés introduits par Erin Catto :

- **Reference face (face de référence)**
- **Incident face (face incidente)**

Ces deux notions structurent toute la suite de l’algorithme.

#### Face de référence (reference face)

La face de référence est directement issue du SAT.

Lors de la détection polygone–polygone :
- nous testons les axes normaux des faces,
- nous identifions l’axe avec la **pénétration minimale** (la plus critique),
- cet axe correspond à une face spécifique d’un des deux objets.

Cette face est appelée **face de référence**.

Dans notre implémentation actuelle :
- cette information est déjà calculée,
- l’axe retourné par `collidingPolygonPolygon` est précisément cette face de référence,
- le point de pénétration maximale est également déjà disponible.

Autrement dit, **nous possédons déjà la face de référence**, même si nous ne la nommons pas encore ainsi explicitement.

#### Face incidente (incident face)

La face incidente est une face du **second objet**, opposée à la face de référence.

Plus précisément :
- c’est la face dont la normale est **la moins alignée** avec la normale de la face de référence,
- autrement dit, celle dont le produit scalaire avec la normale de référence est **le plus négatif**.

Intuitivement :
- la face de référence définit la direction dominante de la collision,
- la face incidente est celle qui « arrive » en face de cette référence.

Pour trouver cette face incidente :
1. on parcourt toutes les faces du second polygone,
2. on calcule le produit scalaire entre leurs normales et la normale de référence,
3. on sélectionne la face ayant la valeur minimale.

Cette étape est simple, robuste et déterministe.

### Pourquoi ces deux faces sont essentielles

La combinaison :
- d’une face de référence,
- et d’une face incidente,

permet de construire deux segments :
- un segment de référence,
- un segment incident.

C’est **entre ces deux segments** que l’on appliquera ensuite l’algorithme de clipping.

Le clipping :
- tronque le segment incident par rapport aux limites de la face de référence,
- produit zéro, un ou deux points de contact valides,
- garantit des points bien positionnés et physiquement cohérents.

### Prochaine étape

À ce stade :
- nous savons déjà extraire la face de référence via le SAT,
- nous savons comment déterminer la face incidente sur l’autre corps.

La prochaine séance consistera à :
- implémenter l’algorithme de recherche de la face incidente,
- introduire le **clipping** entre segments,
- générer automatiquement **un ensemble de points de contact** exploitables par le solveur.

Ces notions — *reference edge* et *incident edge* — vont désormais être centrales et récurrentes dans la suite du cours.
