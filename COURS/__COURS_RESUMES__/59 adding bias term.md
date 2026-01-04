![[medias/59 adding bias term 2025-12-26 05.53.24.excalidraw]]
```cpp
class JointConstraint: public Constraint{
	private:
		MatMN jacobian;
		VecN cachedLambda;
		float bias;
};
// changer la signature pour avoir delta time
void JointConstraint::PreSolve(float dt){
	const Vec2 pa = a->LocalSpaceToWorldSpace(aPoint);
	const Vec2 pb = b->LocalSpaceToWorldSpace(bPoint);
	const Vec2 ra = pa-a->position;
	const Vec2 rb = pb-b->position;
	
	jacobian.Zero();
	
	Vec2 J1 = (pa-pb) * 2.0;
	jacobian.rows[0][0] = J1.x;
	jacobian.rows[0][1] = J1.y;
	
	float J2 = ra.Cross(pa-pb) * 2.0;
	jacobian.rows[0][2] = J2;
	
	Vec2 J3 = (pb-pa) * 2.0;
	jacobian.rows[0][3] = J3.x;
	jacobian.rows[0][4] = J3.y;
	
	float J4 = ra.Cross(pb-pa) * 2.0;
	jacobian.rows[0][5] = J4;
	
	// avant toute chose on applique le cached lambda du Solve() précédent
	// warm starting
	const MatMN Jt = jacobian.Transpose();
	VecN impulses = Jt* cachedLambda;
	
	a->ApplyImpulseLinear(Vec2(impulses[0], impulses[1]));
	a->ApplyImpulseAngular(impulses[2]);
	b->ApplyImpulseLinear(Vec2(impulses[3], impulses[4]));
	b->ApplyImpulseAngular(impulses[5]);
	
	// compute bias term
	const float beta = 0.1f;
	// C = positional error
	float C = (pb-pa).Dot(pb-pa);
	C = std::max(0.0, C-0.01f);
	bias = (beta/dt)* C;
}

void JointConstraint::Solve(){
	const VecN V = GetVelocities();
	const MatMN invM = GetInvM();
	
	const MatMN J = jacobian;
	const MatMN Jt = jacobian.Transpose();
	
	// compute lambda
	MatMN lhs = J*invM*Jt;
	MatMN rhs = J*V*-1.0f;
	// appply bias
	rhs[0] -= bias;
	VecN lambda = MatMN::SolveGaussSeidlel(lhs, rhs);
	cachedLambda += lambda;
	// (...)
	
	
}
```

