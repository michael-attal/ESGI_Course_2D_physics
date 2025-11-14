
![[medias/14 angular motion 2025-11-11 07.27.50.excalidraw|800]]

### Implémentation test4

```cpp
struct Body{
	// linear
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;
	Vec2 sumForces;
	float mass;
	float invMass;
	
	// angular
	float rotation; //theta
	float angularVelocity; // omega
	float angularAcceleration; //alpha
	
}

void Body::IntegrateAngular(float dt)
{
	angularVelocity += angularAcceleration *dt;
	rotation += angularVelocity*dt;
}
```