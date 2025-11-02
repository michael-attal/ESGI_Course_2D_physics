# Transition from Particles to Rigid Bodies

All right, it is time for us to move from particles and enter the realm of rigid bodies.  
Instead of having just these particles where we were basically ignoring the shape, the rotation, it was everything was okay, right?  

If you think about, for example, understanding what happens with a missile from a distance, we can basically just bypass an ignore the idea of shape and dimensions, and we can treat that missile from a distance only as a particle.  

So we go, we apply forces which act acceleration, velocity and position, and everything is fine just thinking about particle physics.  

But we want to know, zoom in and understand what happened with this body, is that have an actual shape.  
They have dimension, they have width, height, they have vertices, right, and they have center of mass.  

---

# Rigid Bodies Concepts

So we're going to enter and we're going to expand a couple of issues, a couple of simplifications that we can do with rigid bodies.  
Let's zoom in and understand how we're going to approach now thinking about this bodies, right?  

Instead of particles, we have bodies that are rigid, that do not deform.  
Rigid bodies, different than particles which we could basically ignore shape and rotation as we were doing before, rigid bodies, they will have shape, they will have rotation, and they will have this concept of center of mass or center of gravity.  

Remember how we have the particle class now, and that particle only has the position, the velocity acceleration, and the forces are acting on it.  
Now we will have to add a couple of more things.  

For example, our rotation angle, that shape is going to rotate by, we have to also have this idea of an actual shape, right?  
So what is the shape that is going to be attached to this body?  
Is it a circle?  
Is it a polygon?  
Is it an oriented box?  

So we're going to have to figure out how to represent this shape in space as well.  

---

# Applying Particle Formulas to Rigid Bodies

And the good news is that all those formulas that we were looking for particles, for example, the formulas for displacement, velocity acceleration, forces acting on it, the idea of integration, all those things that we discussed previously, they are going to hold true for bodies as well, for this rigid body as well.  

If you think of a rigid body, is this object that you will have a shape, and especially, right, as it moves, everything moves together, and as it collides, nothing gets deformed, right?  

Of course, rigid bodies, they do not exist in the real world, right?  
I think it's very funny that people actually pay me money to teach about things that don't exist, but we're going to simplify the problem and assume that if things collide, they will not deform, right?  

There is no damage in that collision spot, nothing gets deformed, we're not going to consider the atomic properties and the molecules that are affected by that hit by that collision.  

We're going to simplify our problem and think that we have rigid bodies that never deform and the shape always maintains as we collide, as we move, as our rigid bodies move around, the shape will always be rigid, right?  
They are rigid, they never deform.  

---

# Shapes of Rigid Bodies

And we are going to have to pick a couple of shapes that we have to represent, right?  
So in our implementation, in our physics engine, we are going to treat this rigid bodies.  

We're going to have to pick some shapes to work with, right?  
We're going to implement three, what I'm calling three main shapes.  
They are actually two different shapes, but we're going to have three different types of shapes.  

So circles, polygons and boxes.  
And you see how I said that boxes, they will inherit from polygons.  
It makes sense, right?  
Boxes will be basically this four-sided polygons.  

So we're going to have an enumeration, right?  
Because I want to be able to determine what is the type of that shape.  

So we're going to have a shape type enumeration.  
We can either have a box, a polygon, or a circle, right?  
So whenever we are going to create a shape, it will have a type, and then that type will be either a box.  
That is oriented box that can rotate a polygon, which is going to be this vertices in space.  
And the final one is going to be this idea of a circle, right? With the radios, with the size, and these are going to be the pre-main types of shapes that we're going to do in our physics ending.  

You're going to say, okay, Gustavo, what about more complex shapes?  
You'll see that most physics engines, especially two deep physics engines, they will have these primitive, like box, polygons and circles.  

And if you want to create more complex shapes, then it's just a matter of grouping these things together, right? Having circles together with boxes with polygons to kind of approximate the shape that you want to represent in your game, in your simulation.  

So I'm still going to work only with boxes, polygons and circles.  
And then in the future, we can talk about grouping these things together, having these complex structure of shapes that are going to help us create more complex images and things like that.  

But these are going to be the enumeration that we have.  

---

# Renaming Particle Classes to Body Classes

And I'm going to quickly pause here for a moment because I went to address one thing quickly.  
Do you see how before we had the class particle, right? Particle.h and particle.cpp?  
We are going to have something called, let's say, body.h and body.cpp.  

Right? And remember how I said that, the good news is that the formulas for particles that we were looking before, the velocity, acceleration, forces, they hold true.  
Because if you think about displacement, if you think about acceleration, if you think about linear movement, the velocity acceleration displacement, we can still apply forces, we can still accelerate, still change the velocity and position.  
If we consider the center of mass of these rigid bodies.  

Right? So if I come here and I apply a force, I will apply that force and I can change acceleration and the linear movement. I can do that in the center of mass.  

So I still talk about these particles, which is the center of gravity, the center of mass of my rigid body.  
But now, just besides thinking about this force, the velocity acceleration and this linear movement, I have to just go to also and think about the shape. Right? So what happens with that shape? I have to move all the vertices together. I have to move all these sides of the box together with that center of mass.  

