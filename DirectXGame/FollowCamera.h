#pragma once

#include "ViewProjection.h"
#include "WorldTransform.h"
#include "MathUtilityForText.h"

class FollowCamera {
public:
	void Initialize();

	void Update();

	void Draw();

	void SetTarget(const WorldTransform* target) { target_ = target; }

	const ViewProjection& GetViewProjection() { return viewProjection_; }

private:
	ViewProjection viewProjection_;
	const WorldTransform* target_ = nullptr;
};