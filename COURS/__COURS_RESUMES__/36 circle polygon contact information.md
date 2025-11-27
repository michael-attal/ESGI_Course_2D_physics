![[medias/36 circle polygon contact information 2025-11-21 06.54.18.excalidraw]]

### Implémentation


```cpp
bool CollisionDetection::IsCollidingPolygonCircle(Body* polygon, Body* circle, Contact& contact) {
    const PolygonShape* polygonShape = (PolygonShape*) polygon->shape;
    const CircleShape* circleShape = (CircleShape*) circle->shape;
    const std::vector<Vec2>& polygonVertices = polygonShape->worldVertices;

    bool isOutside = false;
    Vec2 minCurrVertex;
    Vec2 minNextVertex;
    float distanceCircleEdge = std::numeric_limits<float>::lowest();

    // Loop all the edges of the polygon/box finding the nearest edge to the circle center
    for (int i = 0; i < polygonVertices.size(); i++) {
        int currVertex = i;
        int nextVertex = (i + 1) % polygonVertices.size();
        Vec2 edge = polygonShape->EdgeAt(currVertex);
        Vec2 normal = edge.Normal();

        // Compare the circle center with the rectangle vertex
        Vec2 vertexToCircleCenter = circle->position - polygonVertices[currVertex];
        float projection = vertexToCircleCenter.Dot(normal);

        // If we found a dot product projection that is in the positive/outside side of the normal
        if (projection > 0) {
            // Circle center is outside the rectangle
            distanceCircleEdge = projection;
            minCurrVertex = polygonVertices[currVertex];
            minNextVertex = polygonVertices[nextVertex];
            isOutside = true;
            break;
        } else {
            // Circle center is inside the rectangle, find the min edge (the one with the least negative projection)
            if (projection > distanceCircleEdge) {
                distanceCircleEdge = projection;
                minCurrVertex = polygonVertices[currVertex];
                minNextVertex = polygonVertices[nextVertex];
            }
        }
    }
}

if (isOutside) {
    /////////////////////////////////////////////////
    // Check if we are inside region A:
    ////////////////////////////////////////////////
    Vec2 v1 = circle->position - minCurrVertex;      // vector from the nearest vertex to the circle center
    Vec2 v2 = minNextVertex - minCurrVertex;         // the nearest edge (from curr vertex to next vertex)
    if (v1.Dot(v2) < 0) {
        // Distance from vertex to circle center is greater than radius → no collision
        if (v1.Magnitude() > circleShape->radius) {
            return false;
        } else {
            // Detected collision in region A:
            contact.a = polygon;
            contact.b = circle;
            contact.depth = circleShape->radius - v1.Magnitude();
            contact.normal = v1.Normalize();
            contact.start = circle->position + (contact.normal * -circleShape->radius);
            contact.end = contact.start + (contact.normal * contact.depth);
        }
    }
} else {
    /////////////////////////////////////////////////
    // Check if we are inside region B:
    /////////////////////////////////////////////////
    v1 = circle->position - minNextVertex;           // vector from the next nearest vertex to the circle center
    v2 = minCurrVertex - minNextVertex;              // the nearest edge
    if (v1.Dot(v2) < 0) {
        // Distance from vertex to circle center is greater than radius... no collision
        if(v1.magnitude() > circleShape->radius){
	        return false
        } else{
	        // Detected collision in region B:
	        contact.a = polygon;
	        contact.b= circle;
	        contact.depth = circleShape->radius -v1.Magnitude();
	        contact.normal =v1.Normalize();
	        contact.start = circle->position + (contact.normal * -circleShape->radius);
            contact.end = contact.start + (contact.normal * contact.depth);
        }
    }
    else{
	    /////////////////////////////////////////////////
	    // we are inside region C:
	    /////////////////////////////////////////////////
	    
	    if(distanceCircleEdge > circleShapeRadius)
	    {
		    // no collision, distance between the closest distance and the circle center is greater than the radius
		    return false;
	    }else{
		    // detected collision in region C
		    contact.a = polygon;
		    contact.b = circle;
		    contact.depth = circleShapeRadius- distanceCircleEdge;
		    contact.normal = (minNextVertex-minCurrVertex).Normal();
		    contact.start = circle->position - (contact*circleShape->radius);
		    contact.end = contact.start + (contact.normal * contact.depth);
	    }
    }
}
} else{
	// the center of circle is inside the polygon, it is definitely colliding!
	contact.a = polygon;
	contact.b = circle;
	contact.depth = circleShape->radius - distanceCircleEdge;
	contact.normal = (minNextVertex - minCurrVertex).Normal();
	contact.start = circle->position - (contact.normal * circleShape->radius);
	contact.end = contact.start + (contact.birlak * contact.depth);
	
}



```