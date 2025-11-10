# References
https://en.wikipedia.org/wiki/List_of_moments_of_inertia

# Introduction

All right, very well, so we just learned that we have these ideas of angular velocity and angular acceleration, which is analogous to what we had before in the linear velocity and linear acceleration, right, but now considering this rotation around the certain axis.  

# How to Start Angular Acceleration

And the last question was, all right, so how do we start accelerating in the first place? Right, so how can we change that acceleration, right, to begin accelerating an object in this angular motion, and the answer to that was torque. You will see that we can initiate a rotational motion by applying a torque force to our object, and you will see most books used the Greek letter tau to represent torque. Torque is defined as the ability of a force to rotate an object around a certain axis.  

# Formal Definition of Torque

And I want us to start thinking about this formal idea of what torque is really about. Well, I'm going to show a formula here, don't worry about the crazy formula. It means that the torque force is equal to an initial force vector times a distance the times the sine of an angle data. What does this mean? This thing right here is the actual formal definition in mechanics of this torque force. And I want to explain what f is in this formula, what d is in this formula and what this angle data represents in our torque force formula.  

# Force, Distance, and Angle

If we look in this scenario right here, I have an object, I have a little center of mass which is going to be the axis that I want to rotate around, and I want to rotate. Let's think that I want to rotate this line right here, counterclockwise. For me to rotate something, I am going to apply a certain force right here, so I can apply a force right here. But that force, I can apply the direction of this force can be right here or it can be this way, right? So what is the direction of the force? This is where our angle beta comes into play, right? So this angle beta right here, the sine of the angle beta is going to come from this angle that is from our object, right?  

# Effect of Angle on Torque

This axis n, the force f that I'm trying to apply. I can apply a force right here or I can apply a force in this direction where the angle is less than, which means that the torque, the rotation, the torque force is going to be a lot greater if it is 90 degrees, right? Where my sine of the angle is the greater value, then it is if I apply like this. So if it is zero degrees, then it's going to be no torque. I cannot rotate. Do you see where we're going with this?  

# Maximum Torque and the Sine Function

If I apply a force here or if I apply a force right here, it's going the maximum torque force is going to come from this angle right here where I have 90 degrees. That is why I have this multiplication by the sine of the angle beta. So the torque force, this rotation force, has to do with the angle of that force that I'm applying on that object, but also I have what I'm calling the D, right?  

# The Role of Distance (D)

So that D is the distance of the center and the actual where I'm applying that force. Again, think if you are trying to open a door, it is a lot easier to open the door and rotate a door if you push closer to the handle, then it is if you try to push that door closer to the hinge. So if you hit the maximum rotation, you're going to apply a force closer to the hand, right? So you can just push and that door is going to rotate a lot more.  

# Components of Torque

This is why we have this deep, which is the distance of where we are applying that force in comparison to the center of the rotation. So the torque force comes from the force that we are applying. The distance from the lever here, the distance from the center of how we want to rotate the axis and the angle, the direction of that force, how we apply, are we applying like these, are we applying like these? So how we apply the direction, plays a part in how strong that torque force release.  

# Simplifying Torque for Physics Engines

This is kind of the formal definition that you will see in most physics books of the torque, but I want to point out that we are not going to use exactly this formula in our physics engine. We are going to simplify our problem a lot. We are going to look at torque, almost like we were looking at that idea of force before.  

# Torque and Angular Acceleration Analogy

Remember the linear force F equals M8. We are going to have torque and moment of inertia, so torque is going to be the objects. Moment of inertia, multiply by its angular acceleration. How equals moment of inertia, I times a, this thing right here is analogous to F equals M8. Force equals mass times acceleration, torque equals moment of inertia times acceleration, angular acceleration.  

# Understanding Moment of Inertia

So I want us to always remember that the torque is the force that we apply, and moment of inertia is going to be this measurement of how hard it is to accelerate something angular, right in this rotation motion. So if this thing is true, if this is analogous to F equals to M8, doing simple algebra, I can find that the angular acceleration is the torque force divided by the moment of inertia.  

# Relationship Between Torque, Force, and Inertia

You see how the moment of inertia is very similar to what mass was before in the linear motion. angular acceleration, right, acceleration is equal to the force divided by the moment of inertia now. Before we were dividing by the mass, now we divide this moment of inertia. So torque is analogous to force from this linear movement before, and moment of inertia is analogous to what mass was before in our linear motion.  

# Moment of Inertia and Shape

So there you have it on the screen, linear and angular motion before I had force and mass. Now I have torque and moment of inertia, which we are representing with the capital I letter, by this upper case I letter, and you will see most physics books and most physics engine use for the moment of inertia and upper case I. Right, so let's just quickly just zoom in a little bit in this moment of inertia right here.  

# Calculating Moment of Inertia

