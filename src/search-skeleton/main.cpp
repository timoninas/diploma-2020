#include "SetGraph.hpp"

bool checkResults(std::shared_ptr< std::deque<int> > result, std::shared_ptr< std::deque<int> > expectedVertex, std::shared_ptr< std::deque<int> > unexpectedVertex);

void printResult(bool isOK);

void testLogic() {
    // Graph 1
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
        graph.AddEdge(13, 15);
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

//        graph.PrintVertices();
//        graph.SearchSkeletonV2({27, 11}, {0, 0});
    }

    // Graph 3
    {
        SetGraph graph;

        graph.AddVertex(4, 21); // 0
        graph.AddVertex(15, 21); // 1
        graph.AddVertex(24, 20); // 2
        graph.AddVertex(9, 17); // 3
        graph.AddVertex(5, 16); // 4
        graph.AddVertex(22, 15); // 5
        graph.AddVertex(15, 14); // 6
        graph.AddVertex(-2, 12); // 7
        graph.AddVertex(10, 12); // 8
        graph.AddVertex(30, 8); // 9
        graph.AddVertex(4, 11); // 10
        graph.AddVertex(16, 9); // 11
        graph.AddVertex(10, 7); // 12
        graph.AddVertex(24, 4); // 13
        graph.AddVertex(4, 6); // 14
        graph.AddVertex(14, 4); // 15
        graph.AddVertex(8, 2); // 16
        graph.AddVertex(18, 1); // 17
        graph.AddVertex(24, 0); // 18
        graph.AddVertex(0, 0); // 19
        graph.AddVertex(12, -3); // 20
        graph.AddVertex(4, -5); // 21
        graph.AddVertex(32, -2); // 22

        graph.AddEdge(0, 1);
        graph.AddEdge(0, 3);
        graph.AddEdge(0, 4);
        graph.AddEdge(0, 7);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 2);
        graph.AddEdge(1, 5);
        graph.AddEdge(1, 6);
        graph.AddEdge(2, 5);
        graph.AddEdge(2, 9);
        graph.AddEdge(3, 4);
        graph.AddEdge(3, 8);
        graph.AddEdge(3, 6);
        graph.AddEdge(4, 7);
        graph.AddEdge(4, 10);
        graph.AddEdge(5, 6);
        graph.AddEdge(5, 11);
        graph.AddEdge(5, 13);
        graph.AddEdge(5, 9);
        graph.AddEdge(6, 8);
        graph.AddEdge(6, 11);
        graph.AddEdge(7, 10);
        graph.AddEdge(7, 14);
        graph.AddEdge(7, 19);
        graph.AddEdge(8, 11);
        graph.AddEdge(8, 12);
        graph.AddEdge(8, 14);
        graph.AddEdge(8, 10);
        graph.AddEdge(9, 13);
        graph.AddEdge(9, 18);
        graph.AddEdge(10, 14);
        graph.AddEdge(11, 12);
        graph.AddEdge(11, 15);
        graph.AddEdge(11, 17);
        graph.AddEdge(11, 13);
        graph.AddEdge(12, 14);
        graph.AddEdge(12, 16);
        graph.AddEdge(12, 15);
        graph.AddEdge(13, 17);
        graph.AddEdge(13, 18);
        graph.AddEdge(14, 16);
        graph.AddEdge(14, 19);
        graph.AddEdge(15, 16);
        graph.AddEdge(15, 20);
        graph.AddEdge(15, 17);
        graph.AddEdge(16, 19);
        graph.AddEdge(16, 20);
        graph.AddEdge(17, 20);
        graph.AddEdge(17, 18);
        graph.AddEdge(18, 20);
        graph.AddEdge(18, 22);
        graph.AddEdge(19, 20);
        graph.AddEdge(19, 21);

//        graph.PrintVertices();
//        graph.SearchSkeletonV2(22, 21);
    }
