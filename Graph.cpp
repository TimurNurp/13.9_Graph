#include "Graph.h"

Graph::~Graph()
{	
	vertexCount = 0;

	if (vertexes != nullptr)
		delete[] vertexes;

}

void Graph::addVertex(std::string& name)
{
	if (vertexCount <= SIZE) {
		vertexes[vertexCount].setName(name) ;
		vertexCount++;
	}
	else
		std::cout << "Graf is overflow" << std::endl;

}

void Graph::addEdge(std::string& name, std::string& friend_)
{
	for (int i = 0; i < vertexCount; i++)
		if (vertexes[i].getName() == name) {
			vertexes[i].addEdge(friend_);
		}

		else if (vertexes[i].getName() == friend_) {
			vertexes[i].addEdge(name);
		}

}

std::string Graph::getVertex(const int &index)
{
	return vertexes[index].getName();
}

int Graph::getCountEdge(int& index)
{
	return vertexes[index].friendCount;
}

std::string Graph::getEdge(int& index1, int& index2)
{
	return vertexes[index1].getEdge(index2);
}

bool Graph::isFreinds(const int& name1, const int& name2) 
{
	for (int i = 0; i < vertexes[name1].friendCount; i++)
		if (vertexes[name2].getName() == vertexes[name1].getEdge(i))
			return true;
	return false;
}


void Graph::findFriends(const std::string& name, const int& leigth)
{
	int start = 0; //индекс имени, точка входа

	for (int i = 0; i < vertexCount; i++) //поиск индекса имени
		if (vertexes[i].getName() == name) {
			start = i;
		}

	int* queue_to_visit = new int[SIZE] {}; // очередь вершин для обхода
	int queueCount = 0;

	bool* visited = new bool[SIZE] {}; // список посещенных вершин

	for (int i = 0; i < SIZE; i++)
		visited[i] = false;

	int chainsVertex = leigth; //количество друзей

	queue_to_visit[queueCount++] = start; // кладем в очередь начальную вершину

	while (queueCount > 0)
	{
		// взятие из очереди вершины
		int current = queue_to_visit[0];

		//сдвиг очереди на 1 влево
		for (int i = 0; i < queueCount; i++) {
			queue_to_visit[i] = queue_to_visit[i + 1];
		}
		//уменьшение счетчика вершин в очереди
		--queueCount;

		//отметка посещении вершины
		visited[current] = true;

		std::cout << vertexes[current].getName() << " -> ";


		// поиск смежных вершин и добавление их в очередь
		if(chainsVertex  > 0) 
		for (int i = 0; i < SIZE; i++)
		{
			bool alreadyAdded = false;
			for (int j = 0; j < queueCount; j++) // просмотр очереди и исключение добавленных вершин
				if (queue_to_visit[j] == i) {
					alreadyAdded = true;
					break;
				}

			 // перебор ребер вершины
				if ((!alreadyAdded) && (!visited[i]) && isFreinds(current, i)) {
					queue_to_visit[queueCount] = i;
					++queueCount;
				}
		}
		--chainsVertex;
	}
	std::cout << std::endl;


	delete[] queue_to_visit;
	delete[] visited;

}
