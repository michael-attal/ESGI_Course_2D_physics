![[medias/33 post-collision velocity at point 2025-11-19 08.31.20.excalidraw]]

### implémentation

![[medias/33 post-collision velocity at point-20251120.png]]

```cpp
void Contact::ResolveCollision() {
    // Apply positional correction using the projection method
    ResolvePenetration();
    
    // Define elasticity (coefficient of restitution e)
    float e = std::min(a->restitution, b->restitution);
    
    // Calculate the relative velocity between the two objects
    Vec2 ra = end - a->position;
    Vec2 rb = start - b->position;
    // V = v + w X r
    Vec2 va = a->velocity + Vec2(-a->angularVelocity * ra.y, a->angularVelocity * ra.x);
    Vec2 vb = b->velocity + Vec2(-b->angularVelocity * rb.y, b->angularVelocity * rb.x);
    const Vec2 vrel = va - vb;

    // Calculate the relative velocity along the normal collision vector
    float vrelDotNormal = vrel.Dot(normal);

    // Now we proceed to calculate the collision impulse
    const Vec2 impulseDirection = normal;
    const float impulseMagnitude = -(1 + e) * vrelDotNormal / ((a->invMass + b->invMass) + ra.Cross(normal) * ra.Cross(normal) * a->invI + rb.Cross(normal) * rb.Cross(normal) * b->invI);
    
    Vec2 jn = impulseDirection * impulseMagnitude;
    
    // Apply the impulse vector to both objects in opposite direction
    a->ApplyImpulse(jn, ra);
    b->ApplyImpulse(-jn, rb);
}


void Body::ApplyImpulse(const Vec2& j) {
    if (IsStatic()) {
        return;
    }
    velocity += j * invMass;
}

void Body::ApplyImpulse(const Vec2& j, const Vec2& r) {
    if (IsStatic()) {
        return;
    }
    // linear
    velocity += j * invMass;
    // angularVelocity == w, perpendiculaire à l'écran, 
    // c'est donc à lui qu'on ajoute de la vélocité
    // r.Cross(j) aussi perpendiculaire à l'écran, mais
    // ici la méthode Cross retourne un scalaire 
    // (la dernière composante d un cross product 3D)
    /*
    float Vec2::Cross(const Vec2& v) const {
		return (x * v.y) - (y * v.x);
	}
    */
    // angular
    angularVelocity += r.Cross(j) * invI;
}
```

### pb du cross product en 2D
![[medias/33 post-collision velocity at point 2025-11-20 08.06.21.excalidraw]]
$\omega(0,0,w)$ 
$r(r_x,r_y,0)$

$\omega \times r = (0*0-\omega*ry, \omega*rx-0*0)$
$\omega \times r = (-\omega*ry, \omega*rx)$

![[medias/33 post-collision velocity at point-20251119-1.png]]

![[medias/33 post-collision velocity at point-20251119-2.png]]


