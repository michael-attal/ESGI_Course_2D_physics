![[medias/08 drag force 2025-11-10 08.34.32.excalidraw]]

### Code de la fonction

```cpp
Vec2 Force::GenerateDragForce(Particle particle, float k)
{
	if(particle.velocity.MagnitudeSquared() >0.0f)
	{
		Vec2 dragDir = particle.velocity.Normalized() * -1.0;
		float dragMagnitude= k * particle.velocity.MagnitudeSquared();
		drafForce = dragDir * dragMagnitude;
	}
	
	return dragForce
}

Vec2 drag = Force::GenerateDragForce(*particle, 0.01);
particle->AddForce(drag);
```