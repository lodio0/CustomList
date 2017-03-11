#pragma once
#include<memory>
struct Node
{
	Node(int value) : value(std::make_unique<int>(value)) , next(nullptr) {}
	std::unique_ptr<int> value;
	std::unique_ptr<Node> next;
};
class CustomList
{
public:
	CustomList();
	CustomList(int value);

	int GetFirstValue(); // throw exeption when lisrt is empty

	bool AddFirst(int value);

	int Size();

	bool DeleteByValue(int value);//delete first value with value
	bool DeleteFirst(); // return true if can delete first element

	~CustomList();
private:
	std::unique_ptr<Node> createNewNode(int value);
	bool deleteAfterNode(Node* node);

	int currentSize =0 ;
	std::unique_ptr<Node> root;
};

