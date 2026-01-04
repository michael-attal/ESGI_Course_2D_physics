```cpp
// application.cpp
Body* bob = new Body() // mass = 0.0
Body* head = ...
Body* torso = ...
Body* leftArm = ...
 
//(...);
JointConstraint* neck = new JointConstraint(head, torso, head->position+Vec2(0,25)); 
```