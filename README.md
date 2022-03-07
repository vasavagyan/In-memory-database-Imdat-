# In-memory-database-Imdat-
This is a Redis-like database which is built on client-server connection using stream sockets. The database gives client 5 containers to work with. There are some commands which user must be familiar with to use right syntax. The data is kept in hash tables. Each one of the 5 containers has his own hash table to keep data with various keys. The program is written for Linux platform. The commands are for following containers:

Commands for String container:
1) set - example: set keyName valueName  (adds the value "valueName" in the string hash table with key "keyName")
2) get - example: get keyName            (finds the value with key "keyName" in the string hash table)
3) del - example: del keyName            (deletes the value with key "keyName" in the string hash table)

Commands for doubly linked list container:
1) lpushb - example: lpushb keyName valueName   (adds an element on the back of the list with key "keyName")
2) lpushf - example: lpushf keyName valueName   (adds an element on the front of the list with key "keyName")
3) lget   - example: lget keyName               (returns all the elements of the list with key "keyName")
4) lpopb  - example: lpopb keyName              (pops out the last element of the list with key "keyName")
5) lpopf  - example: lpopf keyName              (pops the first element of the list with key "keyName")
6) ldel   - example: ldel keyName               (deletes the list with key "keyName")

Commands for set container:
1) spush - example: spush keyName valueName     (adds an element in the set with key "keyName")
2) sget  - example: sget keyName                (returns all elements inorder of the set with key "keyName")
3) sdel  - example: sdel keyName                (deletes the set with key "keyName")

Commands for priority queue container:
1) qpush - example: qpush keyName valueName priority  (adds the "valueName" element in the queue with given "priority" and with key "keyName")
2) qpop  - example: qpop keyName                      (pops out the element with biggest priority in the queue with key "keyName")
3) qtop  - example: qtop keyName                      (returns the top element in the queue with key "keyName")
4) qdel  - example: qdel keyName                      (deletes the queue with key "keyName")

Commands for hash table container:
1) hpush - example: hpush keyName key value     (adds an element in the hash table with key "key" and value "value")
2) hget  - example: hget keyName key            (returns the value of the hash table with key "key")
3) hdel  - example: hdel keyName                (deletes the hash table with key "keyName")
