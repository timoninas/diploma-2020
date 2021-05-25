#include "SetGraph.hpp"

SetGraph::SetGraph(const IGraph& sendedGraph) {
    graph.resize(sendedGraph.VerticesCount());
}

void LOG(std::string message) {
    std::cout << "[LOG] " << message << std::endl;
}

int SetGraph::VerticesCount() const {
    return graph.size();
}

void SetGraph::AddVertex(double x, double y) {
    vertex_v2_t v{x, y, int(vertices.size())};
    vertices.push_back(v);
}

void SetGraph::PrintVertices() const {
    for (auto item: vertices) {
        std::cout << "\nVertex:" << std::endl;
        std::cout << item.numberVertex << " : (" << item.point.x << "," << item.point.y << ")" << std::endl;
        GetNextEdges(item.numberVertex);
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from < vertices.size());
    assert(to < vertices.size());
    assert(from >= 0);
    assert(to >= 0);
    point_t p1 = vertices[from].point;
    point_t p2 = vertices[to].point;
    edge_t e1{int(edges.size()), p1, p2, from, to};
    edges.push_back(e1);
}

const vertex_v2_t& SetGraph::GetVertex(int at) {
    assert(at >= 0);
    assert(at < vertices.size());
    return vertices[at];
}

const edge_t& SetGraph::GetEdge(int at, int fromVertexNumber) {
    assert(at >= 0);
    assert(at < edges.size());
    
    if (edges[at].numberVertices.first != fromVertexNumber) {
        edges[at].swipeVertices();
    }
    
    return edges[at];
}

const edge_t& SetGraph::GetEdge(int at) {
    assert(at >= 0);
    assert(at < edges.size());
    return edges[at];
}

std::set<edge_t, cmpAngle> SetGraph::GetNextEdges(int vertex) const {
    std::set<edge_t, cmpAngle> result;
    
    for (auto item: edges) {
        if (item.numberVertices.first == vertex || item.numberVertices.second == vertex) {
            if (item.numberVertices.first != vertex) {
                std::swap(item.numberVertices.first, item.numberVertices.second);
                std::swap(item.points.first, item.points.second);
            }
            
            result.insert(item);
        }
    }
    
    return result;
}

void SetGraph::SearchSkeletonV2(const int inputVertex, const int outputVertex) {
    // -----------------------------
    // MARK:- Подготовительная часть
    // -----------------------------
    // MARK:- Сформировать массив для каждой вершины с прилежащими ребрами
    for (auto vIter = vertices.begin(); vIter != vertices.end(); vIter++) {
        
        auto currentVertex = vIter;
        auto currentNumberVertex = currentVertex->numberVertex;
        
        std::set<edge_t, cmpAngle> angledEdges = GetNextEdges(currentNumberVertex);
        
        for (auto angIter = angledEdges.begin(); angIter != angledEdges.end(); angIter++) {
            currentVertex->numberEdges.push_back(angIter->numberEdge);
        }
        
        // MARK:- Поставить ребрам пометку dead, со степенью вершины 1
        if (currentVertex->numberEdges.size() == 1 &&
            (currentNumberVertex != inputVertex && currentNumberVertex != outputVertex)) {
            for (auto deadIter = currentVertex->numberEdges.begin(); deadIter != currentVertex->numberEdges.end(); deadIter++) {
                auto numberEdge = (*deadIter);
                edges[numberEdge].label = GraphLabels::dead;
            }
        }
    }
    
    // -----------------------------
    // MARK:- Начало алгоритма
    //        0. Инициализация
    // -----------------------------
    vertices[inputVertex].label = GraphLabels::inskeleton;
    vertices[outputVertex].label = GraphLabels::inskeleton;
    bool isFindOutputVertex = false;
    
    auto initialVertex = vertices[inputVertex];
    for (auto iter = initialVertex.numberEdges.begin(); iter != initialVertex.numberEdges.end(); iter++) {
        
        // Меняем номера вершин местами, если входящяя вершина не равна ею в ребре
        auto numberEdge = *iter;
        if (edges[numberEdge].numberVertices.first != initialVertex.numberVertex) {
            edges[numberEdge].swipeVertices();
        }
        
        // MARK:- Пропуск всех ребер, кроме посещенного
        //        Проверка на непосещенность ребра
        auto currentEdge = GetEdge(*iter);
        if (currentEdge.label != GraphLabels::notvisited) continue;
        
        // Помечаем ребро как посещенное
        currentEdge.label = GraphLabels::visited;
        edges[currentEdge.numberEdge].label = GraphLabels::visited;
        
        // MARK:- Получаем только notvisited ребра
        //        Запускаем LeftTraversal
        auto resultTravertsal = LeftTraversalWithInitializationV2(currentEdge.numberVertices.second, inputVertex, outputVertex);
        std::cout << "resultTravertsal = " << resultTravertsal << std::endl;
        if (resultTravertsal == outputVertex) {
            isFindOutputVertex = true;
            LOG("Find output vertex");
            break;
        } else if (resultTravertsal == inputVertex) {
            LOG("Come back to input vertex");
        } else {
            LOG("Something went wrong");
            assert(0);
        }
        
        std::stringstream buffer;
        buffer << "resultTravertsal = " << resultTravertsal;
        LOG(buffer.str());
    }
    
    // Если выходная вершина не была найдена
    // Заканчиваем алгоритм
    if (!isFindOutputVertex) {
        LOG("Not found vertex / Different graph connectivity");
        return;
    }
    
    LOG("Continue Algorithm");
    // MARK:- Правый обход
    //        Идем правым обходом от выхода до входа
    //        Помечаем вершины как ВО и добавляем их
    //        В стек
    auto vertex = GetVertex(outputVertex);
    std::cout << "LOG " << vertex.label << std::endl;
    
    auto inSkeletonStack = RightTraversal(vertex.numberVertex);
    for (auto iter = inSkeletonStack->begin(); iter != inSkeletonStack->end(); iter++) {
        auto vertex = GetVertex(*iter);
        std::cout << "Number: " << vertex.numberVertex << std::endl;
    }
    std::cout;
}

