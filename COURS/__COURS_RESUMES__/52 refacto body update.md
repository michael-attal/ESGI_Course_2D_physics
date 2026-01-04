```cpp
// cosntraint.h
void JointConstraint::Solve()
{
	//TODO: load the jacobian matrix
	
	//TODO: V=GetVelocities() // velocities
	//TODO: invM=GetInvM() // inverse mass matrix
	
	//TODO: Compute lambda (impulse magnitude)
	
	//TODO: Apply the lambda impulse to A and B
}
// world.cpp

void world::Update(float dt)
{
	for(auto body: bodies)
	{
		Vec2 weight = Vec2(0.0, body->mass * G * PIXELS_PER_METER);
		body->AddForce(weight);
		
		for(auto force: forces)
			body->AddForce(force);
		
		for(auto torque: torques)
			body->AddTorque(torque);
	}
	
	/* 	
	for(auto body: bodies)
	{
		// integration of velocities + convert to world space
		body->Update(dt);
	} 
	*/
	
	//1. integrate all forces (a= F/m)
	for(auto body: bodies)
	{
		body->IntegrateForces(dt);
	}
	//2. solve all constraints ! (appliquer les impulses)
	for(auto& constraint: constraints)
		constraint->Solve();
	
	//3. Integrate velocities (update vertices)
	for(auto body: bodies)
	{
		body->IntegrateVelocities(dt);
	}
		
	CheckCollisions();
}
```

```cpp
/*
refacto pour solve les contraintes
*/
// body.h
void IntegrateForces(const float dt);
void IntegrateVelocities(const float dt);
// body.cpp

// plus de séparation entre linéaire et angulaire
// mais sépration entre intégration de l accélération et la vélocité
void Body::IntegrateForces(const float dt){
	if(IsStatic()) return;
	//linear
	acceleration = sumForces*invM;
	velocity += acceleration * dt;
	
	//angular
	angularAcceleration = sumTorque*invI;
	angularVelocity += angularAcceleration*dt;
	
	//reset
	ClearForces();
	ClearTorque();
}

void Body::IntegrateVelocities(const float dt){
	if(IsStatic()) return;
	//linear
	position += velocity * dt;
	//angular
	roation += angularVelocity*dt; 
	
	// update the vertices to world space
	shape->UpdateVertices(rotation, position);
	
}


```

