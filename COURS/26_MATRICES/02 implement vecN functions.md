## 1. Principe général de l’implémentation  
Cette étape ne présente **aucun concept fondamentalement nouveau**.  
Il s’agit principalement d’**adapter des opérations vectorielles classiques** afin qu’elles fonctionnent avec un nombre **arbitraire de composantes** (*n components*).

L’objectif est donc de passer d’une logique « vecteur de taille fixe » à une logique **dynamique**, déterminée au moment de la construction.

---

## 2. Constructeur par défaut  
Le constructeur par défaut ne fait **aucune allocation mémoire**.

Il se contente d’initialiser l’état interne de l’objet :

- `n = 0`  
- `data = nullptr`

```cpp
VECN::VECN() : n(0), data(nullptr) {}
```

Ce choix est volontaire :

- un vecteur vide est valide,
    
- aucune allocation inutile n’est effectuée.
    

---

## 3. Constructeur avec taille `n`

Ce constructeur est responsable de **toute l’allocation dynamique**.

### Rôle :

- fixer le nombre de composantes,
    
- allouer un tableau de `float` sur le tas (_heap_).
    

```cpp
VECN::VECN(int n) : n(n) 
{     
	data = new float[n]; 
}
```

À ce stade :

- la taille du vecteur est connue uniquement **à l’exécution**,
    
- chaque instance de `VECN` peut avoir une dimension différente.
    

---

## 4. Allocation et responsabilité mémoire

Dès lors que l’on utilise `new[]`, il est **impératif** de libérer la mémoire correspondante.

Cela implique l’existence d’un **destructeur**.

---

## 5. Destructeur

Le destructeur libère le tableau dynamique alloué lors de la construction.

```cpp
VECN::~VECN() {     delete[] data; }
```

Ce mécanisme garantit :

- l’absence de fuite mémoire,
    
- une gestion explicite du cycle de vie des ressources.
    

---

## 6. Constructeur de copie

Ce constructeur permet de créer un `VECN` **à partir d’un autre**.

### Étapes :

1. Copier la taille `n`,
    
2. Allouer un nouveau tableau,
    
3. Copier chaque composante.
    

```cpp
VECN::VECN(const VECN& other) : n(other.n) 
{     
	data = new float[n];     
	for (int i = 0; i < n; ++i) {         
		data[i] = other.data[i];     
} 
}
```

Il s’agit d’une **copie profonde** (_deep copy_), indispensable pour éviter le partage de pointeurs.

---

## 7. Méthode `Zero()`

Cette méthode met **toutes les composantes du vecteur à zéro**.

```cpp
void VECN::Zero() {     
	for (int i = 0; i < n; ++i) {         
		data[i] = 0.0f;     
	} 
	}
```

Utilité :

- initialisation des solveurs,
    
- remise à zéro d’un vecteur de travail,
    
- stabilité numérique.
    

---

## 8. Rappel : produit scalaire

Le produit scalaire entre deux vecteurs à _n_ composantes est défini par :

v⋅w=∑i=0n−1vi×wiv \cdot w = \sum_{i=0}^{n-1} v_i \times w_iv⋅w=i=0∑n−1​vi​×wi​

Le nombre de composantes n’a aucune importance tant qu’il est identique pour les deux vecteurs.

---

## 9. Implémentation du `Dot`

La méthode retourne un **scalaire flottant**.

```cpp
float VECN::Dot(const VECN& v) const 
{     
	float sum = 0.0f;     
	for (int i = 0; i < n; ++i) {         
		sum += data[i] * v.data[i];     
	}    
    return sum; }
```

Étapes :

- initialisation de l’accumulateur,
    
- multiplication composante par composante,
    
- accumulation du résultat.
    

---

## 10. Hypothèse implicite

Cette implémentation suppose que :

- les deux vecteurs ont la **même dimension**.
    

La gestion des erreurs (assertions, exceptions) est volontairement ignorée à ce stade, pour rester focalisé sur les concepts essentiels.

---

## 11. Style volontairement minimaliste

Les méthodes sont écrites de manière :

- lisible,
    
- directe,
    
- sans optimisation prématurée.
    

L’objectif est pédagogique, non industriel.

---

## 12. Travail demandé 

À partir de cette base, on doit implémenter :

- `operator+`
    
- `operator-`
    
- `operator*`
    
- `operator+=`
    
- `operator-=`
    
- `operator*=`
    
- `operator[]` (version const et non const)
    

Toutes ces méthodes reposent sur :

- des boucles sur `n`,
    
- des opérations élémentaires sur les composantes.
    

---

## 13. Intention pédagogique

L’écriture manuelle de ces opérateurs permet de :

- comprendre la surcharge d’opérateurs en C++,
    
- maîtriser la gestion mémoire,
    
- préparer les structures nécessaires aux **solveurs de contraintes**.
    

---

## 14. Prochaine étape

Dans la suite du cours :

- présentation d’une implémentation complète,
    
- validation du comportement des opérateurs,
    
- transition vers les **matrices dynamiques (`MATMN`)**.
