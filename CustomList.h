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


	bool DeleteByValue(int value);//delete first value with value
	~CustomList();
private:
	std::unique_ptr<Node> root;
};

