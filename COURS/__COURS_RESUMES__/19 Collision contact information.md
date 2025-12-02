![[medias/19 Collision contact information 2025-11-14 06.59.46.excalidraw]]

### contact information - code

```cpp
struct Contact{
	Body* a;
	Body* b;
	Vec2 start;
	Vec2 end;
	
	Vec2 normal;
	float depth;
};

struct CollisionDetection{
	static bool isColliding(Body* a, Body* b, Contact& contact);
	static bool isCollidingCircleCircle(Body* a, Body* b, Contact& contact);
	
};

bool CollisionDetection::IsCollidingCircleCircle(Body* a, Body* b, Contact& contact) {
    CircleShape* aCircleShape = (CircleShape*) a->shape;
    CircleShape* bCircleShape = (CircleShape*) b->shape;

    const Vec2 ab = b->position - a->position;
    const float radiusSum = aCircleShape->radius + bCircleShape->radius;

    bool isColliding = ab.MagnitudeSquared() <= (radiusSum * radiusSum);

    if (!isColliding) {
        return false;
    }

    contact.a = a;
    contact.b = b;
    contact.normal = ab;
    contact.normal.Normalize();
    contact.start = b->position - contact.normal * bCircleShape->radius;
    contact.end = a->position + contact.normal * aCircleShape->radius;

    contact.depth = (contact.end - contact.start).Magnitude();
    
    return true;
}
```