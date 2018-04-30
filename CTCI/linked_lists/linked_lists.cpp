

struct Node
{
	int data;
	Node* next;
};


bool has_cycle1(Node* head)
{
	if (!head)
		return false;

	Node* tortoise = head;
	Node* hare = head->next;

	while (tortoise != 0 && hare->next != 0)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
			return true;
	}

	return false;
}


bool has_cycle2(Node* head)
{
	if (head == nullptr)
		return false;

	while (head->next != nullptr)
	{
		if (head->next->data > head->data)
		{
			return true;
		}
		head->data += 1;
		head = head->next;
	}
	return false;
}

int main()
{
	return 0;
}