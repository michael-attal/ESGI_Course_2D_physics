# Implementing Shape Functions

Let's start implementing the functions of shape.  
We have to get the flow radius and this thing should be simple, right?  
All I have to do is say this is equal to the parameter radius and you know what?  
You remember how I like to always write a little message in my constructor and this constructor to see if we don't have any memory leak and keep track of things.  
So I'm going to say circle shape, cross structure, and then we just of course just get things done.  
So I have a circle shape.  
I'm also going to have a constructor.  
And the constructor for now we don't have much.  
I'm just going to have circle shape, this structure.  

# Polygon and Box Shapes

And since I have now this circle, I'm going to have something very similar for the shape.  
So let me just get this one and let me do something similar for Polygon.  
But the Polygon shape.  
We receive the vertices that we need to go and initialize my vertices, right?  
But this is the thing.  
I am not going to waste our time here.  
I'm just going to say to do, because we are not going to implement Polygon right now or even box.  
I just want you to focus on circles for now.  
And this thing right here, well, we're going to have to do all these things later.  
And Polygon shape.  
Which also to do later.  
And I'm just going to go ahead and fill the constructor for the box.  
So we have this thing ready when we need it.  
Box shape.  
Let's shape.  
And the box shape, if I recall correctly.  
Let me just take inside the parentheses.  
We receive a closed width and a closed height.  
And then we're going to do the destructor as well.  
So box shape and box shape.  
I think that's it.  
I'm just saying everything.  

# Constructor Issues

Why is box shape complaining?  
Let me just see the header file.  
Why did I do wrong here?  
Constructor box shape has explicitly initialized Polygon shape.  
Did I forget to say that Polygon shape has a default constructor?  
Oh, yes, I did.  
I just declared a constructor with parameters, but I need to also.  
Polygon shape.  
So our inheritance doesn't have to explicitly declare this thing.  
Do you see?  
Since I don't want you to go and have to call polygon shape constructor in my box shape class.  
I can just say here Polygon shape equals default the constructor.  
And it does everything behind the scenes for me.  
Well, I think that's it.  
There we go.  
So now it's fixed.  
Perfect.  

# Implementing `get_type`

Let's see what else do I need to do here.  
So besides having the constructor and the structure.  
I just want to do one more thing before we move forward.  
Which is that property that method get type of each one of them.  
Alright, so here I have my circle shape.  
I need to come here and implement the get type, which is going to be off the type.  
Shape type.  
So get type.  
I think it is caused because it doesn't change anything.  
And the own responsibility of the get type is just a return circle.  
That type of the enimeration that I have.  
And I'm going to have something very similar for the polygon shape.  
So I'm going to have something which is.  
Shake type.  
Polygon shape.  
Get type that returns the type.  
All again.  
And you know, I'm going to have in box shape.  
And get type that returns.  
Box.  
So now every time that I ask shape.  
Get type.  
It will return correctly.  
Box.  
Circle.  
Polygon.  
Whatever that thing is.  
Whatever type.  
That shape is declared S.  
Cool.  

# Linker Error and Pure Virtual Method

And you just see.  
What is the state that we are.  
Oh.  
Problem.  
So this is a linker error.  
It says type info for shape.  
So linker command.  
Right.  
So note, I'm using the table.  
Usually means that the first non-inline virtual member function has no definition.  
Well, thank you.  
See plus plus.  
That's very helpful.  
But I think I know what that is.  
I think that in the time that I declare my shape class.  
So let me just come back to shape.H.  
So up here whenever I was declaring my shape.  
You see how I have all this virtual methods and virtual functions here.  
I need to say that this thing right here.  
The shape type.  
Get type.  
It is a pure virtual method.  
So I don't have the implementation in shape.  
Everything will be implemented in the child classes.  
And I have to do that by saying.  
Call equals zero.  
This forces this is a pure virtual method.  
Implementation.  
The definition will be in the children classes.  
Right.  
I think that's it.  
I think that's going to fix my linker error.  
Oh, beautiful.  
So yeah.  
We are in good shape.  
Okay.  
We don't have much going on here.  
I would just have the skeleton of circle polygon and box shape.  

# Integrating Shapes with Body

Because what I really want to do now is I want to come here.  
And I want to open my body dot H.  
And in my body object.  
This side's having the loss of the position acceleration.  
For says the mass and the inverse of the mass.  
I want to do a couple of things.  
So one of the things that I want to do is I want to say that I'm going to have a shape.  
For each one of these bodies.  
Right.  
And I'm using the parent class because my shape can be either a circle, a box, a polygon.  
So this is just a shape pointer.  
And I'm going to initialize this thing with a no pointer.  
And of course, I'm going to have to come here and include shape dot H.  
Correct.  

# Constructing Bodies with Shapes

And let's just do a couple of things here.  
So besides passing whenever I construct a body, whenever I initialize a body,  
besides passing the position x and y and the mass.  
I want to come here and say that I can pass also a converse.  
Reference to a shape called shape.  
So in the moment that I am creating a body, I can pass already the definition of the shape.  
I can say create the body as a circle shape with this radius.  
So I can pretty much already create everything in the constructor of my body.  
I think that's a good idea because let's just come here in my application.  
This is what I want to do.  
Whenever I'm creating a body here, whenever I'm trying to create a new body,  
I need to pass a shape.  
Now right.  
So let's just think of this works.  
I want to pass.  
The first parameter is the shape.  
What I want to ultimately do is I want to say right here directly.  
I want to say circle shape.  
And pass the parameter of my circle shape which is the slow radius.  
Let's just say that I want to create a body which is a circle shape with the radius 50.  
And then at this position x, this position y and mass 1.0.  
But my first parameter is my circle shape and the radius.  
That is what I want to do.  

