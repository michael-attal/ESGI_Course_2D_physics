# Introduction

- Jusqu'à présent, notre détection et résolution de collision consiste à **séparer les corps rigides**.
- Nous utilisons la **méthode de projection** pour éviter les chevauchements.
- Cependant, cela ne produit pas de **résultat réaliste en termes de vitesses**.

---

# Scénario : Deux corps en collision

- Deux billes se rencontrent avec une certaine vitesse.
- Pour un rebond réaliste, nous devons utiliser la **méthode de l'impulsion**.
- Elle permet de résoudre la collision en appliquant une **impulsion dans une direction** avec une **magnitude donnée**.

---

# Données disponibles pour la collision

- Vitesses initiales : $V_A$ et $V_B$
- Profondeur de pénétration
- Points de contact : début et fin
- Normale de collision

---

# Méthode de l'impulsion

- Permet de **changer instantanément la vitesse** des corps en collision.
- Différence majeure avec les forces : pas d'accélération intermédiaire.
- Simplification utilisée pour notre moteur physique.

---

# Nature des changements de vitesse

- Le changement de vitesse est **immédiat**.
- La durée d'une frame ($\Delta t$) **n’influence pas** le résultat.
- Contrairement aux forces, la **réaction est instantanée**.

---

# Impulsion et transfert de momentum

- Appliquer une impulsion équivaut à **transférer instantanément du momentum** entre les corps.
- Momentum = **masse × vitesse**
- Quantité vectorielle, direction et magnitude importantes.

---

# Importance du momentum

- Détermine la **difficulté à arrêter un objet en mouvement**.
- Influence : **masse et vitesse**
- Exemples :
  - Boule de bowling vs ballon : même vitesse, masse différente → momentum différent.
  - Deux voitures identiques : vitesse différente → momentum différent.

---

# Conservation du momentum

- Principe : le **momentum total d’un système reste constant**.
- Lors d’une collision, le momentum est **redistribué** mais total reste inchangé.
- Exemple des billes de billard :
  - Boule blanche transfère momentum à la boule rouge.
  - Boule rouge se met en mouvement, boule blanche ralentit ou s’arrête.
- Formule :  
  $\text{masse}_A \cdot V_A + \text{masse}_B \cdot V_B = \text{masse}_A \cdot V_A' + \text{masse}_B \cdot V_B'$

---

# Constante de masse

- Dans notre moteur :
  - La **masse des objets ne change pas** avant et après collision.
  - Focus uniquement sur **nouvelles vitesses** $V_A'$ et $V_B'$.

---

# Transition vers les impulsions

- Compréhension du momentum et de sa conservation.
- Application directe dans la **méthode de l'impulsion** pour résoudre les collisions.
- Permet de gérer **rebonds réalistes** et transfert de momentum dans le moteur physique.
