**Angular Velocity Direction**

You just saw that we are storing the angular velocity as a single scalar float value in our code. I just want to take some time to explain the reasoning behind this value and also reflect on the direction of this angular velocity.

If we were talking about objects in 3 dimensions, the angular velocity would be a 3D vector. This _angular velocity_ vector would be **_perpendicular_** to the _linear velocity_ vector.

![[medias/angular3d.png]]

Since we are implementing a 2D physics engine and our linear velocity is a 2D vector defined only on the _x-y_ plane, the angular velocity is a vector in the **_z_** direction (since our objects rotate around their center of mass). We could try to imagine that the direction of this angular velocity as pointing inside the screen.

![[medias/angular2d.png]]

And this is why, for simplicity, our implementation stores the angular velocity as a simple scalar/float representing the _z-component_ **magnitude** of this vector.