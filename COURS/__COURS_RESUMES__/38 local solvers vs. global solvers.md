![[medias/38 local solvers vs. global solvers 2025-12-13 12.02.20.excalidraw]]

### Implémentation

```cpp
void Contact::ResolvePenetration()
{
	if(a->isStatic() && b->isStatic())
	{
		return;
	}
	float da = depth  / (a->invMass + b->invMass) * a->invMass;
	float db = depth  / (a->invMass + b->invMass) * b->invMass;
	
	a->position -= depth*normal*0.8;
	b->position += depth*normal*0.8;
	
	a->shape->UpdateVertices(a->rotation, a->posiiton);
	b->shape->UpdateVertices(b->rotation, b->posiiton);
}
// iteration
for(int i=0; i<10; i++)
{
	CheckCollision();
}
```
	