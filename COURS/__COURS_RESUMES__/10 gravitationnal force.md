![[medias/10 gravitationnal force 2025-11-10 09.14.27.excalidraw]]

### Code de la fonction

```cpp
Vec2 Force::GenerateGravitationalForce(Particle a, Particle b, float G)
{
	Vec2 d = b.position - a.position;
	float distSqared = d.MagnitudeSquared();
	Vec2 attractionDir = d.UnitVector();
	float attractionMagnitude = G * (a.mass*b.mass/distanceSquared);
	Vec2 attractionForce = attrationDir * attractionMagnitude;
	return attractionForce;
}
Vec2 attraction = Force::GenerateGravitationalForce(*particleA,*particleB,G);
particleA->addForce(attraction);
particleB->addForce(-attraction);
```
