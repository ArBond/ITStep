/*SELECT DISTINCT Department
FROM Table_1  as La
WHERE c2> 44 AND 
 EXISTS (SELECT Department
 FROM Table_1
 WHERE c2 <33 and department =La.Department );*/
 /*SELECT DISTINCT model, price
FROM Laptop
WHERE price > ALL (SELECT price 
 FROM PC
 );*/
 /*
  SELECT snum, sname                            
               FROM  Salespeople                             
              WHERE city = 'London'                         
               UNION                                          
               SELECT cnum, cname                             
                FROM Customers                                
                WHERE city = 'London'; 
 */

 https://ru.wikipedia.org/wiki/Join_(SQL)
