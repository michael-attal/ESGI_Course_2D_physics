![[medias/67 unstable stack of boxes 2026-01-02 11.28.22.excalidraw]]

```cpp
// contact.h
struct Contact{
	Body* a;
	Body* b;
	
	Vec2 start;
	Vec2 end;
	
	Vec2 normal;
	float depth;
	
};

// list of multiple contacts
std::vector<Contact> contacts;

//CollisionDetection.h
struct CollisionDetection {
    static bool IsColliding(Body* a, Body* b, std::vector<Contact>& contacts);
    static bool IsCollidingCircleCircle(Body* a, Body* b, std::vector<Contact>& contacts);
    static bool IsCollidingPolygonPolygon(Body* a, Body* b, std::vector<Contact>& contacts);
    static bool IsCollidingPolygonCircle(Body* polygon, Body* circle, std::vector<Contact>& contacts);
};
// on reecrit aussi Collision.cpp

```

