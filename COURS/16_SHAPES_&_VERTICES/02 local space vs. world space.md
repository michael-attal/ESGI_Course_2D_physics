# Transforming Vertices from Local to World Space

OK, so this one should be quick. All we want to do is go and transform the vertices from local space and then translate them to the correct position. We'll have that body and rotate to the correct rotation angle of that body in what we call the world space. We have to transform from local space to world space. Correctly going and putting that body in that place in the world where they should be. So this is what we have to do.  
#physics-engine/local-space-to-world-space

---

## Creating the Update Vertices Method

Do you see how we have this integrate linear integrate angular right here? How about we go and we create something called `updateVertices()`? That is going to be performed for everybody that is a polygon, right? So we have to go and update the vertices at every physics simulation step, because every pass we have to we can be rotated a certain angle and then we can change the rotation angle or we can go and move the X and Y position to the right to the left.  
#physics-engine/update-vertices

---

## Determining When to Update

Every pass of the simulation we have to go and update the vertices every time. And I think right here in our update function should be a good place to go and perform that. So please just bear with me for a second because I am going to do something a little bit nasty. I'm going to say if my body shape get type is polygon. Well it has to be polygon or box.  
#physics-engine/update-condition

---

## Checking the Shape Type

So let me just change quickly here. I'm going to say that I'm going to create a volume variable called `isPolygon` that receives the return of `bodyShape.getType() == polygon` or `bodyShape.getType() == box`. Do you agree that I need to go and update the vertices for both polygons and box?  
#physics-engine/shape-type

---

## Casting and Updating Polygon Shapes

So this thing right here I'm going to perform a simple test. If our shape is polygon, if we are talking about a polygon shape here in this body, I want to say well first of all let me just get that polygon shape from the body shape casting polygon shape. So I am going there fetching the polygon shape if it actually is a polygon and this is going to work either for polygons or boxes because box inherits from polygons.  
#physics-engine/polygon-casting

---

## Defining the Update Vertices Function

So this will work as well. Polygon shape and I want to have a method. I'm going to create a method called `updateVertices()` and I can even pass in the update vertices. Why is the position that I want to translate my vertices and why is the rotation angle that I have to rotate my vertices?  
#physics-engine/function-definition

---

## Passing Rotation and Translation

Let me just pass here body rotation right is the rotation angle inside my body in radians and what is the translation? What is the position that we have to go and move this object? Where we come from body position? Do you agree? So this is where we have to go and update our vertices.  
#physics-engine/rotation-translation

---

## Implementing in Polygon Shape

We have to rotate and translate to this correct position in the world. Effectively moving things and transforming things from a local space to world space. Which means that we have to go to our polygon shape and we have to create this `updateVertices()` method right here.  
#physics-engine/implementation

---

## Adding Prototype in shape.h

So let me just say that in here let me just go to our shape.h to add the prototype. So this is only valid for polygons. Right polygons and boxes but if I come here and I add to the polygon shape this thing is going to be employed `updateVertices()` and we receive rotation and a position right so float angle that we want to rotate my and a vector to position.  
#physics-engine/header-prototype

---

## Commenting the Function

So comes back to let me receive actually reference position. This position is the position that we're going to translate this vertices of the body. Correct I think that's it. I'm even going to come here and say function to rotate and translate the polygons vertices from the local space to world space.  
#physics-engine/comment-function

---

## Implementation in shape.cpp

So we have to go when you have to implement this thing right here. Let's open our implementation shape.cpp. Because our polygon shape we're going to have now a new method to update the vertices. Polygon shape you write about here. You're going to have an update vertices that is from the polygon shape.  
#physics-engine/cpp-implementation

---

## Handling Local and World Vertices

But you know what we have to stop for a moment and because do you remember how our polygon shape we have the list of vertices? What are these vertices right here? Are they the local vertices or are they the world vertices? I would claim that I think it's a good idea to actually duplicate this thing. So let's just say that we're going to have not just vertices. We're going to have the local vertices and we're going to have the world vertices.  
#physics-engine/local-vs-world

---

## Local vs World Space Explanation

So this thing is the original set of vertices with respect to the origin in local space in our model space. And whenever we go and we update and we transform those local vertices into world vertices we load this world vertices right here. So our polygon shape we will always carry these two things.  
#physics-engine/local-world-concept

---

## Example of Box Shape

The original local vertices there are with respect to the origin. Let's say that we have our box where the origin of the box is the coordinate system at origin 00 and then they become world vertices right where they are correctly transformed and rotated and translated into the correct position in the work right into this world space.  
#physics-engine/box-example

---

## Initialization of Local Vertices

So that means that whenever we come here and we initialize our box shape with the vertices in our shape of CPP, remember how our box shape we were loading the vertices this thing we are loading the local vertices. So from line 57 to 16 I'm a search for vertices and replaced by local vertices. Everything that is correct.  
#physics-engine/init-local-vertices

---

## Updating Vertices During Simulation

So now the local vertices are loaded with the local vertices right and then right here in our update vertices. Oops I think here online 40 whenever we are cloning we have to pass the local vertices. And right here whenever we are updating the vertices these is what we have to do.  
#physics-engine/update-during-simulation

---

## Rotating and Translating Vertices

We have to loop all the vertices transforming from local to world space which means that I have to go and do a for loop going through all the vertices all the local vertices. So I started zero while my i is less than local vertices dot size.  
#physics-engine/rotation-translation-loop

---

