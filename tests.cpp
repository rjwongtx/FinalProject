//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <avltree.h>
#include <dsstring.h>
#include <vector.h>

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
    i.insert(30);
    i.insert(60);
    i.insert(40);
    i.insert(90);
    i.insert(25);
    i.insert(45);
    i.insert(35);
    i.insert(65);
    i.insert(45);
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
    REQUIRE(i.contains(30)==true);
    REQUIRE(i.contains(60)==true);
    REQUIRE(i.contains(40)==true);
    REQUIRE(i.contains(92)==false);
    REQUIRE(i.contains(25)==true);
    REQUIRE(i.contains(45)==true);
    REQUIRE(i.contains(35)==true);
    REQUIRE(i.contains(65)==true);
    REQUIRE(i.contains(13)==false);
    i.makeEmpty();
    REQUIRE(i.contains(30)==false);
    REQUIRE(i.contains(60)==false);
    REQUIRE(i.contains(40)==false);
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