std::shared_ptr<std::deque<int>> SetGraph::RightTraversal(const int& submittedVertex) {
    
    std::shared_ptr< std::deque<int> > traversalStack( new std::deque<int>() );;
    
    auto currentVertex = GetVertex(submittedVertex);
    int size = currentVertex.numberEdges.size();
    
    traversalStack->push_back(submittedVertex);
    
    while(1) {
        auto popedVertex = GetVertex(traversalStack->back());
        
        for (auto iter = popedVertex.numberEdges.begin();
                iter != popedVertex.numberEdges.end();
                iter++) {
            auto edge = GetEdge(*iter, popedVertex.numberVertex);
            
            if (edge.label == GraphLabels::visited) {
                edges[edge.numberEdge].label = GraphLabels::inskeleton;
                traversalStack->push_back(edge.numberVertices.second);
                break;
            }
        }
    }
    
    return traversalStack;
}

int SetGraph::LeftTraversalWithInitializationV2(const int& submittedVertex, const int& inputVertex, const int& outputVertex) {
    
    auto prevVertexNumber = inputVertex;
    auto currentVertex = GetVertex(submittedVertex);
    int size = currentVertex.numberEdges.size();
    
    std::cout << std::endl << std::endl << "PATH:" << std::endl;
    
    while (1) {
        auto iter = 0;
        auto limitCrawl = 0;
        
        // MARK:- Доходим по массиву ребер у вершины до того ребра
        //        От которого пришли, чтобы со следующего начать левый обход
        for (; iter < size && limitCrawl <= size ; limitCrawl++) {
            auto tmpEdge = GetEdge(currentVertex.numberEdges[iter], currentVertex.numberVertex);
            
            if (tmpEdge.numberVertices.second == prevVertexNumber) {
                iter = (iter + 1) % size;
                break;
            }
            iter = (iter + 1) % size;
        }
        
        // MARK:- Просмотр ситуации когда мы больше
        //        Чем по одному кругу прошли по ребрам вершины
        if (limitCrawl >= size) {
            return inputVertex;
        }
        
        limitCrawl = 0;
        // MARK:- Цикл по ребрам графа левым обходом
        //        Идем начиная со следующего ребра, от которого пришли
        //        В текущую вершину :)
        while (limitCrawl <= size) {
            limitCrawl++;
            
            // Берем текующее ребро для последующей экспертизы
            auto edge = GetEdge(currentVertex.numberEdges[iter], currentVertex.numberVertex);
            
            // Смотрим если мы дошли до желаемого ребра
            // Или дошли до начального ребра, тогда заканчиваем
            // Левый обход
            if (edge.numberVertices.first == outputVertex) {
                return outputVertex;
            } else if (edge.numberVertices.first == inputVertex) {
                return inputVertex;
            }
            
            // Доп обмен вершинами. Тк нам начальная нужна на первой позиции
            if (edge.numberVertices.first != currentVertex.numberVertex) {
                edge.swipeVertices();
                edges[edge.numberEdge].swipeVertices();
            }
            
            // MARK:- Нормальный случай, когда идем левым обходом
            //        По непосещенным ребрам
            // VVV
            if (edge.label == GraphLabels::notvisited) {
                edge.label = GraphLabels::visited;
                edges[edge.numberEdge].label = GraphLabels::visited;
                
                prevVertexNumber = currentVertex.numberVertex;
                currentVertex = GetVertex(edge.numberVertices.second);
                size = currentVertex.numberEdges.size();
                
                std::cout << prevVertexNumber << " ";
                
                break;
                
            // MARK:- Случай, когда мы зашли в тупик и нам нужно выбраться
            //        Поэтому следуем по посещнным ребрам, левым обходом
            // VVV
            } else if (edge.label == GraphLabels::visited) {
                prevVertexNumber = currentVertex.numberVertex;
                currentVertex = GetVertex(edge.numberVertices.second);
                size = currentVertex.numberEdges.size();
                
                std::cout << prevVertexNumber << " ";
                
                break;
                
            // MARK:- Случай, когда дошли до мертвого ребра, который
            //        Всегда ведет в тупик
            // VVV
            } else if (edge.label == GraphLabels::dead) {
                iter = (iter + 1) % size;
                
                std::cout << "d(" <<  edge.numberVertices.second << ") ";
                
                continue;
                
            // MARK:- Случай. Нереальный
            // VVV
            } else if (edge.label == GraphLabels::inskeleton) {
                assert(0);
                
            // MARK:- Случай. Нереальный
            // VVV
            } else {
                assert(0);
            }
            iter = (iter + 1) % size;
        }
        
        // Если прошли по кругу и нет никакого результата
//        if (limitCrawl > size) {
//            return inputVertex;
//        }
    }
    
    return 0;
}


