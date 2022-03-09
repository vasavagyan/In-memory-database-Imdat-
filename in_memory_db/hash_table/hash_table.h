#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../string/string.h"
#include "../list/list.h"

#include <vector>

struct HashMethod
{
	HashMethod() = default;
	int operator()(const String& ob, const int tableSize) const
	{
		int h = 0;
		int rand1 = 28374;
		int rand2 = 23466;
		for (int i = 0; i < ob.strlen(); ++i) {
			h = (rand1 * h + ob[i]) % tableSize;
			rand1 = (rand1 * rand2) % (tableSize - 1);
		}
		return h < 0 ? h + tableSize : h;
	}
};

template <typename Key, typename Val, typename Hash = HashMethod>
class HashTable
{
public:
	HashTable();
	HashTable(const Key&, const Val&);
	HashTable(const HashTable& other) = default;
	HashTable(HashTable&& other) = default;
	HashTable& operator=(const HashTable& other) = default;
	HashTable& operator=(HashTable&& other) = default;
	~HashTable() = default;

	Val& operator[](const Key&);
	void insert(std::pair<Key, Val>);
	void emplace(const Key&, const Val&);
	void erase(const Key&);
	void clear();
	bool find(const Key&);

private:
	Hash hashStr;
	std::vector<List<std::pair<Key, Val>>> vec;
};

#include "hash_table.hpp"

#endif //HASH_TABLE_H
