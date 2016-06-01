#include "ArrayList.h"


ArrayList *al_newArrayList(void)
{
    ArrayList *nuevoArrayList = (ArrayList*)malloc(sizeof(ArrayList));
    nuevoArrayList->add = al_add;
    nuevoArrayList->clear = al_clear;
    nuevoArrayList->clone = al_clone;
    nuevoArrayList->contains = al_contains;
    nuevoArrayList->containsAll = al_containsAll;
    nuevoArrayList->deleteArrayList = al_deleteArrayList;
    nuevoArrayList->get = al_get;
    nuevoArrayList->indexOf = al_indexOf;
    nuevoArrayList->isEmpty = al_isEmpty;
    //Inicializar todo

    return nuevoArrayList;
}


int al_add(ArrayList* pList,void* pElement)
{
    return 0;
}

int al_len(ArrayList* pList)
{

    return 0;
}

int al_contains(ArrayList* pList, void* pElement)
{
    return 0;
}


int al_set(ArrayList* pList, int index,void* pElement)
{
    return 0;
}


int al_remove(ArrayList* pList,int index)
{
    return 0;
}


int al_clear(ArrayList* pList)
{
    return 0;
}


int al_push(ArrayList* pList, int index, void* pElement)
{
    return 0;
}


int al_indexOf(ArrayList* pList, void* element)
{
    return 0;
}


int al_isEmpty(ArrayList* pList)
{
    return 0;
}


void* al_get(ArrayList* pList , int index)
{
    return NULL;
}


void* al_pop(ArrayList* pList , int index)
{
    return NULL;
}


int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    return 0;
}


int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)
{
    return 0;
}


ArrayList* al_clone(ArrayList* pList)
{
    return NULL;
}


ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    return NULL;
}


int al_deleteArrayList(ArrayList* pList)
{
    return 0;
}
