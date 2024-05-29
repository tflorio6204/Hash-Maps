// Name: Thomas Florio

#include "HashMap.hpp"
#include "HashNode.hpp"
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

hashMap::hashMap(bool hash1, bool coll1)
{
    first = "";
    numKeys = 0;
    collisions = 0;
    hashcoll = 0;
    mapSize = 101;
    hashfn = hash1;
    collfn = coll1;
    map = new hashNode * [mapSize];
    for(int i = 0; i < mapSize; i++)
    {
        map[i] = nullptr;
    }
}

hashMap::~hashMap() {
    for(int i=0; i<mapSize; i++) {
        if(map[i] != NULL) {
            delete map[i];
            map[i] = NULL;
        }
    }
    delete [] map;
}

void hashMap::addKeyValue(string k, string v)
{
    int i = getIndex(k);
    if(map[i] == NULL)
    {
        map[i] = new hashNode(k, v);
        numKeys++;
    }
    else
    {
        map[i]->addValue(v);
        hashcoll++;
    }
}

int hashMap::getIndex(string k)
{
    double loadFactor = (double)numKeys/(double)mapSize;
    if(loadFactor > 0.70)
    {
        reHash();
    }
    int index = -1;
    if(hashfn)
    {
        index = calcHash1(k);
        if(map[index] != nullptr && k != map[index] -> keyword)
        {
            if(collfn)
            {
                index = coll1(index, 1, k);
            }
            else
            {
                index = coll2(index, 1, k);
            }
        }
    }
    else if(!hashfn)
    {
        index = calcHash2(k);
        if(collfn)
        {
            index = coll1(index, 1, k);
        }
        else
        {
            index = coll2(index, 1, k);
        }
    }
    return index;
}

int hashMap::calcHash2(string k)
{
    int hashVal = 0;
    int strLength  = 0;
    while(k[strLength])
    {
        strLength++;
    }
    for(int i = 0; i < strLength; i++)
    {
        hashVal += (int)k[i];
    }
    hashVal = hashVal % mapSize;
    return hashVal;
}

int hashMap::calcHash1(string k){
    int hashVal2 = 0;
    int strLength  = 0;
    while(k[strLength])
    {
        strLength++;
    }
    for(int i = 0; i < strLength; i++)
    {
        hashVal2 = (hashVal2*7 + ((int)k[i])) % mapSize;
    }
    return hashVal2;
}

bool hashMap::isPrime(int num)
{
    if(num == 0 || num == 1)
    {
        return false;
    }
    for(int i = 2; i < num/2; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void hashMap::getClosestPrime()
{
    int doubSize = 2 * mapSize;
    int prime = doubSize;
    bool found = false;
    while(!found)
    {
        prime++;
        if(isPrime(prime))
        {
            found = true;
        }
    }
    mapSize = prime;
}

void hashMap::reHash()
{
    hashcoll = 0;
    collisions = 0;
    int prevSize = mapSize;
    hashNode ** oldMap = map;
    getClosestPrime();
    auto** arrCopy = new hashNode*[mapSize];
    map = arrCopy;
    for(int i=0; i<mapSize; i++)
    {
        arrCopy[i] = nullptr;
    }
    for(int i = 0; i < prevSize; i++)
    {
        if(oldMap[i] != NULL)
        {
            int index = getIndex(oldMap[i] -> keyword);
            arrCopy[index] = oldMap[i];
        }
    }
    delete [] oldMap;
}

int hashMap::coll1(int h, int i, string k)
{
    while(map[h] != nullptr && map[h] -> keyword != k)
    {
        if(map[h] != NULL && map[h] -> keyword == k)
        {
            return h;
        }
        i++;
        collisions++;
        h = (h+i) % mapSize;
    }
    return h;
}

int hashMap::coll2(int h, int i, string k)
{
    while(map[h] != nullptr && map[h] -> keyword != k)
    {
        if(map[h] != NULL && map[h] -> keyword == k)
        {
            return h;
        }
        i++;
        collisions++;
        h = (i * i + h) % mapSize;
    }
    return h;
}

void hashMap::printMap() {
    cout << "Hash Map:" << endl;
    for (int i = 0; i < mapSize; i++) {
        // print valid values
        if (map[i] != NULL) {
            printf("[%6d] ", i);
            cout << map[i]->keyword << ": ";
            for (int j = 0; j < map[i]->currSize;j++) {
                cout << map[i]->values[j] << ", ";
            }
            cout << endl;
        }
    }
    cout << "Hash Map Size: " << mapSize << endl;
}