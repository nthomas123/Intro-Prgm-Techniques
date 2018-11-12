/*
Noble Thomas
 */
#include "stdafx.h"#include < vector > #include < string >
    #include < iostream >
    using namespace std;
// Return appropriate sigular/plural grade/grades
string gradeOrGrades(int count) {
    if (count == 1) {
        return "grade";
    } else {
        return "grades";
    }
}
//Return leter grade
string convertGrades(int grade) {
    if ((grade < 60) && (grade >= 0)) {
        return "(F)";
    } else if ((grade < 70) && (grade >= 60)) {
        return "(D)";
    } else if ((grade < 75) && (grade >= 70)) {
        return "(C)";
    } else if ((grade < 80) && (grade >= 75)) {
        return "(C+)";
    } else if ((grade < 83) && (grade >= 80)) {
        return "(B-)";
    } else if ((grade < 87) && (grade >= 83)) {
        return "(B)";
    } else if ((grade < 90) && (grade >= 87)) {
        return "(B+)";
    } else if ((grade < 93) && (grade >= 90)) {
        return "(A)";
    } else if ((grade < 100) && (grade >= 93)) {
        return "(A)";
    }
}
//
// Return appropriate sigular/plural is/are
string isOrAre(int count) {
    if (count == 1) {
        return "is";
    } else {
        return "are";
    }
}
// Display the count of the given grade
void displayCount(string label, vector < float > grades) {
    // The size of this vector
    int size = grades.size();
    cout << "You entered " << size;
    // Appropriate label
    cout << " " << label << " ";
    // grade or grades
    cout << gradeOrGrades(size) << ".";
    cout << endl;
}
//Letter grade function
string displayLetter(string label, float grade) {
    // grade or grades
    string x = convertGrades(grade);
    return x;
}
// Display the given grades
void displayGrades(string label, vector < float > grades) {
    // The size of this vector
    int size = grades.size();
    cout << endl;
    if (size == 0) {
        // If the vector is empty
        cout << "There are no " << label << " grades.";
    } else {
        cout << "Here ";
        cout << isOrAre(size); // is or are
        cout << " the " << size;
        cout << " " << label << " "; // valid or invalid
        cout << gradeOrGrades(size) << ":" << endl;
        // Loop over the vector
        for (int i = 0; i < grades.size(); i++) {
            cout << grades[i] << endl;
        }
    }
}
int main() {
    // One grade entered by the user
    float grade = 0;
    // The highest valid grade entered
    float high = 0;
    /*
     * The lowest valid grade entered
     * We initialize to 101, because that will for the first
     * grade to be considered lowest.
     * If we initialized it to 0, then the low grade will always
     * be 0.
     */
    float low = 101;
    // The sum of all the valid grades
    float total = 0;
    // The count of all the valid grades
    int count = 0;
    //Conversion of valid grades
    float letterGrade = 0;
    // Vector to hold the valid grades
    vector < float > validGrades;
    // Vector to hold the invalid grades
    vector < float > invalidGrades;
    while (true) {
        // Read in a grade from the keyboard
        cout << "Enter a grade: ";
        cin >> grade;
        /***********************************\
        * Loop will exit if the grade is -1 *
        \***********************************/
        if (grade == -1) {
            break;
        }
        // Grade must be between 0 and 100
        if ((grade < 0) || (grade > 100)) {
            cout << "Error. Grade must be between 0 and
            100;
            or - 1 to finish " << endl;
            // Append this invalid grade to the invalid
            grades vector
            invalidGrades.push_back(grade);
        } else {
            // Increment the count of valid grades
            count++;
            // Increment the total of all the valid
            grades
            total += grade;
            // Append this valid grade to the valid
            grades vector
            validGrades.push_back(grade);
            /*
            * Determine the high grade
            * If the current grade is greater than the
            highest grade we've
            * seen, then we want to store it as the new
            highest grade.
            */
            if (grade > high) {
                high = grade;
            }
            /*
            * Determine the low grade
            * If the current grade is less than than the
            lowest grade we've
            * seen, then we want to store it as the new
            low grade.
            */
            if (grade < low) {
                low = grade;
            }
        }
    }
    // Display the count of the valid grades
    displayCount("valid", validGrades);
    // Display the count of the invalid grades
    displayCount("invalid", invalidGrades);
    // Display the letter of the valid grades
    for (int i = 0; i < validGrades.size(); i++) {
        displayLetter("valid", validGrades[i]);
    }
    // No need to output results if no grades were entered
    if (count > 0) {
        //Display number grades with letter grade
        cout << "Highest grade: " << high <<
            displayLetter("valid", high) << endl;
        cout << "Lowest grade: " << low <<
            displayLetter("valid", low) << endl;
        cout << "Average: " << total / count <<
            displayLetter("valid", total / count) << endl;
    }
    // Display the valid grades
    displayGrades("valid", validGrades);
    // Display the invalid grades
    displayGrades("invalid", invalidGrades);
    system("pause");
    return 0;
}