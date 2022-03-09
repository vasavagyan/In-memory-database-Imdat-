#include "hash_table.h"

//default constructor
template <typename Key, typename Val, typename Hash>
HashTable<Key, Val, Hash>::HashTable() : vec(100) {}

//param constructor
template <typename Key, typename Val, typename Hash>
HashTable<Key, Val, Hash>::HashTable(const Key& key, const Val& val) : vec(100)
{
	int index = hashStr(key, vec.size());
	vec[index].push_back(std::make_pair<key, val>);
}

template <typename Key, typename Val, typename Hash>
Val& HashTable<Key, Val, Hash>::operator[](const Key& key)
{
	int index = hashStr(key, vec.size());
	if (vec[index].begin() != nullptr) {
		for (auto it = vec[index].begin(); it != vec[index].end(); ++it) {
			if (it->first == key) {
				return it->second;
			}
		}
	}

	vec[index].push_back(std::make_pair(key, Val()));
	typename List<std::pair<Key, Val>>::iterator iter = vec[index].begin();
	iter->first = key;
	return iter->second;
}

template <typename Key, typename Val, typename Hash>
void HashTable<Key, Val, Hash>::insert(std::pair<Key, Val> pr)
{
	int index = hashStr(pr.first, vec.size());
	vec[index].push_back(std::make_pair(pr.first, pr.second));
}

template <typename Key, typename Val, typename Hash>
void HashTable<Key, Val, Hash>::emplace(const Key& key, const Val& val)
{
	int index = hashStr(key, vec.size());
	vec[index].push_back(std::make_pair(key, val));
}

template <typename Key, typename Val, typename Hash>
void HashTable<Key, Val, Hash>::erase(const Key& key)
{
	int index = hashStr(key, vec.size());
	for (auto it = vec[index].begin(); it != vec[index].end(); ++it) {
		if (it->first == key) {
			vec[index].erase(it);
			break;
		}
	}
}

template <typename Key, typename Val, typename Hash>
void HashTable<Key, Val, Hash>::clear()
{
	for (int i = 0; i < vec.size(); ++i) {
		vec[i].clear();
	}
}

template <typename Key, typename Val, typename Hash>
bool HashTable<Key, Val, Hash>::find(const Key& key)
{
        int index = hashStr(key, vec.size());
        if (vec[index].begin() != nullptr) {
                for (auto it = vec[index].begin(); it != vec[index].end(); ++it) {
                        if (it->first == key) {
                                return true;
                        }
                }
        }
        return false;
}
