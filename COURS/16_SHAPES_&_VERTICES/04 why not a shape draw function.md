# Quick Question

All right, very quick question just before we move forward.  
I want you to propose a quick exercise.  
Look, as I came here in this render function that we have right now, several students they came to me and say, OK, Gustavo, what is going on?  
Because we are going body by body, right? So rigid body by rigid body and then you are doing this very nasty text, right?

---

# Render Function Logic

If the body shape at type is equals equals circle, then we go when we draw a circle here.  
If the body shape equals equals box, then we go when you draw a polygon.  
Then we're probably going to have several other shapes, right?  
If this shape is polygon, then we draw a polygon.  

---

# The Question

The question is Gustavo, why are you doing this?  
Right? So why are you not using proper object oriented programming techniques?  
Because if you want to draw a circle or if you want to draw a polygon, why don't you have a method inside the circle class called draw that knows how to draw a circle?  
Why don't you have a method in the polygon class?  
So you can just say shape, draw, and then the shape knows already how to go and draw itself, right?  
This is the whole idea of polymer phism from object oriented programming, right?  
So why are you not, why are you polluting and adding all this dirt here in the render function?  
And why don't you just say shape, draw, and then each shape knows how to draw itself.  

---

# Object-Oriented Design Reflection

And that is an absolutely great question, right?  
I would always encourage you to think about the things we should think about, delegating the draw responsibility to the shape.  
But my question is why didn't I do that?  
And I want to send this over to you.  
I want you to answer this question.  

---

# Exercise

I want you to go to the discussion board and I want you to write one line or one paragraph explaining,  
why do you think that I decided to put that logic and add right here outside in our render function?  
Right, all this nasty dirty checks, if it is equals to circle, draw circle here.  
If it is equal to shape, draw circle circle here.  
Why am I drawing things here inside the render instead of drawing them inside our shape class?  

Go quickly, go to the discussion board, right?  
One line, I want you to see if you already understand why I decided to do this.
