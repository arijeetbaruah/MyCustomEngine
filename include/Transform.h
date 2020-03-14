#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform
{
public:
	Transform();
	Transform(const glm::vec3& position, Transform* parent = nullptr);
	~Transform();

	void SetWorldPosition(const glm::vec3& worldPos);
	void SetLocalPosition(const glm::vec3& localPos);

	void SetWorldScale(const glm::vec3& worldScale);
	void SetLocalScale(const glm::vec3& localScale);

	Transform* GetParent() const {
		return parent;
	}

	void SetParent(Transform* newParent) {
		parent = newParent;
	}

	glm::mat4 GetWorldMatrix() const {
		return worldMatrix;
	}

	glm::mat4 GetLocalMatrix() const {
		return localMatrix;
	}

	glm::vec3 GetWorldPosition() const {
		return glm::vec3(worldMatrix[12], worldMatrix[13], worldMatrix[14]);
	}

	glm::vec3 GetLocalPosition() const {
		return localPosition;
	}

	glm::vec3 GetLocalScale() const {
		return localScale;
	}

	glm::quat GetLocalOrientation() const {
		return localOrientation;
	}

	void SetLocalOrientation(const glm::quat& newOr) {
		localOrientation = newOr;
	}

	glm::quat GetWorldOrientation() const {
		return worldOrientation;
	}

	void UpdateMatrices();

protected:
	glm::mat4		localMatrix;
	glm::mat4		worldMatrix;

	glm::vec3		localPosition;
	glm::vec3		localScale;
	glm::quat		localOrientation;
	glm::quat		worldOrientation;

	Transform* parent;

	std::vector<Transform*> children;
};

