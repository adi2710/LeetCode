# SELECT Email FROM (SELECT Email, COUNT(Email) AS cnt FROM Person GROUP BY Email) AS sub WHERE sub.cnt > 1;

SELECT Email FROM Person GROUP BY Email HAVING COUNT(Email) > 1;