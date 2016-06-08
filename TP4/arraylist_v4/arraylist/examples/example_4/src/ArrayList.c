#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int resizeDown(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

void swap(void *vp1,void *vp2,int size);
void ordenar(void **lista,int size, int (*pFunc)(void* ,void*),char order);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList,void* pElement)
{
    if(pList == NULL || pElement == NULL)
        return -1;

    if(resizeUp(pList))
        return -1;

    pList->pElements[pList->size] = pElement;
    pList->size = pList->size +1;
    return 0;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    if(pList == NULL)
        return -1;

    free(pList->pElements);
    free(pList);
    if(pList->size > 0)
        return 0;
    else
        return 1;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)
{
    if(pList == NULL)
    {
        return -1;
    }
    return pList->size;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList , int index)
{
    if(pList == NULL)return NULL;
    if(index < 0 )return NULL;
    if(index >= pList->size)return NULL;

    return pList->pElements[index];
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int i;
    if(pList == NULL || pElement == NULL)
        return -1;

    for(i=0;i< pList->size;i++)
    {
        if(pList->pElements[i] == pElement)
            return 1;
    }
    return 0;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)
{
    if(pList == NULL){return -1;}
    if(pElement == NULL){return -1;}
    if(index < 0){return -1;}
    if(index >= pList->size){return -1;}

    pList->pElements[index] = pElement;

    return 0;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)
{
    if(pList == NULL)return -1;
    if(index < 0 )return -1;
    if(index >= pList->size)return -1;

    pList->pElements[index] = NULL;// HAY QUE HACER ESTO?

    contract(pList,index);
    resizeDown(pList);
    pList->size = pList->size - 1;
    return 0;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)
{
    int i;
    if(pList == NULL)return -1;
    for(i=0;i< pList->size;i++)
    {
        pList->pElements[i] = NULL;// HAY QUE HACER ESTO?
    }
    pList->size = 0;
    resizeDown(pList);
    return 0;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)
{
    ArrayList * aux;
    if(pList == NULL)return NULL;

    aux = al_newArrayList();
    if(aux == NULL)return NULL;

    aux->size = pList->size;
    aux->reservedSize = pList->reservedSize;
    aux->pElements = realloc(aux->pElements,pList->reservedSize * sizeof(void*));
    if(aux->pElements == NULL)return NULL;
    memcpy( aux->pElements , pList->pElements , pList->reservedSize * sizeof(void*));

    return aux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)
{
    if(pList == NULL)return -1;
    if(pElement == NULL)return -1;
    if(index < 0 )return -1;
    if(index > pList->size)return -1;
    expand(pList,index);

    pList->set(pList,index,pElement);

    return 0;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int index = 0;
    if(pList == NULL)return -1;
    if(pElement == NULL)return -1;

    for(index = 0;index < pList->size;index++)
    {
        if(pList->get(pList,index) == pElement)
            return index;
    }
    return -1;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)
{
    if(pList == NULL)return -1;
    return !(pList->size > 0);
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)
{
    void* aux = NULL;
    if(pList == NULL)return NULL;
    if(index < 0 )return NULL;
    if(index >= pList->size)return NULL;

    aux = pList->get(pList,index);
    pList->remove(pList,index);
    resizeDown(pList);
    return aux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    ArrayList *aux = NULL;
    int i = 0;
    if(pList == NULL)return NULL;
    if(from > to)return NULL;
    if(to > pList->size)return NULL;
    if(from < 0)return NULL;

    aux = al_newArrayList();
    if( aux == NULL)return NULL;

    for(i = from; i <= to;i++)
    {
        aux->add(aux,pList->get(pList,i));
    }

    return aux;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int i,j;
    int contadorDeIguales = 0;
    if(pList == NULL)return -1;
    if(pList2 == NULL)return -1;

    for(i = 0; i < pList->size;i++)
    {
        for(j=0;j< pList2->size;j++)
        {
            if(al_get(pList,j) == al_get(pList2,i))
            {
                contadorDeIguales++;
                break;
            }
        }
    }

    return (contadorDeIguales == pList2->size);
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)
{
    if(pList == NULL)return -1;
    if(pFunc == NULL)return -1;
    if(order != 1 && order != 0)return -1;

    ordenar(pList->pElements,pList->size,pFunc,order?'a':'d');

    return 0;
}



int resizeDown(ArrayList* pList)
{
    int newSpace;
    void **auxPElements=NULL;
    if(pList->reservedSize - pList->size > 10)
    {
        newSpace = (pList->reservedSize - 10) * sizeof(void*);
        auxPElements = realloc(pList->pElements,newSpace);
        if(auxPElements == NULL)
            return -1;
        pList->reservedSize = pList->reservedSize -10 10;
        pList->pElements = auxPElements;
    }
    return 0;
}

/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)
{
    int newSpace;
    void **auxPElements=NULL;
    if(pList->size == pList->reservedSize)
    {
        newSpace = (10+ pList->reservedSize) * sizeof(void*);
        auxPElements = realloc(pList->pElements,newSpace);
        if(auxPElements == NULL)
            return -1;
        pList->reservedSize = pList->reservedSize + 10;
        pList->pElements = auxPElements;
    }
    return 0;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int i;
    if(pList == NULL)return -1;
    if(index < 0 )return -1;
    if(index > pList->size)return -1;

    if(resizeUp(pList))
        return -1;

    for(i = pList->size; i >= index;i--)
    {
        pList->pElements[i] = pList->pElements[i-1];
    }
    pList->size++;
    return 0;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int i;
    if(pList == NULL)
        return -1;
    if(index < 0 || index >= pList->size)
        return -1;

    for(i = index; i < (pList->size-1) ;i++)
    {
        pList->pElements[i] = pList->pElements[i+1];
    }

    return 0;
}
void swap(void *vp1,void *vp2,int size)
{
  void *buf = malloc(size);
  memcpy(buf,vp1,size);
  memcpy(vp1,vp2,size);
  memcpy(vp2,buf,size);  //memcpy ->inbuilt function in std-c
}

// COPIADO DE MI MD_LIB
void ordenar(void **lista, int size, int (*cmp)(void* ,void*),char order)
{
    int i,j;
    void* auxSwap;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if( order == 'a')
            {
                if(cmp(lista[i],lista[j]) > 0)
                {
                    auxSwap = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxSwap;
                }
            }
            if(order == 'd')
            {
                if(cmp(lista[i],lista[j]) < 0)
                {
                    auxSwap = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxSwap;
                }
            }
        }
    }
}




