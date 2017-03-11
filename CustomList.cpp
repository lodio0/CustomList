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
		root = std::move(root->next);
		currentSize--;
		return true;
	}
	Node * currentNode = root.get();
	while (currentNode->next != nullptr)
	{
		if (*currentNode->next->value == value)
		{
			std::shared_ptr<Node> toDelete = std::move(currentNode->next);
			currentNode->next = std::move(toDelete->next);
			currentSize--;
			return true;
		}
		currentNode = currentNode->next.get();
	}
	return false;
}

CustomList::~CustomList()
{
}

std::unique_ptr<Node> CustomList::createNewNode(int value)
{
	++currentSize;
	return std::make_unique<Node>(value);
}
