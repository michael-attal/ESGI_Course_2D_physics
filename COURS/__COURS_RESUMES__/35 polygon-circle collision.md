![[medias/35 polygon-circle collision 2025-11-20 09.25.38.excalidraw|800]]

### Implémentation

```cpp
bool CollisionDetection::IsCollidingPolygonCircle(Body* polygon, Body* circle, Contact& contact) {
    const PolygonShape* polygonShape = (PolygonShape*) polygon->shape;
    const std::vector<Vec2>& polygonVertices = polygonShape->worldVertices;

    Vec2 minCurrVertex;
    Vec2 minNextVertex;

    // Loop all the edges of the polygon/box
    for (int i = 0; i < polygonVertices.size(); i++) {
        int currVertex = i;
        int nextVertex = (i + 1) % polygonVertices.size();
        Vec2 edge = polygonShape->EdgeAt(currVertex);
        Vec2 normal = edge.Normal();

        // Compare the circle center with the rectangle vertex
        Vec2 circleCenter = circle->position - polygonVertices[currVertex];

        // Project the circle center onto the edge normal
        float projection = circleCenter.Dot(normal);

        // If we found a dot product projection that is in the positive side of the normal
        if (projection > 0) {
            // Circle center is outside the rectangle
            minCurrVertex = polygonShape->worldVertices[currVertex];
            minNextVertex = polygonShape->worldVertices[nextVertex];
            break;
        }
    }

    // Draw the vertices of the closest edge in the screen
    Graphics::DrawFillCircle(minCurrVertex.x, minCurrVertex.y, 5, 0xFF00FFFF);
    Graphics::DrawFillCircle(minNextVertex.x, minNextVertex.y, 5, 0xFF00FFFF);

    return false;
}

```

### implémentation 3 régions

```cpp
bool IsCollidingPolygonCircle(Body* polygon, Body* circle){
	if(!inside){
	//TODO: if circle center is in region A
	//TODO: if circle center is in region B
	//TODO: if circle center is in region C
	} else{
		// TODO: circle center is inside polygon
	}
}
```