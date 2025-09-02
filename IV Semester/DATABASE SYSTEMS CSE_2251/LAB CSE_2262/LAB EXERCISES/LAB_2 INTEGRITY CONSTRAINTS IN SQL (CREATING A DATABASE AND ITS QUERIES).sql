-- Q1)  Create Employee table with following constraints:
-- Make EmpNo as Primary key.
-- Do not allow EmpName, Gender, Salary and Address to have null values.
-- Allow Gender to have one of the two values: ‘M’, ‘F’

create table employee(
  2  EmpNo number(10) primary key,
  3  EmpName varchar(20) not null,
  4  Gender char(2) not null,
  5  Salary number(10,2) not null,
  6  Address varchar(30) not null,
  7  DNo number(10),
  8  check(gender in('F','M')));

-- Q2)Create Department table with following:
-- Make DeptNo as Primary key
-- Make DeptName as candidate key

create table Department(
  2  DeptNo number(10) primary key,
  3  DeptName varchar(20) unique,
  4  Location varchar(20));


-- Q3) Make DNo of Employee as foreign key which refers to DeptNo of Department

alter table employee modify foreign key(dno) references department(deptno);

-- Q4)Insert few tuples into Employee and Department which satisfies the above constraints.

insert into department values(1, 'CSE', 'MIT');
insert into department values(2, 'CCE', 'MIT');
insert into department values(3, 'EEE', 'NIIT');
insert into department values(4, 'MECH', 'IIT');

insert into employee values(1, 'abcde', 'M', 3000000, 'Manipal', 1);
insert into employee values(2, 'bcdef', 'F', 2000000, 'Manipal', 2);
insert into employee values(3, 'cdefg', 'M', 2500000, 'Bombay', 3);
insert into employee values(4, 'defgh', 'F', 2500000, 'Bombay', 4);

-- Q5)Try to insert few tuples into Employee and Department which violates some of the
--above constraints 

-- Invalid Insertions
insert into employee values(1, 'Jack', 'M', 10000, 'Bangalore', 4);
insert into employee values(1, 'Jack', 'M', 10000, 'Bangalore', 4)
insert into employee values(5, 'Jack', 'C', 10000, 'Bangalore', 4);
insert into employee values(5, 'Jack', 'C', 10000, 'Bangalore', 4)
insert into department values(1, 'IT', 'MIT');
insert into department values(1, 'IT', 'MIT')
insert into department values(5, 'CSE', 'MIT');
insert into department values(5, 'CSE', 'MIT')

-- Q6) Try to modify/delete a tuple which violates a constraint.
-- Invalid Updation
update employee set gender='C' where EmpNo=2;
update employee set gender='C' where EmpNo=2

-- Invalid Deletion
delete from department where deptno=1;
delete from department where deptno=1

-- Q7) Modify the foreign key constraint of Employee table such that whenever a department
-- tuple is deleted, the employees belonging to that department will also be deleted.

select constraint_name from user_constraints where table_name='EMPLOYEE' and constraint_type='R';

"
CONSTRAINT_NAME                                                                 
------------------------------                                                  
SYS_C007108 
"                                                                    

-- Remoing Prev Constraint
alter table employee drop constraint SYS_C007108;

"
Table altered.
"

-- Adding New Constraint
alter table employee add constraint DC_DNo foreign key(dno) references Department(deptno) on delete cascade;

"
Table altered.
"

-- Displaying Employee Table
select * from employee;

"
     EMPNO EMPNAME              GENDER         SALARY ADDRESS                               DNO                                                                                                                                                                                                             
---------- -------------------- ---------- ---------- ------------------------------ ----------                                                                                                                                                                                                             
         1 abcde                M             3000000 Manipal                                 1                                                                                                                                                                                                             
         2 bcdef                F             2000000 Manipal                                 2                                                                                                                                                                                                             
         3 cdefg                M             2500000 Suratkal                                3                                                                                                                                                                                                             
         4 defgh                F             2500000 Bombay                                  4      
"                                                                                                                                                                                                       

-- Displaying Department Table
select * from department;

"
    DEPTNO DEPTNAME             LOCATION                                                                                                                                                                                                                                                                    
---------- -------------------- --------------------                                                                                                                                                                                                                                                        
         1 CSE                  MIT                                                                                                                                                                                                                                                                         
         2 CCE                  MIT                                                                                                                                                                                                                                                                         
         3 EEE                  NIIT                                                                                                                                                                                                                                                                       
         4 MECH                 IIT  
