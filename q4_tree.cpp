#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std ;

struct Node {

    int value = -1 ;
    Node * leftchild ;
    Node * rightchild ;

} ;

typedef Node * NodePtr ;

NodePtr gHead = NULL ;
bool gHeadisEmpty = true ;

void Add( NodePtr root, int addvalue ) ;
void PostOrder( NodePtr root ) ;

int main(){

    NodePtr head = NULL ;

    int input ;

    cin >> input ;
    for ( ; input != 0 ; cin >> input ) {

        Add( head, input ) ;
        head = gHead ;

    } // for

    PostOrder( head ) ;

} // main

void Add( NodePtr root, int addvalue ) {

    if ( gHeadisEmpty ) {

        root = new Node ;
        root->leftchild = NULL ;
        root->rightchild = NULL ;
        root->value = addvalue ;
        gHeadisEmpty = false ;
        gHead = root ;

    } // if

    else {

        if ( root->leftchild == NULL && addvalue < root->value ) {

            root->leftchild = new Node ;
            root->leftchild->leftchild = NULL ;
            root->leftchild->rightchild = NULL ;
            root->leftchild->value = addvalue ;

        } // if

        else if ( root->rightchild == NULL && addvalue >= root->value ) {

            root->rightchild = new Node ;
            root->rightchild->leftchild = NULL ;
            root->rightchild->rightchild = NULL ;
            root->rightchild->value = addvalue ;

        } // if

        else if ( addvalue < root->value )
            Add( root->leftchild, addvalue ) ;

        else if ( addvalue >= root->value )
            Add( root->rightchild, addvalue ) ;

    } // else


} // add()

void PostOrder( NodePtr root ) {

    if ( root != NULL ) {

        if ( root->leftchild != NULL )
            PostOrder( root->leftchild ) ;
        if ( root->rightchild != NULL )
            PostOrder( root->rightchild ) ;

    } // if

    cout << root->value << endl ;

} // Postorder
