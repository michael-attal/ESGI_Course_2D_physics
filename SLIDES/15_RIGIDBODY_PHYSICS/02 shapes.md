# Transition to Angular Motion and Shapes

Very well.  
So we moved everything from particle and now we have this class which is called body, right?  
We still have those ideas of linear movement, right?  
So position velocity and acceleration that we have still the sum forces, but let's just think about this.  

Our body, now we have to accomplish a couple of expert things.  
We need to have a to-do here which is we have to think about angular motion.  

So besides having the linear motion position, the loss in acceleration, it is linear fashion.  
We have now this angular motion, right?  
And we're going to have to start to discuss this very soon, right?  
The angle, the idea of angular acceleration, angular velocity, torque.  
So we're going to study this very, very soon.  

I just want to point out that besides having the sum of forces, the mass and the inverse of the mass, right?  
The reciprocal of the mass, we are going to have now this thing right here which is going to be a pointer to the geometry or the shape of our rigid body.  
And I have their shape, pointer, shape, which I'm just starting that pointer with no, right?  
So I'm going to hold a pointer to that shape class, right?  
A pointer to a shape object.  

And this shape right here, we are going to define and then we're going to have classes for polygons, circles, square, but they are all going to inherit from the parent class shape.  
That is why I have this shape pointer, right?  
That's it, right?  
Normal, simplest, plus stuff, just holding the pointer of my geometry, of my shape.  

And everything here is pretty much the same, a constructor, oh, just pointing out that the constructor.  
I am passing what is the const shape, shape, type.  
So I can pass a shape whenever I'm creating my body.  
So I can create my body, passing the box, shape, passing the circle, shape, passing the polygons, shape.  
So I can already construct a body, passing the shape that I want that body to be.  

The structure at force clear forces the same thing ahead before and the integrate function of course, just to go there and integrate acceleration, velocity, find the position, you know, move things around.  

---

# Shape Class Overview

Very well, so I want to quickly look at this shape class, I think that is going to be very simple, we inheritance approach, right?  
This object oriented inheritance.  

So I'm going to have a parent class called shape, which it has a structure by default.  
And I also have something called GAT type, which is going to return that shape type, remember that enumeration, circle, polygon, box.  
I can ask my shape to say, why is your type?  
And then the GAT type function, it's going, I'm going to override in this classes that I'm going to inherit.  
I just say GAT type, return circle.  
So I know what is the type of that shape.  

And we are going to have a couple of extra methods and functions.  
One of them is called GAT moment of inertia.  
Don't worry about this too much, we are going to explain this in the next lecture, moment of inertia has to do with mass, so each shape has a different moment of inertia, right? How it rotates.  
So we're going to learn how to calculate this moment of inertia very soon.  
But just think for now that we have methods and we can just basically override this methods in our child classes.  

---

# Circle Shape

For example, right, we have something called a circle shape.  
So I'm going to have this struct circle shape, which inherits from public shape.  
And look at what I have inside my circle, I have a float radius, right?  
It only makes sense for us to think about radius if we're talking about the circle shape.  
So I have the radius in my circle shape.  

I have a constructor, a structure, I have a GAT type.  
This GAT type right here is probably going to be return circle, right? That enumeration circle and GAT moment of inertia, we're going to have to override and implement the calculation of the moment of inertia.  
Again, don't worry about it too much, we have this circle shape.  

---

# Polygon Shape

And besides the circle, we are going to have a polygon shape, right?  
So class struct polygon shape inheriting from the parent class shape and look at what my polygon has.  
My polygon has a vector, has a list of vector two vertices, right? Makes sense that a polygon is a list of vector of several vertices, vector two, right? Two D vertices.  

And then we have a constructor, polygon shape, which is the default constructor.  
We have a constructor that I can pass already the list of vector, which is going to be my list of vertices.  
So if I want to create a polygon, I can pass already the vector with a list of vector two vertices.  
I have a destructor and I have the GAT moment of inertia again, which we are going to see very soon.  

---

# Box Shape

So we have a circle, we have a polygon and I took the liberty of thinking about this scenario, thinking that we're going to have a box shape, which is going to be this box with width and height.  
But a box shape, do we all agree that inherits from polygon shape and a box is basically a four-sided polygon?  

So again, this is kind of the structure, the whole object oriented approach, the class diagram that I'm coming up with this shape class.  
So our body has a pointer to a shape and our shape can be either circle, we can be a polygon.  
I'm representing three sides here, but we can have four vertices, five vertices, one hundred vertex polygons, right?  
This thing is going to be a convex polygon, right?  

I'm going to discuss the difference between convex and concave polygons very soon, but just remember that these polygons that we're going to represent with this class right here, we are only going to work with convex polygons, all right?  

And then we have this special polygon, which is our box that has a width and height.  
And then I can create a box shape passing the width and the height as parameter, probably this constructor is going to go there and initialize the vertices of my box.  
And then I can destruct box shape, get moment of inertia, all of those things.  

---

# Implementation Plan

So this thing that you're seeing right here in your screen, this is the class diagram that I'm going to use to represent this ideas of a shape, right?  
So we are working with circles, polygons, and this special polygon, which is a box, this box that can be rotated, that can collide, bounce, back and forth, these are my geometry.  

If I these are the shapes that we can attach to our rigid bodies in our physics engine.  
Does this own make sense? I think so, let's just do what we usually do.  

Let's go to the code editor, let's start implementing and coding our shape class, coding our circle class, polygon class, you will see that we will start by coding our circle class first.  

Because circles, they are pretty much the simplest type of shape that we can work with.  
It is a lot easier to think about collisions of circles, it's a lot easier to think about moving circles and drawing circles.  

And so probably notice our particles. Yes, sure, in this conceptual idea, they were just a little point.  
But we were already thinking of particles, almost like this small circle, right? That collided with the window, the bounce, back and forth.  

So circles are going to be the first shape that we're going to look at and implement.  
And after we get everything correctly done with circles, then we move to polygons.  
And then after we have polygons ready, then it's just a matter of going and doing a couple of more things to account for this special polygon which is our box class.  

So let's just go to the code editor and let's start implementing our bodies and our shapes.
