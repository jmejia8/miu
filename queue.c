// queue structure
typedef struct _node
{
	string index;
	struct _node* back;
} Queue;


//
// General fuction for the queue
// Enqueue 
// Dequeue
//
int enqueue(Queue** front, Queue** end, string index){
	Queue* new_node = (Queue *) malloc(sizeof(Queue));

	// if somethig is wrong return false
	if (new_node == NULL)
	{
		printf("Error: malloc in enqueue\n");
		exit(0);
	}

	new_node->index  = index;
	new_node->back  = NULL;

	if (*end != NULL){
		Queue* my_end = *end;
		my_end->back = new_node; 
	}

	*end = new_node; 
	
	// if there's no elements in queue
	if (*front == NULL)
		*front = new_node;

	return 1;
}

string dequeue(Queue** front, Queue** end){


	if (*front == NULL || *end == NULL){
		*front = NULL;
		*end = NULL;
		return "0";
	}


	Queue* aux = *front;

	if (aux->back == NULL)
	{
	
		*front = NULL;
		*end = NULL;
	
	}else{
		*front = aux->back;
	}

	

	string tmp = aux->index;

	free(aux);

	return tmp;	
}