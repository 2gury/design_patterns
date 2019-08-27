#include <iostream>
#include <vector>

class Part1 {};
class Part2 {};
class Part3 {};
class Part4 {};

class Product {
public:
    std::vector<Part1*> vp1;
    std::vector<Part2*> vp2;
    std::vector<Part3*> vp3;
    std::vector<Part4*> vp4;
};

class Builder {
public:
    virtual ~Builder() {};
    virtual void CreateProduct() {};
    virtual void BuildPart1() {};
    virtual void BuildPart2() {};
    virtual void BuildPart3() {};
    virtual void BuildPart4() {};
    virtual Product* GetResult() {return 0;};
};

class ConcreteBuilder1 : public Builder {
public:
    void CreateProduct() {
        pr = new Product;
    }
    void BuildPart1() {
        pr->vp1.push_back(new Part1);
    }
    void BuildPart2() {
        pr->vp2.push_back(new Part2);
    }
    Product* GetResult() {
        return pr;
    }
private:
    Product* pr;
};

class ConcreteBuilder2 : public Builder {
public:
    void CreateProduct() {
        pr = new Product;
    }
    void BuildPart3() {
        pr->vp3.push_back(new Part3);
    }
    void BuildPart4() {
        pr->vp4.push_back(new Part4);
    }
    Product* GetResult() {
        return pr;
    }
private:
    Product* pr;
};

class Director {
public:
    Director(Builder* builder_for_set): concrete_builder(builder_for_set) {};
    void SetBuilder(Builder* builder_for_set) {
        concrete_builder = builder_for_set;
    }
    Product* Construct() {
        concrete_builder->CreateProduct();
        concrete_builder->BuildPart1();
        concrete_builder->BuildPart2();
        concrete_builder->BuildPart3();
        concrete_builder->BuildPart4();
        return concrete_builder->GetResult();
    }
private:
    Builder* concrete_builder;
};

int main() {

    Director* director1 = new Director(new ConcreteBuilder1);
    
    Product* product1 = director1->Construct();
    Director* director2 = new Director(new ConcreteBuilder2);
    Product* product2 = director2->Construct();
    return 0;
}