void SetGraph::SearchSkeleton(int inputVertex, int outputVertex) {
    PrintVertices();
    
    auto inputEdges = GetNextEdges(inputVertex);
    auto initialStartVertex = inputVertex;
    auto currentVertex = inputVertex;
    vertices[inputVertex].label = GraphLabels::visited;
    std::shared_ptr<std::deque<int>> initTraversal;
    
    // НАЧАЛО АЛГОРИТМА
    // 0. Инициализация
    for (auto iter = inputEdges.cbegin(); iter != inputEdges.cend(); iter++) {
        auto currentEdge = (*iter);
        if (currentEdge.label != GraphLabels::notvisited) continue;
        
        initTraversal = LeftTraversalWithInitialization(currentVertex, outputVertex);
        
        if (initTraversal->empty()) {
            currentVertex = initialStartVertex;
        } else {
            currentVertex = initTraversal->back();
        }
        
        if (currentVertex == inputVertex) {
            // Если встретился тупик, то ничего не делаем
            // TODO: Нужна проверка на цикл. Если он встретился,
            // Тогда ребра между циклом пометить посещенными
            std::cout << "NOT FINDED PATH -> NEXT ITERATION" << std::endl;
        } else if (currentVertex == outputVertex) {
            // Если дошли до выходной вершины, то выходим из цикла
            std::cout << "FIND TRAVERSAL -> BREAK LOOP" << std::endl;
            break;
        } else {
            // Сюда не должны зайти
            assert(0);
        }
    }
    
    if (initTraversal->empty()) {
        std::cout << "NON-CONNECTED GRAPH" << std::endl;
        assert(0);
    }
    
    MarkSkeletonVerteciesAndEdges(initTraversal);
    
    for (auto iter = edges.begin(); iter != edges.end(); iter++) {
        auto first = GetVertex((*iter).numberVertices.first);
        auto second = GetVertex((*iter).numberVertices.second);
        std::cout << first.numberVertex << "[" << first.label << "] " << second.numberVertex << "[" << second.label << "] " << " -> " << (*iter).label << std::endl;
    }
    
    // 1. Построение остова
    std::shared_ptr<std::deque<int>> resultTraversal;
    auto tmpVer = GetNextEdges(initTraversal->front());
    while (!initTraversal->empty()) {
        auto tmpVertex = initTraversal->front();
        initTraversal->pop_front();
        if (tmpVertex == outputVertex) {
            // Дошли до последней вершины
            // Значит весь граф обошли и все остовы построили
            std::cout << "OUTPUT VETRTEX -> REACHED" << std::endl;
            break;
        }
        
        auto nextEdges = GetNextEdges(tmpVertex);
        for (auto iter = nextEdges.begin(); iter != nextEdges.end(); iter++) {
            auto edgeNotInSkeleton = (*iter);
            // Если ребро не посещено, пропускаем итерацию
            if (edgeNotInSkeleton.label != GraphLabels::notvisited) continue;
            
            // Помечаем, как проитерированное
            edgeNotInSkeleton.label = GraphLabels::visited;
            edges[edgeNotInSkeleton.numberEdge].label = GraphLabels::visited;
            
            resultTraversal = LeftTraversalBuildingSkeleton(edgeNotInSkeleton.numberVertices.second);
            if (resultTraversal->empty()) {
                // Вернулся пустой стек
                // Пропускаем и переходим к след. итерации
                std::cout << "Returned empty stack" << std::endl;
            } else {
                // Есть содержимое в стеке
                // Новые вершины остовные
                // Добавляем в resultTraversal
                // И дальше while обработает их
                std::cout << "Returned new part of skeleton" << std::endl;
                resultTraversal->push_front(edgeNotInSkeleton.numberVertices.first);
                
                // Когда начальная и конечная вершина в деке равны
                // Переходим к следующей итерации циклаe
                if (resultTraversal->front() == resultTraversal->back()) {
                    std::cout << "Come in the same vertex" << std::endl;
                    continue;
                }
                MarkSkeletonVerteciesAndEdges(resultTraversal);
                std::cout << "First new skeleton" << std::endl;
                
                
                for (auto iter = edges.begin(); iter != edges.end(); iter++) {
                    auto first = GetVertex((*iter).numberVertices.first);
                    auto second = GetVertex((*iter).numberVertices.second);
                    std::cout << first.numberVertex << "[" << first.label << "] " << second.numberVertex << "[" << second.label << "] " << " -> " << (*iter).label << std::endl;
                }
                
                resultTraversal->pop_front();
                resultTraversal->pop_back();
                while (!resultTraversal->empty()) {
                    auto poped = resultTraversal->back();
                    resultTraversal->pop_back();
                    initTraversal->push_front(poped);
                    std::cout << "Push vertices: " << poped << std::endl;
                }
            }
        }
    }
}

