Implement the following Queries on UNIVERSITY Database:
Set Operations
UNION (Use union all to retain duplicates):
1. Find courses that ran in Fall 2009 or in Spring 2010
INTERSECT (Use intersect all to retain duplicates):
2. Find courses that ran in Fall 2009 and in spring 2010
MINUS:
3. Find courses that ran in Fall 2009 but not in Spring 2010
Null values
4. Find the name of the course for which none of the students registered.

-- Set Operatiions

-- #1 
SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 
UNION ALL SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010;

-- #2
SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 
INTERSECT SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010;                    

-- #3
SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 
MINUS SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010; 

-- #4 
SELECT course.course_id FROM course WHERE course.course_id NOT IN (SELECT takes.course_id FROM takes); 


Nested Subqueries
Set Membership (in / not in):
5. Find courses offered in Fall 2009 and in Spring 2010.
6. Find the total number of students who have taken course taught by the instructor
with ID 10101.
7. Find courses offered in Fall 2009 but not in Spring 2010.
19
8. Find the names of all students whose name is same as the instructor’s name.


-- Set Membership (in / not in)

-- #5 
SELECT s1.course_id FROM section s1 WHERE semester = 'Fall' AND year = 2009 AND s1.course_id IN (SELECT s2.course_id FROM section s2 WHERE semester = 'Spring' and year = 2010 ); 

-- #6 
SELECT COUNT(UNIQUE takes.id) FROM takes WHERE takes.course_id IN (SELECT teaches.course_id FROM teaches WHERE teaches.ID = '10101'); 

-- #7 
SELECT s1.course_id FROM section s1 WHERE semester = 'Fall' AND year = 2009 AND s1.course_id NOT IN (SELECT s2.course_id FROM section s2 WHERE semester = 'Spring' and year = 2010 ); 

-- #8 
SELECT UNIQUE student.name FROM student WHERE student.name IN (SELECT instructor.name FROM instructor); 


Set Comparison (>=some/all)
9. Find names of instructors with salary greater than that of some (at least one) instructor
in the Biology department.
10. Find the names of all instructors whose salary is greater than the salary of all
instructors in the Biology department.
11. Find the departments that have the highest average salary.
12. Find the names of those departments whose budget is lesser than the average salary

-- Set Comparison (>=some/all)

-- #9 
SELECT i1.name FROM instructor i1 WHERE i1.salary > SOME(SELECT i2.salary FROM instructor i2 WHERE i2.dept_name = 'Biology'); 

-- #10 
SELECT i1.name FROM instructor i1 WHERE i1.salary > ALL(SELECT i2.salary FROM instructor i2 WHERE i2.dept_name = 'Biology' ); 

-- #11 
SELECT dept_name FROM(SELECT dept_name, avg(salary) avgsal FROM instructor GROUP BY dept_name) WHERE avgsal = (SELECT MAX(avgsal) FROM (SELECT dept_name, AVG(salary) avgsal FROM instructor GROUP BY dept_name)); 

-- #12 
SELECT department.dept_name FROM department WHERE department.budget < (SELECT avg(salary) avgsal FROM instructor); 

Test for Empty Relations (exists/ not exists)
13. Find all courses taught in both the Fall 2009 semester and in the Spring 2010 semester.
14. Find all students who have taken all courses offered in the Biology department.
Test for Absence of Duplicate Tuples
15. Find all courses that were offered at most once in 2009.
16. Find all the students who have opted at least two courses offered by CSE department.
-- Test for Empty Relations (exists/ not exists)

-- #13 
SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 AND EXISTS(SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010); 

-- #14 
SELECT DISTINCT S.ID, S.name FROM student S WHERE NOT EXISTS((SELECT course_id FROM course WHERE dept_name = 'Biology') 
EXCEPT(SELECT T.course_id FROM takes T WHERE S.ID = T.ID));


-- Test for Absence of Duplicate Tuples

-- #15
SELECT course_id from (SELECT course_id, count (*) count FROM section WHERE section.year=2009 group by course_id) WHERE count=1;

-- #16
SELECT id FROM (select id,count(*) count FROM takes WHERE takes.course_id like 'CS%' group by id) WHERE count>=2;



Subqueries in the From Clause
17. Find the average instructors salary of those departments where the average salary is
greater than 42000

Views
18. Create a view all_courses consisting of course sections offered by Physics
department in the Fall 2009, with the building and room number of each section.
19. Select all the courses from all_courses view.
20. Create a view department_total_salary consisting of department name and total
salary of that department.

-- Subqueries in the From Clause

-- #17 
SELECT dept_name, avg_salary FROM (SELECT dept_name, AVG(salary) avg_salary FROM instructor GROUP BY dept_name) WHERE avg_salary > 42000;


-- Views

-- #18 
CREATE VIEW all_courses as SELECT section.course_id, building, room_number FROM section, course WHERE semester = 'Fall' AND year = 2009 AND section.course_id = course.course_id AND dept_name = 'Physics';

-- #19 
SELECT course_id FROM all_courses;

-- #20 
CREATE VIEW department_total_salary as SELECT dept_name, SUM(salary) sum_sal FROM instructor GROUP BY dept_name;