"                                                                                                                                                                                                                                                                  

-- 
delete from department where deptno=3;

"
1 row deleted.
"

-- Displaying Data
select * from employee;

"
     EMPNO EMPNAME              GENDER         SALARY ADDRESS                               DNO                                                                                                                                                                                                             
---------- -------------------- ---------- ---------- ------------------------------ ----------                                                                                                                                                                                                             
         1 abcde                M             3000000 Manipal                                 1                                                                                                                                                                                                             
         2 bcdef                F             2000000 Manipal                                 2                                                                                                                                                                                                             
         4 defgh                F             2500000 Bombay                                  4    
"                                                                                                                                                                                                         

-- 
select * from department;

"
    DEPTNO DEPTNAME             LOCATION                                                                                                                                                                                                                                                                    
---------- -------------------- --------------------                                                                                                                                                                                                                                                        
         1 CSE                  MIT                                                                                                                                                                                                                                                                         
         2 CCE                  MIT                                                                                                                                                                                                                                                                         
         4 MECH                 IIT      

" 


-- Q8) Create a named constraint to set the default salary to 10000 and test the constraint by
--inserting a new record.

alter table employee modify salary default 10000;
insert into employee(empno, empname, gender, address, dno) values(8, 'Test', 'M', 'Bangalore', 1);
select * from employee;

"
     EMPNO EMPNAME              GENDER         SALARY ADDRESS                               DNO                                                                                                                                                                                                             
---------- -------------------- ---------- ---------- ------------------------------ ----------                                                                                                                                                                                                             
         1 abcde                M             3000000 Manipal                                 1                                                                                                                                                                                                             
         2 bcdef                F             2000000 Manipal                                 2                                                                                                                                                                                                             
         4 defgh                F             2500000 Bombay                                  4                                                                                                                                                                                                             
         8 Test                 M               10000 Bangalore                               1       
" 
 
-- Q9)  List all Students with names and their department names.

select name, dept_name from student;

"
NAME                 DEPT_NAME                                                                                                                                                                                                                                                                              
-------------------- --------------------                                                                                                                                                                                                                                                                   
Zhang                Comp. Sci.                                                                                                                                                                                                                                                                             
Shankar              Comp. Sci.                                                                                                                                                                                                                                                                             
Brandt               History                                                                                                                                                                                                                                                                                
Chavez               Finance                                                                                                                                                                                                                                                                                
Peltier              Physics                                                                                                                                                                                                                                                                                
Levy                 Physics                                                                                                                                                                                                                                                                                
Williams             Comp. Sci.                                                                                                                                                                                                                                                                             
Sanchez              Music                                                                                                                                                                                                                                                                                  
Snow                 Physics                                                                                                                                                                                                                                                                                
Brown                Comp. Sci.                                                                                                                                                                                                                                                                             
Aoi                  Elec. Eng.                                                                                                                                                                                                                                                                             
Bourikas             Elec. Eng.                                                                                                                                                                                                                                                                             
Tanaka               Biology                                                                                                                                                                                                                                                                                

13 rows selected.
"

-- Q10) List all instructors in CSE department
select * from instructor where dept_name='Comp. Sci.';

"
ID    NAME                 DEPT_NAME                SALARY                                                                                                                                                                                                                                                  
----- -------------------- -------------------- ----------                                                                                                                                                                                                                                                  
10101 Srinivasan           Comp. Sci.                65000                                                                                                                                                                                                                                                  
45565 Katz                 Comp. Sci.                75000                                                                                                                                                                                                                                                  
83821 Brandt               Comp. Sci.                92000   
"                                                                                                                                                                                                                                               

-- Q11)Find the names of courses in CSE department which have 3 credits

select title from course where dept_name='Comp. Sci.' and credits=3;

"
TITLE                                                                                                                                                                                                                                                                                                       
--------------------------------------------------                                                                                                                                                                                                                                                          
Robotics                                                                                                                                                                                                                                                                                                    
Image Processing                                                                                                                                                                                                                                                                                            
Database System Concepts   
"                                                                                                                                                                                                                                                                                 

-- Q12)For the student with ID 12345 (or any other value), show all course-id and title of all
--courses registered for by the student.

select title, course_id from course natural join takes where ID=12345;

