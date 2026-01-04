```cpp
//constraint.cpp

const Vec2 pa = a->LocalSpaceToWorldSpace(aPoint);
const Vec2 pb = b->LocalSpaceToWorldSpace(bPoint);

const Vec2 ra = pa-a->position;
const Vec2 rb = pb-b->position;

jacobian.Zero();

Vec2 J1 = (pa-pb)*2.0;
jacobian.rows[0][0] = J1.x;
jacobian.rows[0][1] = J1.y;

float J2 = ra.Cross(pa-pb) * 2.0;
jacobian.rows[0][2] = J2;

Vec2 J3 = (pb-pa) *2.0;
jacobian.rows[0][3] = J3.x;
jacobian.rows[0][4] = J3.y;

float J4 = rb.Cross(pb-pa) * 2.0;
jacobian.rows[0][5] = J4;

const VecN V= GetVelocities();
const MatMN invM = GetInvM(); 
// jacobian transpose
const MatMN Jt = jacobian.Transpose();
const MatMN J = jacobian;

// compute lambda
// solve linear equation
// right hand side
VecN rhs = J*V*-1.0; // on omet le biais pour l'instant => A
// left hand side
MatMN lhs = J*invM * Jt; // Jt est la direction de l'impulse => B
VecN lambda = MatMN::SolveGaussSeidel(lhs, rhs); 
// new code

// lambda est la magnitude de l'impulse
// Jt est la direction de l'impulse
// compute the final impulse
VecN impulses = Jt * lambda; // direction * magnitude
// apply the impulses to A and B
// on doit refactoriser ApplyImpulse()
// ApplyImpulseLinear() + ApplyImpulseAngular()
a->ApplyImpulseLinear(Vec2(impulses[0],impulses[1]));
a->ApplyImpulseAngular(impulses[2]);
b->ApplyImpulseLinear(Vec2(impulses[3],impulses[4]));
b->ApplyImpulseAngular(impulses[5]);



```

```cpp
// body.h
void ApplyImpulseLinear(const Vec2& j);
void ApplyImpulseAngular(const float j);
void ApplyImpulseAtPoint(const Vec2& j, const Vec2& r);

// body.cpp
void Body::ApplyImpulseLinear(const Vec2& j)
{
	if(isStatic())
		return;
	velocity += j* invMass;
}
void ApplyImpulseAngular(const float j)
{
	if(isStatic())
		return;
	angularVelocity += j * invI;
}
void ApplyImpulseAtPoint(const Vec2& j, const Vec2& r){
	if(isStatic())
		return;
	velocity += j * invMass;
	angularVelocity += r.Cross(j)*invI;
}

```