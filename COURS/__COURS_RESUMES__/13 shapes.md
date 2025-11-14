
![[medias/13 shapes 2025-11-11 07.00.31.excalidraw]]

### Implémentation de la classe Bodu

```cpp
struct Body
{
	// linear motion
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;
	
	// angular motion
	// TODO
	// Forces
	Vec2 sumForces;
	

    // mass
    float mass, invMass;
    
    // shape
    Shape* shape = NULL;
    
    Body(const Shape& shape, float x, float y, float m);
    ~Body();
    
    void AddForce(const vec2& force);
    void ClearForce();
    
    void integrate(float dt)
};

enum ShapeType {
	CIRCLE,
	POLYGON,
	BOX	
};

struct Shape {
	virtual ~Shape() = default;
	virtual ShapeType = GetType const = 0;
	virtual float getMomentOfInertia const = 0;
}

struct CircleShape: public Shape {
	float radius;
	CircleShape(const float radius);
	virtual ~CircleShape();
	ShapeType GetType() const override;
	float GetMomentOfInertia() const override;
}

struct PolygonShape: public Shape {
	PolygonShape() = default;
	PolygonShape(const vector<Vec2> vertices) = default;
	virtual ~PolygonShape();
	ShapeType GetType() const override;
	float GetMomentOfInertia() const override;
}

struct BoxShape: public PolygonShape {
	float width, height;
	PolygonShape() = default;
	BoxShape(float width, float height) = default;
	virtual ~BoxShape();
	ShapeType GetType() const override;
	float GetMomentOfInertia() const override;
}
```


