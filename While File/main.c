#include <stdio.h>
#include <time.h>
#include <windows.h>
#define HEADER "Attendance Sheet"

int main() {

    int const bscs_ya1_total_students = 6, bscs_ya2_total_students = 50, bsit_ya1_total_students = 50, bsit_ya2_total_students = 50;
    int bscs_ya1_students = 0, bscs_ya2_students = 0, bsit_ya1_students = 0, bsit_ya2_students = 0;
    char course[50], section[50], last_name[50], first_name[50], vaccinationStatus[50], contactNumber[15];
    int startOfclass = 1666782633, absentCutoff = 1666782933;
    int endOfline = 0;
    int presentStudents = 0, lateStudents = 0;
    int absentStudents, timesUp = 0;
    char presentStatus, absentStatus;


    FILE *fpointer;

    fpointer  = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-1\\BSCS_YA-1_Attendance_Sheet.txt", "w");
        fprintf(fpointer, "%s\n", HEADER);
	fclose(fpointer);

    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-2\\BSCS_YA-2_Attendance_Sheet.txt", "w");
        fprintf(fpointer, "%s\n", HEADER);
	fclose(fpointer);

    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-1\\BSIT_YA-1_Attendance_Sheet.txt", "w");
        fprintf(fpointer, "%s\n", HEADER);
	fclose(fpointer);

    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-2\\BSIT_YA-2_Attendance_Sheet.txt", "w");
        fprintf(fpointer, "%s\n", HEADER);
	fclose(fpointer);



	while(bscs_ya1_students < bscs_ya1_total_students && bscs_ya2_students < bscs_ya2_total_students && bsit_ya1_students < bsit_ya1_total_students && bsit_ya2_students < bsit_ya2_total_students && timesUp != 1){

            printf("Attendance Sheet\n");
            printf("\nEnter your course: ");
            scanf("%s", &course);
            printf("Enter your section: ");
            scanf("%s", &section);

        if(strcmp(strupr(course), "BSCS") == 0){
            // this statement runs if the student inputs any iteration of YA1 (not case sensitive)
            if(strcmp(strupr(section), "YA-1") == 0 || strcmp(strupr(section), "1-YA-1") == 0 || strcmp(strupr(section), "1YA-1") == 0 || strcmp(strupr(section), "1-YA1") == 0 || strcmp(strupr(section), "YA1") == 0 || strcmp(strupr(section), "1YA1") == 0){

                printf("\nLast Name: ");
                scanf("\n%[^\n]", &last_name);
                printf("First Name: ");
                scanf("\n%[^\n]", &first_name);
                printf("Contact Number: ");
                scanf("%s", &contactNumber);
                printf("Vaccination Status: ");
                scanf("\n%[^\n]", &vaccinationStatus);

                sleep(1);
                    time_t arrivalTime = time(NULL);
                    char *interval = ctime(&arrivalTime);

                if(arrivalTime > absentCutoff){

                    printf("\nSorry, the Attendance Sheet has now closed.\nNext time, try waking up earlier :   ^)\n");

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-1\\BSCS_YA-1_Attendance_Sheet.txt", "r");

                        for (presentStatus = getc(fpointer); presentStatus != EOF; presentStatus = getc(fpointer))
                            if (presentStatus == '^')
                            presentStudents += 1;
                    fclose(fpointer);

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-1\\BSCS_YA-1_Attendance_Sheet.txt", "r");
                        for (absentStatus = getc(fpointer); absentStatus != EOF; absentStatus = getc(fpointer))
                            if (absentStatus == '~')
                            lateStudents += 1;

                    fclose(fpointer);

                    absentStudents = bscs_ya1_total_students - (presentStudents + lateStudents);

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-1\\BSCS_YA-1_Attendance_Sheet.txt", "a");
                        fprintf(fpointer, "\nSummary:\n");
                        fprintf(fpointer, "\nNumber of Students Present: %d", presentStudents);
                        fprintf(fpointer, "\nNumber of Students Late: %d", lateStudents);
                        fprintf(fpointer, "\nNumber of Students Absent: %d", absentStudents);
                    fclose(fpointer);

                    timesUp = 1;

                }else{

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-1\\BSCS_YA-1_Attendance_Sheet.txt", "a");

                        fprintf(fpointer, "\nName: %s, %s", last_name, first_name);
                        fprintf(fpointer, "\nContact Number: %s", contactNumber);
                        fprintf(fpointer, "\nVaccination Status: %s", vaccinationStatus);
                        fprintf(fpointer, "\nTime of Arrival: %s", interval);

                        if(arrivalTime <= startOfclass){
                            fprintf(fpointer, "^");
                        }else if(arrivalTime > startOfclass && arrivalTime <= absentCutoff){
                            fprintf(fpointer, "~");
                        }
                            fprintf(fpointer, "\n");

                    fclose(fpointer);
                    bscs_ya1_students++;

                    printf("\nYour response has been recorded.\nThank You.");
                }

                sleep(5);
                system("cls");

            }else if(strcmp(strupr(section), "YA-2") == 0 || strcmp(strupr(section), "1-YA-2") == 0 || strcmp(strupr(section), "1YA-2") == 0 || strcmp(strupr(section), "1-YA2") == 0 || strcmp(strupr(section), "YA2") == 0 || strcmp(strupr(section), "1YA2") == 0){

                printf("\nLast Name: ");
                scanf("\n%[^\n]", &last_name);
                printf("First Name: ");
                scanf("\n%[^\n]", &first_name);
                printf("Contact Number: ");
                scanf("%s", &contactNumber);
                printf("Vaccination Status: ");
                scanf("\n%[^\n]", &vaccinationStatus);

                sleep(1);
                    time_t arrivalTime = time(NULL);
                    char *interval = ctime(&arrivalTime);

                if(arrivalTime > absentCutoff){

                    printf("\nSorry, the Attendance Sheet has now closed.\nNext time, try waking up earlier :   ^)\n");

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-2\\BSCS_YA-2_Attendance_Sheet.txt", "r");

                        for (presentStatus = getc(fpointer); presentStatus != EOF; presentStatus = getc(fpointer))
                            if (presentStatus == '^')
                            presentStudents += 1;
                    fclose(fpointer);

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-2\\BSCS_YA-2_Attendance_Sheet.txt", "r");
                        for (absentStatus = getc(fpointer); absentStatus != EOF; absentStatus = getc(fpointer))
                            if (absentStatus == '~')
                            lateStudents += 1;
                    fclose(fpointer);

                    absentStudents = bscs_ya2_total_students - (presentStudents + lateStudents);

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-2\\BSCS_YA-2_Attendance_Sheet.txt", "a");
                        fprintf(fpointer, "\nSummary:\n");
                        fprintf(fpointer, "\nNumber of Students Present: %d", presentStudents);
                        fprintf(fpointer, "\nNumber of Students Late: %d", lateStudents);
                        fprintf(fpointer, "\nNumber of Students Absent: %d", absentStudents);
                    fclose(fpointer);

                    timesUp = 1;

                }else{

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-2\\BSCS_YA-2_Attendance_Sheet.txt", "a");

                        fprintf(fpointer, "\nName: %s, %s", last_name, first_name);
                        fprintf(fpointer, "\nContact Number: %s", contactNumber);
                        fprintf(fpointer, "\nVaccination Status: %s", vaccinationStatus);
                        fprintf(fpointer, "\nTime of Arrival: %s", interval);

                        if(arrivalTime <= startOfclass){
                            fprintf(fpointer, "^");
                        }else if(arrivalTime > startOfclass && arrivalTime <= absentCutoff){
                            fprintf(fpointer, "~");
                        }
                            fprintf(fpointer, "\n");

                    fclose(fpointer);
                    bscs_ya2_students++;

                    printf("\nYour response has been recorded.\nThank You.");
                }

                sleep(5);
                system("cls");

            }else{
                printf("\nError! Invalid Section");
                sleep(3);
                system("cls");
            }

        }else if(strcmp(strupr(course), "BSIT") == 0){

            if(strcmp(strupr(section), "YA-1") == 0 || strcmp(strupr(section), "1-YA-1") == 0 || strcmp(strupr(section), "1YA-1") == 0 || strcmp(strupr(section), "1-YA1") == 0 || strcmp(strupr(section), "YA1") == 0 || strcmp(strupr(section), "1YA1") == 0){

                printf("\nLast Name: ");
                scanf("\n%[^\n]", &last_name);
                printf("First Name: ");
                scanf("\n%[^\n]", &first_name);
                printf("Contact Number: ");
                scanf("%s", &contactNumber);
                printf("Vaccination Status: ");
                scanf("\n%[^\n]", &vaccinationStatus);

                sleep(1);
                    time_t arrivalTime = time(NULL);
                    char *interval = ctime(&arrivalTime);

                if(arrivalTime > absentCutoff){

                    printf("\nSorry, the Attendance Sheet has now closed.\nNext time, try waking up earlier :   ^)\n");

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-1\\BSIT_YA-1_Attendance_Sheet.txt", "r");

                        for (presentStatus = getc(fpointer); presentStatus != EOF; presentStatus = getc(fpointer))
                            if (presentStatus == '^')
                            presentStudents += 1;
                    fclose(fpointer);

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-1\\BSIT_YA-1_Attendance_Sheet.txt", "r");
                        for (absentStatus = getc(fpointer); absentStatus != EOF; absentStatus = getc(fpointer))
                            if (absentStatus == '~')
                            lateStudents += 1;
                    fclose(fpointer);

                    absentStudents = bsit_ya1_total_students - (presentStudents + lateStudents);

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-1\\BSIT_YA-1_Attendance_Sheet.txt", "a");
                        fprintf(fpointer, "\nSummary:\n");
                        fprintf(fpointer, "\nNumber of Students Present: %d", presentStudents);
                        fprintf(fpointer, "\nNumber of Students Late: %d", lateStudents);
                        fprintf(fpointer, "\nNumber of Students Absent: %d", absentStudents);
                    fclose(fpointer);

                    timesUp = 1;

                }else{

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-1\\BSIT_YA-1_Attendance_Sheet.txt", "a");

                        fprintf(fpointer, "\nName: %s, %s", last_name, first_name);
                        fprintf(fpointer, "\nContact Number: %s", contactNumber);
                        fprintf(fpointer, "\nVaccination Status: %s", vaccinationStatus);
                        fprintf(fpointer, "\nTime of Arrival: %s", interval);

                        if(arrivalTime <= startOfclass){
                            fprintf(fpointer, "^");
                        }else if(arrivalTime > startOfclass && arrivalTime <= absentCutoff){
                            fprintf(fpointer, "~");
                        }
                            fprintf(fpointer, "\n");

                    fclose(fpointer);
                    bsit_ya1_students++;

                    printf("\nYour response has been recorded.\nThank You.");
                }

                sleep(5);
                system("cls");

            }else if(strcmp(strupr(section), "YA-2") == 0 || strcmp(strupr(section), "1-YA-2") == 0 || strcmp(strupr(section), "1YA-2") == 0 || strcmp(strupr(section), "1-YA2") == 0 || strcmp(strupr(section), "YA2") == 0 || strcmp(strupr(section), "1YA2") == 0){

                printf("\nLast Name: ");
                scanf("\n%[^\n]", &last_name);
                printf("First Name: ");
                scanf("\n%[^\n]", &first_name);
                printf("Contact Number: ");
                scanf("%s", &contactNumber);
                printf("Vaccination Status: ");
                scanf("\n%[^\n]", &vaccinationStatus);

                sleep(1);
                    time_t arrivalTime = time(NULL);
                    char *interval = ctime(&arrivalTime);

                if(arrivalTime > absentCutoff){

                    printf("\nSorry, the Attendance Sheet has now closed.\nNext time, try waking up earlier :   ^)\n");

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-2\\BSIT_YA-2_Attendance_Sheet.txt", "r");

                        for (presentStatus = getc(fpointer); presentStatus != EOF; presentStatus = getc(fpointer))
                            if (presentStatus == '^')
                            presentStudents += 1;
                    fclose(fpointer);

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-2\\BSIT_YA-2_Attendance_Sheet.txt", "r");
                        for (absentStatus = getc(fpointer); absentStatus != EOF; absentStatus = getc(fpointer))
                            if (absentStatus == '~')
                            lateStudents += 1;

                    fclose(fpointer);

                    absentStudents = bsit_ya2_total_students - (presentStudents + lateStudents);

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-2\\BSIT_YA-2_Attendance_Sheet.txt", "a");
                        fprintf(fpointer, "\nSummary:\n");
                        fprintf(fpointer, "\nNumber of Students Present: %d", presentStudents);
                        fprintf(fpointer, "\nNumber of Students Late: %d", lateStudents);
                        fprintf(fpointer, "\nNumber of Students Absent: %d", absentStudents);
                    fclose(fpointer);

                    timesUp = 1;

                }else{

                    fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-2\\BSIT_YA-2_Attendance_Sheet.txt", "a");

                        fprintf(fpointer, "\nName: %s, %s", last_name, first_name);
                        fprintf(fpointer, "\nContact Number: %s", contactNumber);
                        fprintf(fpointer, "\nVaccination Status: %s", vaccinationStatus);
                        fprintf(fpointer, "\nTime of Arrival: %s", interval);

                        if(arrivalTime <= startOfclass){
                            fprintf(fpointer, "^");
                        }else if(arrivalTime > startOfclass && arrivalTime <= absentCutoff){
                            fprintf(fpointer, "~");
                        }
                            fprintf(fpointer, "\n");

                    fclose(fpointer);
                    bsit_ya2_students++;

                    printf("\nYour response has been recorded.\nThank You.");
                }

                sleep(5);
                system("cls");

            }else{
                printf("\nError! Invalid Section");
                sleep(3);
                system("cls");
            }
        }else{
            printf("\nError! Invalid Course!");
            sleep(3);
            system("cls");
        }
	}

	if(bscs_ya1_students == bscs_ya1_total_students){

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-1\\BSCS_YA-1_Attendance_Sheet.txt", "r");
            for (presentStatus = getc(fpointer); presentStatus != EOF; presentStatus = getc(fpointer))
                if (presentStatus == '^')
                    presentStudents += 1;
        fclose(fpointer);

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-1\\BSCS_YA-1_Attendance_Sheet.txt", "r");
            for (absentStatus = getc(fpointer); absentStatus != EOF; absentStatus = getc(fpointer))
                if (absentStatus == '~')
                    lateStudents += 1;
        fclose(fpointer);

        absentStudents = bscs_ya1_total_students - (presentStudents + lateStudents);

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-1\\BSCS_YA-1_Attendance_Sheet.txt", "a");
            fprintf(fpointer, "\nSummary:\n");
            fprintf(fpointer, "\nNumber of Students Present: %d", presentStudents);
            fprintf(fpointer, "\nNumber of Students Late: %d", lateStudents);
            fprintf(fpointer, "\nNumber of Students Absent: %d", absentStudents);
        fclose(fpointer);

        printf("\nThe Attendace Sheet has now officially closed! Thank You!\n");

	}else if(bscs_ya2_students == bscs_ya2_total_students){

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-2\\BSCS_YA-2_Attendance_Sheet.txt", "r");

            for (presentStatus = getc(fpointer); presentStatus != EOF; presentStatus = getc(fpointer))
                if (presentStatus == '^')
                presentStudents += 1;
        fclose(fpointer);

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-2\\BSCS_YA-2_Attendance_Sheet.txt", "r");
            for (absentStatus = getc(fpointer); absentStatus != EOF; absentStatus = getc(fpointer))
                if (absentStatus == '~')
                lateStudents += 1;
        fclose(fpointer);

        absentStudents = bscs_ya2_total_students - (presentStudents + lateStudents);

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSCS 1-YA-2\\BSCS_YA-2_Attendance_Sheet.txt", "a");
            fprintf(fpointer, "\nSummary:\n");
            fprintf(fpointer, "\nNumber of Students Present: %d", presentStudents);
            fprintf(fpointer, "\nNumber of Students Late: %d", lateStudents);
            fprintf(fpointer, "\nNumber of Students Absent: %d", absentStudents);
        fclose(fpointer);

        printf("\nThe Attendace Sheet has now officially closed! Thank You!\n");

	}else if(bsit_ya1_students == bsit_ya1_total_students){

         fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-1\\BSIT_YA-1_Attendance_Sheet.txt", "r");

            for (presentStatus = getc(fpointer); presentStatus != EOF; presentStatus = getc(fpointer))
                if (presentStatus == '^')
                presentStudents += 1;
        fclose(fpointer);

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-1\\BSIT_YA-1_Attendance_Sheet.txt", "r");
            for (absentStatus = getc(fpointer); absentStatus != EOF; absentStatus = getc(fpointer))
                if (absentStatus == '~')
                lateStudents += 1;
        fclose(fpointer);

        absentStudents = bsit_ya1_total_students - (presentStudents + lateStudents);

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-1\\BSIT_YA-1_Attendance_Sheet.txt", "a");
            fprintf(fpointer, "\nSummary:\n");
            fprintf(fpointer, "\nNumber of Students Present: %d", presentStudents);
            fprintf(fpointer, "\nNumber of Students Late: %d", lateStudents);
            fprintf(fpointer, "\nNumber of Students Absent: %d", absentStudents);
        fclose(fpointer);

        printf("\nThe Attendace Sheet has now officially closed! Thank You!\n");

	}else if(bsit_ya2_students == bsit_ya2_total_students){

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-2\\BSIT_YA-2_Attendance_Sheet.txt", "r");

            for (presentStatus = getc(fpointer); presentStatus != EOF; presentStatus = getc(fpointer))
                if (presentStatus == '^')
                presentStudents += 1;
        fclose(fpointer);

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-2\\BSIT_YA-2_Attendance_Sheet.txt", "r");
            for (absentStatus = getc(fpointer); absentStatus != EOF; absentStatus = getc(fpointer))
                if (absentStatus == '~')
                lateStudents += 1;

        fclose(fpointer);

        absentStudents = bsit_ya2_total_students - (presentStudents + lateStudents);

        fpointer = fopen("C:\\Users\\Romille Ilaida\\Desktop\\Attendance Folder\\BSIT 1-YA-2\\BSIT_YA-2_Attendance_Sheet.txt", "a");
            fprintf(fpointer, "\nSummary:\n");
            fprintf(fpointer, "\nNumber of Students Present: %d", presentStudents);
            fprintf(fpointer, "\nNumber of Students Late: %d", lateStudents);
            fprintf(fpointer, "\nNumber of Students Absent: %d", absentStudents);
        fclose(fpointer);

        printf("\nThe Attendace Sheet has now officially closed! Thank You!\n");

	}

	return 0;
}
