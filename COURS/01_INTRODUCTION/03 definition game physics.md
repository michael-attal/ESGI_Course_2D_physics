<!-- .slide: data-transition="slide" -->

# Physique du jeu vidéo  
## Définir le périmètre du cours

---

## Introduction : Que signifie « physique » dans le jeu vidéo ?

Avant toute chose, il est essentiel de **définir clairement le champ d’étude** de ce cours.  
Le mot *physique* couvre un ensemble immense de domaines : la thermodynamique, la mécanique quantique, la relativité, l’optique, les ondes, la lumière, la température, etc.  

---

Ici, nous devons restreindre notre perspective pour être précis.  
Lorsqu’on parle de **physique du jeu vidéo**, il ne s’agit pas de tout cela.  
Nous allons nous concentrer sur un sous-ensemble bien précis : **la mécanique newtonienne** — autrement dit, **les lois du mouvement** et leurs implications dans un monde 2D simulé.  

---

![[03 what is game physics-20251102.png]]

---

## Ce que nous allons étudier

Notre travail portera sur les **concepts fondamentaux du mouvement** :  
- **Accélération**, **vitesse**, **déplacement**  
- **Gravité** et **poids**  
- **Frottement (friction)** et **traînée (drag)**  
- **Forces**, **impulsions (impulses)** et **moment cinétique (momentum)**  

Autrement dit, nous allons étudier comment des objets rigides interagissent dans un environnement 2D — comment ils se déplacent, tournent, entrent en collision et réagissent aux forces.  



---

## Les corps rigides et les collisions

Notre simulation reposera sur la **mécanique des corps rigides (rigid body mechanics)**.  
Les objets conserveront leur forme lorsqu’ils entreront en collision — nous ne traiterons **pas de déformation** ni d’élasticité avancée.  

---

Nous aborderons :  
- La **détection de collision (collision detection)** : comment savoir que deux objets se rencontrent ?  
- La **résolution de collision (collision resolution)** : comment calculer les forces et les impulsions nécessaires pour les séparer ?  

Ces concepts formeront la base de notre **moteur physique 2D**, que nous implémenterons progressivement.  

---

<!-- .slide: data-transition="slide" -->

## Détails et approfondissements

Les principaux domaines que nous explorerons seront :  
- **La cinématique** : position, vitesse, accélération  
- **La dynamique** : forces, impulsions, contraintes  
- **Les interactions** : frottement, gravité, ressorts, contraintes molles (*soft constraints*)  
- **La rotation** : mouvement angulaire et couple (*torque*)  

Chaque section du cours ouvrira la “boîte noire” de ces notions pour en comprendre **les fondements mathématiques** et **leur traduction en code C++**.  



---

<!-- .slide: data-transition="slide" -->

## Ce que nous n’allons pas couvrir

Pour éviter toute confusion, il est important de préciser **ce que ce cours ne traite pas**.  
Nous n’aborderons **pas** :

- La **thermodynamique** (température, entropie, pression)  
- L’**électromagnétisme** (électricité, magnétisme, lumière, optique)  
- La **mécanique quantique** ou la **relativité**  
- La **mécanique des fluides** (gaz, liquides, viscosité, turbulence)  

Nous mentionnerons brièvement certaines notions comme **l’énergie** ou **le travail** lorsque cela sera utile (par exemple, en mécanique lagrangienne), mais sans approfondissement.  

---

## Focus sur la mécanique newtonienne

Notre champ d’étude se situe dans la **mécanique newtonienne classique**, celle du XIXᵉ siècle :  
celle où la matière est rigide, les objets ont une masse, une position et une vitesse, et les forces déterminent leur mouvement.  

Nous étudierons les notions de :  
- **Force** et **accélération**  
- **Quantité de mouvement (momentum)**  
- **Impulsion (impulse)**  
- **Rotation** et **couple (torque)**  

C’est cette vision du monde — simple mais puissante — qui fonde la plupart des moteurs physiques utilisés aujourd’hui dans les jeux 2D.  

---

## Conclusion

En résumé, notre étude de la **physique 2D du jeu vidéo** se concentrera sur :
- la **mécanique des corps rigides**,
- la **détection et la résolution de collisions**,
- la **traduction algorithmique** des lois de Newton.  

Nous laissons de côté les domaines plus avancés pour rester concentrés sur les **bases nécessaires à un moteur de simulation efficace et robuste**.  

C’est dans ce cadre que nous allons **commencer à manipuler les notions de mouvement, de masse et de force**.  