std::shared_ptr<std::deque<int>> SetGraph::LeftTraversalWithInitialization(const int& currentVertexNumber, const int& stopVertexNumber) {
    
    std::shared_ptr< std::deque<int> >vertexStack( new std::deque<int>() );
    vertexStack->push_back(currentVertexNumber);
    
    while(!vertexStack->empty()) {
        auto popedVertex = vertexStack->back();
        
        auto nextEdges = GetNextEdges(popedVertex);
        bool isFinded = false;
        
        for (auto iter = nextEdges.cbegin(); iter != nextEdges.cend(); iter++) {
            
            auto iteratedEdge = (*iter);
            
            
            if (iteratedEdge.isNotvisited()) {
                edges[iteratedEdge.numberEdge].label = GraphLabels::visited;
                
                auto tmpVertex = GetVertex(iteratedEdge.numberVertices.second);
                
                if (tmpVertex.isNotvisited()) {
                    vertices[tmpVertex.numberVertex].label = GraphLabels::visited;
                    tmpVertex.label = GraphLabels::visited;
                    vertexStack->push_back(tmpVertex.numberVertex);
                    isFinded = true;
                    break;
                } else {
                    // CASE с встречой цикла
//                    visitInnerEdges(tmpVertex.numberVertex, iteratedEdge.numberEdge);
                }
            }
        }
        
        if (isFinded) {
            auto poped = vertexStack->back();
            if (poped == stopVertexNumber) {
                return vertexStack;
            }
        } else {
            vertexStack->pop_back();
        }
    }
    
    return vertexStack;
}

std::shared_ptr<std::deque<int>> SetGraph::LeftTraversalBuildingSkeleton(const int& currentVertexNumber) {
    std::shared_ptr< std::deque<int> >vertexStack( new std::deque<int>() );
    
    vertexStack->push_back(currentVertexNumber);
    
    while (!vertexStack->empty()) {
        auto poped = vertexStack->back();
        auto popedVertex = GetVertex(poped);
        auto nextEdges = GetNextEdges(poped);
        bool isFinded = false;
        bool isFindedSkeleton = false;
        
        std::cout << popedVertex.label << "] -> " << popedVertex.point.x << " " << popedVertex.point.y << std::endl;
        
        for (auto iter = nextEdges.begin(); iter != nextEdges.end(); iter++) {
            auto iteratedEdge = (*iter);
            
            if (iteratedEdge.label == GraphLabels::visited) {
                continue;
            } else if (iteratedEdge.label == GraphLabels::notvisited) {
                iteratedEdge.label = GraphLabels::visited;
                edges[iteratedEdge.numberEdge].label = GraphLabels::visited;
                
                auto tmpVertex = GetVertex(iteratedEdge.numberVertices.second);
                
                if (tmpVertex.isNotvisited()) {
                    tmpVertex.label = GraphLabels::visited;
                    vertices[tmpVertex.numberVertex].label = GraphLabels::visited;
                    
                    vertexStack->push_back(tmpVertex.numberVertex);
                    isFinded = true;
                    break;
                } else if (tmpVertex.isInskeleton()) {
                    vertexStack->push_back(tmpVertex.numberVertex);
                    isFindedSkeleton = true;
                    break;
                } else {
                    //CASE с встречой цикла
                    //visitInnerEdges(tmpVertex.numberVertex, iteratedEdge.numberEdge);
                }
            } else if (iteratedEdge.label == GraphLabels::inskeleton) {
                break;
            }
        }
        
        if (isFindedSkeleton) {
            std::cout << "Find skeleton" << std::endl;
            return vertexStack;
        }
        
        if (isFinded) {
            std::cout << "Find not visited vertex" << std::endl;
        } else {
            std::cout << "Find visited vertex" << std::endl;
            vertexStack->pop_back();
        }
    }
    
    return vertexStack;
}

