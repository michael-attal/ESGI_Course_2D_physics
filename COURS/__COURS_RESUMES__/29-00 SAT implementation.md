
![[medias/29 SAT implementation 2025-11-18 10.18.25.excalidraw]]


### implementation

```cpp
float FindMinSeperation(PolygonShape& a, PolygonShape& b)
{
	float separation = std::numeric_limits<float>::lowest();
	
	for(Vec2 va: a->vertices){
		Vec2 normal = a->Perpendicular(va);
		float minSep = std::numeric_limits<float>::max();
		for(Vec2 vb: b->vertices){
			minSep = std::min(minSep, Dot(vb-va, normal));
		}
		if(minSep > separation)
			separation = minSep;
		
	}
	return separation;
}

bool IsCollidingPolygonPolygon(PolygonShape& a, PolygonShape& b)
{
	return FindMinSeperation(a,b) <= 0 && return FindMinSeperation(b,a) <= 0;
}
```

### support points

![[medias/support-point2.jpg]]

![[medias/support-point1.jpg]]
