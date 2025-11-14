![[medias/circle circle collision detection 2025-11-12 12.07.35.excalidraw]]

### Implémentation
```cpp

bool CollisionDetection::IsColliding(Body* a, Body*b){
	bool aIsCircle = a->shape->GetType() == CIRCLE;
	bool bIsCircle = b->shape->GetType() == CIRCLE;
	
	if(aIsCircle && bIsCircle){
		return IsCollidingCircleCircle(a,b);
	}
	//TODO detect collision between other shapes
	
}

bool CollisionDetection::IsCollidingCircleCircle(Body* a, Body *b){
	CircleShape* aCircleShape = (CircleShape)* a->shape;
	CircleShape* bCircleShape = (CircleShape)* b->shape;
	
	const Vec2 ab =b->position-a->position;
	
	const float radiusSum = aCircleShape->radius + bCircleShape->radius;
	bool isColliding = ab.MagnitudeSquared <= (radiusSum*radiusSum);
	return isColliding;
	
}

struct CollisionDetection{
	static bool IsColliding(Body*a, Body*b);
	static bool IsCollidingCircleCircle(Body*a, Body*b);
	//TODO
	static bool IsCollidingPolygonPolygon(Body*a, Body*b);
	static bool IsCollidingCirclePolygon(Body*a, Body*b);
	
	
};

```