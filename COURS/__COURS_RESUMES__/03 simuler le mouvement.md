### Accélération constante

![[medias/03 simuler le mouvement 2025-11-08 12.00.01.excalidraw|800]]

### Implémentation

```cpp
void Particle::Integration(float dt)
{
	velocity += acceleration *dt;
	position += velocity*dt;
}
```
