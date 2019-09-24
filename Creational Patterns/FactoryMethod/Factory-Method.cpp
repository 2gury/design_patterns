//Example of `factory method' design pattern in C++

#include <iostream>

//////////////////////////////////////////////////
//Not classic implementation of 'factory method'//
//////////////////////////////////////////////////

enum ID {Product1 = 10, Product2  = 10};

class Product {
public:
   static Product* CreateProduct(ID ProductID);
   virtual void info() = 0;
   virtual ~Product();
};

class ConcreteProduct1 : public Product {
public:
   void info() {
       std::cout << "ConcreteProduct1" << std::endl;
   }
};
class ConcreteProduct2 : public Product {
public:
   void info() {
       std::cout << "ConcreteProduct2" << std::endl;
   }
};

Product* CreateProduct(ID ProductID) {
   Product* CreatedProduct;
   if (ProductID == Product1) {
       CreatedProduct = new ConcreteProduct1;
   } else if (ProductID == Product2) {
       CreatedProduct = new ConcreteProduct2;
   }
   return CreatedProduct;
}


//////////////////////////////////////////////////
//The classic implementation of 'factory method'//
//////////////////////////////////////////////////

class Product {
public:
    virtual ~Product() {};
};

class ConcreteProduct1 : public Product {};
class ConcreteProduct2 : public Product {};

class Creator {
public:
    virtual ~Creator() {};
    virtual Product* CreateProduct()  = 0;
};

class ConcreteCreator1 : public Creator {
public:
    Product* CreateProduct()  {
        return new ConcreteProduct1;
    }
};

class ConcreteCreator2 : public Creator {
public:
    Product* CreateProduct()  {
        return new ConcreteProduct2;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
