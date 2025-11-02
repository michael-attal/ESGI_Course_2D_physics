# Implementation

Very well, so quick and easy, let me just implement that thing.  
I want to remove all these things, so the integration linear integration angular and the update vertices, I want to yank these things from here, and we are going to have something called body update, and we are probably going to have to pass the delta time.

---

# Creating the Update Method

So we are going to create this update method of the body, and that should be something that we have to declare a prototype here, so it is sizing the rating linear angular i and going to have probably quite a update pass in the float dt, like the delta time, and now in my implementation, probably way down we are going to have this right update delta time, and all I am going to do is paste that code that we have before, oops, maybe just put this back of it, and well let's see what we have to do.

---

# Integrations

Now it is not body integrate, I can delete this thing, so it is just integrate linear passing the delta time, what else this thing is simply integrate angular passing the delta time, Boo is polygon comes from the shape of the body, get type is it was polygon or the shape of the body, get type equals box, and if it is polygon, I have to go there and get the polygon shape of my shape, the rotation and the position, I don't need to specify body error rotation, it is just this dot rotation and this dot position, that should do the job.

---

# Updating and Testing

So let's see we have now this update that is responsible for performing linear integration, angular integration, and update the vertices of my polygon and the box, and if I come back to my application dot CPP, there we go, we are asking to update all the bodies for every simulation step, for every frame we are updating the bodies, we are integrating linear integrating angular and now updating the vertices, transforming things from local space into world space, and this is the final test CPR correctly showing everything, beautiful and we should still see our rotating box and that is exactly what we see.

---

# Next Steps: Collisions

Look you can come here add a lot of boxes, you can start moving things around applying different torques rotating things you can add circles and boxes, but the thing is we are not colliding anything, and this is going to be now this next section, I am going to, as I promise before, I am going to start with circles, so we are going to look and zoom in into these ideas of circles, how do we perform circle collision, how do we check overlap, how do we resolve this collision, so we have a lot of interesting territory to check right now, these ideas of collision, and this is going to be probably a very long and detailed discussions because we have to talk about momentum, we have to talk about impulses that we have to apply, we have to talk about overlap, checking if the shapes are colliding, it is a pretty interesting topic, so get ready and let's start talking about collisions.
