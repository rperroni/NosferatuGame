
#include "ObjectAdder.h"


int ObjectAdder::searchId(Dictionary &dict, int startId, int endId) {

    bool idNotFound = true;
    int matchingId;

    while(idNotFound && startId <= endId) {

        if (! dict.search(startId)) {
            matchingId = startId;
            idNotFound = false;
        }
        else
            startId++;

    }


    if (!idNotFound)
        return matchingId;
    else
        return -1;

}
