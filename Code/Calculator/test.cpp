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

// Expression generator
std::string Test::randomExpression()
{
    // length of each number
    int lhs_numOfDigits = rand_between(1, 5);
    int rhs_numOfDigits = rand_between(1, 5);

    // choses random operator 
    int op = rand_between(1, 4);

    // left-hand side, Right-hand side, overall result nums
    std::string lhs = "";
    std::string rhs = "";
    std::string result = "";
    
    // Random digits chosen for each num
    for (int i = 0; i < lhs_numOfDigits; ++i)
        lhs += std::to_string(rand_between(0, 9));
    for (int i = 0; i < rhs_numOfDigits; i++)
        rhs += std::to_string(rand_between(0, 9));
    bool exp = rand_between(0, 1);

    // makes expression in parths
    if (exp)
    {  
        // randomly chosen an op
        if (op == 1)
            result = TokenChar::leftParth + lhs + TokenChar::plus + rhs + TokenChar::rightParth;
        if (op == 2) 
            result = TokenChar::leftParth + lhs + TokenChar::minus + rhs + TokenChar::rightParth;
        if (op == 3) 
            result = TokenChar::leftParth + lhs + TokenChar::multiply + rhs + TokenChar::rightParth;
        if (op == 4) 
            result = TokenChar::leftParth + lhs + TokenChar::divide + rhs + TokenChar::rightParth;
        exp = rand_between(0, 1);
    }
    // makes expression w/o parths
    else if (!exp)
    { 
        if (op == 1) result = lhs + TokenChar::plus + rhs;
        if (op == 2) result = lhs + TokenChar::minus + rhs;
        if (op == 3) result = lhs + TokenChar::multiply + rhs;
        if (op == 4) result = lhs + TokenChar::divide + rhs;
    }

    if (result == "") return "An expression was not generated.";   
    return result;
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
            lhs += std::to_string(rand_between(0, 9));
        for (int i = 0; i < rhs_numOfDigits; i++)
            rhs += std::to_string(rand_between(0, 9));

        // Make number and op nodes
        Interface* LHS = new NumberNode(std::stod(lhs));
        Interface* RHS = new NumberNode(std::stod(rhs));
        Interface* Op = new OperatorNode(op, LHS, RHS);

        // tess addition
        // A + B == properally operated
        // A + B == B + A
        if (op == 1)
        {   
            if (LHS->evaluate() + RHS->evaluate() == Op->evaluate() && RHS->evaluate() + LHS->evaluate() == Op->evaluate())
                ++_pass;
            else 
            {
                std::cerr << "Operator Test Failure\n";
                std::cerr << "Test #" << counter << "\n";   
                std::cerr << "Addition test Failure\n";
                ++_fail;
            }
            ++counter;
        }
        // test subtraction
        // A - B == properally operated
        // B - A == (A - B) * -1
        // if (A and B are not 0 &&  A != B) then A - B != B - A
        if (op == 2)
        {
            if (LHS->evaluate() - RHS->evaluate() == Op->evaluate() 
               && (RHS->evaluate() - LHS->evaluate()) * -1 == Op->evaluate()
               && (RHS->evaluate() - LHS->evaluate()) == Op->evaluate() * -1
               && ((RHS->evaluate() && LHS->evaluate() != 0 && RHS->evaluate() != LHS->evaluate()) && RHS->evaluate() - LHS->evaluate() != LHS->evaluate() - RHS->evaluate()))
                ++_pass;
            else
            {
                std::cerr << "Operator Test Failure\n";
                std::cerr << "Test #" << counter << "\n";
                std::cerr << "Subtraction test Failure\n";
                ++_fail;
            }
            ++counter;
        }
        // test multiplication
        // A * B == properally operated
        // A * B == B * A
        if (op == 3)
        {
            if (LHS->evaluate() * RHS->evaluate() == Op->evaluate() && RHS->evaluate() * LHS->evaluate() == Op->evaluate())
                ++_pass;
            else
            { 
                std::cerr << "Operator Test Failure\n";
                std::cerr << "Test #" << counter << "\n";  
                std::cerr << "Multiplication test Failure\n";
                ++_fail;
            }
            ++counter;
        }
        // test division
        // A / B == properally operated
        // A or B / 0 == an error
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
                std::cerr << "Operator Test Failure\n";
                std::cerr << "Test #" << counter << "\n";
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
        std::cout << "All tests completed\n";
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
        // random expression generated
        std::string expression = randomExpression();

        // expression is passed in tokenizer
        _Tokenizer = new Tokenizer(expression);
        Token* token = new Token;

        // randomly chose an index and see if the token matches
        int index = rand_between(0, expression.size());

        // itr through expression until token is reached
        for (int i = 0; i < index; ++i) 
        {
            // Needs to account for long digits?
            token = _Tokenizer->getNextToken();
        }

        // plus token check
        if (token->getToken() == Tokens::PLUS && expression[index] == TokenChar::plus)
        {
            ++_pass;
            ++counter;
        }
        // minus token check
        else if (token->getToken() == Tokens::MINUS && expression[index] == TokenChar::minus)
        {
            ++_pass;
            ++counter;
        }
        // multiply token check
        else if (token->getToken() == Tokens::MULTIPLY && expression[index] == TokenChar::multiply)
        {
            ++_pass;
            ++counter;
        }
        // divide token check
        else if (token->getToken() == Tokens::DIVIDE && expression[index] == TokenChar::divide)
        {
            ++_pass;
            ++counter;
        }
        // left parth token check
        else if (token->getToken() == Tokens::LPARTH && expression[index] == TokenChar::leftParth)
        {
            ++_pass;
            ++counter;
        }
        // right parth token check
        else if (token->getToken() == Tokens::RPARTH && expression[index] == TokenChar::rightParth)
        {
            ++_pass;
            ++counter;
        }
        // end of expression token check
        else if (token->getToken() == Tokens::STOP && index == expression.size())
        {
            ++_pass;
            ++counter;
        }
        // integer token check
        else if (token->getToken() == Tokens::NUMBER && std::isdigit(expression[index]))
        {
            ++_pass;
            ++counter;
        }
        else
        {
            std::cerr << '\n';
            std::cerr << "Token Test Failure\n";
            std::cerr << "Test #" << counter << '\n';
            std::cerr << "Expression: "<< expression << "       Index: " << index << "          Expected Token: " << expression[index] <<'\n';
            if (token->getToken() == Tokens::PLUS) std::cerr << "Current Token:  " << TokenChar::plus << "\n";
            else if (token->getToken() == Tokens::MINUS) std::cerr << "Current Token:  " << TokenChar::minus << "\n";
            else if (token->getToken() == Tokens::MULTIPLY) std::cerr << "Current Token:  " << TokenChar::multiply << "\n";
            else if (token->getToken() == Tokens::DIVIDE) std::cerr << "Current Token:  " << TokenChar::divide << "\n";
            else if (token->getToken() == Tokens::NUMBER) std::cerr << "Current Token:  " << token->getValue() << "\n";
            else if (token->getToken() == Tokens::LPARTH) std::cerr << "Current Token:  " << TokenChar::leftParth << "\n";
            else if (token->getToken() == Tokens::RPARTH) std::cerr << "Current Token:  " << TokenChar::rightParth << "\n";
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
        std::cout << "All tests completed\n";
        std::cout << "Successes: " << _pass << "\n";
        std::cout << "Failures: " << _fail << "\n";
    }
    else std::cerr << "Error with Token testing\n" << counter << " tests ran\n";
    std::cout << "********************************************************\n";
}