void SetGraph::visitInnerEdges(const int& repeatedVertex, const int& numberEdge) {
    auto vertex = GetVertex(repeatedVertex);
    auto edge = GetEdge(numberEdge);
    std::cout << "NEXT VERTEX: " << vertex.numberVertex << " " << vertex.point.x << " " << vertex.point.y << std::endl;
    std::cout << "CURR EDGE: " << edge.numberEdge << " " << edge.numberVertices.first << " " << edge.numberVertices.second << std::endl;
    
    auto nextEdges = GetNextEdges(repeatedVertex);
    
    auto isFind = false;
    for (auto iter = nextEdges.rbegin(); iter != nextEdges.rend(); iter++) {
        auto tmpEdge = (*iter);
        std::cout << "from: " << tmpEdge.numberVertices.first << " " << tmpEdge.points.first.x << " " << tmpEdge.points.first.y << std::endl;
        std::cout << "to: " << tmpEdge.numberVertices.second << " " << tmpEdge.points.second.x << " " << tmpEdge.points.second.y << std::endl << std::endl;
        
        if (isFind == true) {
            if (tmpEdge.isVisited()) {
                std::cout << "FINDED CYCLE 2 EDGE " << tmpEdge.numberVertices.first << " " << tmpEdge.numberVertices.second << std::endl;
//                break;
            }
        } else {
            if (tmpEdge.numberEdge == numberEdge) {
                std::cout << "FINDED CYCLE 1 EDGE " << tmpEdge.numberVertices.first << " " << tmpEdge.numberVertices.second << std::endl;
                isFind = true;
            }
        }
    }
}

void SetGraph::MarkSkeletonVerteciesAndEdges(std::shared_ptr<std::deque<int>> needToMarkDeque) {
    // Отметить все вершине в стеке, как в остове
    std::vector<std::pair<int, int>> pairEdgesInSekelton;
    for (auto iter = needToMarkDeque->begin(); iter != needToMarkDeque->end(); iter++) {
        auto currentVertex = GetVertex(*iter);
        auto currentNumberVertex = currentVertex.numberVertex;
        currentVertex.label = GraphLabels::inskeleton;
        vertices[currentNumberVertex].label = GraphLabels::inskeleton;
        std::cout << currentVertex.point.x << " " << currentVertex.point.y << " " << currentVertex.label << std::endl;
        if (iter != needToMarkDeque->begin()) {
            auto firstNumberVertex = currentVertex.numberVertex;
            auto secondNumberVertex = GetVertex(*(iter - 1)).numberVertex;
            pairEdgesInSekelton.push_back(std::make_pair(firstNumberVertex, secondNumberVertex));
        }
    }
    
    // Отмечаем ребра, как вошедшие в остов
    for (auto iterEdge = edges.begin(); iterEdge != edges.end(); iterEdge++) {
        auto tmpEdge = (*iterEdge);
        // Сравнение всех пар их стека со всеми парам ребер
        for (auto iterPair = pairEdgesInSekelton.begin(); iterPair != pairEdgesInSekelton.end(); iterPair++) {
            auto tmpPair = (*iterPair);
            if  ((tmpPair.first == tmpEdge.numberVertices.first &&
                 tmpPair.second == tmpEdge.numberVertices.second) ||
                (tmpPair.second == tmpEdge.numberVertices.first &&
                  tmpPair.first == tmpEdge.numberVertices.second)) {
                edges[tmpEdge.numberEdge].label = GraphLabels::inskeleton;
            }
        }
    }
}
