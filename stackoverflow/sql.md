https://devhints.io/mysql

http://g2pc1.bu.edu/~qzpeng/manual/MySQL%20Commands.htm


## Resolving DELETE where tables are linked

https://dev.mysql.com/doc/refman/5.6/en/create-table-foreign-keys.html

When you have an error in the form of:

```Cannot delete or update a parent row: a foreign key constraint fails (`ftw`.`B`, CONSTRAINT `B_A` FOREIGN KEY (`id`) REFERENCES `A` (`id`))```

It means that you are trying to delete a record using "id" from table A, there is a record in table B that references the record in A and the record in B must somehow be taken care of first.
