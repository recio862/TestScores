/* 
Name: Renato Recio
Program Status: Complete
Program Function: Test Scores
                  Process test scores for students in a classs
				
*/


////////////////////////////////////////////////////////////////////
//Include                                                         
///////////////////////////////////////////////////////////////////	
#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////
//Student Structure
///////////////////////////////////////////////////////////////////	
struct Student{
       string name; //Stores individual student names
       int score; //Stores student test score
       };


////////////////////////////////////////////////////////////////////
//Function prototypes                                              
///////////////////////////////////////////////////////////////////	
int number_of_students(); //Number
void store_student_info(Student *ptr, int total_students);
void sort_students_by_score(Student *ptr, int total_students);
float calculate_average(Student *ptr, int total_students);
void print_students(Student *ptr, int total_students, float average);
void exit_program();



////////////////////////////////////////////////////////////////////
//Main Driver
///////////////////////////////////////////////////////////////////	
int main(){

float average; //Class average 

int total_students = number_of_students(); 

Student *classptr; //Initialize an array of total_students size
classptr = new Student[total_students];
Student *ptr = &classptr[0]; //Create a pointer to the array

store_student_info(ptr, total_students); //Store all input for student info into the struct array
sort_students_by_score(ptr, total_students); //Sort array in ascending order based on score
average = calculate_average(ptr, total_students); //Calculate the average of the class
print_students(ptr, total_students, average); //Print out class statistics
exit_program(); //Exit the program

}

////////////////////////////////////////////////////////////////////
//Store all student data into the Student array
///////////////////////////////////////////////////////////////////	
void store_student_info(Student *ptr, int total_students){ 
string student_name;
int student_score = -1;
int class_index = 0;


while (class_index < total_students){
      
//Input student name
cout << "\nPlease enter the name of student #" << class_index + 1 << ": ";
getline(cin,student_name); //dummy 
getline(cin, student_name);

             //Input student name must be less than or equal to 30
           while (student_name.length() > 30)
           {
                 cout << "\nPlease enter a name with less than 30 characters: ";
                 getline(cin, student_name);
           }

//Input student score
cout << "Please enter the score of student #" << class_index + 1 << ": ";
cin >> student_score;
    
             //Input student score must be 0-105
           while (student_score < 0 || student_score > 105)
           {
                 cout << "\nPlease enter a score between 0 and 105, inclusive";
                 cin >> student_score;
           }

//Store the data in the struct
ptr->name = student_name;
ptr->score = student_score;

//Increment pointer to next struct in the array
*ptr++;
class_index++;
}
}


////////////////////////////////////////////////////////////////////
//Use bubble sort to sort the students by score
///////////////////////////////////////////////////////////////////	
void sort_students_by_score(Student *ptr, int total_students){
   int temp_score;
   int i;
   string temp_name;
   int next_score;
   string next_name;
   int count;
   bool swap;
   
   
   //Bubble sort algorithm 
   do 
   {
        swap = false;
        
        for (count = 0 ; count < total_students - 1; count++, *ptr++)
          {
                   *ptr++; //go to next
                   next_score = ptr->score;
                   next_name = ptr->name;
                   *ptr--; //back to current
                  if (ptr->score > next_score){
                                 temp_score = ptr->score; temp_name = ptr->name;
                                 ptr->score = next_score; ptr->name = next_name;
                                 *ptr++;
                                 ptr->score = temp_score; ptr->name = temp_name;
                                 swap = true;
                                 *ptr--;
                                 }
                                 }
          for (i = count; i > 0; i--, *ptr--);
                   
                   }
                   while (swap);
                   
}                 
                   
                   
////////////////////////////////////////////////////////////////////
//Calculate the class average
///////////////////////////////////////////////////////////////////	
float calculate_average(Student *ptr, int total_students){
    int average = 0;
    int current_student, i;
    
    for (i = 0; i < total_students; i++, *ptr++){
        current_student = ptr->score;
        average+=current_student;
        }
    
    average = average / total_students;
    
    return average;
    
    
}

////////////////////////////////////////////////////////////////////
//Print data for each student
///////////////////////////////////////////////////////////////////	
void print_students(Student *ptr, int total_students, float average){
     int i;
     cout << setw(30) << left << "\nName";
     cout << right <<setw(6)<< "Score\n";
     cout << setfill('-') <<setw(36) << "\n";

     for (i = 0; i < total_students; i++, *ptr++){
        cout << left << setfill(' ') << setw(30)<< ptr->name;
        cout << right << setw(5)<< ptr->score<<"\n";
        }
     cout << setfill('-') <<setw(36)<<"\n";
     cout << setfill(' ')<< left <<setw(25) << "Average:";
     cout << right << setprecision(1) << fixed <<setw(10)<< average;
     
     }

////////////////////////////////////////////////////////////////////
//User inputs number of students in the class
///////////////////////////////////////////////////////////////////	
int number_of_students(){
    int total = -1;
    cout << "Please enter the number of students in the class: ";
    cin >> total;
    while (total <= 0){
          cout << "\nPlease enter a positive integer for the number of students greater than 0: ";
          cin >> total;
          }
    return total;
} 

////////////////////////////////////////////////////////////////////
//Exit the program
///////////////////////////////////////////////////////////////////
void exit_program(){  
string exit;
cout << "\nPress enter to exit";
getline(cin, exit);
getline(cin, exit);
}
