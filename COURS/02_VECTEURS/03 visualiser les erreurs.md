# Comprendre les Erreurs dans p5.js

---

## Introduction

Avant de continuer, il est important de comprendre **comment l’éditeur p5.js signale les erreurs**.  
Cela permet de savoir **quand quelque chose ne fonctionne pas et pourquoi**.

---

## Exemple d’Erreur

Supposons que, au lieu de mettre `100`, nous utilisions une variable `w` qui **n’existe pas**.  
Ou encore, si nous oublions un point-virgule ou faisons une faute de frappe, l’éditeur va **générer une erreur**.  


---

## Lire le Message d’Erreur

En exécutant le code :  
- L’erreur apparaît **en bas de l’éditeur**  
- Exemple : `Uncaught ReferenceError: W is not defined in sketch line 17`  
- Cela indique **la ligne concernée** et le **type d’erreur**, facilitant la correction


---

## Comment Gérer les Erreurs

- Observez toujours le message d’erreur  
- Il indique **ce qui est incorrect** et **où cela se produit**  
- Cette pratique est essentielle pour **comprendre et corriger rapidement** les problèmes


---

## Résumé

- L’éditeur p5.js signale les erreurs de manière claire  
- Les messages indiquent la **ligne** et la **nature** de l’erreur  
- Lire et comprendre ces messages est crucial pour coder efficacement
