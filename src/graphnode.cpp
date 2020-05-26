#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

GraphNode::GraphNode(const GraphNode &node)
{
    //_childEdges = node._childEdges;
    _parentEdges = node._parentEdges;
    //_chatBot = node._chatBot;
    _id = node._id;
    _answers = node._answers;
}

GraphNode& GraphNode::operator=(const GraphNode &node)
{
    if(this == &node)
        return *this;

    _parentEdges.clear();
    _answers.clear();

    //_childEdges = node._childEdges;
    _parentEdges = node._parentEdges;
    _chatBot = node._chatBot;
    _id = node._id;
    _answers = node._answers;
    return *this;
}

GraphNode::GraphNode(GraphNode &&node)
{
    _childEdges = std::move(node._childEdges);
    _parentEdges = std::move(node._parentEdges);
    _chatBot = std::move(node._chatBot);
    _id = node._id;
    _answers = std::move(node._answers);

    node._id = 0;
    //node._chatBot = nullptr;
    //node._childEdges.clear();
    //node._parentEdges.clear();
    //node._answers.clear();
}

GraphNode& GraphNode::operator=(GraphNode &&node)
{
    if(this == &node)
        return *this;

    _parentEdges.clear();
    _answers.clear();

    //_childEdges = node._childEdges;
    _parentEdges = node._parentEdges;
    //_chatBot = node._chatBot;
    _id = node._id;
    _answers = node._answers;

    node._id = 0;
    //node._chatBot = nullptr;
    node._parentEdges.clear();
    node._answers.clear();

    return *this;
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}