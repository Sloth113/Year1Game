#pragma once
#include "Object.h"
#include "ResourceManager.h"
#include "MathLibDLL.h"
#include "RoundThings.h"
//Custom object for game
class FastObj : public Object
{
public:
	FastObj(const std::string name, std::shared_ptr<ResourceBase> texture);
	FastObj(const std::string name, const char* filename);
	FastObj(const FastObj& other);
	~FastObj();

	FastObj& operator= (const FastObj& other);

	virtual std::shared_ptr<IPrototype> clone();
	virtual std::string getName() { return m_name; }

	bool isAlive() { return m_alive; }
	MathDLL::Vector2 getPosition() { return m_position; }
	int getScore() { return 20; }
	void setAlive(bool state) { m_alive = state; };
	void setDirection(float x, float y);
	void setPosition(float x, float y);
	bool checkCollision(float x, float y);

	void update(float dt);
	void draw(aie::Renderer2D* renderer);

private:
	std::shared_ptr<ResourceBase> m_texture;
	MathDLL::Vector2 m_position;
	MathDLL::Vector2 m_velocity;
	bool m_alive;
	std::string m_name;
	RoundThings m_collider;
};