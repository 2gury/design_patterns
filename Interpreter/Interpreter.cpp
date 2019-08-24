#include <iostream>
#include <string>

class AbstractExpression {
public:
    virtual ~AbstractExpression() {};
    virtual bool interpreter(std::string) = 0;
};

class TerminalExpression : public AbstractExpression {
public:
    TerminalExpression(std::string other_data): data(other_data) {};
    bool interpreter(std::string context) {
        if (context == data) {
            return true;
        } else {
            return false;
        }
    }
private:
    std::string data;
};

class OrExpression : public AbstractExpression {
public:
    OrExpression(AbstractExpression* first, AbstractExpression* second):
    expression1(first), expression2(second) {};
    bool interpreter(std::string conext) {
        return expression1->interpreter(conext) || expression2->interpreter(conext);
    }
private:
    AbstractExpression* expression1;
    AbstractExpression* expression2;
};

class AndExpression : public AbstractExpression {
public:
    AndExpression(AbstractExpression* first, AbstractExpression* second):
    expression1(first), expression2(second) {};
    bool interpreter(std::string context) {
        return expression1->interpreter(context) && expression2->interpreter(context);
    }
private:
    AbstractExpression* expression1;
    AbstractExpression* expression2;
};

int main(int argc, const char * argv[]) {
    TerminalExpression tt("OG");
    std::cout << tt.interpreter("Health") << std::endl;
    
    OrExpression orexp(new TerminalExpression("dbac"), new  TerminalExpression("cbda"));
    std::cout << orexp.interpreter("cbda") << std::endl;
    
    AndExpression andexp(new TerminalExpression("cbda"), new  TerminalExpression("cbdf"));
    std::cout << andexp.interpreter("cbda") << std::endl;
    
    return 0;
}
