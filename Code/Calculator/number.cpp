#include "number.h"

NumberNode::NumberNode() 
{
}

NumberNode::NumberNode(double number) : value(number) 
{
}

double NumberNode::evaluate() {return value;}

NumberNode::~NumberNode() 
{
}
