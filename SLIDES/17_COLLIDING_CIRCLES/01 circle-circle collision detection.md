# Introduction

And we are finally here.  
So after we spoke about these ideas of having forces being applied and we have this rigid bodies, nothing more natural than testing this collision between rigid bodies.  
Right?  
If we have all these circles, these shapes around, now we have boxes rotating, we have torque, we have several things working in our favor, but we need to test if things are colliding.  
Right?  

---

# Discrete Simulation

What happens if we are simulating our two circles here?  
They have this forces, they have this velocity.  
And then as we are in this discrete step by step simulation, frame by frame, several frames per second, each one of those simulation steps.  
We go and we have to update the position of my rigid bodies.  
So they have to go and they move a little bit there.  
And then with that force, we find acceleration, we find the velocity and that velocity changes the position.  
And then we go and we update to the new position.  
We estimate where the objects should go and then they go that direction.  
They are getting closer and closer to each other, but the movement is not continuous, right?  
We are in this discrete simulation step frame per frame.  

---

# Collision Scenario

So the natural order of things here, after we go and we estimate the new position and we move them closer to each other, we are going to next step, get closer, next step, closer.  
And then eventually we will eventually reach this situation right here, this scenario.  
Where our rigid bodies, the shape of our rigid bodies is colliding, right?  
We have this overlap between the shapes.  
This is collision for us.  
So we are going to have to understand what happens in that situation right there.  

---

# Two Parts of Collision Handling

Actually we are going to separate this problem into two parts.  
The first part is detecting a collision, so true or false, right?  
We have to go and analyze the shapes, compare every object in our scene with every other rigid body in our scene and check if they are colliding, true or false.  
So this is detection.  

And then the second part, if we detect this overlap, if we detect this intersection, then we have to learn how to resolve that collision, right?  
So not only detecting, we have to know how do we go and we resolve this collision, right?  
So how do we move these objects apart, so they are not colliding anymore, or maybe we have to apply some impulses to give this more realistic effect of what we would expect these objects to how these objects should be.  

---

# Focus on Collision Detection

This is what we are talking about, right?  
Detecting collisions.  
And I want to focus first on this area of detecting collisions.  
You will see that depending on the shape, depending on how is going to be the geometry of our rigid bodies, detecting the collisions can be easier or harder and it can be faster or slower for the machine.  
So we are going to have to learn a couple of tricks, a couple of techniques that go and improve the performance, how do we check if objects are colliding or not.  

---

# Starting Simple: Circle vs Circle

And I want to start with the simplest of the examples which is this one right here, circle with circle collision.  
So whenever we have two circles and we have to check if they are colliding, I'm going to use a term that I usually don't like to use, but this thing is pretty much trivial, right?  
Whenever we have two circles, if we have the radius of those two circles and we have the idea of the distance, checking true or false, right, is Boolean outcome, is it colliding or not?  
It's pretty easy to understand.  
All we have to do is basically say, if the distance, right, if I get the distance between A and B, if the distance between is rigid bodies, A and B, is less than the sum of the two radios, then collision is true, right?  
Then we have detected a collision between these two objects.  

Pretty easy, pretty simple.  
This is pretty much the easiest collision detection that we have between these two circle shapes.  
And this is so easy that we're going to start with this one right here.  

---

# High-Level Algorithm

The algorithm, this high level is this thing, right?  
If the distance between the two bodies, A and B is less than the sum of the radios, of the radios of those two rigid bodies, we have a collision, right?  
We have detected a collision.  

---

# Implementation Plan

And I am going to throw you in the deep waters and already showing the code of how I think we have to go and solve this thing in our physics engine, right?  
So the first thing that I want to do is, I want to have a new class, right?  
I want to have a new struct, and then we want to have a couple of methods, right?  
And the first method is going to be this big method called escoliding.  

And as you can see here, this collision detection class is going to have the escoliding method.  
And I am going to pass a pointer to those two rigid bodies.  
And I'm calling them in the parameters A and B.  
So I'm basically going to check, E is rigid body, A, colliding with rigid body B.  

