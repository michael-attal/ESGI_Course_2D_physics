---
# Différentes approches du SAT

Nous venons de voir une **explication globale** de l’algorithme SAT classique.  

On pourrait implémenter l’algorithme exactement comme décrit précédemment. Par exemple, lorsque nous parlons de **projeter les points sur chaque axe**, cela implique généralement l’utilisation du **produit scalaire (dot product)**.  

Cependant, le code SAT que j’utilise est légèrement différent de la version naïve présentée dans les slides. Quelques modifications permettent d’**optimiser les performances**.

---
# Implémentations alternatives

Il existe plusieurs manières de coder le SAT :  

- Certaines implémentations ne se contentent pas de détecter la collision, elles permettent aussi de **récupérer les informations de collision** (normale, profondeur, point de contact).  
- D’autres implémentations optimisent le nombre de comparaisons pour **gagner en performance**, ce qui peut être crucial pour des jeux avec de nombreux objets.  
- Il est donc normal de rencontrer des variantes du SAT codées différemment selon les développeurs.

---
# Principe invariant

Peu importe l’implémentation choisie, le principe de base reste identique au SAT classique :  

- Vérifier s’il existe un **axe séparateur** entre les deux corps.  
- Si au moins un axe sépare les deux corps, il n’y a pas de collision.  

---
# Prochaines étapes

Nous allons maintenant apprendre à **coder l’algorithme SAT** en prenant en compte ces optimisations et en récupérant les informations de collision.  
Cette version facilitera la gestion des collisions et sera plus performante dans le cadre d’un moteur physique.  

#tags
#collision-detection/sat, #sat-optimization, #algorithm-implementation, #game-development, #physics-engine
