# Particle physics

- on commence par simuler la physique de particules
- les particules n'ont pas de shape (pas de forme), on les considère comme de simples points avec une masse
- on le représentera en dessinant un cercle (dans le rendu)
- comment simuler le mouvement de ces particules ?

Si on connait le vecteur vitesse on peut calculer la position de la particule à la prochaine frame.

![[medias/02 particles 2025-11-06 12.14.18.excalidraw]]

## Les trois lois de NEWTON

Le mouvement des particules dans notre moteur 2D peut être modélisé en utilisant les LOIS DE NEWTON.

### 1 INERTIE

Si aucune force n'est appliquée à un objet, alors sa vélocité ne change pas.
Cela vaut pour un objet immobile, mais aussi à un objet qui se déplace à vitesse constante.

Plutôt logique, si mon objet est immobile et que je ne lui applique aucune force il restera immobile.

S'il se déplace à vitesse constante, il ne devrait jamais s'arrêter. Pourtant dans notre réalité,
un ballon qui se déplace à vitesse constante ne devrait jamais s'arrêter pourtant il s'arrêtera
bien à un moment... Cela est du à la force de traînée (la résistance de l'air, ou drag force).
Cette existe bel et bien et agit sur l'objet. Ce phénomène ne serait pas possible dans l'espace
où la force de traînée serait nulle (égale à zéro).

### 2 FORCE, MASSE ET ACCELERATION

La somme des forces appliquées à un objet est égale à la masse de l'objet multipliée par son accélération. 
L'accélération est la taux de variation de la vélocité (sa dérivée).

$$
\Sigma \vec F = m\vec a \implies \vec a = \frac{\Sigma \vec F}{m}
$$

La formule mathématique est intuitive, en effet, l'accélération est inversement proportionnelle à la masse.
Autrement dit, plus la masse de l'objet est élevée plus l'objet sera difficile à déplacer.


### 3 ACTION/REACTION

Pour toute force appliquée par un objet A sur un objet B, il existe une force égale et opposée appliquée
par l'objet B sur l'objet A. C'est l'action-réaction.
En d'autres termes, dès qu'un objet exerce une force sur un autre objet, le second objet exerce une force
de même magnitude (norme, longueur) et dans la direction opposée.

![[medias/newton3.excalidraw]]

### Classe Particle

```cpp
struct Particle{
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;
	
	float mass;
	
	Particle(float x, float y, float mass);
	~Particle();
};
```

```cpp
Particle(float x, float y, float mass)
{
	this->position = Vec(x,y);
	this->mass = mass;
}
```

### Vélocité de la particule

Dans la fonction `Update()`, on définit un vecteur vélocité qu'on ajoute naïvement à la position de la particule.
(intégration d'Euler implicite).

```cpp
Update(){
	particle->velocity = Vec2(2.,0.);
	
	particle->position.x += particle->velocity.x;
	particle->position.y += particle->velocity.y;
	
	// pareil que particle->position += particle->velocity;
}
```

### Contrôler le framerate

![[medias/02 particles 2025-11-08 11.07.52.excalidraw|800]]


```cpp
const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;
```

### Mouvement indépendant du framerate

```cpp

void Application::Update(){
	//calculate the delta time factor to be used when we update objects
	float dt = (SDL_GetTicks() - timePreviousFrame) / 1000.0f;
	
	//move objects as a function of deltatime
	particle->velocity.x = 50 * deltatime; 
	particle->velocity.y = 10 * deltatime;
	// euler integration
	particle->position.Add(particle->velocity);
}
```

### Vélocité constante

![[medias/02 particles 2025-11-08 11.17.38.excalidraw|800]]

### Accélération constante

```cpp
void Application::Update(){
    // on prédit la nouvelle position grâce à l intégration d'Euler
	particle->acceleration = Vec2(0.,9.8); // simule une gravité
	// integration de l accélération pour obtenir la nouvelle vitesse
	particle->velocity += particle->acceleration*deltatime
	// integration de la vitesse pour obtenir la nouvelle position
	particle->position += particle->velocity*deltatime
}
```

### Simuler le rebond sur le mur (hack)

![[medias/02 particles 2025-11-08 11.46.48.excalidraw|800]]

```cpp
// exemple avec le mur de gauche
if(particle->position.x - particle->radius <=0){
	particle->position.x = particle->radius;
	particle->velocity.x *= -1.0;*
}
// a réadapter sur les trois autres murs
```






