# Cloning Shapes

But there's just one gotcha here, everyone that.  
If you don't understand how C++ works, this gotcha is going to consume a lot of your time.  
So I'm just going to go ahead and explain why is the gotcha.  
Do you see how I am creating a circle shape passing the radius?  
This thing right here, I'm not using the new keyword, right?  
I'm not creating a dynamic object in the heap.  
This is going to create an object in the stack and pass as a parameter.  
But the problem is in the moment that I returned from this constructor.  
And the moment that I end the scope of the constructor.  
This thing that was in the stack gets deallocated.  
I delete this object in the stack.  
So look at what I have to do.  

In my constructor of the body.  
I remember I have here my constructor.  
Let's look at the implementation of the body.cpp.  
Right here.  
So I am passing a const shape reference shape.  
And if I come here and I say this shape equals shape.  
I am going to initialize this shape attribute inside my body.  
But this parameter right here.  
In the moment that I leave this method at the end.  
That shape parameter is going to be removed.  
And this thing right here is also going to lose that object pointer.  
Correct.  
I am assigning this shape to the parameter object that is in the stack.  
But in the moment that I leave this method.  
This shape right here is going to be removed.  
And this thing right here is also going to lose that reference that I just assigned.  
So that means that I need to come here and I need to create something.  
Let's just say dot clone because I need to create a new object.  
I need to clone this object with those values from the shape.  
Do you see why I had to do that?  

So since I'm passing this thing which is in the stack.  
I have to come here.  
I need to clone that value and create a brand new object to assign to my shape attribute here.  
Meaning that whenever I come here and I leave this method I don't lose that object.  
That object is going to be inside my body.  
I don't lose that parameter.  
I don't lose that object.  
And I have the clone of the previous parameter inside.  
I know is a lot of loops here and there.  
But this is the point right.  
I just need to remember that C++ is annoying.  
I'm not using smart pointers either everything has been done manually.  
But I think it's important that we all understand why these things might happen.  

# Implementing `clone` in Shape Classes

Okay, so I'm just going to go quickly and create this clone of my shape.  
Which is going to be here in my shape dot h.  
So let me just quickly come here in my shape class.  
And I'm going to say that I'm going to have to always overwrite something called clone.  
And this clone right here will return a pointer to a new shape.  
And I'm even going to say const.  
And I'm going to say that is equal zero because this is a pure virtual method that needs to be written in the children classes.  
So shape clone.  
Let's implement for this circle here.  
Clone.  
Which is a const override right.  
I am manually saying that I am overwriting this clone function.  
And I'm using this one and paste to the other one.  
And I'm going to have something here.  
And I'm going to have a clone for the box shape as well.  
You see, I will have to implement a clone function for the polygon for the box and for the circle.  
I need to be able to know how to clone that shape object and return a brand new object shape based on the parameters.  

Let's see what we can do here.  
If I go to my shape dot cpp, I will have to start implementing this things.  
So how do I implement cloning a circle?  
For me to clone an object, I have to say return new new.  
I have to use new circle shape.  
So I need to create a new circle shape object.  
I need to paste the radius.  
So this radius.  
Oops, and it's not just circle radius circle shape.  
Sorry.  
And I don't actually need this dot.  
So just simply radius here.  
This is the radius.  
So this is how I clone a circle shape.  
I return a new object based on that radius.  
Let's do a polygon shape.  
So how do I clone a polygon shape?  
So shape pointer.  
All of them shape.  
How do I clone a new polygon?  
So it is return new polygon shape.  
What do I have to pass here?  
I need to pass.  
Oops.  
What do I have to pass here?  
But I need to pass the vector of vertices.  
Meaning this vertices.  
Or simply just vertices.  
And that's pretty much it.  
I just have to go and return a new object that I can just go in a sign later.  
What else do I need?  
The box.  
So shape.  
Clone.  
What do I have to create?  
Return new dot shape.  
What do I have to pass?  
I have to pass the width and the height.  
This dot width and this dot height.  
That should do the job for me.  

# Memory Management in Body

Cool.  
So this is a very annoying dotcha.  
That if we don't do we're going to have several problems of basically not being able to initialize this circle shape or this box shape.  
Whatever shape you want to initialize, you need to go there and clone this thing that was created in this stack.  
Which also means that since we're talking about C++,  
we know that we are the ones responsible for going and de-locating.  
The leading everything that we create using the new keyword.  

So since I came here in my body dot CPP.  
And since the clone function goes there and creates a new shape object for me.  
I need to come here to my body.  
This structure.  
And what do I have to do?  
The link to shape attribute that I have that I just created above.  
That's it.  
So the moment that I come here, I create a new object shape.  
I assign to that pointer.  
And right here, every time that I delete a body,  
I have to delete that shape pointer with the attributes inside.  
Everything that I have in that object, I delete my shape pointer.  
I delete my shape object that I have attached to this body.  

# Next Steps

Good stuff.  
So this is all the loops and hoops of using shapes with our body.  
I think let me see if I forgot something.  
I don't think so finger trust.  
Yeah, good.  
So I am going to pause right here.  
Right?  
Since we are coming here and we are definitely in our application dot CPP.  
Now we are creating a new rigid body with a shape which is a circle of 50 pixels radius.  
This is what we need to start thinking about some special characteristics of rigid bodies.  
Now, how do we go about drawing this rigid body which has a shape?  
How do we go about changing the mass?  
How do we go about changing the rotation of this rigid body?  
Because now we are going to enter this realm of rotation angular motion torque.  
We have to discuss these ideas of angular velocity angular acceleration angular motion of rigid body.  
That is going to be our next topic.