"
TITLE                                              COURSE_ID                                                                                                                                                                                                                                                
-------------------------------------------------- ------------------------------                                                                                                                                                                                                                           
Intro. to Computer Science                         CS-101                                                                                                                                                                                                                                                   
Game Design                                        CS-190                                                                                                                                                                                                                                                   
Robotics                                           CS-315                                                                                                                                                                                                                                                   
Database System Concepts                           CS-347                                                                                                                                                                                                                                                   
"

-- Q13) List all the instructors whose salary is in between 40000 and 90000.

select * from instructor where salary between 40000 and 90000;

"
ID    NAME                 DEPT_NAME                SALARY                                                                                                                                                                                                                                                  
----- -------------------- -------------------- ----------                                                                                                                                                                                                                                                  
10101 Srinivasan           Comp. Sci.                65000                                                                                                                                                                                                                                                  
12121 Wu                   Finance                   90000                                                                                                                                                                                                                                                  
15151 Mozart               Music                     40000                                                                                                                                                                                                                                                  
32343 El Said              History                   60000                                                                                                                                                                                                                                                  
33456 Gold                 Physics                   87000                                                                                                                                                                                                                                                  
45565 Katz                 Comp. Sci.                75000                                                                                                                                                                                                                                                  
58583 Califieri            History                   62000                                                                                                                                                                                                                                                  
76543 Singh                Finance                   80000                                                                                                                                                                                                                                                  
76766 Crick                Biology                   72000                                                                                                                                                                                                                                                  
98345 Kim                  Elec. Eng.                80000                                                                                                                                                                                                                                                  

-- #14) . Display the IDs of all instructors who have never taught a course

select id from instructor where id not in (select distinct id from teaches);

"
ID                                                                                                                                                                                                                                                                                                          
-----                                                                                                                                                                                                                                                                                                       
33456                                                                                                                                                                                                                                                                                                       
58583                                                                                                                                                                                                                                                                                                       
76543   
"                                                                                                                                                                                                                                                                                                    

-- #15) Find the student names, course names, and the year, for all students those who have
-- attended classes in room-number 303.

select name, title, takes.year from student, section, course, takes where room_number=3128 and course.course_id = section.course_id and course.course_id = takes.course_id and takes.id = student.id and takes.year = section.year and takes.sec_id = section.sec_id and section.semester = takes.semester;

"
NAME                 TITLE                                                    YEAR                                                                                                                                                                                                                          
-------------------- -------------------------------------------------- ----------                                                                                                                                                                                                                          
Zhang                Database System Concepts                                 2009                                                                                                                                                                                                                          
Shankar              Game Design                                              2009                                                                                                                                                                                                                          
Shankar              Database System Concepts                                 2009                                                                                                                                                                                                                          
Williams             Game Design                                              2009                                                                                                                                                                                                                          
Brown                Image Processing                                         2010                                                                                                                                                                                                                          
Aoi                  Intro. to Digital Systems                                2009                                                                                                                                                                                                                          

-- #16) For all students who have opted courses in 2015, find their names and course id’s
-- with the attribute course title replaced by c-name.
Select name,course_id,title as c_name from (student natural join takes) join course using(course_id) where year=2015;

"
NAME                 COURSE_ID                      C_NAME                                                                                                                                                                                                                                                  
-------------------- ------------------------------ --------------------------------------------------                                                                                                                                                                                                      
Tanaka               BIO-301                        Genetics                                                                                                                                                                                                                                                
Levy                 CS-101                         Intro. to Computer Science                                                                                                                                                                                                                              
Bourikas             CS-315                         Robotics                                                                                                                                                                                                                                                
Shankar              CS-315                         Robotics                                                                                                                                                                                                                                                
Brown                CS-319                         Image Processing                                                                                                                                                                                                                                        
Levy                 CS-319                         Image Processing                                                                                                                                                                                                                                        
Chavez               FIN-201                        Investment Banking                                                                                                                                                                                                                                      
Brandt               HIS-351                        World History                                                                                                                                                                                                                                           
Sanchez              MU-199                         Music Video Production                                                                                                                                                                                                                                  

9 rows selected.
"

-- #17)Find the names of all instructors whose salary is greater than the salary of at least
-- one instructor of CSE department and salary replaced by inst-salary

select distinct a.name, a.salary as inst_salary from instructor a, instructor b where a.salary > b.salary and b.dept_name='Comp. Sci.';

