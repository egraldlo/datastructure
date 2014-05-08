/*
 * SChild1.cpp
 *
 *      Author: casa
 */

#include "SChild1.h"

SChild1::SChild1() {

}

SChild1::SChild1(int ID):ID(ID),child(0){

}

SChild1::SChild1(int ID,SParent *sc):ID(ID),child(sc){

}

SChild1::~SChild1() {
}

SChild::SChild(){

}

SChild::SChild(int ID):ID(ID){

}

SChild::~SChild() {

}
