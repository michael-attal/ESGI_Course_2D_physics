
## Vecteurs

![[medias/01_vectors 2025-11-07 07.16.06.excalidraw|800]]

### Implémentation

```cpp
struct Vec2 {
	float x;
	float y;
	
	Vec2(float x, float y) : x(x), y(y) {}
	
	~Vec2() = default;
	
}
```

```cpp
struct Vec3 {
	float x;
	float y;
	float z;
	
	Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	
	~Vec3() = default;
	
}
```

```cpp

int main()
{
	Vec3 position(3.7,25.0,-3.0);
	Vec3 velocity(4.5,-2.0,-2.0);
}
```

## Vector operations

### Magnitude d'un vecteur

![[medias/vector_magnitude.excalidraw|800]]


### Addition de vecteurs

![[medias/vector_addition.excalidraw|800]]

### Soustraction de vecteurs

![[medias/Vector operations 2025-11-05 08.39.20.excalidraw|800]]

### Egalité de vecteurs

![[medias/Vector operations 2025-11-05 08.46.27.excalidraw|800]]

### Scale (mise à l'échelle)

![[medias/Vector operations 2025-11-05 08.49.10.excalidraw|800]]


### Dot Product (produit scalaire)

![[medias/Vector operations 2025-11-05 08.53.37.excalidraw|1000]]


### Cross product (produit vectoriel)


![[medias/Vector operations 2025-11-05 09.26.23.excalidraw|800]]

### Vecteur perpendiculaire

![[medias/Vector operations 2025-11-05 09.40.22.excalidraw|800]]

### Normalisation

![[medias/Vector operations 2025-11-05 10.14.59.excalidraw|1000]]


### Rappels fonctions trigonométriques

![[medias/01_vecteurs 2025-11-07 08.49.24.excalidraw|800]]

### Rotation

![[medias/01_vectors 2025-11-07 08.34.18.excalidraw|800]]






