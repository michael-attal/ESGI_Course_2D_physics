# Question

So, what do you think?  
Why did I decide to pull all this nest illogic and add all these estatements with drawing instructions here in the render function instead of delegating and having a draw method that knows how to draw a circle in the circle shape class or how to draw a polygon in the polygon shape class?  
Why did I decide to do things here and not there?  

---

# Reasoning

The reason why I decided to do that is because mostly because I don't want to have rendering instructions inside our physics engine, right?  
I don't want to break that rule that we said that our physics engine is agnostic to rendering.  
I don't want to have this SDL specific rendering instructions in our physics engine inside our physics folder inside our source.  
Does it make sense?  

---

# Separation of Concerns

I want, if I have to draw something, I want to draw right here outside, right?  
I have to, I have this space outside my physics engine that I have to go and draw things.  
My physics engine, the little folder, the physics folder that has shape, rigid body, particle, any other things collision.  
Now, anything that has to do with physics engine, I don't want to have any rendered things.  
Our physics engine needs to be agnostic to rendering.  

---

# Design Decision

That is why I decided to not add any drawing instructions inside our shape class.  
If you want to draw something, the user that is using your engine has to come here and draw themselves, right?  
They have to go and ask the draw circle how they want to do.  
They have to go and ask the draw polygon.  
They have to come and ask the draw hexagon or pentagon whatever shape they have to draw.  

---

# Conclusion

So this is the quick answer because I don't want to have rendered instructions inside my physics engine folder and that's it.
