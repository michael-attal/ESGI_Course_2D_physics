![[medias/15 Torque & moment of inertia 2025-11-12 07.27.03.excalidraw]]

### liste de moments d inertie

https://en.wikipedia.org/wiki/List_of_moments_of_inertia

### Implémentation

```cpp
float CircleShape::GetMomentOfInertia() const{
	// on doit encore multiplier par la masse
	return (1/2) * (radius*radius);
}

float BoxShape::GetMomentOfInertia() const{
	// on doit encore multiplier par la masse
	return (1/12) * (width*width + height * height);
}

Body::Body(Shape& shape, float x, float y, float m)
{
	// ...
	this->I = shape.GetMomentOfInertia * mass;
}
```

### Intégration linéaire et intégration angulaire

```cpp
void Body::IntegrateLinear(float dt)
{
	acceleration = sumForces * invMass;
	velocity+= acceleration *dt;
	position += velocity *dt;
	ClearForces();
}

void Body::IntegrateAngular(float dt)
{
	angularAcceleration = sumTorque * invI;
	angularVelocity+= angularAcceleration *dt;
	rotation += angularVelocity *dt;
	ClearTorque();
}
```

![[medias/moment-of-inertia-lucasvieira.gif]]