But so far, I don't know the shapes, right?  
I don't know the geometry of those rigid bodies.  
They can be boxes, they can be polygons, they can be some weird shape that I still don't know.  
I have to check.  
I have to say Boolean, A is circle and B is circle.  
So I'm just performing a simple check, A shape, get type equals equals circle, B shape, get type equals equals circles.  

---

# Circle-to-Circle Collision

So these two Boolean variables, if A is circle and B is circle.  
So if I'm talking about a circle with circle collision check, then I'm going to say return is colliding circle circle A and B.  
This is colliding circle circle A and B is a new method that I'm going to have here, that is responsible for detecting circle with circle collision.  
Right?  
So this method right here is only responsible for checking circle with circle collision, detecting collisions between circle and circle.  

---

# Inside the Implementation

Let's look at it on how I kind of implement to this thing.  
You will see that I received those pointers again to those two bodies.  
I know that they're going to be circle shape, right?  
I just tested here.  
So I'm going to fat and get the shape of the circle A, the shape of the circle B.  
I'm going to have a vector that I'm calling it A, B, which is going to be the vector of the distance between A and B.  
Right?  
So B position minus A position.  
There's two rigid bodies that I have.  
I subtract B minus A.  
I'm going to have a vector that is pointing from A to B.  
So this vector A, B right here is going to be super useful for us because I need to check the radius of the circles with that distance, right?  
With the length of this vector A, B.  

---

# Radius Sum and Magnitude Check

So I'm going to calculate something important, which is called the radius sum.  
And the radius sum is the shape of the A radius plus the shape of the B radius.  
Right?  
So I have the distance.  
I have the vector A, B, and I have the sum of the two radii.  
Right?  
And then my e-scoliding Boolean variable is says vectorab dot magnitude squared.  
And I'm using magnitude squared to get the length because I can check with the radius sum squared.  
Right?  
So if I get the magnitude squared and I compare, if it is less than the radius sum squared, I can get away without taking that expensive square root, remember of the magnitude.  

So magnitude squared in this case, if I'm just comparing, if the magnitude is less than the sum of the radii, I can use magnitude squared.  
That is a good case here for me.  

---

# Boolean Collision Test

So if the magnitude squared of the vector A, B, that vector between A and B is less than or equal the radius sum, right?  
The sum of the radii is squared in this case.  
I'm going to get true or false.  
If it is colliding or not, and then all I have to do is just return is colliding back to my detection function.  
So this function detects collision between circles.  

---

# Future Work

And you see how I have a two-do here besides checking circle with circle collision.  
Of course, I'm going to have in the very near future.  
I'm going to have box with box.  
I'm going to have box with circle.  
I'm going to have box with polygon or polygon with circle.  
I'm going to have polygon with some weird curve thing.  
I don't know, right?  
We're going to have to check how many shape we're going to implement.  
But here it is, I would to do for the future.  
Right?  

Right now, we are only considering circle with circle, but we're going to have to check box with circle, box with box, polygon with triangle and etc.  
So we're going to have several checks.  
This marked thing to do is.  

---

# Implementation in Code

Now that we have this thing warm in our mind, let's just go to the source code, quickly create this collision detection class.  
And as soon as we have the colliding detection, we have this big method that is going to be, this method is almost going to be like a multiplexer, right?  
It's going to receive those two bodies and it's going to call the correct function depending on the type of the shape.  
Are we talking about two circles then we go for this method?  
Are we talking about a circle and a box? Then we go for another method.  
Are we talking about a polygon and a circle? We go to another method.  

---

# Conclusion

So this thing right here is going to basically go in fork to this special methods, but this is our entry door.  
Right? We have to check if these two related bodies are colliding.  
And then we go to this specific check circle with circle collision.  

Oh good. So let's just quickly go to the source code and start implementing this new collision detection class that we have.  
Let's start just creating this methods because very soon we're going to have to learn the sites detecting.  
We have to also talk about collision resolution.  
Right? So if we detected collision, how do we go about resolving, right? Moving those objects apart so they are not colliding anymore.  
And that is what we're going to see very soon.
