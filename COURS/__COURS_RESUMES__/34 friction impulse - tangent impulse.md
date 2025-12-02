![[medias/34 friciton impulse 2025-11-20 09.03.22.excalidraw]]

### Implémentation

```cpp
void Contact::ResolveCollision(){
	ResolvePenetration();
	
	float e = std::min(a->restitution, b->restitution);
	// add friction (attribut ajouté dans struct Body)
	float e = std::min(a->friction, b->friction);
	
	Vec2 ra = end - a->position;
	Vec2 rb = start - b->position;
	Vec2 va = a->velocity + Vec2(-a->angularVelocity* ra.y, a->angularVelocity * ra.x);
	Vec2 vb = b->velocity + Vec2(-b->angularVelocity* rb.y, b->angularVelocity * rb.x);
	const Vec2 vrel = va-vb;
	
	float vrelDotNormal = vrel.Dot(normal);
	// collision impulse along normal
	const Vec2 impulseDirectionN = normal;
	const float impulseMagnitudeN = -(1+e) * vrelDotNormal / 
	((a->invMass+b->invMass)+ ra.Cross(normal)*ra.Cross(normal)* a->invI + rb.Cross(normal)*rb.Cross(normal)* b->invI);
	Vec2 jN = impulseDirectionN * impulseMagnitudeN;
	
	// collision impulse along tngent
	Vec2 tangent = normal.Normal();
	float vrelDotTangent = vRel.Dot(tangent);
	const Vec2 impulseDirectionT = tangent;
	const float impulseMagnitudeT = f * -(1+e) * vrelDotTangent / 
	((a->invMass+b->invMass)+ ra.Cross(tangent)*ra.Cross(tangent)* a->invI + rb.Cross(tangent)*rb.Cross(tangent)* b->invI);
	Vec2 jT = impulseDirectionT * impulseMagnitudeT;
	// combining tangent and normal impulses
	Vec2 j = jN+jT;
	a->ApplyImpulse(j, ra);
	b->ApplyImpulse(-, rb);
	
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



