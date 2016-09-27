class CQueue
{
private:
	class Node
	{
	public:
		string data;
		Node* back;
	};

	Node* front = NULL;
	Node* end = NULL;

public:
	bool enqueue(string s){
		Node* neew = new Node;

		neew->data = s;
		neew->back = NULL;

		if (end != NULL){
			end->back = neew; 
		}

		end = neew; 
		
		// if there's no elements in queue
		if (front == NULL)
			front = neew;

		return true;
	}

	string dequeue(){
		if (front == NULL || end == NULL){
			front = NULL;
			end = NULL;
			return "0";
		}


		Node* aux = front;

		if (aux->back == NULL)
		{
		
			front = NULL;
			end = NULL;
		
		}else{
			front = aux->back;
		}

		

		string tmp = aux->data;

		delete aux;

		return tmp;		
	}
};