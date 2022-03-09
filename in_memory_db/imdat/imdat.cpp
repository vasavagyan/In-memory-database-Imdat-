#include "imdat.h"

#include <iostream>

Imdat::Imdat()
{
	commandMap["set"] = &Imdat::set;
	commandMap["get"] = &Imdat::get;
	commandMap["del"] = &Imdat::del;
	commandMap["lpushb"] = &Imdat::lpushb;
	commandMap["lpushf"] = &Imdat::lpushf;
	commandMap["lget"] = &Imdat::lget;
	commandMap["lpopb"] = &Imdat::lpopb;
	commandMap["lpopf"] = &Imdat::lpopf;
	commandMap["ldel"] = &Imdat::ldel;
	commandMap["spush"] = &Imdat::spush;
	commandMap["sget"] = &Imdat::sget;
	commandMap["sdel"] = &Imdat::sdel;
	commandMap["qpush"] = &Imdat::qpush;
	commandMap["qpop"] = &Imdat::qpop;
	commandMap["qtop"] = &Imdat::qtop;
	commandMap["qdel"] = &Imdat::qdel;
	commandMap["hpush"] = &Imdat::hpush;
	commandMap["hget"] = &Imdat::hget;
	commandMap["hdel"] = &Imdat::hdel;
}

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

String Imdat::set(const std::vector<String>& com) //com is "set" "name" "Vzgo"
{
	stringMap.emplace(com[1], com[2]);
	return "ok";
}

String Imdat::get(const std::vector<String>& com) //com[0] is "get", com[1] is "name"
{
	return stringMap[com[1]];
}

String Imdat::del(const std::vector<String>& com) //com[0] is "del", com[1] is "name"
{
	stringMap.erase(com[1]);
	return "ok";
}

String Imdat::lpushb(const std::vector<String>& com) //com[0]` "lpushb", com[1]` "x", com[2]` "10"
{
	listMap[com[1]].push_back(com[2]);
	return "ok";
}

String Imdat::lpushf(const std::vector<String>& com) //com[0]` "lpushf", com[1]` "x", com[2]` "10"
{
	listMap[com[1]].push_front(com[2]);
	return "ok";
}

String Imdat::lpopb(const std::vector<String>& com) //com[0]` "lpopb", com[1]` "x"
{
	listMap[com[1]].pop_back();
	return "ok";
}

String Imdat::lpopf(const std::vector<String>& com) //com[0]` "lpopf", com[1]` "x"
{
	listMap[com[1]].pop_front();
	return "ok";
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

String Imdat::ldel(const std::vector<String>& com) //com[0]` "ldel", com[1]` "x"
{
	listMap[com[1]].clear();
	return "ok";
}

String Imdat::spush(const std::vector<String>& com) //com[0]` "spush", com[1]` "s", com[2]` "hello"
{
	setMap[com[1]].insert(com[2]);
	return "ok";
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

String Imdat::sdel(const std::vector<String>& com) //com[0]` "sdel", com[1]` "s"
{
	setMap[com[1]].clear();
	return "ok";
}

String Imdat::qpush(const std::vector<String>& com) //com[0]` "qpush", com[1]` "q", com[2]` "vay", com[3]` "4"
{
	int priority = _stoi(com[3]);

	queueMap[com[1]].push(com[2], priority);
	return "ok";
}

String Imdat::qpop(const std::vector<String>& com) //com[0]` "qpop", com[1]` "q"
{
	String value = queueMap[com[1]].pop();
	return "ok";
}

String Imdat::qtop(const std::vector<String>& com) //com[0]` "qtop", com[1]` "q"
{
	return queueMap[com[1]].top();
}

String Imdat::qdel(const std::vector<String>& com) //com[0]` "qdel", com[1]` "q"
{
	queueMap[com[1]].clear();
	return "ok";
}

String Imdat::hpush(const std::vector<String>& com) //com[0]` "hpush", com[1]` "h", com[2]` "hashKey", com[3]` "hashVal"
{
	htMap[com[1]].emplace(com[2], com[3]);
	return "ok";
}

String Imdat::hget(const std::vector<String>& com) //com[0]` "hget", com[1]` "h", com[2]` "hashKey"
{
	String value = htMap[com[1]][com[2]];
	return value;
}

String Imdat::hdel(const std::vector<String>& com) //com[0]` "hget", com[1]` "h"
{
	htMap[com[1]].clear();
	return "ok";
}

String Imdat::call(const std::vector<String>& com)
{
	if (commandMap.find(com[0])) {
		return (this->*commandMap[com[0]])(com);
	}
	return "Wrong command";
}
