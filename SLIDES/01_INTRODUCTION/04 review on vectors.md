---
class: transition
background: "#0a192f"
transition: fade
layout: center
---

# Introduction aux vecteurs  

---

## 🌐 Pourquoi commencer par les vecteurs ?

Avant de plonger dans la programmation de notre moteur physique, nous devons commencer par un outil mathématique fondamental : **le vecteur**.  

Les vecteurs sont **omniprésents dans la physique des jeux vidéo**.  
Ils servent à représenter pratiquement toutes les grandeurs physiques impliquées dans une simulation :  
- **Position**  
- **Vitesse (velocity)**  
- **Accélération (acceleration)**  
- **Forces** (poids, gravité, frottement, traînée, portance, impulsion, etc.)

Dans un moteur physique, **tout mouvement et toute interaction** se décrit à l’aide de vecteurs.  
C’est pourquoi il est essentiel que leur manipulation devienne pour vous une **seconde nature**.  

![[medias/04 review on vectors-20251027.png]]

---

## 🎯 Objectifs pédagogiques

À la fin de cette section, vous devrez être capable de :  
- Représenter et manipuler des vecteurs en 2D.  
- Effectuer des **opérations vectorielles de base** :  
  - addition et soustraction,  
  - produit scalaire (*dot product*),  
  - produit vectoriel (*cross product*).  
- Comprendre la **signification géométrique et physique** de ces opérations.  

Ces opérations forment la grammaire mathématique sur laquelle repose **tout moteur physique**, qu’il soit en 2D ou 3D.  


---

## ⚙️ Un outil mathématique central pour la physique 2D

Chaque concept de notre moteur physique utilisera les vecteurs :  
- **Les forces** : direction et intensité de l’action appliquée.  
- **Les vitesses** : orientation et rapidité du mouvement.  
- **Les accélérations** : variation de la vitesse.  
- **Les positions** : coordonnées des objets dans l’espace 2D.  

Autrement dit, un vecteur décrit toujours **une grandeur orientée** — un mouvement ou une force dans une direction donnée.


---

# Pour les étudiants déjà à l’aise  

---

## 🚀 Pour les étudiants déjà à l’aise

Si vous avez déjà suivi un cours sur les vecteurs et que vous êtes capable de :  
- expliquer intuitivement ce qu’est une **addition de vecteurs**,  
- interpréter le **produit scalaire** comme une mesure d’alignement,  
- et le **produit vectoriel** comme une mesure de rotation ou de perpendicularité,  

alors vous pouvez éventuellement **passer cette section** et rejoindre le cours au moment de l’installation du compilateur C++ et du développement du moteur physique.  

Cependant, si vous souhaitez consolider vos bases ou revoir les fondements géométriques de ces opérations, **je vous conseille vivement de rester** : cette courte révision vous permettra de comprendre plus facilement les équations que nous implémenterons plus tard.  



---

# Conclusion  

---

## 🧭 Conclusion

Les **vecteurs** sont le socle de tout moteur de physique de jeu vidéo.  
Ils permettent de **traduire les lois de Newton** dans un espace numérique et de donner vie à nos objets simulés.  

Avant de parler de collisions, de rotation ou d’impulsions, nous devons donc maîtriser ce langage mathématique commun.  

Passons maintenant à l’étude détaillée de ces outils et de leurs propriétés.  

