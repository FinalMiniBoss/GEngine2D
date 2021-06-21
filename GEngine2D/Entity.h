#pragma once

#include <vector>
#include <memory>

class Entity
{
private:
	static uint32_t _UUIDCounter;
public:


private:
	std::vector<std::shared_ptr<Entity>> _children;
	uint32_t UUID = 99;

public:
	Entity();
	~Entity();

	void addChild(std::shared_ptr<Entity> _child);
};

