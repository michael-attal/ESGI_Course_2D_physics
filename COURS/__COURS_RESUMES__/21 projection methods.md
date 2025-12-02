![[medias/21 projection methods 2025-11-14 08.00.03.excalidraw]]

### Implémentation

```cpp
void Contact::ResolvePenetration()
{
	float da = (depth*b->mass) / (a->mass + b->mass);
	float db = (depth * a->mass) / (a->mass + b->mass);
	
	a->position -= normal *da;
	b->position += normal *db;
	
}

// with invert of the mass

void Contact::ResolvePenetration()
{
	float da = depth / (a->invMass+b->invMass) * a->invMass;
	float db = depth / (a->invMass+b->invMass) * b->invMass;
	
	a->position -= normal *da;
	b->position += normal *db;
	
}
```