SELECT Email FROM (SELECT Email, COUNT(Email) AS cnt FROM Person GROUP BY Email) AS sub WHERE sub.cnt > 1;