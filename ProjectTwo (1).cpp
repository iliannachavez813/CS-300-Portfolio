#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <algorithm>
#include <cctype>

using namespace std;

// Stores the information for each course
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Removes extra spaces from the beginning and end of text
string trim(const string& text) {
    size_t start = text.find_first_not_of(" \t\r\n");

    if (start == string::npos) {
        return "";
    }

    size_t end = text.find_last_not_of(" \t\r\n");
    return text.substr(start, end - start + 1);
}

// Converts a course number to uppercase
string toUpperCase(string text) {
    transform(text.begin(), text.end(), text.begin(),
        [](unsigned char c) {
            return static_cast<char>(toupper(c));
        });

    return text;
}

// Finds a course using its course number
const Course* findCourse(const vector<Course>& courses,
    const string& courseNumber) {

    for (const Course& course : courses) {
        if (course.courseNumber == courseNumber) {
            return &course;
        }
    }

    return nullptr;
}

// Loads course information from the CSV file
bool loadCourses(const string& filename, vector<Course>& courses) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open the file." << endl;
        return false;
    }

    vector<Course> loadedCourses;
    string line;

    while (getline(file, line)) {
        if (trim(line).empty()) {
            continue;
        }

        stringstream ss(line);
        Course course;
        string prerequisite;

        getline(ss, course.courseNumber, ',');
        getline(ss, course.courseTitle, ',');

        course.courseNumber = toUpperCase(
            trim(course.courseNumber));
        course.courseTitle = trim(course.courseTitle);

        // Every course must have a number and title
        if (course.courseNumber.empty() ||
            course.courseTitle.empty()) {

            cout << "Error: Invalid course information."
                << endl;
            return false;
        }

        // Prevent duplicate course numbers
        if (findCourse(loadedCourses,
            course.courseNumber) != nullptr) {

            cout << "Error: Duplicate course number."
                << endl;
            return false;
        }


        // Read any prerequisites listed for the course
        while (getline(ss, prerequisite, ',')) {
            prerequisite = toUpperCase(trim(prerequisite));

            if (!prerequisite.empty()) {
                course.prerequisites.push_back(prerequisite);
            }
        }

        loadedCourses.push_back(course);
    }

    file.close();

    if (loadedCourses.empty()) {
        cout << "Error: The file contains no courses."
            << endl;
        return false;
    }

    // Make sure all prerequisites are valid courses
    for (const Course& course : loadedCourses) {
        for (const string& prerequisite :
            course.prerequisites) {

            if (findCourse(loadedCourses,
                prerequisite) == nullptr) {

                cout << "Error: Prerequisite "
                    << prerequisite
                    << " was not found." << endl;
                return false;
            }
        }
    }

    courses = loadedCourses;

    cout << "Course data loaded successfully!"
        << endl;

    return true;
}

// Sorts and prints courses in alphanumeric order
void printCourseList(vector<Course> courses) {

    sort(courses.begin(), courses.end(),
        [](const Course& a, const Course& b) {
            return a.courseNumber < b.courseNumber;
        });

    cout << "\nHere is a sample schedule:\n"
        << endl;

    for (const Course& course : courses) {
        cout << course.courseNumber << ", "
            << course.courseTitle << endl;
    }
}

// Searches for a course and displays its information
void printCourse(const vector<Course>& courses,
    string courseNumber) {

    courseNumber = toUpperCase(trim(courseNumber));

    const Course* course = findCourse(courses,
        courseNumber);

    if (course == nullptr) {
        cout << "Course not found." << endl;
        return;
    }

    cout << "\n" << course->courseNumber << ", "
        << course->courseTitle << endl;

    if (course->prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
        return;
    }

    cout << "Prerequisites: ";

    // Display prerequisite numbers and titles
    for (size_t i = 0;
        i < course->prerequisites.size(); i++) {

        string prerequisiteNumber =
            course->prerequisites[i];

        const Course* prerequisite =
            findCourse(courses, prerequisiteNumber);

        cout << prerequisiteNumber;

        if (prerequisite != nullptr) {
            cout << " (" << prerequisite->courseTitle
                << ")";
        }

        if (i + 1 < course->prerequisites.size()) {
            cout << ", ";
        }
    }

    cout << endl;
}

// Displays the menu and handles user choices
int main() {
    vector<Course> courses;
    string input;
    string filename;
    string courseNumber;
    bool dataLoaded = false;

    cout << "Welcome to the course planner."
        << endl;

    while (true) {
        cout << "\n1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;

        cout << "\nWhat would you like to do? ";
        getline(cin, input);

        if (!cin) {
            break;
        }

        input = trim(input);

        if (input == "1") {
            cout << "Enter the file name: ";
            getline(cin, filename);

            if (!cin) {
                break;
            }

            filename = trim(filename);

            dataLoaded = loadCourses(filename, courses);
        }
        else if (input == "2") {
            if (dataLoaded) {
                printCourseList(courses);
            }
            else {
                cout << "Please load the course data first."
                    << endl;
            }
        }
        else if (input == "3") {
            if (dataLoaded) {
                cout << "What course do you want to know about? ";
                getline(cin, courseNumber);

                if (!cin) {
                    break;
                }

                printCourse(courses, courseNumber);
            }
            else {
                cout << "Please load the course data first."
                    << endl;
            }
        }
        else if (input == "9") {
            cout << "Thank you for using the course planner!"
                << endl;
            break;
        }
        else {
            cout << input << " is not a valid option."
                << endl;
        }
    }

    return 0;
}