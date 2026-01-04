
![[medias/66 penetration constraint - bounciness 2025-12-31 09.10.30.excalidraw]]

```cpp
void PenetrationConstraint::PreSolve(const float dt){
	// compute relative velocity pre-impulse normal (used to compute elasticity)
	Vec2 va =a->velocity + Vec2(-a->angularVelocity *ra.y, a->angularVelocity * ra.x);
	Vec2 vb =a->velocity + Vec2(-b->angularVelocity *rb.y, b->angularVelocity * rb.x);
	float vrelDotNormal = (va-vb).Dot(n);
	
	// get restitution between the 2 bodies
	float e = std::min(a->restitution, b->restitution);
	
	// compute bias term considering elasticity (restitution)
	bias  = (beta/dt) * C + (e*vrelDotNormal);
	
}
```