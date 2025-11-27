
![[medias/30 finding extra collision information 2025-11-18 10.46.49.excalidraw]]

### implementation

```cpp
float FindMinSeperation(PolygonShape& other, Vec2& axis, Vec2& point)
{
	float separation = std::numeric_limits<float>::lowest();
	
	for(int i=0; i< this->worldVertices.size(); i++){
		Vec2 va = this->worldVertices[i];
		Vec2 normal = this->EdgeAt(i).Normal();
		float minSep = std::numeric_limits<float>::max();
		Vec2 minVertex;
		for(int j=0; j< other->worldVertices.size(); j++){
		    Vec2 vb = other->worldVertices[j];
		    float proj =(vb-va).Normal();
		    if(proj < minSep)
		    {
			    minSep = proj;
			    minVertex = vb;
		    }
			minSep = std::min(minSep, proj);
		}
		if(minSep >separation){
			separation = minSep;
			axis = this->EdgeAt(i);
			point = minVertex;
			
		}
		
	}
	return separation;
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
	// contact.depth
	// contact.start
	// contact.end
	// contact.normal
	
	return true;
	
}
```