```cpp
// world.h
std::vector<Constraint*> constraints;
// ...
void AddConstraint(Constraint* constraint);
std::vector<Constraint*>& GetConstraints();

// world.cpp
void AddConstraint(Constraint* constraint){
	constraints.push_back(constraint);
}

std::vector<Constraint*>& GetConstraints()
{
	return constraints;
}

// application.cpp
// Add two bodies

Body* a = new Body(CircleShape(30), Graphics::Width()/2.0, Graphics::Height()/2.0, 0.0f) 
Body* b = new Body(CircleShape(20), a->position.x - 100.0, a->position.y, 1.0f) 

// Add a joint constraint
// le point d ancrage est le centre de masse de a => on verra un pendule
Constraint* joint = new Constraint(a, b,a->position);
world.AddConstraint(joint);
```
