# L’intégration comme somme continue  

Dans un contexte de simulation numérique, nous passons souvent d’une **description discrète** d’un système (un ensemble de particules manipulé en code) à une **description continue** (un modèle physique).  
La notion d’intégrale est l’outil mathématique qui permet ce passage.  

---

## Sommes discrètes et programmation  

Le symbole « $\Sigma$ » représente une **somme discrète**.  
Par exemple, si un solide est modélisé par $N$ particules, le **centre de masse** en $x$ s’exprime comme une addition des masses $m_i$ pondérées par leurs positions $x_i$, puis normalisée par la masse totale $M$ :  

![[medias/discrete-sum.png]]

En programmation, cela se traduit naturellement par une boucle qui accumule la quantité $m_i x_i$ sur l’ensemble des particules.  

---

## Du discret au continu  

Si l’on raffine notre modèle — particules de plus en plus petites et nombreuses, jusqu’à devenir **infinitésimales** —  
le solide devient un **milieu continu**.  
Les sommes sur des éléments discrets ne suffisent plus : nous devons représenter une infinité de contributions locales.  

---

## Une somme continue : la notation de l’intégrale  

La notation « $\int$ » peut être vue comme un « S » allongé : elle représente une **somme continue**.  
On remplace alors la somme discrète par une intégrale sur la masse :  

![[medias/continuous-sum.png]]

Chaque $dm$ désigne une « très petite portion de masse ».  
En intégrant $x\,dm$, on additionne toutes ces portions pondérées par leur position.  

---

## Pourquoi c’est essentiel en simulation  

Ce lien entre somme discrète et intégrale est central dans la modélisation numérique :

- un moteur physique ou un shader manipule des **valeurs discrètes** (grilles, particules, pixels),  
- mais les équations qu’il approxime proviennent du **modèle continu** (champ de masse, densité, énergie).  

L’intégration est donc un pont :  
elle permet d’écrire les lois de la physique au niveau continu, tout en laissant l’ordinateur appliquer des méthodes discrètes pour obtenir une solution approchée.  
