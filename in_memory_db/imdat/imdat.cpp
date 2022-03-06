#include "imdat.h"

#include <iostream>

int Imdat::_stoi(const String& str)
{
	int j = 0;
	int i = 0;
	while (str[i] >= '0' && str[i] <= '9') {
		j = j * 10 + (str[i] - '0');
		++i;
	}
	return j;
}

void Imdat::set(const std::vector<String>& com) //com is "set" "name" "Vzgo"
{
	stringMap.emplace(com[1], com[2]);
}

String Imdat::get(const std::vector<String>& com) //com[0] is "get", com[1] is "name"
{
	return stringMap[com[1]];
}

void Imdat::del(const std::vector<String>& com) //com[0] is "del", com[1] is "name"
{
	stringMap.erase(com[1]);
}

void Imdat::lpushb(const std::vector<String>& com) //com[0]` "lpushb", com[1]` "x", com[2]` "10"
{
	listMap[com[1]].push_back(com[2]);
}

void Imdat::lpushf(const std::vector<String>& com) //com[0]` "lpushf", com[1]` "x", com[2]` "10"
{
	listMap[com[1]].push_front(com[2]);
}

void Imdat::lpopb(const std::vector<String>& com) //com[0]` "lpopb", com[1]` "x"
{
	listMap[com[1]].pop_back();
}

void Imdat::lpopf(const std::vector<String>& com) //com[0]` "lpopf", com[1]` "x"
{
	listMap[com[1]].pop_front();
}

String Imdat::lget(const std::vector<String>& com)  //com[0]` "lget", com[1]` "x"
{
	String str;
	if (listMap[com[1]].begin() != nullptr) {
		for (auto it = listMap[com[1]].begin(); it != listMap[com[1]].end(); ++it) {
			str = str + " " + (*it);
		}
	}
	return str;
}

void Imdat::ldel(const std::vector<String>& com) //com[0]` "ldel", com[1]` "x"
{
	listMap[com[1]].clear();
	std::cout << "List cleaned successfully" << std::endl;
}

void Imdat::spush(const std::vector<String>& com) //com[0]` "spush", com[1]` "s", com[2]` "hello"
{
	setMap[com[1]].insert(com[2]);
}

String Imdat::sget(const std::vector<String>& com) //com[0]` "sget", com[1]` "s", com[2]` "hello"
{
	if (setMap[com[1]].empty()) {
		std::cout << "Set is empty" << std::endl;
		return "";
	}
	String val = setMap[com[1]].get();
	return val;
}

void Imdat::sdel(const std::vector<String>& com) //com[0]` "sdel", com[1]` "s"
{
	setMap[com[1]].clear();
}

void Imdat::qpush(const std::vector<String>& com) //com[0]` "qpush", com[1]` "q", com[2]` "vay", com[3]` "4"
{
	int priority = _stoi(com[3]);

	queueMap[com[1]].push(com[2], priority);
}

void Imdat::qpop(const std::vector<String>& com) //com[0]` "qpop", com[1]` "q"
{
	String value = queueMap[com[1]].pop();
}

String Imdat::qtop(const std::vector<String>& com) //com[0]` "qtop", com[1]` "q"
{
	return queueMap[com[1]].top();
}

void Imdat::qdel(const std::vector<String>& com) //com[0]` "qdel", com[1]` "q"
{
	queueMap[com[1]].clear();
}

void Imdat::hpush(const std::vector<String>& com) //com[0]` "hpush", com[1]` "h", com[2]` "hashKey", com[3]` "hashVal"
{
	htMap[com[1]].emplace(com[2], com[3]);
}

String Imdat::hget(const std::vector<String>& com) //com[0]` "hget", com[1]` "h", com[2]` "hashKey"
{
	String value = htMap[com[1]][com[2]];
	return value;
}

void Imdat::hdel(const std::vector<String>& com) //com[0]` "hget", com[1]` "h"
{
	htMap[com[1]].clear();
	std::cout << "Hash Table cleaned successfully" << std::endl;
}
