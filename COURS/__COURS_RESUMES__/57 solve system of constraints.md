![[medias/57 solve system of constraints 2025-12-21 11.31.23.excalidraw]]

On rajoute plusieurs bodies, plusieurs contraintes pour fabriquer une chaîne.

Marche mais il y a un problème, les impulses n'ont pas l'air assez forts.

Avec un système de contraintes, il faut résoudre le système dans son ensemble
	- global solver vs. local solver

En effet, lorsqu'on résoud une contrainte on casse le résultat de la précédente.

Il faut aborder le pb de manière **itérative** pour approcher de la solution correcte.

Solve() sera appelée plusieurs fois à chaque étape de la simulation.
Ici 50 fois.

Mais 50 est une valeur bien trop grande.

=> Technique du **warm starting**
```cpp
for(int i=0; i< 50; i++)
{
	for(auto constraint:constraints)
		constraint->Solve();
}
```


```cpp
world = new World(-9.8);
const int NUM_BODIES = 8;
for(int i=0; i< NUM_BODIES;i++)
{
	float mass = (i==0.0) ? 0.0 : 1.0;
	Body* body = new Body(BoxShape(30,30), Graphics::Width() - i*40,100,mass);
	body->SetTexture("./assets/crate.png");
	world->AddBody(body);	
}

// add joints
for(int i=0; i< NUM_BODIES-1;i++)
{
	Body* a = world->GetBodies()[i];
	Body* b = world->GetBodies()[i+1];
	JointConstraint* joint = new JointConstraint(a,b, a->position);
	world->AddConstraint(joint);
}
```

```cpp
// constraint.cpp
for(auto joint: world->GetConstraints())
{
	const Vec2 pa = joint->a->LocalSpaceToWorldSpace(joint->aPoint);
	const Vec2 pb = joint->b->LocalSpaceToWorldSpace(joint->aPoint);
	Graphics::DrawLine(pa.x,pa.y,pb.x,pb.y,0xFF555555);
	
}
```