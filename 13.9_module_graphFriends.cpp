// 13.9_module_graphFriends.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <cstdlib>

#include "Graph.h"

int main()
{
    Graph graph;
    std::string names[] = { "Artem", "Anna", "Alex", "Sergey", "Roma", "Ivan", "Nik", "Anastasia", "Stas", "Vika", "Valeria", "Ksenia", "Dmidtry", "Anton", "Nata"};
    
    int countNames = sizeof(names) / sizeof(names[0]);

    //заполняем граф вершинами равными количеству индексов массива имен
    for (int i = 0; i < countNames; i++)
        graph.addVertex(names[i]);
   
    //добавляем связи в граф, индекс имени и индекс друга
    int random1 = 0;
    int random2 = 0;
    for (int i = 0; i < countNames; i++) {
        random1 = rand() % countNames;
        random2 = rand() % countNames  ;
        if(random1 == random2 && random1 > 1 && random1)
            graph.addEdge(names[random1-1], names[random2]);
        else
            graph.addEdge(names[random1], names[random2]);
    }
    
    //вывод заполненного графа
    for (int i = 0; i < graph.vertexCount; i++) {
        std::cout << "name: \t" << graph.getVertex(i) << std::endl;
        std::cout << "friends: " ;
        for (int j = 0; j < (graph.getCountEdge(i)); j++)
            std::cout << graph.getEdge(i, j) << " ; ";
        std::cout << '\n' << std::endl;
    }

    graph.findFriends(graph.getVertex(4), 3);


    return 0;
}
