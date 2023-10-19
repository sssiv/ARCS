#include "number.h"

NumberNode::NumberNode() {}

NumberNode::NumberNode(const double& number) : value(number) {}

double NumberNode::evaluate() {return value;}

NumberNode::~NumberNode() {}