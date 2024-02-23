/*	Student Name	:	Deepthi Valachery
	Student ID		:	[redact]
	Course Code		:	COMP 1603
	Assignment		:	1
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main () {
	ifstream inputFile;
	inputFile.open("students.txt");
	
	int *i, *id, *subject, *marks;
	int *idNum=0, *sum, *highest;
	int *max, *maxId;
	float *avg;
	
	id = (int *) malloc (sizeof (int));
    subject = (int *) malloc (sizeof (int));
    i = (int *) malloc (sizeof (int));
    marks = (int *) malloc (sizeof (int));
    idNum = (int *) malloc (sizeof (int));
    max = (int *) malloc (sizeof (int));
    sum = (int *) malloc (sizeof (int));
    avg = (float *) malloc (sizeof (float));
    highest = (int *) malloc (sizeof (int));
    maxId = (int *) malloc (sizeof (int));
	
	
	if (!inputFile.is_open()) {
	cout << "File could not be opened. Aborting..." << endl;
	exit(1)	;
	}
	
	cout << "Grade scheme: A (80-100), B (70-79), C (60-69), D (50-59), F (<50)" << endl << endl;
	
	inputFile >> *id;
	
	while (*id != 0){
		inputFile >> *subject;
		cout << "ID = " << *id << endl << endl;
		*idNum = *idNum + 1;										//Number of candidates
		
		if (*subject > *max){
			*max = *subject;										//Max number of subjects taken by candidate
		}
		*sum = 0;
		for (*i=1;*i<=*subject;(*i)++){
			inputFile >> *marks;
			cout << "Score = " << *marks;
			*sum = *sum + *marks;
			
			if ((*marks>=80) && (*marks<=100)) {
			cout << "\tGrade = A" << endl;
			}
			else if ((*marks>=70) && (*marks<=79)) {				//Print student ID with marks and grade
			cout << "\tGrade = B" << endl;
			}
			else if ((*marks>=60) && (*marks<=69)) {
			cout << "\tGrade = C" << endl;
			}
			else if ((*marks>=50) && (*marks<=59)) {
			cout << "\tGrade = D" << endl;
			}
			else if (*marks<50) {
			cout << "\tGrade = F" << endl;
			}
			
			}
		cout << endl;
		*avg = *sum / *subject;										//Average mark for each candidate
		cout << "Average for candidate " << *id << " is " << *avg << endl;
		
		if (*avg > *highest){										//Highest average for any candidate overall
			*highest = *avg;
			*maxId = *id;
		}
		
		inputFile >> *id;
		
		cout << "----------------------------" << endl;
		
	}
	cout << endl;
	cout << "----------SUMMARY RESULTS-----------" << endl;
	
	cout << "No. of Candidtes = " << *idNum << endl;
	cout << "Maximum number of subjects taken = " << *max << endl;
	cout << "Highest average = " << *highest << " obtained by " << *maxId << endl;
	
	cout << "---------------------------------------" << endl;
	
	
	
	inputFile.close();
	
	
	free (i);														//Free all variables
	free (id);
	free (subject);
	free (marks);
	free (sum);
	free (idNum);
	free (max);
	free (maxId);
	free (sum);
	free (avg);
	free (highest);
	
	
	return 0;
}
