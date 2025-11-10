# Introduction

All right. We are back. One of the things that I want to do is I want to be able to draw this shape, right? Is circle, this box. We are starting with circles now. So I want to be able to come and draw this new shape.  

# Removing Radius from Body

There's just one thing that I want to quickly do. Do you remember how we have still the radius inside our body? Because we had that radius from the particle before. I have to go and remove this radius from the body. Our radius is only in the circle shape class. So we are going to come here quickly and just remove that radius from the body and just adapt our source code to account for the shape.  

So this is no more. The radius comes from the shape. I'm saying 50 pixels radius in my circle shape. And of course, if I come here and I open my body dot H, I have to remove the radius from the body. And we're moving the radius from the body is going to create a couple of issues here. Especially if we go down, I think we have a problem because we are using the radius in this manual collision check with the boundaries of the window.  

# Collision Check Update

Remember this hack that we have right here? This thing was checking the boundaries of the window and for that we were using that particle radius that we had before. Which we don't have anymore. This radius needs to come from our shape. We have to test the geometry of the body that is in the circle shape.  

So let's do this. I have a for loop that is looping all the bodies. And I am going to protect and say that if the body shape and then I have something called get type remember. So if the type of this shape of the body is equal to circle that in a narration type and I have if this is true, let me just wrap everything and let me just move all these things to the right of it.  

And if this is true, then I have to test not the body radius, but the circle shape radius. And if this thing is true, I'm going to have to come here and create something called a circle shape, point or call circle shape. And this comes from my body shape.  

So I'm going to have to get the circle shape. I might have to cast this thing. So I'm just going to do a nasty secast here. A circle shape pointer. So I am getting that circle shape from my body shape making sure that this is a circle shape.  

# Replacing Body Radius with Circle Radius

And then do you see how I have all this body radius here? I'm going to replace all this body arrow radius by circle shape radius. So let me just quickly do a quick search and replace here. So between lines 76 and 89, let's search for body radius and replace by circle shape radius and the entire selection global.  

Boom, there we go. So I just change quickly the body radius by the circle shape. Because I am making sure that I'm only trying to check objects of the type circle, right, shapes of the type circle here. Nothing else will check for this collision with the window. Only shapes of the type circle.  

# Rendering Shapes

So this is okay. Let me check something else here. We are passing the body radius in the draw function. So here is where we have to stop and think about how we can go and render this shapes.  

I am going to say this. So in this for loop right here where I loop all the bodies, I am going to say if my body shape yet time if the type is equal to a circle. So only if it is circle, I'm going to go ahead and I'm going to close my statement. And I'm going to have here to do in the very near future. We're going to have to draw other types of shapes or shapes.  

So I am coming here and checking from that body. Only draw the bodies that have the shape circle. And let's think of how we can do that. I have to come here and say that I'm going to have a circle shape pointer circle. Same thing before comes from body shape. And this thing I have to cast.  

And sure we could use a simplest plus modern cast but I'm just going to say circle shape pointer like this. So again, I am extracting that circle shape from my body and then I can use this shape right here. circle shape arrow radius because this circle shape indeed has arrays.  

# Drawing and Rotation

Okay, all good. So I think that takes care of our circles. So let me just quickly do a test. If we come here and we try to compile, I think that we'll do the job. Good. Let's see how those looks. We probably want to have a big shape with 50 pixels rate, right? So that makes sense.  

But something else that I want you to already come here and do is look. Sure, I can come here and draw a feel circle, but we are entering the realm of rigid bodies that can rotate. So I am going to come here and I'm going to change this draw feel circle by a simple draw circle.  

And the draw circle method we have to pass. Look at the parameters. An x, a y position, a radius and a float angle. So I can pass. I can specify the angle of rotation of that shape that I want to draw that circle.  

# Implementing Rotation Test

And this is going to be super handy for us because we want to start talking about rotation of rigid bodies. So let me just come here and try to do a couple things. So x and y. And then I have the circle shape radius and before the color, I have to pass an angle. So let's just say, for example, 0.0. So if my rotation of my circle is 0.0, let's see, we should not rotate.  

So we have this circle that is not filled. And we have that line. And you will see many two deep physics engines out there do exactly that. So if we try to render a circle with a rotation, we have a line to indicate where is that circle rotated.  

# Dynamic Rotation Example

And let's even put that to test. So instead of 0.0, let me just come here and declare who does do a nasty thing here. So let's just say static angle equals to 0.0 or some declaring aesthetic variable. And I want to always before I leave my render function, I want to say angle plus equals 0.01, right?  

This is radiance, of course. So let me just come here. Oops, I think I'm going to mistake this thing has to be slow angle. So I start at 0 and every time that I call my render, I increase by 0.01. And since this variable is static, it's going to persist this value, right? It's not going to erase. And right here, let me just pass that angle.  

# Visualization of Rotation

So I expect to see this angle increase by 0.01 radiance every time. Let's see how that looks. There you go. So now we have a way of determining and displaying the rotation of a shape.  

Of course, this rotation that I have, this angle has nothing to do with my body yet, right? Our body, we still haven't declared the angle of rotation of the body, the velocity of rotation, the acceleration of the rotation. We're going to start to talk about this body properties, this angular properties in the next video.  

# Angular Motion Preview

But there is a way that we can just specify the angle of rotation of a circle when we can draw and we see the little line changing the angle. So we have an idea of where is that circle rotating.  

Having that line is very common. You will see libraries like box to the chipmunk to the any to the physics engine. They will have some debug mode. They will have this circle with this line to indicate the rotation of the circle.  

But for us, I just wanted to show that we have now this option of drawing a circle passing an angle and that is going to be super handy for us now that we're going to start talking about.  

How fast is the velocity changing of that rotation? So how fast is that angle changing the rotation? That is going to be our angular velocity. How fast is the acceleration of that change? So we're going to have an angular acceleration.  

Do you see where we're going with this? So besides being able to move up and down, left and right with this linear movement, we're going to have now this idea of angular movement, right? Radians, how much do we change? We have an angular velocity, an angular acceleration. But this is the topic of our next conversation. Let's think about angular motion of weighted values.
