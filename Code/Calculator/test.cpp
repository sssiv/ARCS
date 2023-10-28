#include "test.h"

// Generates a random number starting "From" X all the way "to" Y
int Test::rand_between(const int& from, const int& to)
{
    // True Random
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(from, to);
    //for (int i = 0; i < 10; ++i) std::cout <<  dist(gen) << " ";
    return dist(gen);
}

// Expression testing needs to be implimented 
void Test::testOps()
{
    // pass/fail count
    _pass = 0;
    _fail = 0;

    int counter = 0;
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
                ++_pass;
            else 
            {
                std::cerr << "Addition test Failure\n";
                ++_fail;
            }
            ++counter;
        }
        // test subtraction
        if (op == 2)
        {
            if (LHS->evaluate() - RHS->evaluate() == Op->evaluate() && (RHS->evaluate() - LHS->evaluate()) * -1 == Op->evaluate()
                && (RHS->evaluate() - LHS->evaluate()) == Op->evaluate() * -1)
                ++_pass;
            else
            {
                std::cerr << "Subtraction test Failure\n";
                ++_fail;
            }
            ++counter;
        }
        // test multiplication
        if (op == 3)
        {
            if (LHS->evaluate() * RHS->evaluate() == Op->evaluate() && RHS->evaluate() * LHS->evaluate() == Op->evaluate())
                ++_pass;
            else
            {   
                std::cerr << "Multiplication test Failure\n";
                ++_fail;
            }
            ++counter;
        }
        // test division
        if (op == 4)
        {
            if (RHS->evaluate() == 0)
            {
                if (Op->evaluate() == std::nan(""));
                    ++_pass;
            }
            else if (LHS->evaluate() / RHS->evaluate() == Op->evaluate())
                ++_pass;
            else
            {
                std::cerr << "Division test Failure\n";
                ++_fail;   
            }
            ++counter;
        }
        delete LHS, RHS, Op;
    }

    std::cout << "\n********************************************************\n";
    std::cout << "Running "<< _numOfTests << " Operator Tests . . .\n";
    if (_pass + _fail == _numOfTests)
    {
        std::cout << "All tests ran\n";
        std::cout << "Successes: " << _pass << "\n";
        std::cout << "Failures: " << _fail << "\n";
    }
    else std::cerr << "Error with Operator testing\n" << counter << " tests ran\n";
    std::cout << "********************************************************\n";
}

// For some reason the numbers are coming out huge
// Maybe the other test cases are having issues with the RNG
void Test::testTokenizer()
{
    int counter = 0;
    for (int i = 0; i < _numOfTests; ++i)
    {         
        // length of number
        int lhs_numOfDigits = rand_between(1, 5);
        int rhs_numOfDigits = rand_between(1, 5);
        int op = rand_between(1, 4);

        // left-hand and Right-hand side nums
        std::string lhs = "";
        std::string rhs = "";
        std::string result = "";
    
            // Random digits chosen for each num
            for (int i = 0; i < lhs_numOfDigits; ++i)
            {
                lhs += std::to_string(rand_between(0, 9));
            }
            for (int i = 0; i < rhs_numOfDigits; i++)
            {
                rhs += std::to_string(rand_between(0, 9));
            }

            bool exp = rand_between(0, 1);

            // picks op and puts in expression
            if (exp)
            {
                // randomly pick an op
                if (op == 1)
                {  
                    result =  "(" + lhs + '+' + rhs + ")";
                }
                if (op == 2)
                {
                    result = "(" + lhs + '-' + rhs + ")";
                }
                if (op == 3)
                {
                    result = "(" + lhs + '*' + rhs + ")";
                }
                if (op == 4)
                {
                    result = "(" + lhs + '/' + rhs + ")";
                }
            }
            // randomly pick an op
            else
            { 
                if (op == 1)
                {  
                    result = lhs + '+' + rhs;
                }
                if (op == 2)
                {
                    result = lhs + '-' + rhs;
                }
                if (op == 3)
                {
                    result = lhs + '*' + rhs;
                }
                if (op == 4)
                {
                    result = lhs + '/' + rhs;
                }
            }

        _Tokenizer = new Tokenizer(result);

        int index = rand_between(0, lhs_numOfDigits + rhs_numOfDigits);
        Token* token = new Token;
        for (int i = 0; i < index; ++i)
        {
            token = _Tokenizer->getNextToken();
        }

        if (token->getToken() == Tokens::PLUS && result[index] == '+')
        {
            ++_pass;
            ++counter;
        }
        else if (token->getToken() == Tokens::MINUS && result[index] == '-')
        {
            ++_pass;
            ++counter;
        }
        else if (token->getToken() == Tokens::MULTIPLY && result[index] == '*')
        {
            ++_pass;
            ++counter;
        }
        else if (token->getToken() == Tokens::DIVIDE && result[index] == '/')
        {
            ++_pass;
            ++counter;
        }
        else if (token->getToken() == Tokens::LPARTH && result[index] == '(')
        {
            ++_pass;
            ++counter;
        }
        else if (token->getToken() == Tokens::RPARTH && result[index] == ')')
        {
            ++_pass;
            ++counter;
        }
        else if (token->getToken() == Tokens::STOP && index == result.size())
        {
            ++_pass;
            ++counter;
        }
        else if (token->getToken() == Tokens::NUMBER && std::isdigit(result[index]))
        {
            ++_pass;
            ++counter;
        }
        else
        {
            std::cerr << '\n';
            std::cerr << "Expression: "<< result << "       Index: " << index << "          Expected Token: " << result[index] <<'\n';
            if (token->getToken() == Tokens::PLUS) std::cerr << "Current Token:  +\n";
            else if (token->getToken() == Tokens::MINUS) std::cerr << "Current Token:  -\n";
            else if (token->getToken() == Tokens::MULTIPLY) std::cerr << "Current Token:  *\n";
            else if (token->getToken() == Tokens::DIVIDE) std::cerr << "Current Token:  /\n";
            else if (token->getToken() == Tokens::NUMBER) std::cerr << "Current Token:  A number\n";
            else if (token->getToken() == Tokens::LPARTH) std::cerr << "Current Token:  (\n";
            else if (token->getToken() == Tokens::RPARTH) std::cerr << "Current Token:  )\n";
            else if (token->getToken() == Tokens::STOP) std::cerr << "Current Token:  STOP\n";
            else std::cerr << "Current Token:  Unidentified\n";
            std::cerr << '\n';
            ++_fail;
            ++counter;
        }

        delete token;
    }
    

    std::cout << "\n********************************************************\n";
    std::cout << "Running "<< _numOfTests << " Token Tests . . .\n";
    if (_pass + _fail == _numOfTests)
    {
        std::cout << "All tests ran\n";
        std::cout << "Successes: " << _pass << "\n";
        std::cout << "Failures: " << _fail << "\n";
    }
    else std::cerr << "Error with Token testing\n" << counter << " tests ran\n";
    std::cout << "********************************************************\n";
}

