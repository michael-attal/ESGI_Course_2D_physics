![[medias/11 spring force 2025-11-10 11.52.43.excalidraw]]

### Code de la fonction spring force


```cpp
Vec2 Force::GenerateSpringForce(const Particle particle, vec2 anchor, float restLength, float k)
{
	vec2 d = particle.position - anchor;
	
	float displacement = d.Magnitude-restLength;
	Vec2 springDir = d.unitVector();
	float spingMagnitude = -k * displacement;
	Vec2 springForce = springDir*springMagnitude;
	return springForce;
}

Vec2 springForce = Force::GenerateSpringForce(*particle, vec2(100,100), 300, 20);
particle->AddForce(springForce);
```

### Multiple particles: chain

```cpp
Vec2 Force::GenerateSpringForce(const Particle particle a, const Particle b, float restLength, float k)
{
	vec2 d = a.position - b.position;
	
	float displacement = d.Magnitude-restLength;
	Vec2 springDir = d.unitVector();
	float spingMagnitude = -k * displacement;
	Vec2 springForce = springDir*springMagnitude;
	return springForce;
}

for(int i= 0; i< NUM_PARTICLES; i++)
{
	int currParticle = i;
	int prevParticle = i-1;
	Vec2 springForce = Force::GenerateSpingForce(
		*particles[currParticle],
		*particles[prevParticle],
		restLength, k);
	particles[currParticle]->AddForce(springForce);
	particles[prevParticle]->AddForce(-springForce);
	
}
```

![[medias/11 spring force-20251110.png]]





