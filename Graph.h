#pragma once
#include <string>
#include <iostream>

#define SIZE 15


struct Edge {  // структура ребра
    std::string friend_; // в какую вершину ведет

    Edge() = default;
    Edge(const std::string& name) : friend_(name) {};
 
};

class Vertex {  // структура вершины

    Edge* friends = new Edge[SIZE]; // ребра, ведущие из вершины
    std::string name_;  // номер вершины
 
public: 
    int friendCount = 0;
    
    Vertex() = default;

    Vertex(const std::string& name) : name_(name) {};
   
    ~Vertex() {
        if (friends != nullptr)
            delete[] friends;
        friendCount = 0;
    }
    // добавление связи для человека
    void addEdge(const std::string& newFriend) {
        if (friendCount < SIZE) {
            friends[friendCount].friend_ = newFriend;
            ++friendCount;
        }
        else
            std::cout << "friends array is overflow" << std::endl;
        
    }
    // получить имя друга
    std::string getEdge(int& index) {
        return friends[index].friend_;
    }
    // получить имя 
    std::string getName() {
        return name_;
    }
    // установить имя
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
        // добавить человека
        void addVertex(std::string& name);
        // добавить друга для человека
        void addEdge(std::string& name, std::string& friend_);
        // получить имя человека (индекс в массиве)
        std::string getVertex(const int& index);
        // получить кол-во друзей человека
        int getCountEdge(int& index);
        // получить имя друга человека(человек, друг)
        std::string getEdge(int& index1, int& index2);
        bool isFreinds(const int& name1, const int& name2);
        //поиск друзей отностительно одного из имен(name), длина цепочки(leigth)
        void findFriends(const std::string& name, const int& leigth);

      
      

};