"
NAME                 INST_SALARY                                                                                                                                                                                                                                                                            
-------------------- -----------                                                                                                                                                                                                                                                                            
Crick                      72000                                                                                                                                                                                                                                                                            
Katz                       75000                                                                                                                                                                                                                                                                            
Gold                       87000                                                                                                                                                                                                                                                                            
Einstein                   95000                                                                                                                                                                                                                                                                            
Wu                         90000                                                                                                                                                                                                                                                                            
Brandt                     92000                                                                                                                                                                                                                                                                            
Singh                      80000                                                                                                                                                                                                                                                                            
Kim                        80000                                                                                                                                                                                                                                                                            

-- Q18)Find the names of all instructors whose department name includes the substring 'ch'

select name from instructor where dept_name like '%ch%';

-- #19) List the student names along with the length of the student names
select name, length(name) from student;

"
NAME                 LENGTH(NAME)                                                                                                                                                                                                                                                                           
-------------------- ------------                                                                                                                                                                                                                                                                           
Zhang                           5                                                                                                                                                                                                                                                                           
Shankar                         7                                                                                                                                                                                                                                                                           
Brandt                          6                                                                                                                                                                                                                                                                           
Chavez                          6                                                                                                                                                                                                                                                                           
Peltier                         7                                                                                                                                                                                                                                                                           
Levy                            4                                                                                                                                                                                                                                                                           
Williams                        8                                                                                                                                                                                                                                                                           
Sanchez                         7                                                                                                                                                                                                                                                                           
Snow                            4                                                                                                                                                                                                                                                                           
Brown                           5                                                                                                                                                                                                                                                                           
Aoi                             3                                                                                                                                                                                                                                                                           
Bourikas                        8                                                                                                                                                                                                                                                                           
Tanaka                          6                                                                                                                                                                                                                                                                           

13 rows selected.
"

-- #20)List the department names and 3 characters from 3rd position of each department name

select dept_name, substr(dept_name, 3, 3) from department;

