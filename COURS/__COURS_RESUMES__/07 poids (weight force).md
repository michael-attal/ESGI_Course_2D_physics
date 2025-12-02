
![[medias/07 poids (weight force) 2025-11-08 13.26.19.excalidraw|800]]

### Implémentation

```cpp
// on multiplie par la masse, mais sera divisé par la masse pendant le calcul de l'accélération
// en effet, accélération = somme_des_force / masse
Vec2 weight = Vec2(0.,particle->mass *9.8 * PIXELS_PER_METER);
particle->AddForce(weight)
```