Group By:
-- 1. 
Find the number of students in each course
SELECT dept_name,count(DISTINCT ID) FROM student GROUP BY dept_name;
 
-- 2. 
Find those departments where the average number of students are greater than 10
SELECT dept_name,count(DISTINCT ID) FROM (student NATURAL JOIN TAKES) GROUP BY dept_name HAVING COUNT(DISTINCT ID) >= 2;
 
-- 3. 
Find the total number of courses in each department
SELECT dept_name,COUNT(distinct course_id) FROM course GROUP BY dept_name;
 
-- 4. 
Find the names and average salaries of all departments whose average salary is greater than 42000.
SELECT dept_name,AVG(salary) FROM instructor GROUP BY dept_name HAVING AVG(salary) > 42000;
 
-- 5. 
Find the enrolment of each section that was offered in Spring 2009.
SELECT sec_id,COUNT(DISTINCT ID) FROM (TAKES NATURAL JOIN section) WHERE semester='Spring' AND year=2009 GROUP BY sec_id;
 
Ordering the display of Tuples (Use ORDER BY ASC/DESC):
-- 6. 
List all the courses with prerequisite courses, then display course id in increasing order.
SELECT course_id,prereq_id FROM prereq ORDER BY course_id;
 
-- 7. 
Display the details of instructors sorting the salary in decreasing order.
SELECT name,salary FROM instructor ORDER BY salary DESC;

Derived Relations:
-- 8.
Find the maximum total salary across the departments.
SELECT MAX(total_salary) FROM (SELECT SUM(salary) AS total_salary FROM instructor GROUP BY dept_name);
 
-- 9. 
Find the average instructors’ salaries of those departments where the average salary is greater than 42000.
SELECT AVG(T) FROM (SELECT AVG(salary) AS T FROM instructor GROUP BY dept_name HAVING AVG(salary) > 42000);
 
-- 10. 
Find the sections that had the maximum enrolment in Spring 2010.
SELECT MAX(total_student) FROM (SELECT COUNT(ID) AS total_student FROM TAKES GROUP BY sec_id, semester, year HAVING semester='Spring' and year=2010);
 
-- 11. 
Find the names of all instructors who teach all students that belong to ‘CSE’ department.
SELECT DISTINCT name FROM teaches, instructor WHERE teaches.id = instructor.id AND course_id IN (SELECT DISTINCT course_id FROM takes,student WHERE dept_name='Comp. Sci.' AND student.id = takes.id);
 
-- 12. 
Find the average salary of those department where the average salary is greater than 50000 and total number of instructors in the department are more than 5
//considered 2
SELECT dept_name, AVG(salary) FROM instructor GROUP BY dept_name HAVING AVG(salary)>50000 AND COUNT(ID)>=2;

With Clause:

-- 13.
Find all departments with the maximum budget.
WITH temp AS (SELECT max(budget) AS temp FROM department) SELECT * FROM department,temp WHERE temp = department.budget;
 
-- 14.
Find all departments where the total salary is greater than the average of the total salary at all departments
WITH temp AS (SELECT avg(sum(salary)) AS T FROM instructor group by dept_name) SELECT distinct dept_name FROM instructor,temp group by dept_name,T having sum(salary)>T;
 
-- 15.
Find the sections that had the maximum enrolment in Fall 2009
WITH temp AS (SELECT max(count(id)) AS T FROM takes WHERE semester='Fall' and year=2009 group by sec_id) SELECT sec_id FROM temp,takes WHERE semester='Fall' and year=2009 group by sec_id,temp.T having count(id) = temp.T;
 
-- 16.
Select the names of those departments where the total credits earned by all the students is greater than the total credits earned by all the students in the Finance Department
WITH temp AS (SELECT sum(tot_cred) AS T FROM student WHERE dept_name='Finance') SELECT dept_name FROM student,temp group by dept_name,temp.T having sum(tot_cred) > temp.T;

(Use ROLLBACK (and SAVEPOINT) to undo the effect of any modification on
database before COMMIT)

-- 17) Delete all the instructors of Finance department.

savepoint s1;
delete FROM instructor WHERE dept_name='Finance';
rollback to s1;
 
-- 18.) Delete all courses in CSE department.

savepoint s2;
delete FROM course WHERE dept_name='Comp. Sci.';
rollback to s2;

-- 19) Transfer all the students from CSE department to IT department.

update student set dept_name="Physics" where dept_name="Comp. Sci.";

-- 20 ) Increase salaries of instructors whose salary is over $100,000 by 3%, and all
--others receive a 5% raise

update instructor set salary=case
where salary <= 100000 then
salary * 1.05
else 
salary *1.03
end;

-- 21 ) Add all instructors to the student relation with tot_creds set to 0.

insert into student select id, name, dept_name, from instructor;

-- 22. ) Delete all instructors whose salary is less than the average salary of instructors.

delete from instructor where salary < (select avg(salary) from instructor)
