/*  student.h 
 *
 *  Defines the STUDENT_T data type for use
 *  in CPE100 labs related to binary file I/O
 *
 *  Created by Sally Goldin, 15 September 2006
 */

#define MAXCOUNT 20

typedef struct
   {  
   char name[64];       /* Name of the student */
   int age;             /* Age in years */  
   char gender;         /* 'M' if male, 'F' if female  */   
   int quizGrades[5];   /* Grades from last 5 quizzes  */
   double gpa;          /* Current grade point average */
   } STUDENT_T;