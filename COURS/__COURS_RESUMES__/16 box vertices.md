### Implémentation

```cpp
BoxShape::BoxShape(float width, float height)
{
	this->width = width;
	this->height = height;
	// load vertices
	vertices.push_back(Vec2(-width/2.0, -height/2.0));
	vertices.push_back(Vec2(+width/2.0, -height/2.0));
	vertices.push_back(Vec2(+width/2.0, +height/2.0));
	vertices.push_back(Vec2(-width/2.0, +height/2.0));
	
}
```

![[medias/16 box vertices 2025-11-12 08.05.38.excalidraw]]

