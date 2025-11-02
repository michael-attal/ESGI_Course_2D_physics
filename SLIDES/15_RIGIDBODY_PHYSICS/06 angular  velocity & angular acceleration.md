# Introduction

All right, so we have a new territory to explore here, which is this idea of rotating our object, right?  
We have not just simply linear motion, right? This is the whole idea of displacement, velocity, acceleration.  
Now we have to go and we have to start thinking about this rotation.  
We are talking about rotation, right? This spin around the center of mass.  
We are not talking about rotation, as you will usually see, in the sense of orbiting around a point in the world.  
So we are talking about rotating this object around its own center of mass.  
We saw that before, we use that little float angle parameter in our circle draw function, but we were not doing anything formal regarding the body's angle of rotation, right?  
We were just passing an angle to draw, but our body entity, our body class, doesn’t have a rotation angle inside, and this is what we're going to look right now.  
We are going to talk about this spin, this rotation motion.  
So we have to start talking about these two important ideas, angular velocity and angular acceleration.  
#physics/angular-motion  

# Angular Velocity and Acceleration

All right, so if you think about, intuitively, what that means, we're going to have a velocity which is the rate of change of that angle, right?  
So as we increment the angle, we have a velocity and if the velocity changes, that rate of change increases, we have an acceleration of that angular velocity.  
As a body rotates, we're going to have an angle and I'm using the tata ladder there, the Greek ladder tata to represent the angle of rotation.  
The rate of change of that angle tata, as per unit of time, is called the angular velocity.  
And we are going to use that Greek ladder omega for the angular velocity, as we have that rate of change in the angle, is going to be the omega ladder, the angular velocity.  
#physics/angular-velocity  

# Relationship with Linear Motion

Remember before, the velocity before was the displacement of the position, so the change in position divided by our delta time.  
And in the angular case right now, our velocity and these two things are analogous, right?  
The linear velocity and the angular velocity is going to be the change in the angle divided by the delta time divided by our unit of time.  
Linear velocity angular velocity.  
And you probably know, we're ready, they're going to have the idea of acceleration.  
So likewise, as our body still rotates, the rate of change of our angular velocity.  
So the rate of change of the angular velocity, or unit of time, it's called angular acceleration.  
And we're going to use for angular acceleration, we're going to use the Greek ladder alpha.  
This is classic, right? If you look at any physics book using omega for the angular velocity and alpha for the angular acceleration, this is pretty standard.  
#physics/angular-acceleration  

# Linear and Angular Kinematics

So here we go, again, two things that are analogous, the linear movement and the angular movement.  
If before we have V for velocity and omega for the angular velocity, we have for linear, before A, the linear acceleration was delta V divided by delta T.  
And now we have in the angular side, we have the alpha, which is our angular acceleration, which is the difference in the velocity, the changing velocity divided by time.  
You see, linear and angular, they pretty much deal with the same changes of unit, right?  
But one deals with this changing position, the linear position, changing linear velocity, and this one deals with changing angular, right?  
This angle in radiance and this changing the angular velocity also in radiance.  
#physics/kinematics  

# Units and Representation

You will see that always, right? The standard unit of measurement of this angle is always going to be radiance, not degrees.  
So whenever we are coding in our programming language, most graphics frameworks, most physics frameworks, they will always input our angles as radians.  
#physics/units  

# Linear and Angular Kinematics Relationship

Very well, so I just want to leave this image right here, because I want us to always remember this relationship between linear kinematics and angular kinematics.  
So do you see, we have these ideas of linear before and in the left side, you have all those formulas that we already covered,  
the velocity, which is the changing position over time, the acceleration, which is the changing velocity over time.  
And then remember those formulas also to find the velocity for this kinematics problem where force is not being considered.  
So the velocity is the v0, the initial velocity plus a t, and also the change in position is going to be v0 times the time plus a t squared divided by 2.  
That was linear kinematics, right? All those formulas that we had, that we were not considering forces that we are applying in our objects.  
And we have what I'm calling it, the analogous angular kinematics formulas, right?  
#physics/formulas  

# Angular Kinematics Formulas

