![[medias/11 spring force 2025-11-10 11.52.43.excalidraw|800]]

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

### Multiple particles: soft body

![[medias/11 spring force 2025-11-10 12.14.07.excalidraw]]

```cpp
Vec2 ab = Force::GenerateSpingForce(
		*particles[0],
		*particles[1],
		restLength, k); // a<->b
particles[0]->addForce(ab);
particles[1]->addForce(-ab);

Vec2 bc = Force::GenerateSpingForce(
		*particles[1],
		*particles[2],
		restLength, k); // b<->c
particles[1]->addForce(bc);
particles[2]->addForce(-bc);

Vec2 cd = Force::GenerateSpingForce(
		*particles[2],
		*particles[3],
		restLength, k); // c<->d
particles[2]->addForce(cd);
particles[3]->addForce(-cd);

Vec2 da = Force::GenerateSpingForce(
		*particles[3],
		*particles[0],
		restLength, k); // d<->a
particles[3]->addForce(da);
particles[0]->addForce(-da);

Vec2 ac = Force::GenerateSpingForce(
		*particles[0],
		*particles[2],
		restLength, k); // a<->c
particles[0]->addForce(ac);
particles[2]->addForce(-ac);

Vec2 bd = Force::GenerateSpingForce(
		*particles[1],
		*particles[3],
		restLength, k); // b<->d
particles[1]->addForce(bd);
particles[3]->addForce(-bd);
```

![[medias/11 spring force-20251110-1.png|800]]