"
DEPT_NAME            SUBSTR(DEPT_                                                                                                                                                                                                                                                                           
-------------------- ------------                                                                                                                                                                                                                                                                           
Biology              olo                                                                                                                                                                                                                                                                                    
Comp. Sci.           mp.                                                                                                                                                                                                                                                                                    
Elec. Eng.           ec.                                                                                                                                                                                                                                                                                    
Finance              nan                                                                                                                                                                                                                                                                                    
History              sto                                                                                                                                                                                                                                                                                    
Music                sic                                                                                                                                                                                                                                                                                    
Physics              ysi                                                                                                                                                                                                                                                                                    

7 rows selected.
"

-- #21)List the instructor names in upper case
select upper(name) from instructor;

"
UPPER(NAME)                                                                                                                                                                                                                                                                                                 
--------------------                                                                                                                                                                                                                                                                                        
SRINIVASAN                                                                                                                                                                                                                                                                                                  
WU                                                                                                                                                                                                                                                                                                          
MOZART                                                                                                                                                                                                                                                                                                      
EINSTEIN                                                                                                                                                                                                                                                                                                    
EL SAID                                                                                                                                                                                                                                                                                                     
GOLD                                                                                                                                                                                                                                                                                                        
KATZ                                                                                                                                                                                                                                                                                                        
CALIFIERI                                                                                                                                                                                                                                                                                                   
SINGH                                                                                                                                                                                                                                                                                                       
CRICK                                                                                                                                                                                                                                                                                                       
BRANDT                                                                                                                                                                                                                                                                                                      
KIM                                                                                                                                                                                                                                                                                                         

12 rows selected.
"

-- #22) Replace NULL with value1(say 0) for a column in any of the table

select nvl(grade, 'F') from takes;


-- #23)  Display the salary and salary/3 rounded to nearest hundred from Instructor.

select salary, round(salary/3, -2) from instructor;

"
    SALARY ROUND(SALARY/3,-2)                                                                                                                                                                                                                                                                               
---------- ------------------                                                                                                                                                                                                                                                                               
     65000              21700                                                                                                                                                                                                                                                                               
     90000              30000                                                                                                                                                                                                                                                                               
     40000              13300                                                                                                                                                                                                                                                                               
     95000              31700                                                                                                                                                                                                                                                                               
     60000              20000                                                                                                                                                                                                                                                                               
     87000              29000                                                                                                                                                                                                                                                                               
     75000              25000                                                                                                                                                                                                                                                                               
     62000              20700                                                                                                                                                                                                                                                                               
     80000              26700                                                                                                                                                                                                                                                                               
     72000              24000                                                                                                                                                                                                                                                                               
     92000              30700                                                                                                                                                                                                                                                                               
     80000              26700                                                                                                                                                                                                                                                                               

12 rows selected.
"
-- Adding DOBs to the Database
select * from employee;

"
    EMP_NO EMP_NAME             GENDER         SALARY ADDRESS                                                   DNO                                                                                                                                                                                         
---------- -------------------- ---------- ---------- -------------------------------------------------- ----------                                                                                                                                                                                         
         2 bcdef                  F             2000000 Manipal                                                 2                                                                                                                                                                                         
         3 cdefg                  M             2500000 Bombay                                                  3                                                                                                                                                                                         
         1 abcde                  M             3000000 Manipal                                                 1                                                                                                                                                                                         
         4 defgh                  F             2500000 Bombay                                                  4       
"                                                                                                                                                                                  

-- 
alter table employee add(dob date);

Table altered.

-- 
update employee set dob='20-OCT-2000' where emp_no=2;

1 row updated.

-- 
update employee set dob='17-MAY-2001' where emp_no=3;

1 row updated.

-- 
update employee set dob='18-MAY-2001' where emp_no=1;

1 row updated.

-- 
update employee set dob='28-NOV-2001' where emp_no=4;

1 row updated.

-- #24) Display the birth date of all the employees in the following format:
--‘DD-MON-YYYY’
-- ‘DD-MON-YY’
-- ‘DD-MM-YY’

select emp_name, to_char(dob, 'DD-MON-YYYY') from employee;

"
EMP_NAME             TO_CHAR(DOB,'DD-MON-YYYY')                                                                                                                                                                                                                                                                   
-------------------- --------------------                                                                                                                                                                                                                                                                   
bcdef              20-OCT-2000                                                                                                                                                                                                                                                                            
cdefg             17-MAY-2001                                                                                                                                                                                                                                                                            
abcde                18-MAY-2001                                                                                                                                                                                                                                                                            
defgh             28-NOV-2001 
"
                                                                                                                                                                                                                                                                           


select emp_name, to_char(dob, 'DD-MON-YY') from employee;

"
EMP_NAME             TO_CHAR(DOB,'DD-MON-YY')                                                                                                                                                                                                                                                          
-------------------- ------------------                                                                                                                                                                                                                                                                     
bcdef                    20-OCT-00                                                                                                                                                                                                                                                                              
cdefg                    17-MAY-01                                                                                                                                                                                                                                                                              
abcde                    18-MAY-01                                                                                                                                                                                                                                                                              
defgh                    28-NOV-01   
"                                                                                                                                                                                                                                                                           

-- 
select emp_name, to_char(dob, 'DD-MM-YY') from employee;

"
EMP_NAME             TO_CHAR(                                                                                                                                                                                                                                                                               
-------------------- --------                                                                                                                                                                                                                                                                               
bcdef               20-10-00                                                                                                                                                                                                                                                                               
cdefg               17-05-01                                                                                                                                                                                                                                                                               
abcde               18-05-01                                                                                                                                                                                                                                                                               
defgh               28-11-01  
"                                                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                        
-- #25)  List the employee names and the year (fully spelled out) in which they are born
 ‘YEAR’
 ‘Year’
 ‘year’

 select emp_name, to_char(to_date(to_char(dob, 'YYYY'),'j'),'jsp') from dual, employee;

"
EMP_NAME             TO_CHAR(TO_DATE(TO_CHAR(DOB,'YYYY'),'J'),'JSP')                                                                                                                                                                                                                                        
-------------------- ------------------------------------------------------------------------------                                                                                                                                                                                                         
bcdef                          two thousand                                                                                                                                                                                                                                                                           
cdefg                        two thousand one                                                                                                                                                                                                                                                                       
abcde                        two thousand one                                                                                                                                                                                                                                                                       
defgh                        two thousand one  
"                                                                                                                                                                                                                                                                     

-- #26)List the employee names and the day of the week (fully spelled out) in which they are
born


select emp_name, to_char(dob, 'DAY') from employee;

"
EMP_NAME             TO_CHAR(DOB,'DAY')                                                                                                                                                                                                                                                                     
-------------------- ------------------------------------                                                                                                                                                                                                                                                   
bcdef                     FRIDAY                                                                                                                                                                                                                                                                                 
cdefg                    THURSDAY                                                                                                                                                                                                                                                                               
abcde                     FRIDAY                                                                                                                                                                                                                                                                                 
defgh                    WEDNESDAY     
"                                                                                                                                                                                                                                                                         

-- #27) List the employee names and the month(fully spelled out) in which they are born
 ‘MONTH’
 ‘Month’

select emp_name, to_char(dob, 'MONTH') from employee;

"
EMP_NAME             TO_CHAR(DOB,'MONTH')                                                                                                                                                                                                                                                                   
-------------------- ------------------------------------                                                                                                                                                                                                                                                   
bcdef                     OCTOBER                                                                                                                                                                                                                                                                                
cdefg                       MAY                                                                                                                                                                                                                                                                                    
abcde                       MAY                                                                                                                                                                                                                                                                                    
defgh                     NOVEMBER  
"

-- #28) . Find the last day of the month(and its day of the week) in which employee Mr. X is born

select emp_name, last_day(dob), to_char(last_day(dob), 'DAY') from employee where emp_name='&employee_name';

"
Enter value for employee_name: abcde
old   1: select emp_name, last_day(dob), to_char(last_day(dob), 'DAY') from employee where emp_name='&employee_name'
new   1: select emp_name, last_day(dob), to_char(last_day(dob), 'DAY') from employee where emp_name='abcde'

EMP_NAME             LAST_DAY( TO_CHAR(LAST_DAY(DOB),'DAY')                                                                                                                                                                                                                                                 
-------------------- --------- ------------------------------------                                                                                                                                                                                                                                         
abcde                31-MAY-01 THURSDAY    
"                                                                                                                                                                                                                                                                 

-- #29)  Find the age of all the employees

select emp_name, trunc((sysdate - dob)/365.25) as age from dual, employee;

"
EMP_NAME                    AGE                                                                                                                                                                                                                                                                             
-------------------- ----------                                                                                                                                                                                                                                                                             
bcdef                       20                                                                                                                                                                                                                                                                             
cdefg                       19                                                                                                                                                                                                                                                                             
abcde                       19                                                                                                                                                                                                                                                                             
defgh                       19      
"                                                                                                                                                                                                                                                                       

-- #30) Find the Saturday following the Employee’s 60th birthday

select emp_name, next_day(add_months(dob, 720), 'SATURDAY') from employee where emp_name='&employee_name';

"
Enter value for employee_name: bcdef

old   1: select emp_name, next_day(add_months(dob, 720), 'SATURDAY') from employee where emp_name='&employee_name'
new   1: select emp_name, next_day(add_months(dob, 720), 'SATURDAY') from employee where emp_name='bcdef'

EMP_NAME             NEXT_DAY(                                                                                                                                                                                                                                                                              
-------------------- ---------                                                                                                                                                                                                                                                                              
bcdef              23-OCT-60                                                                                                                                                                                                                                                                              

"

-- #31)List the employees whose birthday falls in the given year X

select emp_name from employee where extract(year from dob) = '&year';

"
Enter value for year: 2001

old   1: select emp_name from employee where extract(year from dob) = '&year'
new   1: select emp_name from employee where extract(year from dob) = '2001'

EMP_NAME                                                                                                                                                                                                                                                                                                    
--------------------                                                                                                                                                                                                                                                                                        
cdefg                                                                                                                                                                                                                                                                                                    
abcde                                                                                                                                                                                                                                                                                                       
defgh 
"                                                                                                                                                                                                                                                                                               

-- #32) List the employees whose birthday fall between the given years X and Y

select emp_name from employee where extract(year from dob) between '&start_year' and '&end_year';

"
Enter value for start_year: 2000
Enter value for end_year: 2001

old   1: select emp_name from employee where extract(year from dob) between '&start_year' and '&end_year'
new   1: select emp_name from employee where extract(year from dob) between '2000' and '2001'

EMP_NAME                                                                                                                                                                                                                                                                                                    
--------------------                                                                                                                                                                                                                                                                                        
bcdef                                                                                                                                                                                                                                                                                                     
cdefg                                                                                                                                                                                                                                                                                                    
abcde                                                                                                                                                                                                                                                                                                       
defgh  
"                                                                                                                                                                                                                                                                                                  

-- #33) List the employees who will retire on the given year X
select emp_name from employee where extract(year from dob) + 58 = '&year';

"
Enter value for year: 2058

old   1: select emp_name from employee where extract(year from dob) + 58 = '&year'
new   1: select emp_name from employee where extract(year from dob) + 58 = '2058'

EMP_NAME                                                                                                                                                                                                                                                                                                    
--------------------                                                                                                                                                                                                                                                                                        
bcdef   
"
