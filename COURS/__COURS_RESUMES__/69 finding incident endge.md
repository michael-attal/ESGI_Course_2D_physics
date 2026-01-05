```cpp
bool CollisionDetection::IsCollidingPolygonPolygon(Body* a, Body* b, std::vector<Contact>& contacts) {
    PolygonShape* aPolygonShape = (PolygonShape*) a->shape;
    PolygonShape* bPolygonShape = (PolygonShape*) b->shape;
    int aIndexReferenceEdge, bIndexReferenceEdge;
    Vec2 aSupportPoint, bSupportPoint;
    float abSeparation = aPolygonShape->FindMinSeparation(bPolygonShape, aIndexReferenceEdge, aSupportPoint);
    if (abSeparation >= 0) {
        return false;
    }
    float baSeparation = bPolygonShape->FindMinSeparation(aPolygonShape, bIndexReferenceEdge, bSupportPoint);
    if (baSeparation >= 0) {
        return false;
    }
    PolygonShape* referenceShape;
    PolygonShape* incidentShape;
    int indexReferenceEdge;
    if (abSeparation > baSeparation) {
        referenceShape = aPolygonShape;
        incidentShape = bPolygonShape;
        indexReferenceEdge = aIndexReferenceEdge;
    } else {
        referenceShape = bPolygonShape;
        incidentShape = aPolygonShape;
        indexReferenceEdge = bIndexReferenceEdge;
    }
    // Find the reference edge based on the index that returned from the function
    Vec2 referenceEdge = referenceShape->EdgeAt(indexReferenceEdge);
    // Find the incident edge
    int incidentIndex = incidentShape->FindIncidentEdge(referenceEdge.Normal());
    /////////////////////////////////////
    // TODO: Clip line segments!
    /////////////////////////////////////
    /*
    Contact contact;
    contact.a = a;
    contact.b = b;
    if (abSeparation > baSeparation) {
        contact.depth = -abSeparation;
        contact.normal = aAxis.Normal();
        contact.start = aPoint;
        contact.end = aPoint + contact.normal * contact.depth;
    } else {
        contact.depth = -baSeparation;
        contact.normal = -bAxis.Normal();
        contact.start = bPoint - contact.normal * contact.depth;
        contact.end = bPoint;
    }
    contacts.push_back(contact);
    */
    return true;
}

int PolygonShape::FindIncidentEdge(const Vec2& normal) const {
    int indexIncidentEdge;
    float minProj = std::numeric_limits<float>::max();
    for (int i = 0; i < this->worldVertices.size(); ++i) {
        auto edgeNormal = this->EdgeAt(i).Normal();
        auto proj = edgeNormal.Dot(normal);
        if (proj < minProj) {
            minProj = proj;
            indexIncidentEdge = i;
        }
    }
    return indexIncidentEdge;
}
```