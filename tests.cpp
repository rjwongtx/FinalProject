//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <avltree.h>
#include <dsstring.h>
#include <vector.h>
#include <hashtable.h>
TEST_CASE("AVL class", "[AVL Tree]"){

    AvlTree<int> i;
    AvlTree<String> s;

    SECTION("insert"){
    i.insert(30);
    i.insert(60);
    i.insert(40);
    s.insert("potato");
    REQUIRE(i.isEmpty()==false);
    REQUIRE(s.isEmpty()==false);
    }

    SECTION("clear tree"){
    i.insert(30);
    i.insert(60);
    i.insert(40);
    s.insert("potato");
    REQUIRE(i.isEmpty()==false);
    REQUIRE(s.isEmpty()==false);
    i.makeEmpty();
    s.makeEmpty();
    REQUIRE(i.isEmpty()==true);
    REQUIRE(s.isEmpty()==true);
    }

    SECTION("contains"){
    AvlTree<char*> test;
    test.insert("potato");
    test.insert("mango");
    test.insert("what");
    test.insert("is");
    test.insert("love");
    test.insert("?");
    REQUIRE(test.contains("potato")==true);
    REQUIRE(test.contains("mango")==true);
    REQUIRE(test.contains("what")==true);
    REQUIRE(test.contains("is")==true);
    REQUIRE(test.contains("love")==true);
    REQUIRE(test.contains("?")==true);

;
    }
    SECTION("resize function"){
        Vector<String> test(2);
        REQUIRE(test.size()==0);
        test.add("Potato");
        test.add("potatod");
        REQUIRE(test.size()==2);
        test.add("Trump");
        REQUIRE(test.size()==3);
        test.add("Hillary");
        REQUIRE(test.size()==4);


    }
}
TEST_CASE("HashTable class", "[HashTable]")
{

    HashTable hashy;

    SECTION("Add"){
    hashy.add("Function Names", 10);
    REQUIRE(hashy.findCount("Function Names")==10);
    hashy.add("# of Classes", 30);
    REQUIRE(hashy.findCount("# of Classes")==30);
    hashy.add("Lines of comments", 100);
    REQUIRE(hashy.findCount("Lines of comments")==100);
    }

    SECTION("Items at Index")
    {

    }
}