So we have the angular velocity, which is the change in the angle divided by delta time.  
And then we have the angular acceleration, which is the changing angular velocity divided by delta time.  
And then we have also, again, the analogous formula, which is the angular velocity comes from the initial angular velocity omega 0 plus alpha t, right?  
The angular acceleration times the time.  
And the last one, the changing the angle theta comes from the initial angular velocity omega 0 times time, plus the angular acceleration alpha times time squared divided by 2.  
Do you see the relationship between linear kinematics and angular kinematics, the left and the right side?  
It is pretty much just the matter of coming here and replacing v and a by omega and alpha.  
#physics/angular-kinematics  

# Implementation in the Body Class

So that means that if I come here to an analysis of my body class, my stroke body, do you remember how we had all those linear motion quantities like position velocity acceleration and also the sum of the forces we had the idea of the mass and the inverse mass?  
We will have to add in our bodies, these ideas of angular velocity and angular acceleration, right?  
The rate of change of the angle, per unit of time, and the rate of change of the velocity per unit of time.  
I'm going to have to go there and declare what we call my angular motion quantities inside my body.  
And we're going to have a float rotation and this rotation is this rotation angle right here which is going to measure in radiance where we are rotated with that body.  
We're going to have what I'm calling the float angular velocity and float angular acceleration and pay attention how angular velocity and angular acceleration, they are not that chosen anymore.  
In our 2D space, angular velocity and angular acceleration, these things I can basically measure with a scalar number.  
#physics/implementation  

# Scalar Representation in 2D

So how fast is that angle changing per time? I'm changing our radiance angle, right?  
I'm not changing a vector velocity. I'm not changing a vector acceleration or vector position.  
I am changing our radiance, right? I'm changing the angle.  
So how much we are changing that angle? I can represent with a single scalar of floating point number angular velocity.  
And likewise, the angular acceleration is also going to be a floating point number as scalar in this 2D scene, right?  
If we are talking about 3D, we are going to see that these things become vectors and then the computations are a little bit more complicated,  
but since we are talking purely 2D in this case, float float and float, right?  
The pattern angle, the omega and the alpha, rotation, angular velocity and angular acceleration, float float and float.  
#physics/2d-vs-3d  

# Integration Function

And I want us to think also that we have to change our integration function.  
Right? So do you remember how we had those integration functions where we have to integrate the acceleration, the linear acceleration to find the linear velocity and integrate the linear velocity to find the linear position?  
I am going to create something called integrate angular, where I am going to say angular velocity plus equals the angular acceleration times the delta time and the rotation meaning my angle, which is the analogous of the position before.  
So the rotation plus equals angular velocity times dt.  
This thing that you're seeing right here, if you want to pause and really understand what's going on, this is my oiler integration, but now for angular motion.  
Do you agree? This thing right here is exactly what we had before for linear movement?  
Now we are creating this integrate angular, which is going to be performed together with the linear integration,  
but now the integrate angular is going to integrate the angular acceleration to find the new angular velocity and integrate angular velocity to find the final rotation, right?  
My tata angle here in the rotation of the spin of my object.  
#physics/integration  

# Conclusion and Next Steps

There you go. This is what I wanted to cover right now.  
This is basically these ideas of using angular acceleration, angular velocity, this angular motion with our object, thinking about acceleration and velocity, right?  
These ideas of kinematics.  
But the question now is this? Well, this is how good and fine we can think about the velocity acceleration, but do you remember that from before?  
The only way that we could start moving an object, accelerating an object, was by applying a force to it or applying force to it, right? This linear force.  
So if before, the only way I could start a movement, the only way that an object could start moving, accelerating was if I apply a linear force to it.  
How do we go about now initiating rotational motion? Meaning in other words, how do we go about initiating that angular acceleration?  
How do we change the angular acceleration in the first place?  
The answer to that question is something called torque.  
We're going to apply a torque force to our object to start accelerating this angular velocity and the angular acceleration of my object, right?  
Start this rotation motion.  
So torque is something that we're going to study in this next chapter.  
I went to dedicate an entire lesson on these two concepts. One is called torque and something super interesting, which is called moment of inertia.  
So without further ado, let's look at what torque and moment of inertia video are.  
#physics/torque, #physics/moment-of-inertia  
