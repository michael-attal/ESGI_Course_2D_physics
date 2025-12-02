![[medias/27 boxes AABB COLLISION detection 2025-11-16 09.05.53.excalidraw]]

### implémentation
```cpp
bool isOverlappingAABB(Box a, Box b){
bool isOverlapX = aLeft <= bRight && bLeft <= aRight;
bool isOverlapY = aBottom <= bTop && bBottom <= aTop; 

return isOverlapX && isOverlapY;
}
```