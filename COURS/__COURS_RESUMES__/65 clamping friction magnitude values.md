![[medias/65 clamping friction magnitude values 2025-12-31 08.52.48.excalidraw]]

```cpp
if(friction > 0.0f)
{
	const float max = cachedLambda[0] * friction;
	cachedLambda[1] = stp::clamp(cachedLambda[1], -max, max);
}
```