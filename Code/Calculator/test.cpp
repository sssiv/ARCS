#include "test.h"

int Test::rand_between(int r1, int r2)
{
    // True Random
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(r1, r2);
    //for (int i = 0; i < 10; ++i) std::cout <<  dist(gen) << " ";
    return dist(gen);
}

// Expression testing needs to be implimented 
void Test::testOps()
{
    // pass/fail count
    int pass = 0;
    int fail = 0;

    // Run tests
    for (int i = 0; i < _numOfTests; i++)
    {
        // length of number
        int lhs_numOfDigits = rand_between(1, 5);
        int rhs_numOfDigits = rand_between(1, 5);
        int op = rand_between(1, 4);

        // left-hand and Right-hand side nums
        std::string lhs = "";
        std::string rhs = "";

        // Random digits chosen for each num
        for (int i = 0; i < lhs_numOfDigits; ++i)
        {
            lhs += std::to_string(rand_between(0, 9));
        }
        for (int i = 0; i < rhs_numOfDigits; i++)
        {
            rhs += std::to_string(rand_between(0, 9));
        }

        // Make number and op nodes
        Interface* LHS = new NumberNode(std::stod(lhs));
        Interface* RHS = new NumberNode(std::stod(rhs));
        Interface* Op = new OperatorNode(op, LHS, RHS);

        // tess addition
        if (op == 1)
        {   if (LHS->evaluate() + RHS->evaluate() == Op->evaluate() && RHS->evaluate() + LHS->evaluate() == Op->evaluate())
                ++pass;
            else 
            {
                std::cerr << "Addition test Failure\n";
                ++fail;
            }
        }
        // test subtraction
        if (op == 2)
        {
            if (LHS->evaluate() - RHS->evaluate() == Op->evaluate() && (RHS->evaluate() - LHS->evaluate()) * -1 == Op->evaluate()
                && (RHS->evaluate() - LHS->evaluate()) == Op->evaluate() * -1)
                ++pass;
            else
            {
                std::cerr << "Subtraction test Failure\n";
                ++fail;
            }
        }
        // test multiplication
        if (op == 3)
        {
            if (LHS->evaluate() * RHS->evaluate() == Op->evaluate() && RHS->evaluate() * LHS->evaluate() == Op->evaluate())
                ++pass;
            else
            {   
                std::cerr << "Multiplication test Failure\n";
                ++fail;
            }
        }
        // test division
        if (op == 4 && RHS->evaluate() != 0)
        {
            if (LHS->evaluate() / RHS->evaluate() == Op->evaluate())
                ++pass;
            else
            {
                std::cerr << "Division test Failure\n";
                ++fail;   
            }
        }
        delete LHS, RHS, Op;
    }

    std::cout << "\n********************************************************\n";
    std::cout << "Running "<< _numOfTests << " Operator Tests . . .\n";
    if (pass + fail == _numOfTests)
    {
        std::cout << "All tests ran successfully\n";
        std::cout << "Successes: " << pass << "\n";
        std::cout << "Failures: " << fail << "\n";
    }
    else std::cerr << "Error with Operator testing, not all tests ran\n";
    std::cout << "********************************************************\n";
}

void Test::testTokenizer()
{
    // generate a random number
    // have it randomly be an expression
    // do nextToken() a random number of times
    // check what is at the index of that string
    // see if the token matches the string index
}

void Test::testParser()
{}

void Test::testAST()
{}

Test::Test() : _numOfTests(rand_between(50, 100))
{
}

double Test::evaluate()
{

    testOps();
    return 0.0;
}

Test::~Test()
{
}