void Test::testParser()
{
    int counter = 0;
    for (int i = 0; i < _numOfTests; ++i)
    {    
        std::string expression = randomExpression();     

        _Tokenizer = new Tokenizer(expression);
        _Parser = new Parser(_Tokenizer);
        if (_Parser->parse() != nullptr) 
        {
            ++_pass;
            ++counter;
        }
        else 
        {
            std::cerr << "Test #" << counter << '\n';
            std::cerr << "Expression: " << expression << " failed\n";
            ++_fail;
            ++counter;
        }
        delete _Tokenizer, _Parser;
    }
    std::cout << "\n********************************************************\n";
    std::cout << "Running "<< _numOfTests << " Parser Tests . . .\n";
    if (_pass + _fail == _numOfTests)
    {
        std::cout << "All tests completed\n";
        std::cout << "Successes: " << _pass << "\n";
        std::cout << "Failures: " << _fail << "\n";
    }
    else std::cerr << "Error with Parser testing\n" << counter << " tests ran\n";
    std::cout << "********************************************************\n";
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
            lhs += std::to_string(rand_between(0, 9));
        for (int i = 0; i < rhs_numOfDigits; i++)
            rhs += std::to_string(rand_between(0, 9));

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
                std::cerr << "AST Test Failure\n";
                std::cerr << "Test #" << counter << "\n";   
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
                std::cerr << "AST Test Failure\n";
                std::cerr << "Test #" << counter << "\n";
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
                std::cerr << "AST Test Failure\n";
                std::cerr << "Test #" << counter << "\n";   
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
                std::cerr << "AST Test Failure\n";
                std::cerr << "Test #" << counter << "\n";   
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
    //testParser();
    return 0.0;
}

Test::~Test()
{
}