#include "SetGraph.hpp"

void testLogic() {
    {
        SetGraph graph;
        
        graph.AddVertex(0, 0); // 0
        graph.AddVertex(2, -2); // 1
        graph.AddVertex(5, -1); // 2
        graph.AddVertex(6, 1); // 3
        graph.AddVertex(7, -3); // 4
        graph.AddVertex(6, -6); // 5
        graph.AddVertex(7, -8); // 6
        graph.AddVertex(3, -9); // 7
        graph.AddVertex(1, -7); // 8
        graph.AddVertex(4, -11); // 9
        graph.AddVertex(10, -4); // 10
        graph.AddVertex(11, -1); // 11
        graph.AddVertex(13, -5); // 12
        graph.AddVertex(16, -7); // 13
        graph.AddVertex(14, -10); // 14
        graph.AddVertex(15, -14); // 15
        graph.AddVertex(9, -12); // 16
        graph.AddVertex(12, -9); // 17
        graph.AddVertex(18, -4); // 18
        graph.AddVertex(20, -2); // 19
        graph.AddVertex(23, -3); // 20
        graph.AddVertex(22, -8); // 21
        graph.AddVertex(21, 0); // 22
        graph.AddVertex(18, 6); // 23
        graph.AddVertex(22, 4); // 24
        graph.AddVertex(24, 5); // 25
        graph.AddVertex(20, 10); // 26
        graph.AddVertex(18, 11); // 27
        graph.AddVertex(17, 7); // 28
        graph.AddVertex(24, 8); // 29
        graph.AddVertex(27, 11); // 30
        graph.AddVertex(23, 10.5); // 31
        graph.AddVertex(21.5, 14); // 32
        
        graph.AddEdge(0, 1);
        graph.AddEdge(1, 2);
        graph.AddEdge(2, 3);
        graph.AddEdge(2, 4);
        graph.AddEdge(4, 5);
        graph.AddEdge(5, 6);
        graph.AddEdge(5, 7);
        graph.AddEdge(7, 8);
        graph.AddEdge(7, 9);
        graph.AddEdge(4, 10);
        graph.AddEdge(10, 11);
        graph.AddEdge(10, 12);
        graph.AddEdge(12, 13);
        graph.AddEdge(13, 14);
        graph.AddEdge(14, 17);
        graph.AddEdge(14, 15);
        graph.AddEdge(14, 15);
        graph.AddEdge(16, 17);
        graph.AddEdge(16, 15);
        graph.AddEdge(13, 18);
        graph.AddEdge(18, 19);
        graph.AddEdge(19, 20);
        graph.AddEdge(20, 21);
        graph.AddEdge(19, 22);
        graph.AddEdge(19, 21);
        graph.AddEdge(22, 23);
        graph.AddEdge(23, 24);
        graph.AddEdge(23, 25);
        graph.AddEdge(24, 25);
        graph.AddEdge(23, 26);
        graph.AddEdge(23, 27);
        graph.AddEdge(23, 28);
        graph.AddEdge(26, 29);
        graph.AddEdge(29, 30);
        graph.AddEdge(30, 32);
        graph.AddEdge(26, 31);
        graph.AddEdge(26, 32);
        
        graph.PrintVertices();
        
        graph.GetNextEdges(31);
    }
}

int main(int argc, const char * argv[]) {
    
    testLogic();
    
    return 0;
}
