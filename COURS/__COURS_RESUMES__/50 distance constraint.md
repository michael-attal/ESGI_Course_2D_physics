![[medias/50 distance constraint 2025-12-18 15.05.19.excalidraw]]

```cpp
// notre World a une liste d'objets et une liste de contraintes
std::vector<Body*> bodies;
std::vector<Constraint*> constraints;

// on ajoute 2 objets Body dans notre World
Body* a = new Body(BoxShape(100,30),100,100,0);
Body* b = new Body(BoxShape(100,30),300,100,0);
world->AddBody(a);
world->AddBody(b);

// on définit la position du point d'ancrage dans le local (ou world?) space
Vec2 anchorPoint = a->position - Vec2(100,0);

// on ajoute une contrainte Joint entre a et b
JointConstraint* joint = new JointConstraint(a,b, anchorPoint);
world->AddConstraint(joint);
```

```cpp
class JointConstraint:: public Constraint()
{
	private:
		MatMN jacobian; // matrice de coefficients, combinaison linéaire avec les vélocités
		// l'anchor point n'est pas seulement un point dans le world space
		Vec2 aPoint; // point d'ancrage dans le local space de l'objet A
		Vec2 bPoint; // point d'ancrage dans le local space de l'objet B
		
	public:
		JointConstraint();
		JointConstraint(Body* a, Body* b, const Vec2& anchorPoint);
		void Solve(float dt) override;
		

}
```

```cpp
// créer une contrainte joint et convertir la position du point d'ancrage vers la
// le local space de A et B

JointConstraint::Constraint(Body* a, Body* b, const Vec2& anchorPoint)
{
	this->a =a;
	this->b =b;
	this->aPoint = a->WorldSpaceToLocalSpace(anchorPoint);
	this->bPoint = b->WorldSpaceToLocalSpace(anchorPoint);
}
```

```cpp
// convert from local space to local space
Vec2 Body::LocalSpaceToWorldSpace(const Vec2& point) const{
	// rotation puis translation
	Vec2 rotated = point.Rotate(rotation);
	return rotated + position;
}
// convert from world space to a rigidbody's local space
// on fait les transformations inverses
Vec2 Body::WorldSpaceToLocalSpace(const Vec2& point) const{
	// translation puis rotation
	float translatedX = point.x - position.x;
	float translatedY = point.y - position.y;
	// rotation avec -rotation (angle opposé)
	float rotatedX = cos(-rotation) * translatedX - sin(-rotation) * translatedY;
	float rotatedY = cos(-rotation) * translatedY + sin(-rotation) * translatedX;
	return Vec2(rotatedX, rotatedY);
}

```

### JointConstraint
```cpp
// Constraint.h

class Constraint{
	public:
		Body* a;
		Body* b;
		Vec2 aPoint; // anchor point in A's local space
		Vec2 bPoint; // anchor point in B's local space
		
		virtual ~Constraint() = default;
		
		MatMN GetInvM();
		VecN GetVelocities();
		
		virtual void Solve() override;
		
}
class JointConstraint: public Constraint{
	private: 
		MatMN jacobian;
	public:
		JointConstraint();
		JointConstraint(Body* a, Body*b, const Vec2& anchorPoint);
		void Solve() override;
};
// Constraint.cpp
JointConstraint::JointConstraint(): Constraint(), jacobian(1,6){
}
JointConstraint::JointConstraint();
JointConstraint(Body* a, Body*b, const Vec2& anchorPoint): Constraint(), jacobian(1,6){
	this->a =a;
	this->b =b;
	
	this->aPoint = a->WorldSpaceToLocalSpace(anchorPoint);
	this->bPoint = b->WorldSpaceToLocalSpace(anchorPoint);
	
	
}


```