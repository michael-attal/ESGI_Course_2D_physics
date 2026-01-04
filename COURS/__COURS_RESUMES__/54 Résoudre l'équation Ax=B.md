![[medias/54 Résoudre l'équation Ax=B 2025-12-20 19.10.27.excalidraw]]

### Octave examples

```bash
#octave / résoudre équation linéaire
# \ : built in operator
octave:1> A = [12,3,-5;1,5,3;3,7,13]
A =

   12    3   -5
    1    5    3
    3    7   13

octave:2> B = [1;28;76]
B =

    1
   28
   76

octave:3> x =A\B
x =

   1
   3
   4 
```

```bash
X = zeros(length(B), 1);

/*Solve Ax=B with Gauss-Seidel method*/
for iteration 1:6
	for i = 1:length(B)
		X(i) = X(i) + (B(i)/A(i,i) - (dot(A(i,:),X)/A(i,i)))
	end
end

X
```

```cpp
const Vec2 pa = a->LocalSpaceToWorldSpace(aPoint);
const Vec2 pb = b->LocalSpaceToWorldSpace(bPoint);

const Vec2 ra = pa-a->position;
const Vec2 rb = pb-b->position;

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
// TODO: implement Gauss-Seidel method to solve Ax=B
VecN lambda = MatMN::SolveGaussSeidel(lhs, rhs); 
// TODO: apply lambda impulse to A and B
