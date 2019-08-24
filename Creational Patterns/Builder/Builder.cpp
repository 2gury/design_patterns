#include <iostream>
#include <vector>

class Part1 {};
class Part2 {};
class Part3 {};
class Part4 {};
class Part5 {};
class Part6 {};

class Product {
public:
    std::vector <Part1> p1;
    std::vector <Part2> p2;
    std::vector <Part3> p3;
    std::vector <Part4> p4;
    std::vector <Part5> p5;
    std::vector <Part6> p6;
};

class Builder {
protected:
    Product *pr;
public:
    virtual void BuildProduct(){};
    virtual void BuildPart1(){};
    virtual void BuildPart2(){};
    virtual void BuildPart3(){};
    virtual void BuildPart4(){};
    virtual void BuildPart5(){};
    virtual void BuildPart6(){};
    virtual Product* GetResult() {return 0;}
};

class ConcreteBuilder1 : public Builder {
public:
    void BuildProduct() {
        pr = new Product;
    }
    void BuildPart1() {
        pr->p1.push_back(Part1());
        std::cout << "Part1" << std::endl;
    }
    void BuildPart2() {
        pr->p2.push_back(Part2());
        std::cout << "Part2" << std::endl;
    }
    void BuildPart3() {
        pr->p3.push_back(Part3());
        std::cout << "Part3" << std::endl;
    }
    void BuildPart4() {
        pr->p4.push_back(Part4());
        std::cout << "Part4" << std::endl;
    }
    void BuildPart6() {
        pr->p6.push_back(Part6());
        std::cout << "Part6" << std::endl;
    }
    Product* GetResult() {
        return pr;
    }
};

class ConcreteBuilder2 : public Builder {
public:
    void BuildProduct() {
        pr = new Product;
    }
    void BuildPart1() {
        pr->p1.push_back(Part1());
        std::cout << "Part1" << std::endl;
    }
    void BuildPart3() {
        pr->p3.push_back(Part3());
        std::cout << "Part3" << std::endl;
    }
    void BuildPart4() {
        pr->p4.push_back(Part4());
        std::cout << "Part4" << std::endl;
    }
    void BuildPart5() {
        pr->p5.push_back(Part5());
        std::cout << "Part5" << std::endl;
    }
    void BuildPart6() {
        pr->p6.push_back(Part6());
        std::cout << "Part6" << std::endl;
    }
    Product* GetResult() {
        return pr;
    }
};

class Director {
public:
    Product* Construct(Builder &builder) {
        builder.BuildProduct();
        builder.BuildPart1();
        builder.BuildPart2();
        builder.BuildPart3();
        builder.BuildPart4();
        builder.BuildPart5();
        builder.BuildPart6();
        return (builder.GetResult());
    }
};

int main() {
    Director director;
    ConcreteBuilder1 builder1;
    ConcreteBuilder2 builder2;

    
    Product* product1 = director.Construct(builder1);
    std::cout << std::endl;
    Product* product2 = director.Construct(builder2);
    return 0;
}
