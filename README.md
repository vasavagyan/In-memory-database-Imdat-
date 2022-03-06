# In-memory-database-Imdat-
This is a Redis-like database which is built on client-server connection using stream sockets. The database gives client 5 containers to work with. There are some commands which user must be familiar with to use right syntax. The data is kept in hash tables. Each one of the 5 containers has his own hash table to keep data with various keys. The commands are for following containers:

Commands for String container:
1) set - example: set keyName valueName  (keeps the value "valueName" in the string hash table with key "keyName")
2) get - example: get keyName    (finds the value with key "keyName" in the string hash table)
3) del - example: del keyName    (deletes the value with key "keyName" in the string hash table)

Commands for doubly linked list container:
1) lpushb - example: lpushb keyName valueName   (pushes an element on the back of the list with key "keyName")
2) lpushf - example: lpushf keyName valueName   (pushes an element on the front of the list with key "keyName")
3) lget   - example: lget keyName               (returns all the elements of the list with key "keyName")
4) lpopb  - example: lpopb keyName              (pops out the last element of the list with key "keyName")
5) lpopf  - example: lpopf keyName              (pops the first element of the list with key "keyName")
6) ldel   - example: ldel keyName               (deletes the list with key "keyName")
