#ifndef IMDAT_H
#define IMDAT_H

#include "../hash_table/hash_table.h"
#include "../list/list.h"
#include "../string/string.h"
#include "../set/set.h"
#include "../priority_queue/priority_queue.h"

#include <vector>

class Imdat
{
public:
	Imdat();
	Imdat(const Imdat&) = delete;
	Imdat& operator=(const Imdat&) = delete;
	Imdat(Imdat&&) = delete;
	Imdat& operator=(Imdat&&) = delete;
	~Imdat() = default;

	//functions for String commands
	String set(const std::vector<String>&);
	String get(const std::vector<String>&);
	String del(const std::vector<String>&);

	//functions for List commands
	String lpushb(const std::vector<String>&);
	String lpushf(const std::vector<String>&);
	String lget(const std::vector<String>&);
	String lpopb(const std::vector<String>&);
	String lpopf(const std::vector<String>&);
	String ldel(const std::vector<String>&);

	//functions for Set commands
	String spush(const std::vector<String>&);
	String sget(const std::vector<String>&);
	String sdel(const std::vector<String>&);

	//functions for priority queue
	String qpush(const std::vector<String>&);
	String qpop(const std::vector<String>&);
	String qtop(const std::vector<String>&);
	String qdel(const std::vector<String>&);
	
	//functions for hash_table
	String hpush(const std::vector<String>&);
	String hget(const std::vector<String>&);
	String hdel(const std::vector<String>&);

	//finds the proper function for command and calls
	String call(const std::vector<String>&);

private:
	int _stoi(const String&);
	
	HashTable<String, String> stringMap;
	HashTable<String, List<String>> listMap;
	HashTable<String, Set> setMap;
	HashTable<String, MaxHeap> queueMap;
	HashTable<String, HashTable<String, String>> htMap;
	
	HashTable<String, String(Imdat::*)(const std::vector<String>&)> commandMap;
};

#endif //IMDAT_H
