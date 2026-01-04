## Validation du clipping et test de stabilité : empilement de boîtes

Après avoir implémenté le clipping des faces et vérifié que les points de contact générés sont cohérents, l’étape suivante consiste à **réactiver l’ensemble du pipeline de simulation** afin d’évaluer le comportement global du moteur physique.

L’objectif est clair :  
**tester la stabilité d’un empilement de boîtes** une fois la résolution de contraintes entièrement réactivée.

---

## Réactivation du pipeline de simulation

La première action consiste à réactiver :
- la résolution des contraintes,
- la boucle de résolution itérative,
- l’intégration temporelle des corps rigides.

Concrètement :
- les contraintes sont collectées,
- elles sont résolues itérativement,
- les impulsions sont appliquées,
- les corps sont ensuite intégrés et mis à jour.

En parallèle, certains éléments de test temporaires sont désactivés :
- suppression du déplacement manuel des objets à la souris,
- retrait des rigid bodies ajoutés artificiellement pour le débogage,
- conservation uniquement des éléments structurels de la scène :
  - le sol,
  - le mur gauche,
  - le mur droit.

L’interaction utilisateur est simplifiée :
- un clic droit permet simplement d’ajouter une boîte dans la scène.

---

## Test 1 : une boîte sur le sol

Dans un premier temps, une seule boîte est ajoutée au-dessus du sol.

Résultat observé :
- deux points de contact sont générés,
- les impulsions sont appliquées sur ces deux points,
- la boîte reste parfaitement stable.

Ce comportement correspond exactement à ce qui était attendu après l’introduction du clipping :
la collision face–face avec le sol produit **deux contacts cohérents**, assurant une correction équilibrée.

---

## Test 2 : empilement progressif

On ajoute ensuite progressivement plusieurs boîtes :

### Deux boîtes
- absence de jittering,
- stabilité visuelle immédiate,
- aucun glissement ou rotation parasite.

### Trois boîtes
- le système reste stable,
- de légères micro-oscillations peuvent apparaître (de l’ordre du pixel),
- aucune instabilité majeure n’est observée.

### Quatre boîtes et plus
- l’empilement reste globalement stable,
- la simulation converge vers un état de repos,
- aucun effondrement spontané n’apparaît.

Bien que la solution ne soit pas mathématiquement parfaite, le gain de stabilité est **très significatif** par rapport à l’état précédent du moteur.

---

## Analyse qualitative des résultats

L’amélioration observée s’explique directement par :
- la génération de **contacts multiples**,
- l’application des impulsions **sur chacun des points de contact**,
- une correction spatiale plus réaliste des pénétrations.

Autrement dit :
> la résolution n’est plus concentrée sur un point unique,  
> mais distribuée sur l’ensemble de la zone de contact.

Cette distribution :
- réduit les couples artificiels,
- limite les oscillations,
- améliore la convergence du solveur.

---

## Limites actuelles

Malgré ces résultats encourageants :
- la stabilité n’est pas absolue,
- des micro-mouvements subsistent,
- les empilements très profonds ou complexes n’ont pas encore été testés.

Ces limites sont normales à ce stade :
le moteur ne dispose pas encore de techniques avancées telles que :
- warm starting,
- bias positionnel (baumgarte amélioré),
- gestion du repos prolongé (sleeping),
- solveur plus robuste ou adaptatif.

---

## Conclusion intermédiaire

L’introduction du clipping des faces et des contacts multiples constitue une **avancée majeure** :

- la stabilité des empilements est nettement améliorée,
- les cas problématiques observés précédemment (contacts aberrants, jittering excessif) sont corrigés,
- le moteur se comporte désormais de manière crédible dans des scénarios standards.

Dans la prochaine étape, l’objectif sera de :
- augmenter la complexité de la scène,
- multiplier les objets,
- identifier les limites structurelles du solveur actuel,
- et déterminer quelles techniques supplémentaires devront être intégrées.

L’évolution du moteur est donc **progressive, mesurable et cohérente**, ce qui valide pleinement les choix algorithmiques réalisés jusqu’ici.
