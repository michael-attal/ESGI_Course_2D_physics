### Comportement inattendu

Avant d’aller plus loin, il est nécessaire de rappeler l’importance du choix de la constante transmise lors du calcul de la force de traînée (*drag force*).  

Dans certains cas, une valeur trop élevée, par exemple `2.0`, engendre un coefficient de traînée excessif.  

Le résultat est une force de traînée supérieure à la vitesse de la particule elle-même, produisant ainsi un comportement anormal : au moment de l’entrée dans le fluide, la particule semble brutalement freinée, voire inverser sa direction.

---

### Scénarios inattendus

Certains scénarios peuvent donc présenter des comportements imprévus selon la valeur des constantes choisies.  

Ce phénomène ne correspond pas à une situation physique réelle, mais découle simplement du modèle mathématique sous-jacent.  

Les calculs de traînée ne dépendent que des valeurs définies pour les coefficients et les constantes : plus ces dernières sont élevées, plus la force de résistance appliquée sera importante.

---

### Choisir la bonne constante

Le choix de la constante dépend entièrement de la nature du phénomène que l’on souhaite simuler.  
Il n’est pas nécessaire ici d’être fidèle à la réalité physique : **dans un moteur de jeu, la priorité est l’aspect visuel et la cohérence avec le gameplay**.  

Ainsi, selon le type de fluide à simuler — qu’il s’agisse d’un liquide dense et visqueux ou simplement de l’air avec une légère résistance — il suffit d’ajuster les valeurs pour obtenir le comportement désiré à l’écran.

---

### Ajustement visuel

Dans ce cas précis, une constante d’environ `0.03` donne un résultat satisfaisant.  
Elle offre un équilibre visuel crédible entre inertie et résistance du fluide.  
Le retour visuel est fluide et cohérent avec la dynamique des particules observée à l’écran.

---

### Conclusion

L’un des attraits principaux de la simulation physique dans le jeu vidéo réside dans sa **flexibilité** : une erreur de constante n’a pas de conséquences graves, hormis un effet visuel légèrement altéré.  
L’essentiel est de maintenir la **cohérence** entre les principes mécaniques simulés et l’esthétique générale du projet.
