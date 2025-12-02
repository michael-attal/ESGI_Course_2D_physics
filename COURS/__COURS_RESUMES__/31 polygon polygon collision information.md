
![[medias/31 polygon polygon collision information 2025-11-18 11.08.49.excalidraw|800]]

```cpp
// best separation from a to b
if(abSeparation > baSeparation)
{
	contact.depth = -abSeparation;
	contact.normal = edge.Normal();
}

// best separation from b to a
if(baSeparation > abSeparation)
{
	contact.depth = -baSeparation;
	contact.normal = -edge.Normal();
}


bool IsCollidingPolygonPolygon(PolygonShape& a, PolygonShape& b, Contact& contact)
{
	
	const PolygonShape* bPolygonShape = (PolygonShape*) a->shape;
	const PolygonShape* aPolygonShape = (PolygonShape*) b->shape;
	Vec2 aAxis, bAxis;
	Vec2 aPoint, bPoint;
	float abSep = aPolygonShape->FindMinSeperation(bPolygonShape, aAxis, aPoint);
	if(abSep >= 0) return false;
	
	float baSep = bPolygonShape->FindMinSeperation(aPolygonShape, bAxis, bPoint);
	if(baSep >= 0) return false;
	
	// TODO: populate contact information
	if(abSeperation > baSeparation)
	{
		contact.depth = -abSeparation; 
		contact.normal = aAxis.normal();
		contact.start = aPoint;
		contact.end = aPoint + contact.normal * contact.depth;
	}
	
	if(baSeperation > abSeparation)
	{
		contact.depth = -baSeparation; 
		contact.normal = -bAxis.normal();
		contact.end = bPoint;
		contact.start = bPoint - contact.normal * contact.depth;
	}
	
	return true;
	
}

```