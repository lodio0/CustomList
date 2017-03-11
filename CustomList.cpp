#include "CustomList.h"
#include <exception>


CustomList::CustomList() : root(nullptr)
{
}

CustomList::CustomList(int value) : root(createNewNode(value))
{

}

int CustomList::GetFirstValue()
{
	try {
		return *root->value;
	}
    catch (std::exception& e)
    {
		throw e;
	}
}

bool CustomList::AddFirst(int value)
{
	if (root == nullptr)
	{
		try {
			root = createNewNode(value);
			return true;
		}
		catch (std::exception& e)
		{
			return false;
		}
	}
	try {
		std::unique_ptr<Node> temp = createNewNode(value);
		temp->next = std::move(root);
		root = std::move(temp);
		return true;
	}
	catch (std::exception& e)
	{
		return false;
	}
}

int CustomList::Size()
{
	return currentSize;
}

bool CustomList::DeleteByValue(int value)
{
	if (root == nullptr)
		return false;

	if (*root->value == value)
	{
		DeleteFirst();
		return true;
	}

	Node * currentNode = root.get();
	while (currentNode->next != nullptr)
	{
		if (*currentNode->next->value == value)
		{
			deleteAfterNode(currentNode);
			return true;
		}
		currentNode = currentNode->next.get();
	}
	return false;
}

bool CustomList::DeleteFirst()
{
	if (root != nullptr)
	{
		root = std::move(root->next);
		currentSize--;
		return true;
	}
	return false;
}

CustomList::~CustomList()
{
	while (DeleteFirst());
}

std::unique_ptr<Node> CustomList::createNewNode(int value)
{
	++currentSize;
	return std::make_unique<Node>(value);
}

bool CustomList::deleteAfterNode(Node * node)
{
	if (node != nullptr) {
		std::shared_ptr<Node> toDelete = std::move(node->next);
		node->next = std::move(toDelete->next);
		currentSize--;
		return true;
	}

	return false;
}
