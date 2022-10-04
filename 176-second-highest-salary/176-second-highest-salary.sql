# Write your MySQL query statement below

# SELECT MAX(salary) AS SecondHighestSalary from Employee 
# WHERE salary
# NOT IN
# (SELECT MAX(salary) from Employee);


SELECT IFNULL((SELECT DISTINCT Salary
	             FROM Employee 
				 ORDER BY Salary DESC 
				 LIMIT 1,1),NULL) AS SecondHighestSalary;