//
    // Graph 2
    {
        SetGraph graph;

        graph.AddVertex(0, 0); // 0
        graph.AddVertex(4, 3); // 1
        graph.AddVertex(8, 4); // 2
        graph.AddVertex(12, 4); // 3
        graph.AddVertex(10, 8); // 4
        graph.AddVertex(0, 4); // 5
        graph.AddVertex(-3, 3); // 6
        graph.AddVertex(-4, 0); // 7
        graph.AddVertex(-7, -2); // 8
        graph.AddVertex(-6, 3); // 9
        graph.AddVertex(-9, 3); // 10
        graph.AddVertex(-5, 6); // 11
        graph.AddVertex(-7, 8); // 12
        graph.AddVertex(-3, 9); // 13
        graph.AddVertex(-3, -3); // 14
        graph.AddVertex(-6, -6); // 15
        graph.AddVertex(-7, -10); // 16
        graph.AddVertex(1, -4); // 17
        graph.AddVertex(1, -9); // 18
        graph.AddVertex(3, -11); // 19
        graph.AddVertex(6, -9); // 20
        graph.AddVertex(5, -5); // 21
        graph.AddVertex(3, -2); // 22
        graph.AddVertex(8, 0); // 23
        graph.AddVertex(10, 4.5); // 24
        graph.AddVertex(-15, -13); // 25
        graph.AddVertex(11, 11); // 26

        graph.AddEdge(0, 1);
        graph.AddEdge(1, 2);
        graph.AddEdge(2, 3);
        graph.AddEdge(3, 4);
        graph.AddEdge(2, 4);
        graph.AddEdge(0, 5);
        graph.AddEdge(0, 6);
        graph.AddEdge(5, 6);
        graph.AddEdge(0, 7);
        graph.AddEdge(7, 8);
        graph.AddEdge(7, 9);
        graph.AddEdge(9, 10);
        graph.AddEdge(9, 11);
        graph.AddEdge(11, 12);
        graph.AddEdge(12, 13);
        graph.AddEdge(13, 11);
        graph.AddEdge(0, 14);
        graph.AddEdge(14, 15);
        graph.AddEdge(15, 16);
        graph.AddEdge(0, 17);
        graph.AddEdge(17, 21);
        graph.AddEdge(21, 20);
        graph.AddEdge(20, 19);
        graph.AddEdge(19, 18);
        graph.AddEdge(18, 17);
        graph.AddEdge(0, 22);
        graph.AddEdge(22, 23);
        graph.AddEdge(23, 24);
        graph.AddEdge(25, 26);

//        graph.PrintVertices();
//        graph.SearchSkeleton(5, 3);
    }
    
    // Graph 4
    {
        SetGraph graph;
        
        graph.AddVertex(-1000, -1000); // 0
        graph.AddVertex(-3, 5); // 1
        graph.AddVertex(-2, 2); // 2
        graph.AddVertex(0, 0); // 3
        graph.AddVertex(3, -3); // 4
        graph.AddVertex(7, -5); // 5
        graph.AddVertex(9, -9); // 6
        graph.AddVertex(11, -7); // 7
        graph.AddVertex(10, -4); // 8
        graph.AddVertex(15, -7); // 9
        graph.AddVertex(16, -9); // 10
        graph.AddVertex(19, -10); // 11
        graph.AddVertex(19, -7); // 12
        graph.AddVertex(24, -5); // 13
        graph.AddVertex(28, -2); // 14
        graph.AddVertex(33, 1); // 15
        graph.AddVertex(3, 0.5); // 16 (3, 1)
        graph.AddVertex(7, -1); // 17
        graph.AddVertex(11, -2); // 18
        graph.AddVertex(15, -3); // 19
        graph.AddVertex(18, -4); // 20
        graph.AddVertex(17, -1); // 21
        graph.AddVertex(14, 0); // 22
        graph.AddVertex(22, -3); // 23
        graph.AddVertex(26, -1); // 24
        graph.AddVertex(29, 0); // 25
        graph.AddVertex(7, -0.5); // 26
        graph.AddVertex(11, 2); // 27
        graph.AddVertex(16, 2); // 28
        graph.AddVertex(15, 5); // 29
        graph.AddVertex(21, 2); // 30
        graph.AddVertex(26, 2); // 31
        graph.AddVertex(30, 2); // 32
        graph.AddVertex(2, 2); // 33
        graph.AddVertex(4, 4); // 34
        graph.AddVertex(8, 6); // 35
        graph.AddVertex(13, 7); // 36
        graph.AddVertex(18, 8); // 37
        graph.AddVertex(23, 7); // 38
        graph.AddVertex(27, 6); // 39
        graph.AddVertex(30, 5); // 40
        graph.AddVertex(9, 10); // 41
        
        graph.AddEdge(1, 2);
        graph.AddEdge(2, 3);
        graph.AddEdge(3, 4);
        graph.AddEdge(4, 5);
        graph.AddEdge(5, 7);
        graph.AddEdge(5, 8);
        graph.AddEdge(7, 8);
        graph.AddEdge(7, 6);
        graph.AddEdge(7, 9);
        graph.AddEdge(9, 12);
        graph.AddEdge(12, 11);
        graph.AddEdge(12, 10);
        graph.AddEdge(10, 11);
        graph.AddEdge(12, 13);
        graph.AddEdge(13, 14);
        graph.AddEdge(14, 15);
        graph.AddEdge(3, 16);
        graph.AddEdge(16, 17);
        graph.AddEdge(17, 18);
        graph.AddEdge(18, 19);
        graph.AddEdge(19, 21);
        graph.AddEdge(19, 22);
        graph.AddEdge(21, 22);
        graph.AddEdge(19, 20);
        graph.AddEdge(20, 23);
        graph.AddEdge(23, 24);
        graph.AddEdge(24, 25);
        graph.AddEdge(25, 15);
        graph.AddEdge(16, 26);
        graph.AddEdge(26, 27);
        graph.AddEdge(27, 28);
        graph.AddEdge(28, 29);
        graph.AddEdge(28, 30);
        graph.AddEdge(30, 31);
        graph.AddEdge(31, 32);
        graph.AddEdge(32, 15);
        graph.AddEdge(3, 33);
        graph.AddEdge(33, 34);
        graph.AddEdge(34, 35);
        graph.AddEdge(35, 36);
        graph.AddEdge(36, 37);
        graph.AddEdge(37, 38);
        graph.AddEdge(38, 39);
        graph.AddEdge(39, 40);
        graph.AddEdge(40, 15);
        graph.AddEdge(6, 41);
        
        graph.PrintVertices();
        graph.PrintEdges();
        
//        auto result = graph.SearchSkeletonV2({33, 1}, {0, 0});
//        auto skeleton = graph.GetSkeleton();
//        for (auto iter = skeleton->cbegin(); iter != skeleton->cend(); iter++) {
//            auto points = *iter;
//            std::cout << "(" << points.first.x << "; " << points.first.y << ") -- (" << points.second.x << "; " << points.second.y << ")" << std::endl;
//        }
        
//        graph.PrintVertices();
 
//        auto result = graph.SearchSkeletonV2(15, 1);
//        std::shared_ptr< std::deque<int> > expectResult( new std::deque<int>{ 15, 14, 13, 12, 9, 7, 5, 4, 3, 2, 1, 15, 25, 24, 23, 20, 19, 18, 17, 16, 16, 26, 27, 28, 30, 31, 32, 7, 8, 3, 33, 34, 35, 36, 37, 38, 39, 40 } );
//        std::shared_ptr< std::deque<int> > unexpectResult( new std::deque<int>{22, 21, 29, 6, 10, 11} );
//
//        printResult(checkResults(result, expectResult, unexpectResult));
    }
    
    // Graph 5
    {
        SetGraph graph;
        
        graph.AddVertex(0, 0); // 0
        graph.AddVertex(3, -2); // 1
        graph.AddVertex(7, -4); // 2
        graph.AddVertex(11, -5); // 3
        graph.AddVertex(15, -4); // 4
        graph.AddVertex(20, -3); // 5
        graph.AddVertex(27, 1); // 6
        graph.AddVertex(5, -7); // 7
        graph.AddVertex(4, -10); // 8
        graph.AddVertex(7, -10); // 9
        graph.AddVertex(4, -14); // 10
        graph.AddVertex(0, -15); // 11
        graph.AddVertex(0, -11); // 12
        graph.AddVertex(11, -8); // 13
        graph.AddVertex(11, -11); // 14
        graph.AddVertex(13, -14); // 15
        graph.AddVertex(10, -14); // 16
        graph.AddVertex(19, -6); // 17
        graph.AddVertex(19, -9); // 18
        graph.AddVertex(23, -6); // 19
        graph.AddVertex(100, 100); // 20
        
        graph.AddEdge(0, 1);
        graph.AddEdge(1, 2);
        graph.AddEdge(2, 3);
        graph.AddEdge(3, 4);
        graph.AddEdge(4, 5);
        graph.AddEdge(5, 6);
        graph.AddEdge(2, 7);
        graph.AddEdge(7, 8);
        graph.AddEdge(8, 9);
        graph.AddEdge(8, 10);
        graph.AddEdge(10, 11);
        graph.AddEdge(12, 8);
        graph.AddEdge(3, 13);
        graph.AddEdge(13, 14);
        graph.AddEdge(14, 15);
        graph.AddEdge(15, 16);
        graph.AddEdge(16, 14);
        graph.AddEdge(5, 19);
        graph.AddEdge(5, 17);
        graph.AddEdge(17, 18);
        
//        graph.PrintVertices();
// 
//        auto result = graph.SearchSkeletonV2(6, 0);
//
//        std::shared_ptr< std::deque<int> > expectResult( new std::deque<int>{0, 1, 2, 3, 4, 5, 6} );
//        std::shared_ptr< std::deque<int> > unexpectResult( new std::deque<int>{7, 13, 17, 19} );
//
//        printResult(checkResults(result, expectResult, unexpectResult));
    }
    
    // Graph 6
    {
        SetGraph graph;
        
        graph.AddVertex({0, 0}); // 0
        graph.AddVertex({3, -3}); // 1
        graph.AddVertex({7, -5}); // 2
        graph.AddVertex({10, -1}); // 3
        graph.AddVertex({15, 3}); // 4
        graph.AddVertex({22, 0}); // 5
        graph.AddVertex({27, -3}); // 6
        graph.AddVertex({30, -5}); // 7
        graph.AddVertex({14, -2}); // 8
        graph.AddVertex({19, -2}); // 9
        graph.AddVertex({16, -5}); // 10
        graph.AddVertex({11, -7}); // 11
        graph.AddVertex({17, -8}); // 12
        graph.AddVertex({24, -6}); // 13
        graph.AddVertex({25, -9}); // 14
        graph.AddVertex({20, -12}); // 15
        graph.AddVertex({15, -11}); // 16
        graph.AddVertex({10, -10}); // 17
        graph.AddVertex({12, -13}); // 18
        graph.AddVertex({7, -14}); // 19
        graph.AddVertex({9, -16}); // 20
        graph.AddVertex({4, -16}); // 21
        
        graph.AddEdge({0, 0}, {3, -3});
        graph.AddEdge({3, -3}, {10, -1});
        graph.AddEdge({10, -1}, {15, 3});
        graph.AddEdge({15, 3}, {22, 0});
        graph.AddEdge({22, 0}, {27, -3});
        graph.AddEdge({27, -3}, {30, -5});
        graph.AddEdge({3, -3}, {7, -5});
        graph.AddEdge({7, -5}, {11, -7});
        graph.AddEdge({11, -7}, {16, -5});
        graph.AddEdge({16, -5}, {14, -2});
        graph.AddEdge({14, -2}, {19, -2});
        graph.AddEdge({19, -2}, {16, -5});
        graph.AddEdge({16, -5}, {24, -6});
        graph.AddEdge({24, -6}, {30, -5});
        graph.AddEdge({30, -5}, {25, -9});
        graph.AddEdge({25, -9}, {20, -12});
        graph.AddEdge({20, -12}, {15, -11});
        graph.AddEdge({15, -11}, {10, -10});
        graph.AddEdge({10, -10}, {7, -5});
        graph.AddEdge({15, -11}, {12, -13});
        graph.AddEdge({12, -13}, {7, -14});
        graph.AddEdge({7, -14}, {9, -16});
        graph.AddEdge({9, -16}, {4, -16});
        graph.AddEdge({4, -16}, {7, -14});
        
//        graph.PrintVertices();
//        graph.PrintEdges();
//
//        auto result = graph.SearchSkeletonV2({30, -5}, {0, 0});
//        auto skeleton = graph.GetSkeleton();
//        for (auto iter = skeleton->cbegin(); iter != skeleton->cend(); iter++) {
//            auto points = *iter;
//            std::cout << "(" << points.first.x << "; " << points.first.y << ") -- (" << points.second.x << "; " << points.second.y << ")" << std::endl;
//        }
    }
    
    // Graph 7
    {
        SetGraph graph;
        
        graph.AddVertex({0, 0}); // 0
        graph.AddVertex({5, 0}); // 1
        graph.AddVertex({10, 0}); // 2
        graph.AddVertex({15, 0}); // 3
        graph.AddVertex({20, 0}); // 4
        graph.AddVertex({10, -3}); // 5
        graph.AddVertex({15, -5}); // 6
        graph.AddVertex({12, -7}); // 7
        graph.AddVertex({13, -9}); // 8
        graph.AddVertex({20, -11}); // 9
        graph.AddVertex({11, -11}); // 10
        graph.AddVertex({15, -12}); // 11
        graph.AddVertex({15, -16}); // 12
        graph.AddVertex({13, -14}); // 13
        graph.AddVertex({10, -18}); // 14
        graph.AddVertex({9, -14}); // 15
        graph.AddVertex({5, -16}); // 16
        graph.AddVertex({6, -13}); // 17
        graph.AddVertex({3, -12}); // 18
        graph.AddVertex({0, -12}); // 19
        graph.AddVertex({5, -9}); // 20
        graph.AddVertex({-3, -11}); // 21
        graph.AddVertex({-1, -8}); // 22
        graph.AddVertex({5, -5}); // 23
        graph.AddVertex({7, -8}); // 24
        
        graph.AddEdge({0, 0}, {5, 0});
        graph.AddEdge({5, 0}, {10, 0});
        graph.AddEdge({10, 0}, {15, 0});
        graph.AddEdge({15, 0}, {20, 0});
        graph.AddEdge({10, 0}, {10, -3});
        graph.AddEdge({10, -3}, {15, -5});
        graph.AddEdge({15, -5}, {12, -7});
        graph.AddEdge({15, -5}, {13, -9});
        graph.AddEdge({15, -5}, {20, -11});
        graph.AddEdge({20, -11}, {11, -11});
        graph.AddEdge({20, -11}, {15, -12});
        graph.AddEdge({20, -11}, {15, -16});
        graph.AddEdge({15, -16}, {15, -12});
        graph.AddEdge({15, -16}, {13, -14});
        graph.AddEdge({15, -16}, {10, -18});
        graph.AddEdge({10, -18}, {9, -14});
        graph.AddEdge({10, -18}, {5, -16});
        graph.AddEdge({5, -16}, {6, -13});
        graph.AddEdge({5, -16}, {3, -12});
        graph.AddEdge({5, -16}, {0, -12});
        graph.AddEdge({0, -12}, {5, -9});
        graph.AddEdge({0, -12}, {-3, -11});
        graph.AddEdge({0, -12}, {-1, -8});
        graph.AddEdge({0, -12}, {5, -5});
        graph.AddEdge({5, -5}, {7, -8});
        graph.AddEdge({5, -5}, {10, -3});
        
//        graph.PrintVertices();
//        graph.PrintEdges();
        
//        auto result = graph.SearchSkeletonV2(4, 0);
//        auto result = graph.SearchSkeletonV2({20, 0}, {0, 0});
//        auto skeleton = graph.GetSkeleton();
//        for (auto iter = skeleton->cbegin(); iter != skeleton->cend(); iter++) {
//            auto points = *iter;
//            std::cout << "(" << points.first.x << "; " << points.first.y << ") -- (" << points.second.x << "; " << points.second.y << ")" << std::endl;
//        }
    }
    
    // Graph 8
    {
        SetGraph graph;
        
        graph.AddVertex({0, 0});
        graph.AddVertex({1, -3});
        graph.AddVertex({1, -6});
        graph.AddVertex({2, 3});
        graph.AddVertex({7, -2});
        graph.AddVertex({5, -6});
        graph.AddVertex({6, -10});
        graph.AddVertex({2, -13});
        graph.AddVertex({8, 3});
        graph.AddVertex({7, 7});
        graph.AddVertex({12, -2});
        graph.AddVertex({14, 1});
        graph.AddVertex({11, 4});
        graph.AddVertex({14, 5});
        graph.AddVertex({11, -5});
        graph.AddVertex({12, -8});
        graph.AddVertex({10, -11});
        graph.AddVertex({16, -3});
        graph.AddVertex({18, 0});
        graph.AddVertex({18, 4});
        graph.AddVertex({19, 7});
        graph.AddVertex({22, 6});
        graph.AddVertex({18, -5});
        graph.AddVertex({17, -8});
        graph.AddVertex({20, -10});
        graph.AddVertex({18, -12});
        graph.AddVertex({14, -11});
        graph.AddVertex({24, -2});
        graph.AddVertex({24, 2});
        graph.AddVertex({26, 5});
        graph.AddVertex({25, -5});
        graph.AddVertex({24, -8});
        graph.AddVertex({23, -12});
        graph.AddVertex({27, -10});
        graph.AddVertex({29, -13});
        graph.AddVertex({33, -1});
        graph.AddVertex({31, 2});
        graph.AddVertex({32, 5});
        graph.AddVertex({34, -4});
        graph.AddVertex({32, -7});
        graph.AddVertex({32, -10});
        
        graph.AddEdge({0, 0}, {2, 3});
        graph.AddEdge({1, -3}, {0, 0});
        graph.AddEdge({1, -3}, {1, -6});
        graph.AddEdge({0, 0}, {7, -2});
        graph.AddEdge({7, -2}, {5, -6});
        graph.AddEdge({5, -6}, {6, -10});
        graph.AddEdge({6, -10}, {2, -13});
        graph.AddEdge({2, -13}, {5, -6});
        graph.AddEdge({7, -2}, {8, 3});
        graph.AddEdge({8, 3}, {7, 7});
        graph.AddEdge({7, -2}, {12, -2});
        graph.AddEdge({12, -2}, {14, 1});
        graph.AddEdge({14, 1}, {11, 4});
        graph.AddEdge({14, 1}, {14, 5});
        graph.AddEdge({12, -2}, {16, -3});
        graph.AddEdge({16, -3}, {18, -5});
        graph.AddEdge({18, -5}, {17, -8});
        graph.AddEdge({17, -8}, {20, -10});
        graph.AddEdge({17, -8}, {18, -12});
        graph.AddEdge({17, -8}, {14, -11});
        graph.AddEdge({16, -3}, {18, 0});
        graph.AddEdge({18, 0}, {18, 4});
        graph.AddEdge({18, 4}, {19, 7});
        graph.AddEdge({18, 4}, {22, 6});
        graph.AddEdge({16, -3}, {24, -2});
        graph.AddEdge({24, -2}, {24, 2});
        graph.AddEdge({24, 2}, {26, 5});
        graph.AddEdge({24, -2}, {25, -5});
        graph.AddEdge({25, -5}, {24, -8});
        graph.AddEdge({24, -8}, {27, -10});
        graph.AddEdge({27, -10}, {29, -13});
        graph.AddEdge({24, -8}, {23, -12});
        graph.AddEdge({24, -2}, {33, -1});
        graph.AddEdge({33, -1}, {31, 2});
        graph.AddEdge({31, 2}, {32, 5});
        graph.AddEdge({33, -1}, {34, -4});
        graph.AddEdge({34, -4}, {32, -7});
        graph.AddEdge({32, -7}, {32, -10});
        
//        graph.PrintVertices();
//        graph.PrintEdges();
//
//        auto result = graph.SearchSkeletonV2({33, -1}, {0, 0});
//        auto skeleton = graph.GetSkeleton();
//        for (auto iter = skeleton->cbegin(); iter != skeleton->cend(); iter++) {
//            auto points = *iter;
//            std::cout << "(" << points.first.x << "; " << points.first.y << ") -- (" << points.second.x << "; " << points.second.y << ")" << std::endl;
//        }
    }
    
    // Graph 8
    {
        SetGraph graph;
        
        graph.AddVertex({0, 0});
        graph.AddVertex({0, -4});
        graph.AddVertex({0, -8});
        graph.AddVertex({0, 4});
        graph.AddVertex({0, 8});
        graph.AddVertex({4, 0});
        graph.AddVertex({4, -4});
        graph.AddVertex({4, -8});
        graph.AddVertex({4, 4});
        graph.AddVertex({4, 8});
        graph.AddVertex({8, 0});
        graph.AddVertex({8, -4});
        graph.AddVertex({8, -8});
        graph.AddVertex({8, 4});
        graph.AddVertex({8, 8});
        graph.AddVertex({12, 0});
        graph.AddVertex({12, -4});
        graph.AddVertex({12, -8});
        graph.AddVertex({12, 4});
        graph.AddVertex({12, 8});
        graph.AddVertex({16, 0});
        graph.AddVertex({16, -4});
        graph.AddVertex({16, -8});
        graph.AddVertex({16, 4});
        graph.AddVertex({16, 8});
        graph.AddVertex({20, 0});
        graph.AddVertex({20, -4});
        graph.AddVertex({20, -8});
        graph.AddVertex({20, 4});
        graph.AddVertex({20, 8});
        
        graph.AddEdge({0, 0}, {4, 0});
        graph.AddEdge({0, 0}, {0, 4});
        graph.AddEdge({0, 0}, {0, -4});
        
        graph.AddEdge({0, 4}, {4, 4});
        graph.AddEdge({0, 4}, {0, 8});
        
        graph.AddEdge({0, -4}, {4, -4});
        graph.AddEdge({0, -4}, {0, -8});
        
        graph.AddEdge({0, 8}, {4, 8});
        graph.AddEdge({0, -8}, {4, -8});
        
        graph.AddEdge({4, 0}, {8, 0});
        graph.AddEdge({4, 0}, {4, -4});
        graph.AddEdge({4, 0}, {4, 4});
        graph.AddEdge({4, -4}, {8, -4});
        graph.AddEdge({4, -4}, {4, -8});
        graph.AddEdge({4, -8}, {8, -8});
        graph.AddEdge({4, 4}, {8, 4});
        graph.AddEdge({4, 4}, {4, 8});
        graph.AddEdge({4, 8}, {8, 8});
        
        graph.AddEdge({8, 0}, {12, 0});
        graph.AddEdge({8, 0}, {8, -4});
        graph.AddEdge({8, -4}, {12, -4});
        graph.AddEdge({8, -4}, {8, -8});
        graph.AddEdge({8, -8}, {12, -8});
        graph.AddEdge({8, 0}, {8, 4});
        graph.AddEdge({8, 4}, {12, 4});
        graph.AddEdge({8, 4}, {8, 8});
        graph.AddEdge({8, 8}, {12, 8});
        
        graph.AddEdge({12, 0}, {16, 0});
        graph.AddEdge({12, 0}, {12, -4});
        graph.AddEdge({12, -4}, {16, -4});
        graph.AddEdge({12, -4}, {12, -8});
        graph.AddEdge({12, -8}, {16, -8});
        graph.AddEdge({12, 0}, {12, 4});
        graph.AddEdge({12, 4}, {16, 4});
        graph.AddEdge({12, 4}, {12, 8});
        graph.AddEdge({12, 8}, {16, 8});
        
        graph.AddEdge({16, 0}, {20, 0});
        graph.AddEdge({16, 0}, {16, -4});
        graph.AddEdge({16, -4}, {20, -4});
        graph.AddEdge({16, -4}, {16, -8});
        graph.AddEdge({16, -8}, {20, -8});
        graph.AddEdge({16, 0}, {16, 4});
        graph.AddEdge({16, 4}, {20, 4});
        graph.AddEdge({16, 4}, {16, 8});
        graph.AddEdge({16, 8}, {20, 8});
        
        graph.AddEdge({20, 0}, {20, 4});
        graph.AddEdge({20, 4}, {20, 8});
        graph.AddEdge({20, 0}, {20, -4});
        graph.AddEdge({20, -4}, {20, -8});
        
        graph.PrintVertices();
        graph.PrintEdges();
        
//        auto result = graph.SearchSkeletonV2({20, 0}, {0, 0});
//        auto skeleton = graph.GetSkeleton();
//        for (auto iter = skeleton->cbegin(); iter != skeleton->cend(); iter++) {
//            auto points = *iter;
//            std::cout << "(" << points.first.x << "; " << points.first.y << ") -- (" << points.second.x << "; " << points.second.y << ")" << std::endl;
//        }
    }
    
    // Egora Graph 1
    {
        SetGraph graph;
        
        graph.AddVertex({0, 0});
        graph.AddVertex({5, -2});
        graph.AddVertex({13, -10});
        graph.AddVertex({18, 9});
        graph.AddVertex({24, 4});
        
        graph.AddEdge({24, 4}, {18, 9});
        graph.AddEdge({18, 9}, {13, -10});
        graph.AddEdge({5, -2}, {13, -10});
        graph.AddEdge({18, 9}, {5, -2});
        graph.AddEdge({0, 0}, {5, -2});
        
        auto result = graph.SearchSkeletonV2({24, 4}, {0, 0});
        auto skeleton = graph.GetSkeleton();
        for (auto iter = skeleton->cbegin(); iter != skeleton->cend(); iter++) {
            auto points = *iter;
            auto pointFirst = get<0>(points);
            auto pointSecond = get<1>(points);
            std::cout << "(" << pointFirst.x << "; " << pointFirst.y << ") -- (" << pointSecond.x << "; " << pointSecond.y << ")" << std::endl;
        }
    }
    
    // Egora Graph 2
    {
        SetGraph graph;
        
        graph.AddVertex({0, 0});
        graph.AddVertex({6, -5});
        graph.AddVertex({11, -4});
        graph.AddVertex({12, -7});
        graph.AddVertex({14, 6});
        graph.AddVertex({21, -3});
        graph.AddVertex({27, 0});
        
        graph.AddEdge({0, 0}, {6, -5});
        graph.AddEdge({6, -5}, {12, -7});
        graph.AddEdge({6, -5}, {11, -4});
        graph.AddEdge({6, -5}, {14, 6});
        graph.AddEdge({12, -7}, {11, -4});
        graph.AddEdge({12, -7}, {21, -3});
        graph.AddEdge({11, -4}, {21, -3});
        graph.AddEdge({11, -4}, {14, 6});
        graph.AddEdge({14, 6}, {21, -3});
        graph.AddEdge({21, -3}, {27, 0});
        
        auto result = graph.SearchSkeletonV2({27, 0}, {0, 0});
        auto skeleton = graph.GetSkeleton();
        for (auto iter = skeleton->cbegin(); iter != skeleton->cend(); iter++) {
            auto points = *iter;
            auto pointFirst = get<0>(points);
            auto pointSecond = get<1>(points);
            std::cout << "(" << pointFirst.x << "; " << pointFirst.y << ") -- (" << pointSecond.x << "; " << pointSecond.y << ")" << std::endl;
        }
    }
}

bool checkResults(std::shared_ptr< std::deque<int> > result, std::shared_ptr< std::deque<int> > expectedVertex, std::shared_ptr< std::deque<int> > unexpectedVertex) {
    for (auto iterRes = result->cbegin(); iterRes != result->cend(); iterRes++) {
        bool isFind = false;
        for (auto iterExpect = expectedVertex->cbegin(); iterExpect != expectedVertex->cend(); iterExpect++) {
            if (*iterRes == *iterExpect) {
                isFind = true;
            }
        }
        
        if (!isFind) {
            return false;
        }
    }
    
    for (auto iterRes = result->cbegin(); iterRes != result->cend(); iterRes++) {
        bool isFind = false;
        for (auto iterUnexpect = unexpectedVertex->cbegin(); iterUnexpect != unexpectedVertex->cend(); iterUnexpect++) {
            if (*iterRes == *iterUnexpect) {
                isFind = true;
            }
        }
        
        if (isFind) {
            return false;
        }
    }
    
    return true;
}

void printResult(bool isOK) {
    if (isOK) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "NOT OK" << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    
    testLogic();
    
    return 0;
}
