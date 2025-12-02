![[medias/24 Impulse 2025-11-15 10.17.55.excalidraw]]

```cpp
struct Body{
	// ...
	float restitution; // (epsilon: elastitity)
}

// impulse est un changmene tinstantané de la vélocité
void Body::ApplyImpulse(const Vec2& j)
{
	if isStatic() return;
	velocity += j* invMass;
}
```