We just found out that moment of inertia is that analogous to mass before. So we divide the force by the moment of inertia, and if we just want to look at it again, moment of inertia, the upper case I is analogous to mass and measures how much an object exists to change its angular acceleration.  

# Examples of Shapes and Formulas

So do you see the same way that mass was how hard was for an object to start moving linearly before, now we have this moment of inertia I, which tells us how difficult it is for an object to start moving angular, right, this rotation. That is what moment of inertia is really all about. Moment of inertia is inversely proportional to the angular acceleration.  

# Moment of Inertia in Practice

I think it is clear for everyone now that the moment of inertia is in the denominator of the fraction. So the bigger the moment of inertia, the smaller is going to be my angular acceleration. The smaller the moment of inertia of the object, the bigger is going to be its angular acceleration.  

# Moment of Inertia in Different Shapes

And I guess no surprises here, right? Since we have the same ideas before for force, mass, and acceleration linear, now we have everything for this angular motion, this rotation, where moment of inertia is exactly what we expect from the mass before. The question now is, okay, so how do we get this value and why is this value? So what is it represent for us in terms of units of measurement?  

# Shape-Dependent Moment of Inertia

Well, there we go, so we are going to have different values of moment of inertia for different shapes. So depending on the shape, if it is a circle, if it is a square, if it is a rectangle, if it is a weird polygon, we are going to have to calculate this moment of inertia because how we rotate and how hard it is to rotate.  

# Examples: Circle and Rectangle

Circle is different than how hard it is to rotate rectangle, and it is how hard it is to rotate a triangle. So we are going to have to calculate based on the shapes. And just to give you some examples, I am going to point out that. I pointed out two shapes, a solid circle and a solid rectangle. And the moment of inertia for these two shapes, the first one, the solid circle is the radius squared divided by two times the mass of my object.  

# Mass and Inertia Relationship

And again, it is no surprise that the mass plays a part in calculating the moment of inertia, because if I have an object with a bigger mass, it is going to be harder to rotate. So that is why we see the mass playing a part in these formulas of the moment of inertia of these different shapes.  

# Rectangle Moment of Inertia

And if we look at the rectangle down there, it is going to be the width of the rectangle squared plus the height of the rectangle squared, everything divided by 12 times the mass of the object, of course, again.  

# Wikipedia Reference and Examples

And this whole concept of moment of inertia is so interesting. If we come here quickly and we open, for example, the Wikipedia page of this moment of inertia. Of course, I'm not going to read everything here, but if you look at the moment of inertia, otherwise known as the mass moment of inertia, the angular mass, I really like this name right here, angular mass.  

# Angular Mass Concept

And if it was by me, I would make every physics book use this name, angular mass. So these ideas of moment of inertia, angular mass is basically a quantity that determines the torque needed for a desired angular acceleration about a certain rotational axis, which is pretty much what we said before on the slides.  

# Comparison with Linear Acceleration

And which is similar to how mass determines the force needed for a desired acceleration. And this thing is linear acceleration, right? Now, it depends on the body's mass distribution and the axis chosen. With larger moments requiring more torque to change the body's rate of rotation.  

# Examples of Moment of Inertia Formulas

There's a lot of explanation here in a lot of interesting theory and formal definitions. But what I want to point out is, right here, we have some examples. Let's see if I can find some examples of shapes. I think down here, yes, so we have some examples, may article list moments of inertia.  

# Circle Example

Here we go. So here, this Wikipedia page, you list some popular shapes and moments of inertia that we can just quickly go and find a formula. So if you come down here, let's say some moments of inertia, if we have a point mass, right? So a point mass at a certain distance are. So if I have a little point mass, kind of orbiting around and we want to calculate the moment of inertia of this thing, we have a formula.  

# Rod and Disk Example

I think the ones, if you have a rod rotating at a certain length, if it is rotating at this end right here, I think this one is the one that I want to look out. So if we have a circular loop, this is our circle, right? So if we have a thin solid disk of radius r and mass m. So this is exactly what we have. We have to calculate the rotation around this z axis right here.  

# Formula Recap

So the moment of inertia at we rotate at the z axis is equal to one half times the mass times r squared. Which is exactly the same formula that I showed you before for this circle.  

# Implementing in Code

So we are going to use these formula right here to calculate the moment of inertia of our circle shape. And then if you have something different, you can come here. We have this cylindrical shell, which we can apply this formula. If you have a solid cylinder with these radius, we have other formulas.  

# Transition to 3D

Okay, and then if you enter these ideas of 3D as sphere above, but if we move from 2D to 3D, then moment of inertia becomes a little bit more complicated.  

# Inertia Tensor in 3D

And you will see in our future 3D physics course that calculating this 3D moment of inertia is not going to be just a simple number. We are going to have what we call an inertia tensor, which is basically this matrix with several numbers that dictate what happens with each one of the axis.  

# Back to 2D Context

