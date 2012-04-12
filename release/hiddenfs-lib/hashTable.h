/**
 * @author Martin Pavlásek (xpavla07@stud.fit.vutbr.cz)
 *
 * Created on 23. březen 2012
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include <string>
#include <map>
#include "types.h"

using namespace std;

/**
 * Bidirectional mapping real file path and its uniqe hash string
 */
class hashTable {
public:
    hashTable();
    hashTable(const hashTable& orig);

    /**
     * Vyhledání v tabulce (mapování hash -> název souboru)
     * @param hash hash řetězec souboru
     * @param path umístění skutečného souboru
     */
    void find(T_HASH hash, string* filename);

    /**
     * Vloží nový záznam do hash tabulky
     * @param hash vypočítaný hash z obsahu souboru
     * @param filename umístění skutečného souboru
     */
    void add(T_HASH hash, string filename);

    /**
     * Remove all items from table
     */
    void clear();
    virtual ~hashTable();
private:
    map<T_HASH, string> table;
};

#endif	/* HASHTABLE_H */
