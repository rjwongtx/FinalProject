#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>    // For NULL
#include "dsstring.h"

using namespace std;
//source code based from http://users.cis.fiu.edu/~weiss/dsaa_c++3/code/AvlTree.h
// AvlTree class

template <typename Comparable>
class AvlTree
{
  public:
    AvlTree( ) : root( NULL )
      { }
    AvlTree( const AvlTree & rhs ) : root( NULL )
    {
        *this = rhs;
    }

    ~AvlTree( )//destructor
    {
        makeEmpty( );
    }


    const Comparable & findMin( ) const//finds the smallest value
    {
        if( isEmpty( ) )
            throw 0;
        return findMin( root )->element;
    }

    const Comparable & findMax( ) const//finds the largest value
    {
        if( isEmpty( ) )
            throw 0;
        return findMax( root )->element;
    }

    bool contains( const Comparable & x ) const//see if the avl tree contains a certain value, only works for char*
    {
        return contains( x, root );
    }

    bool isEmpty( ) const
    {
        return root == NULL;
    }

    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    void makeEmpty( )
    {
        makeEmpty( root );
    }

    void insert( const Comparable & x )//inserts a object into the tree
    {
        insert( x, root );
    }


    const AvlTree & operator=( const AvlTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }

  private:
    struct AvlNode
    {
        Comparable element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;

        AvlNode( const Comparable & theElement, AvlNode *lt,
                                                AvlNode *rt, int h = 0 )
          : element( theElement ), left( lt ), right( rt ), height( h ) { }
    };

    AvlNode *root;

    void insert( const Comparable & x, AvlNode * & t )//insert method
    {
        if( t == nullptr )
            t = new AvlNode( x, nullptr, nullptr );
        else if( t->element > x  )
        {
            insert( x, t->left );
            if( height( t->left ) - height( t->right ) == 2 )
            {
                if( t->left->element > x )
                    rotateWithLeftChild( t );
                else
                    doubleWithLeftChild( t );
            }
        }
        else if(t->element < x )
        {
            insert( x, t->right );
            if( height( t->right ) - height( t->left ) == 2 )
            {
                if( t->right->element < x )
                    rotateWithRightChild( t );
                else
                    doubleWithRightChild( t );
            }
        }
        else
            ;
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

    /*
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    AvlNode * findMin( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /*
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    AvlNode * findMax( AvlNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


    /*
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     */
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        if( t == NULL )
            return false;
        else if( t->element >x )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }


    /*
     * Internal method to make subtree empty.
     */
    void makeEmpty( AvlNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

    /*
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( AvlNode *t ) const
    {
        if( t != NULL )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }


        // Avl manipulations
    /*
     * Return the height of node t or -1 if NULL.
     */
    AvlNode * clone( AvlNode *t ) const
       {
           if( t == NULL )
               return NULL;
           else
               return new AvlNode( t->element, clone( t->left ), clone( t->right ), t->height );
       }
    int height( AvlNode *t ) const
    {
        return t == NULL ? -1 : t->height;
    }

    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    /*
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild( AvlNode * & k2 )
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2 = k1;
    }

    /*
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild( AvlNode * & k2 )
    {
        AvlNode *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2 = k1;
    }

    /*
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    void doubleWithLeftChild( AvlNode * & k1 )
    {
        rotateWithRightChild( k1->left );
        rotateWithLeftChild( k1 );
    }

    /*
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     */
    void doubleWithRightChild( AvlNode * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }
};

#endif