And that is super interesting, but since we are talking only about 2D here, I'm not going to go into too much detail about that.  

# Recap of 2D Shapes

But here we have these two fifths of a sphere. If we go down, we have some other shapes, right, a torus, lip side, a rectangle. So if we want to rotate a rectangle around the center of mass right here in the center, would you look at that? Look at this formula exactly the same formula that I saw before.  

# Formula Confirmation

The moment of inertia in the center of the rectangle comes from one divided by 12 times the mass times the height of the rectangle squared plus the width of the rectangle squared. Exactly what we saw before in this light.  

# Circle and Rectangle Recap

So this one was the formula that we saw for the moment of inertia of the solid disk, our circle, and this one was the rectangle, right? The width squared plus high square divided by 12 times the mass.  

# Implementing in Code (Shapes)

Okay, maybe just changing the elements a little bit, but the formula is exactly the same. And thinking about the moment of inertia, I want to look again at those formulas for the circle and the rectangle, and I want to start looking at implementing these things in code.  

# Circle Shape Implementation

So we stop, how are we going to implement this her shape moment of inertia value? But I was thinking about that and look at what I have in my circle shape, I'm going to have a method called get moment of inertia, which simply returns one half times radius squared.  

# Adding Mass to Calculation

Okay, so this thing right here, the circle shape moment of inertia will only return one half like 0.5 times radius squared. But do you see how we are still missing the mass of this calculation?  

# Mass in Body Constructor

Of course, because the mass is not in my shape, the mass is in my body strength. So I am going to have to calculate the one half times the radius square, but this steel needs to be multiplied by the rigid body's mass.  

# Constructor and Shape Link

And the way that I'm going to do that is, if we look at the body constrictor method, whenever we initialize the shape, the position, the acceleration, I also went to initialize the i, the moment of inertia, which is going to come from the shape of that rigid body dot, get moment of inertia netted, times the mass of my rigid body.  

# Combining Shape and Body Data

All right, do you see how we are dividing the problem? So the shape calculates the part of the shape, and then I come back to my body and then I just multiply by the rigid body's mass. And that is going to work for other shapes as well.  

# Box Shape Example

So if I have a box shape, I can say box shape, get moment of inertia is going to return one divided by 12, which is that formula up there for the solid rectangle. So one divided by 12 times with squared plus high squared.  

# Separation of Concerns

This is only the shape arc, but then I have to go to my rigid body and multiply by the mass. Because the mass only exists in the context of the body class, right? So I hope this makes sense.  

# Integration: Linear and Angular

We're going to divide. We're going to have a get moment of inertia in the circle shape, get moment of inertia in the body shape. But right here in the constructor is where we actually calculate the final upper case i moment of inertia of that rigid body.  

# Linear Integration Recap

By multiplying the shape moment of inertia numbers by the mass of my rigid body to finally get that ultimate formula that we want. Oh good. And just to finalize this topic, think about linear integration and angular integration.  

# Angular Integration Explanation

So if before we had what we call the linear integration, I'm going to separate our integrate functions into two functions. The first one is going to be a linear integration where we find the acceleration by dividing the force by the mass. So we multiply some of the forces time the inverse of the mass.  

# Angular Integration Details

And then we integrate acceleration to find the linear velocity. We integrate the linear velocity to find the position of my object. This is what we were doing before clearing the forces at the end. But now I'm going to have what I call integrate angular, which is going to be very similar to this one above, but it's related to the angular motion.  

# Storing Inverse of Inertia

So i need to find the angular acceleration which comes from the sum of all the torque forces times the inverse of the moment of inertia. So do you see how we are going to have to store the inverse of the moment of inertia the same way that we were storing the inverse of the mass.  

# Angular Integration Summary

That is going to be true for us as well. The inverse of the moment of inertia, the reciprocal of the moment of inertia is going to be more useful for us than the pure moment of inertia. And then to find the same thing, right to find the angular velocity.  

# Rotation and Torque

I integrate the angular acceleration times delta. See, and to find the rotation, I increase by the angular velocity times delta t. And I'm also calling the clear torques. So I'm going to have to clear all the torque forces as well. Pretty similar these two functions, one deals with linear integration, the other one angular integration. They are both going to be super useful for us.  

# Conclusion

Let's do that. Let's just go to the source code now and let's start implementing all this code changes that we just saw on the slides. There is a lot that we have to implement. I am going to pretty much copy and paste most of these useful functions that we just saw on this slide. So we don't have to type everything from scratch again. But hopefully the main idea is behind torque, moment of inertia, these ideas of angular acceleration, angular velocity. Now things a little bit clear in your mind is just a matter of going implementing and let's see if we can just go apply a torque. Now to our objects the same way that we were applying a force before. Let's see if we can apply a torque and see if our object starts to rotate with this angular velocity and angular acceleration. Because what we really care right now is rotating our objects.