void Test::testParser()
{
     for (int i = 0; i < _numOfTests; ++i)
    {         
        // length of number
        int lhs_numOfDigits = rand_between(1, 5);
        int rhs_numOfDigits = rand_between(1, 5);
        int op = rand_between(1, 4);

        // left-hand and Right-hand side nums
        std::string lhs = "";
        std::string rhs = "";
        std::string result = "";
    
            // Random digits chosen for each num
            for (int i = 0; i < lhs_numOfDigits; ++i)
            {
                lhs += std::to_string(rand_between(0, 9));
            }
            for (int i = 0; i < rhs_numOfDigits; i++)
            {
                rhs += std::to_string(rand_between(0, 9));
            }

            if (op == 1)
            {  
                result = lhs + '+' + rhs;
            }
            if (op == 2)
            {
                result = lhs + '-' + rhs;
            }
            if (op == 3)
            {
                result = lhs + '*' + rhs;
            }
            if (op == 4)
            {
                result = lhs + '/' + rhs;
            }

            _Tokenizer = new Tokenizer(result);
            _Parser = new Parser(_Tokenizer);

    }
}

// Still need to test expression, term, factor
void Test::testAST()
{
    // pass/fail count
    _pass = 0;
    _fail = 0;

    int counter = 0;
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

        // Uses AST nodes instead of using the classes directly
        Interface* LHS = _AST->newNumber(std::stod(lhs));
        Interface* RHS = _AST->newNumber(std::stod(rhs));
        Interface* Op = _AST->intOperator(op, LHS, RHS);

        // tess addition
        if (op == 1)
        {   if (LHS->evaluate() + RHS->evaluate() == Op->evaluate() && RHS->evaluate() + LHS->evaluate() == Op->evaluate())
                ++_pass;
            else 
            {
                std::cerr << "Addition test Failure\n";
                ++_fail;
            }
            ++counter;
        }
        // test subtraction
        if (op == 2)
        {
            if (LHS->evaluate() - RHS->evaluate() == Op->evaluate() && (RHS->evaluate() - LHS->evaluate()) * -1 == Op->evaluate()
                && (RHS->evaluate() - LHS->evaluate()) == Op->evaluate() * -1)
                ++_pass;
            else
            {
                std::cerr << "Subtraction test Failure\n";
                ++_fail;
            }
            ++counter;
        }
        // test multiplication
        if (op == 3)
        {
            if (LHS->evaluate() * RHS->evaluate() == Op->evaluate() && RHS->evaluate() * LHS->evaluate() == Op->evaluate())
                ++_pass;
            else
            {   
                std::cerr << "Multiplication test Failure\n";
                ++_fail;
            }
            ++counter;
        }
        // test division
        if (op == 4)
        {
            if (RHS->evaluate() == 0)
            {
                if (Op->evaluate() == std::nan(""));
                {
                    ++_pass;
                }
            }
            else if (LHS->evaluate() / RHS->evaluate() == Op->evaluate())
                ++_pass;
            else
            {
                std::cerr << "Division test Failure\n";
                ++_fail;   
            }
            ++counter;
        }
        delete LHS, RHS, Op;
    }

    std::cout << "\n********************************************************\n";
    std::cout << "Running "<< _numOfTests << " AST Tests . . .\n";
    if (_pass + _fail == _numOfTests)
    {
        std::cout << "All tests ran\n";
        std::cout << "Successes: " << _pass << "\n";
        std::cout << "Failures: " << _fail << "\n";
    }
    else std::cerr << "Error with AST testing\n" << counter << " tests ran\n";
    std::cout << "********************************************************\n";
}

Test::Test() : _numOfTests(rand_between(50, 99)), _pass(0), _fail(0)
{
}

double Test::evaluate()
{
    //testOps();
    //testAST();
    testTokenizer();
    return 0.0;
}

Test::~Test()
{
}