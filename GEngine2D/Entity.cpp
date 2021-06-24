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
	_child->_parent = this;
}

Entity* Entity::parent()
{
	return _parent;
}

std::vector<std::shared_ptr<Entity>>& Entity::children()
{
	return _children;
}

void Entity::update(float _deltaTime)
{
	this->onUpdate(_deltaTime);
	for (auto& child : _children)
	{
		child->update(_deltaTime);
	}
}

void Entity::onUpdate(float _deltaTime)
{
}
