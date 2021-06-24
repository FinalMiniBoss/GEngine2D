#pragma once

#include <vector>
#include <memory>
#include <chrono>

class Entity
{
private:
	static uint32_t _UUIDCounter;
public:


private:
	std::vector<std::shared_ptr<Entity>> _children;
	uint32_t UUID = 99;

	Entity* _parent;

public:
	Entity();
	~Entity();

	void addChild(std::shared_ptr<Entity> _child);
	Entity* parent();
	std::vector<std::shared_ptr<Entity>>& children();

	void update(std::chrono::steady_clock::time_point);
	virtual void onUpdate(std::chrono::steady_clock::time_point);
};

