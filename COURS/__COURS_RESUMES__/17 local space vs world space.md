
### Implémentation

```cpp
struct PolygonShape: public Shape{
	std::vector<Vec2> localVertices;
	std::vector<Vec2> worldVertices;
	
	// function to rotate and translate the polygon vertices
	// from local space to world space
	void UpdateVertices(float angle, const vec2& Position);
}

void PolygonShape::UpdateVertices(float angle, const vec2& Position)
{
	for(int i=0; i< localVertices.size(); i++)
	{
	// 1. rotate
	worldVertices[i] = localVertices.Rotate(angle);
	// 2. translate
	worldVertices[i] += position;
	
	}
}
```