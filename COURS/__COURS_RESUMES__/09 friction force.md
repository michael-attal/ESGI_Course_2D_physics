
![[medias/09 friction force 2025-11-10 08.57.28.excalidraw|800]]

### Code de la fonction

```cpp
Vec2 Force::GenerateFrictionForce(Particle particle, float k)
{
	vec2 frictionDir = particle.velocity*UnitVector() * -1.0;
	float fictionMagnitude = k;
	
	frictionForce = FrictionDirection * frictionMagnitude;
	return frictionForce;
}

Vec2 friction = Force::GenerateFrictionForce(*particle, 0.6);
particle->AddForce(friction);
```