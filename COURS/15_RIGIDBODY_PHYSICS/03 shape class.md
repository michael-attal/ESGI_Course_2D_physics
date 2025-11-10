# Implementing Shape Classes in C++

Cool, so we discussed a lot about these ideas of rigid bodies, the class of the body and also the shape that we're going to have attached to these bodies.  
So in this lecture right here, I want us to stop the philosophy around these classes and I want us to write these functions, classes, structs, because as you will see, the reasoning about the class diagram, the classes, the methods it's easy, but C++ is a little bit annoying, so we'll have to go and fill a lot of the gaps that the C++ syntax expects us to write.  

So let me just do this.  
Let me just enter, basic writing, just edit something called `shape.h`.  
Let's move on and type this thing.  

---

## Protection Guards and Base Structure

So in `shape.h`, all right, my protection guard, same old symbol, and we will have a struct `shape`, which let me just start slowly here.  
We're going to have a virtual, this structure, which is pretty classic if you want to go and inherit from this class later, so I'm going to have this one, I'm going to say that I want the compiler to generate the default, the structure for me, and we need to define the type of the shape, right?  

So it's going to be a circle, a box, a polygon, and for that, let me just quickly come up here, and I will declare an enumeration called `shape_type`, and I am going to have three types of shape.  
We're going to have something called circle, we're going to have something called a polygon, and even though a box is a polygon, I'm going to have a shape type for a box as well.  
So we really know that we're talking about an oriented box, right?  
Yes, it is a polygon, but it is this special polygon called box.  

So three shape types, this is an enumeration, and I want to come here, and I'm going to have a method, which is virtual as well, because it is from this base class.  
So virtual, I have the type of the return is going to be a `shape_type`, our enumeration, and I want to call this `get_type`, and you know where I'm going with this, and I'm even going to say `const`, because `get_type` will probably just return box, return circle, is not going to change anything, the internal state of our object.  

Two virtual methods, right? We're going to have to go and probably override this method later.  

---

## Circle Shape

The logic behind this implementation is that we're going to have not all something called struct `circle_shape`, which is going to inherit from our shape parent class.  
And we also know that a circle has this special thing called `radius`, and I will probably have the constructor and the structure.  

So `circle_shape`, the constructor, I want to pass the radius.  
Called `load_radius`, I want to pass the radius to be initialized, and I need to get this structure `circle_shape`, and I have this virtual because of the inheritance above.  

This structure, you see, C++ has all this verbose syntax that we have to specify `const`, we have to specify the `virtual`, we have to specify what inherits and what does not inherit.  
So I just want to write down with you, so we understand all this little details of the language.  

---

## Polygon Shape

Correct?  
You know what? I'm not going to really implement the meat part of polygons, but I want to just declare here, we're going to have something called struct `polygon_shape`, which also inherits from shape.  

And let's already define a couple of important things.  
Do you remember how our polygons we have a vector of the `vec2` called vertices, and we have to include a couple of things here, so let's just go up and include, I have to include `vec2`, and I also have to include `vec2`, perfect, so we have a list of vertices, all this `vec2`, which are going to be the vertices of my polygons.  

Pretty much the same thing, I have a constructor, and the constructor in this case, I want to be able to pass a list of vectors, well a list of `vec2`s called vertices, so we can go and initialize the member variable inside.  
So that should be it, and also a virtual constructor, `polygon_shape` here, correct?  

Let's see if I forgot something, oh, we have this virtual `get_type`, right?  
So I have to come here, it is mandatory to overwrite that name, so `shape_type get_type() override`, I need to say that I'm overwriting this method right here, which is the player in my parent class, `get_type`.  
And the same thing, I'm going to have exactly the same thing in my polygon class.  

---

## Box Shape

We see a lot of housekeeping, but we will get there.  

A final one here, `struct box_shape`, that inherits from `polygon_shape` in this case, and our `box_shape` will have width, a height, a constructor, and let's say that we can pass the width and the height to construct.  
So we will follow the pattern, and that will solve this structure box.  

There we go.  
Oh, and `get_type` that returns a `shape_type`.  

---

## Summary

So I think this is it, we have our enumeration with all the three types, our big parent class `shape`, that `circle_shape` inherits from, that has the radius, and then we have a `polygon_shape` that also inherits from `shape`, that has a list of vertices, and we have our `box_shape`, which inherits from a `polygon_shape`, which then inherits from `shape` itself.  

I think that's it.  
Well, remember we have a couple of extra methods that we're going to have to add, remember `get_moment_of_inertia` that I mentioned, we will add this thing later, right?  

I just want to have this skeleton, right, just the basic blueprint, high level of `shape`, `circle_shape`, `polygon_shape`, and `box_shape`.  
I am going to save everything, and let me do the dirty job of implementing this thing now, all right, so, `shape.cpp`.  

You also probably realize that I am adding all this classes in one `.h` and in one `.cpp` file, right?  
I'm not breaking them in different files; everything that has to do with shape is here in `shape.h` and `shape.cpp`.
