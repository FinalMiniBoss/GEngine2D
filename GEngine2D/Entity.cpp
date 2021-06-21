#include "Entity.h"
uint32_t Entity::_UUIDCounter = 0;

Entity::Entity() {
	UUID = _UUIDCounter++;
	_children = {};
}

Entity::~Entity() {}

void Entity::addChild(std::shared_ptr<Entity> _child)
{
	_children.push_back(_child);
}
