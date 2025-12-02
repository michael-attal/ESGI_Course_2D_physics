![[medias/12 rigid bodies 2025-11-11 06.35.34.excalidraw]]

### Implémentation

```cpp
struct Particle{
	// linear motion
	Vec2 position, velocity, acceleration;
	Vec2 sumForces;
	
	// mass
	float mass, invMass;
	
	// ANgular motion
	float rotation;
	
	// geometry of the rigid body
	Shape* shape = NULL;
};

enum ShapeType {BOX, POLYGON, CIRCLE};
```