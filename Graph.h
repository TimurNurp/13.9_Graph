#pragma once
#include <string>
#include <iostream>

#define SIZE 15


struct Edge {  // ��������� �����
    std::string friend_; // � ����� ������� �����

    Edge() = default;
    Edge(const std::string& name) : friend_(name) {};
 
};

class Vertex {  // ��������� �������

    Edge* friends = new Edge[SIZE]; // �����, ������� �� �������
    std::string name_;  // ����� �������
 
public: 
    int friendCount = 0;
    
    Vertex() = default;

    Vertex(const std::string& name) : name_(name) {};
   
    ~Vertex() {
        if (friends != nullptr)
            delete[] friends;
        friendCount = 0;
    }
    // ���������� ����� ��� ��������
    void addEdge(const std::string& newFriend) {
        if (friendCount < SIZE) {
            friends[friendCount].friend_ = newFriend;
            ++friendCount;
        }
        else
            std::cout << "friends array is overflow" << std::endl;
        
    }
    // �������� ��� �����
    std::string getEdge(int& index) {
        return friends[index].friend_;
    }
    // �������� ��� 
    std::string getName() {
        return name_;
    }
    // ���������� ���
    void setName(std::string& name) {
        name_ = name;
    }

};


class Graph{
    private:            
        Vertex* vertexes = new Vertex[SIZE]; 


    public:
        int vertexCount = 0;

        Graph() = default;

        ~Graph();
        // �������� ��������
        void addVertex(std::string& name);
        // �������� ����� ��� ��������
        void addEdge(std::string& name, std::string& friend_);
        // �������� ��� �������� (������ � �������)
        std::string getVertex(const int& index);
        // �������� ���-�� ������ ��������
        int getCountEdge(int& index);
        // �������� ��� ����� ��������(�������, ����)
        std::string getEdge(int& index1, int& index2);
        bool isFreinds(const int& name1, const int& name2);
        //����� ������ ������������� ������ �� ����(name), ����� �������(leigth)
        void findFriends(const std::string& name, const int& leigth);

      
      

};

