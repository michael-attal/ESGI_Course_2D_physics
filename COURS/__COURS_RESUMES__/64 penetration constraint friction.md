![[medias/64 penetration constraint friction 2025-12-31 06.59.29.excalidraw]]

```cpp
```cpp
// constraint.h
class PenetrationConstraint : public Constraint {
private:
    MatMN jacobian;
    VecN cachedLambda;
    float bias;
    Vec2 normal;// normal direction dans le local space de A
    // on ajoute un coeff de friction entre les deux corps
    float friction;

public:
    PenetrationConstraint();
    PenetrationConstraint(
	    Body* a, Body* b, const Vec2& aCollisionPoint, const Vec2& bCollisionPoint, const Vec2& normal
	);
    void PreSolve(const float dt) override;
    void Solve() override;
    void PostSolve() override;
    
};
// changer la dimension de la matrice jacobienne et du lambda
PenetrationConstraint::PenetrationConstraint(Constraint(), jacobian(2,6), cachedLambda(2), bias(0.0f)): 
PenetrationConstraint::PreSolve(float dt)
{
	// get the collision point in world space
    const Vec2 pa = a->LocalSpaceToWorldSpace(aPoint);
    const Vec2 pb = b->LocalSpaceToWorldSpace(bPoint);
    Vec2 n = a->LocalSpaceToWorldSpace(normal);
    

    const Vec2 ra = pa - a->position;
    const Vec2 rb = pb - b->position;
	// jacobian dim:  2x6
    jacobian.Zero();
	// on populate la première ligne
    Vec2 J1 = -n;
    jacobian.rows[0][0] = J1.x; // A linear velocity.x
    jacobian.rows[0][1] = J1.y; // A linear velocity.y
    
    float J2 = -ra.Cross(n):
    jacobian.rows[0][2] = J2; // 
    
    Vec2 J3 =n;
    jacobian.rows[0][3] = J3.x; // A linear velocity.x
    jacobian.rows[0][4] = J3.y; // A linear velocity.y
    
    float J4 = rb.Cross(n):
    jacobian.rows[0][5] = J4; // 
    
    // on populate la deuxième ligne (avec tangent et friction)
    friction = std::max(a->friction, b->friction);
    if(friction > 0.0){
	    Vec2 t = n.Normal(); // tangente est perpendiculaire à la normale.
	    jacobian.rows[1][0] = -t.x;
	    jacobian.rows[1][1] = -t.y;
	    jacobian.rows[1][2] =-ra.Cross(t);
	    jacobian.rows[1][3] = t.x;
	    jacobian.rows[1][4] = t.y;
	    jacobian.rows[1][5] = rb.Cross(t);
	    
    }
    
    // warm starting avec normal et tangente
    const MatMN Jt = jacobian.Transpose();
    VecN impulses = Jt*cachedLambda;
    
    a->ApplyImpulseLinear(Vec2(impulses[0], impulses[1]));
    a->ApplyImpulseAngular(Vec2(impulses[2]));
    b->ApplyImpulseLinear(Vec2(impulses[3], impulses[4]));
    b->ApplyImpulseAngular(Vec2(impulses[5]));
    
    // compute the bias term (baumgarte stabilization)
    const float beta = 0.2f;
    // distance constraint
    float C = (pb-pa).Dot(-n);
    C = std::min(0.0f, C+0.01f);
    bias = (beta/dt) * C;
    
}
```