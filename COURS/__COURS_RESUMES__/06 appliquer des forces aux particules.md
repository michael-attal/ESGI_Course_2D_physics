![[medias/06 appliquer des forces aux particules 2025-11-08 13.01.42.excalidraw|800]]

### Implémentation

```cpp
void Application:: Update(){
	Vec2 wind = Vec2(2.,0.);
	particle->AddForce(wind);
	particle->Integrate(deltaTime);
}

void Particle::AddForce(Vec2 force)
{
	sumForces += force;
}

void Particle::Integrate(float dt)
{
	// calcul de l acceleration avec la 2e loi de newton
	acceleration = sumForces / mass;
	velocity += acceleration*dt;
	position += velocity*dt;
	// on reset les forces appliquées à la particule pour la prochaine frame
	ClearForces();
}
```