## Order of Operations

We have to perform two things I have to first rotate and then later translate those vertices into world space. Okay let's pause right here I wanted to pause and see if you understand what we're doing. We have to move from this local vertices we have to rotate this local vertices and then load the world vertices and then translate and load the world vertices. So we perform rotation and then translation and the order matters.  
#physics-engine/order-of-operations

---

## Rotation Around Origin

We need to perform rotation around the origin first and then translate to the correct position in the world mainly because rotation needs to be done around the origin. So we're going to rotate first and only then translate things to the correct body position.  
#physics-engine/rotation-origin

---

## Initializing World Vertices

Let me just see before I forget let me just come here and we cannot forget that. You see how we are loading the local vertices here and let me just make sure that as I load my box shape with those local vertices let me just initialize the world vertices as well.  
#physics-engine/init-world-vertices

---

## Copying Local to World Vertices

So I'm going to have to yank this thing and let me just since we are duplicating let me just add the world vertices as well because I need to have elements in my world vertices to just go there and translate and rotate.  
#physics-engine/duplicate-vertices

---

## Constructor Setup

So in our constructor we are loading for vertices in the local vertices and for vertices in the world vertices it just happens that when we start local vertices in the world vertices they have exactly the same thing but in the simulation steps that we are running then we are going to come here now every step we have to go and update the vertices of our body.  
#physics-engine/constructor-setup

---

## Applying Rotation and Translation

So let's think about rotation and translation and this thing right here should not be that difficult because if we understand how to rotate vectors and we spend one entire lecture remember from the vector course just learning how to rotate a vector around the origin so let's just first rotate.  
#physics-engine/apply-rotation-translation

---

## Rotating Vectors

We should know how to do that right we have a function in our vector class. So I'm going to say world vertices at this position right so these vertex right here I want it to be rotated so we can say local vertices at this position and we have our rotate function correct.  
#physics-engine/vector-rotation

---

## Rotate Then Translate

The vector 2 class we have a rotate function that receives an angle that expects an angle in gradients to rotate that vector around the origin. So what is the angle that I have to rotate well is the parameter angle that we received in the update vertices function correct so here is us rotating the local vertices by a certain angle and then the return of this rotation we come here and we load the world vertices of that index.  
#physics-engine/rotate-translate

---

## Translating Vertices

We are transforming the local vertices rotating by a certain angle and then we are updating and setting to the world vertices so the world vertices right now has the original local space rotated by a certain angle and then we have to translate.  
#physics-engine/translate-vertices

---

## Translation as Vector Addition

How do we translate well I can have my world vertices at that position. What does it mean to translate by a certain position? Well I can basically say class equal position I can add two vectors together remember translation is basically adding two vectors together by a certain vector.  
#physics-engine/vector-addition

---

## Updating World Vertices Each Step

So I come here and I rotate first and then after I rotate I come here and I just add the x components of my vectors I add the y components of my vector and hopefully at the end of this for loop all those vectors will be translated rotated into world space.  
#physics-engine/update-each-step

---

## Drawing Updated Vertices

That’s it so let me just make things shorter so first rotate then we translate and this is what we have to do so I think this is a lot prettier I just these two lines rotate first translate later this is us updating our vertices and this has to happen every step of our simulation.  
#physics-engine/drawing-updated

---

## Integration and Final Output

We are doing that inside the for loop inside my update function. This thing right here is where we integrate linearly integrate the angular properties and then if it is a polygon we go there and we update the vertices of that polygon by the body rotation and body position which means that right here I think we have error whenever we have to pass these values to be drawn so if we want to draw our box what are the vertices that we have to pass to draw it is not vertices anymore it is world vertices do we all agree?  
#physics-engine/final-integration

---

## Visual Confirmation

It is the vertices that are transformed and I think we are in good shape here let's see if I forgot something fine we still have that warning because we have this unused variable but if we make run right now that should be in the middle of my canvas beautiful so we work dating the vertices from the origin 00 now we are translating the box to the middle of the screen where that body is positioned and that is great news.  
#physics-engine/visual-confirmation

---

## Applying Torque

Let's do one final task here let me just come up and let me apply a force so I just come here I still don't want wait I just want torque and you know what I want 200 torque let's just give a big torque and then my body and torque that looks good so if everything works correctly we are going to rotate and translate and that should be visible in our canvas right all we have to do is make sure that we are calling that update vertices for our colleagues every simulation step.  
#physics-engine/torque-application

---

## Final Result

Let's see how that looks beautiful so we have a rotating box right this box all we have to do is pass the width and the height and now our vertices they are correctly being loaded they are correctly being updated from local space to world space at every simulation step of our physics ending and look at that beauty rotate that looks good.  
#physics-engine/final-result

---

## Next Steps

I think that's it in the next video I just want to polish quickly this thing right here because this thing right here is getting pretty ugly right we are starting to add integrate linear integrate angular how about we go and we move this thing from here and we create something like body update meaning that we're going to have an update method inside the body and that update method is responsible for integrating linear integrating angular and updating the polygon vertices.  
#physics-engine/next-steps

---

## Exercise Proposal

So it's pretty much just a matter of coming here removing this thing from here and adding all this logic inside my body class and you know what even better let's use this moment to propose this exercise go ahead yourself and try to create this body update method that implements the integration linear integration angular and the update vertices of our shape go ahead try yourself and I'll be back very soon with my implementation of this thing good luck I'll see you soon.  
#physics-engine/exercise