---

# Updating Codebase

Right? So let me just quickly pause here for a moment and let's go to the code editor and I want to start replacing everything that was particle before. I'm not going to call these things particle anymore. I'm going to call them bodies.  

All right, so let's just get that out of the way. So if we come here to our linear terminal inside my root folder to the physics, let me just show the contents of the source folder.  
So we have application.cpp, application.hg graphics.cpp graphics.h, the first thing that I want to do is I want to come here to my source folder and I'm going to say that I want to rename everything from the physics folder, everything that was I'm going to move everything that was particle.h, it's going to become body.h.  

Okay? I'm going to move. I'm going to rename everything that has to do with particles is going to become body now because it makes more sense. Right? We're talking about bodies, rigid bodies.  

So I'm renaming particle.h2body.h. I have to rename particle.cpp to body.cpp. So I just rename particle.something to body and let's do this. We have to also come here. Let me just come back to my root folder and we have to basically do a search and replace every occurrence of particle, replace it by body now.  

We have to just basically do that quick search and replace in every file in every sub directory in our project. Everything that was particle, I want to basically replace by the word body.  

And if you have an IDE, if you have like visual studio, that is basically just going there, edit, search and replace, find all the files, replace, and I am going to use Linux because that's easier, right? It's easier for me. So I'm going to find everything from this folder down. Right? So in my root folder, every file, every sub directory, down, I want to find all the files.  

And I'm even going to say that I want only the file. I only everything that has the type file, not directories. So I want to find everything and I want to execute, meaning all these files that I find, I want to execute the following command. I want to do a set, which is this thing that is going to help me search and replace.  

So set, what is the input? I want to get this input file. And what is the command that I want to execute? I want to search everything, all the occurrences of the word, particle, and I want to replace by the word, body.  

Okay? And I have to say that I want global to change the entire file. And then I just have to finish the fine comment like this. Right? So I am searching all the occurrences of particle and replacing by body in this file, writing the entire file using the common set.  

This is going to find and replace all the files from this folder down, all the sub directory is all the files searching and replacing this occurrences of the words particle by body.  

Let's see. Right? So I would just assume that that word, I'm going to also go ahead and do this. I'm going to replace all the occurrences of the capitalized particle, right? Then uppercase P by the capitalized body. So the same thing just replacing this uppercase P and B.  

And I am also going to go ahead. And do you remember how we have the protection guards? That was particle, underscore H. I'm going to replace that by body as well. So everything that was uppercase particle by uppercase body, done.  

And then I think we will be tempted to say that everything is okay, but we have to be careful with the plural of the word particles and bodies. Because if it is particle's plural, I want to replace by bodies. You see, it's DIES, right? It's different than bodies like this because probably the search and replace is replacing by bodies like this.  

So let me just quickly fix the plural one. Let me just fix this one. Let me just replace everything that is plural now, bodies that was replaced by the comments above. I want to replace by bodies like this.  

There we go. I want to make sure that I do bodies like this with an uppercase B. And also, I think we don't have any occurrence, bodies like this by bodies like this. Again, just fixing the plural of bodies.  

---

# Verifying Changes

And I think that's it. Let me just think about this. So application, graphics, main recipe P and physics writing side to physics folder force vector 2. I think that will be okay. Let me just do a quick final pass here. Let me just make everything. We should not have any errors, right? Because if we replace everything correctly, it's just syntax change. Right. Good. That's good sign.  

Let me just now do a couple of chats here. So application.cpp. I know that this one has a lot of bodies around. Well, would you look at that? I have replaced everything that was particle before by body. I have the body dot radius. I have the bodies dot push. So I have a vector of body object, right? Called bodies with a correct spelling. And we probably have more occurrence here.  

Right? So for all the bodies inside the bodies vector, I am saying that I'm adding my force to the body. Right? So remember, when I'm adding a force to the body, I'm applying that force in the center of mess. So we can think right now of the center of mess as the absolute middle of my shape, right? As the that little particle that is the absolute middle of my shape of my body.  

We might change that in the future. The center of gravity might not be in the center. We might have a little vector position that is inside. But for now, just think of applying a force in that center of gravity, right? The center of mass, the middle of my body. Same thing, body bodies, body bodies. So everything looks okay.  

Let me just do a final check. We should have our body. Now, right? This is, it was a particle before, but now we have a body. We know that we're going to have a shape around this body. Very soon, we're going to attach a square, a box, a polygon, or a circle. But for now, my body is bouncing around, is colliding with the floor, and it is being applied for cis, gender velocity position, and integrating everything, which is absolutely great news.  

---

# Next Steps: Attaching Shapes

So now that we are back, and we changed all the occurrences of particles by body, I want to start looking at the idea of shapes. Right?  
We need to attach a shape now to this body. Right?  

We're going to have to have this shape class, and then the shape class can be a circle, box, a polygon lens, take a closer look at what we're going to do with the idea of shapes in our rigid body.
