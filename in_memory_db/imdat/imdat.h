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
	Imdat() = default;
	Imdat(const Imdat&) = delete;
	Imdat& operator=(const Imdat&) = delete;
	Imdat(Imdat&&) = delete;
	Imdat& operator=(Imdat&&) = delete;
	~Imdat() = default;

	//functions for String commands
	void set(const std::vector<String>&);
	String get(const std::vector<String>&);
	void del(const std::vector<String>&);

	//functions for List commands
	void lpushb(const std::vector<String>&);
	void lpushf(const std::vector<String>&);
	String lget(const std::vector<String>&);
	void lpopb(const std::vector<String>&);
	void lpopf(const std::vector<String>&);
	void ldel(const std::vector<String>&);

	//functions for Set commands
	void spush(const std::vector<String>&);
	String sget(const std::vector<String>&);
	void sdel(const std::vector<String>&);

	//functions for priority queue
	void qpush(const std::vector<String>&);
	void qpop(const std::vector<String>&);
	String qtop(const std::vector<String>&);
	void qdel(const std::vector<String>&);
	
	//functions for hash_table
	void hpush(const std::vector<String>&);
	String hget(const std::vector<String>&);
	void hdel(const std::vector<String>&);

private:
	int _stoi(const String&);
	
	HashTable<String, String> stringMap;
	HashTable<String, List<String>> listMap;
	HashTable<String, Set> setMap;
	HashTable<String, MaxHeap> queueMap;
	HashTable<String, HashTable<String, String>> htMap;
};

#endif //IMDAT_H
