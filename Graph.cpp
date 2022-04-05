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
	int start = 0; //������ �����, ����� �����

	for (int i = 0; i < vertexCount; i++) //����� ������� �����
		if (vertexes[i].getName() == name) {
			start = i;
		}

	int* queue_to_visit = new int[SIZE] {}; // ������� ������ ��� ������
	
	int queueCount = 0;

	bool* visited = new bool[SIZE] {}; // ������ ���������� ������

	for (int i = 0; i < SIZE; i++)
		visited[i] = false;

	int* arrContact = new int[leigth]{};  // ���������� ������ �� ������ ����� �����������
	int handshake = leigth - 1 ; // ���������� ������ �����������
	int subcycle = 0; // ������� ������ � ����� �����

	queue_to_visit[queueCount++] = start ; // ������ � ������� ��������� �������

	while (queueCount > 0)
	{
		// ������ �� ������� �������
		int current = queue_to_visit[0];
		
		//����� ������� �� 1 �����
		for (int i = 0; i < queueCount; i++) {
			queue_to_visit[i] = queue_to_visit[i + 1];
		}
		//���������� �������� ������ � �������
		--queueCount;

		//������� ��������� �������
		visited[current] = true;

		std::cout << vertexes[current].getName() << " -> ";
			
		if ( (arrContact[0] == 0 || handshake > 0))
			// ����� ������� ������ � ���������� �� � �������
			for (int i = 0; i < SIZE; i++)
			{
				bool alreadyAdded = false;
				for (int j = 0; j < queueCount; j++) // �������� ������� � ���������� ����������� ������
					if (queue_to_visit[j] == i) {
						alreadyAdded = true;
						break;
					}

				 // ������� ����� �������
					if ((!alreadyAdded) && (!visited[i]) && isFreinds(current, i)) {
						queue_to_visit[queueCount] = i;
						++queueCount;
						
						if(subcycle == 0) {
							arrContact[handshake] += 1;
						}
						else{
							arrContact[handshake-1] += 1;
						}
						
						
					}
			}
	
		
		if (arrContact[handshake] <= subcycle)//
		{
			--handshake;
			subcycle = 0;
		}

		++subcycle;

	}

	delete[] queue_to_visit;
	delete[] visited;

}
