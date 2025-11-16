![[medias/25 simplification impulse 2025-11-15 10.53.23.excalidraw]]

### implémentation

```cpp
void Collision::ResolveCollision(Contact& contact){
	Body* a = contact.a;
	Body* b = contact.b;
	
	float e = std::min(a->restitution, b->restitution);
	Vec2 vrel = a-velocity- b->velocity;
	
	float impulseMagnitude =-(1+e) * Vec2::Dot(vrel, contact.normal) / (a->invMass + b->invMass);
	Vec2 impulseDirection = contact.normal;
	
	Vec2 jn impulseDirection*impulseMagnitude;
	a->ApplyImpulse(jn);
	b->ApplyImpulse(-jn);
	
}
```