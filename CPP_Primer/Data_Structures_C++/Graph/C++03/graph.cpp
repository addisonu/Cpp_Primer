//DATE: 12/08/16
//ASSIGNMENT: Project 8
//FILE: graph.h
//DESC: Implementation of template class graph. A graph object is an edge list implementation of a labeled graph with a fixed number of vertices and labels of type Item

template <typename Item> Graph<Item>::Graph() : many_vertices(0) { }

template <typename Item> void Graph<Item>::add_vertex(const Item &label)
{
    vertexlist[many_vertices] = label;
    edges[many_vertices] = std::list<EdgeNode>();
    ++many_vertices;
}

template <typename Item> void Graph<Item>::add_edge(size_t source, size_t target)
{
    edges[source].push_back(EdgeNode(target));
}

template <typename Item> void Graph<Item>::remove_edge(size_t source, size_t target)
{
    for(std::list<EdgeNode>::iterator i = edges[source].begin(); i != edges[source].end(); ++i)
        if(i->getvnum() == target)
            edges[source].erase(i);
}

template <typename Item> Item& Graph<Item>::operator[](size_t vertex)
{
    return vertexlist[vertex];
}

template <typename Item> size_t Graph<Item>::size() const
{
    return many_vertices;
}

template <typename Item> bool Graph<Item>::is_edge(const size_t source, const size_t target) const
{
    if(edges[source].empty())
        return false;

//Search for target in list of argument vertex edges
    for(std::list<EdgeNode>::const_iterator i = edges[source].begin(); i != edges[source].end(); ++i)
        if(i->getvnum() == target)
            return true;
    return false;
}

template <typename Item> std::set<size_t>  Graph<Item>::neighbors(size_t vertex) const
{
    std::set<size_t> verts;

//Add tail --> head edges to verts
    for(std::list<EdgeNode>::const_iterator i = edges[vertex].begin(); i != edges[vertex].end(); ++i)
        verts.insert(i->getvnum());

    return verts;
}

template <typename Item> Item Graph<Item>::operator[](size_t vertex) const
{
    return vertexlist[vertex];
}

template <typename Item> int Graph<Item>::pos(Item label)
{
//Check if graph is empty
    if(!size()){
        throw std::out_of_range("The graph is empty.");
    }
//Search for Item
    for(std::size_t i = 0; i != many_vertices; ++i)
        if(vertexlist[i] == label)
            return i;

//If Item isn't found
    throw std::out_of_range("The item doesn't exist.");
}

template <typename Item> bool Graph<Item>::is_path(size_t source, size_t target) const
{
//Check that source and target aren't equal
    if(source != target){

//Check if there is an edge between source and target
        if(is_edge(source, target)){
            std::cout << source << std::endl;
            std::cout << target << std::endl;

            return true;
        }

//Containers to process vertices:
//marked distinguishes between visited and unvisited vertices
//connections will hold all neighbors of starting vertex
//vertex_queue will hold all vertices to be processed
        bool marked[MAXIMUM];
        std::set<std::size_t> connections;
        std::set<std::size_t>::iterator it;
        std::queue<std::size_t> vertex_queue;

        assert(source < size());

//Populate marked with size() false values
        std::fill_n(marked, size(), false);

//Process the first vertex before entering loop
        marked[source] = true;
        vertex_queue.push(source);

//Print starting vertex position
        std::cout << source << std::endl;

//While there are vertices to process, repeat steps
        do{
            connections = neighbors(vertex_queue.front());

//Pop processed vertices off of queue
            vertex_queue.pop();
            for(it = connections.begin(); it != connections.end(); ++it){
                if(vertexlist[*it] == vertexlist[target]){
//Print target vertex
                    std::cout << *it << std::endl;
                    return true;
            }
                if(!marked[*it]){

//Print all vertex positions traversed
                    std::cout << *it << std::endl;
                    marked[*it] = true;
                    vertex_queue.push(*it);
                }
            }
        }while(!vertex_queue.empty());
    }
    else
        return true;
    return false;
}
