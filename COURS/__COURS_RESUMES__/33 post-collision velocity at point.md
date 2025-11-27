![[medias/33 post-collision velocity at point 2025-11-19 08.31.20.excalidraw]]

### implémentation

![[medias/33 post-collision velocity at point-20251120.png]]

```cpp
void Contact::ResolveCollision(){
	ResolvePenetration();
	
	float e = std::min(a->restitution, b->restitution);
	
	Vec2 ra = end - a->position;
	Vec2 rb = start - b->position;
	// compute relative velocity
	// linear + angular of a MINUS linear+angular of b
	// dans notre moteur 2d , omega est un scalaire representant la magnitude du composant z
	// de la vélocité angulaire. comment faire un cross product?
	// cross(w, r) ?
	Vec2 va = a->velocity + Vec2(-a->angularVelocity* ra.y, a->angularVelocity * ra.x);
	Vec2 vb = b->velocity + Vec2(-b->angularVelocity* rb.y, b->angularVelocity * rb.x);
	
	
	const Vec2 vrel = va-vb;
	
	float vrelDotNormal = vrel.Dot(normal);
	
	// collision impulse
	const Vec2 impulseDirection = normal;
	const float impulseMagnitude = -(1+e) * vrelDotNormal / 
	((a->invMass+b->invMass)+ ra.Cross(normal)*ra.Cross(normal)* a->invI + rb.Cross(normal)*rb.Cross(normal)* b->invI);
	Vec2 jn = impulseDirection * impulseMagnitude;
	a->ApplyImpulse(jn, ra);
	b->ApplyImpulse(-jn, rb);
	
}

void Body::applyImpulse(const Vec2& j){
	if(isStatic())[
		return;
	}
	velocity += j * invMass;
}

void Body::applyImpulse(const Vec2& j, const Vec2& r){
	if(isStatic())[
		return;
	}
	// linear
	velocity += j * invMass;
	// angular
	angularVelocity += r.Cross(j);
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


