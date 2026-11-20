#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Q2
struct Student {
    char name[50];
    char reg_no[30];
    int total_marks;
};

int main() {
    // --- Question 1: Text File for Book Titles ---
    printf("=== Q1: Library Book Titles (Text File) ===\n");
    FILE *fp = fopen("borrowed_books.txt", "a"); // Append mode so existing records aren't deleted
    if (fp != NULL) {
        char title[100];
        printf("Enter book title to borrow: ");
        getchar(); // Clear newline buffer
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = 0; // Remove trailing newline

        fprintf(fp, "%s\n", title);
        fclose(fp);
        printf("Confirmation: Title successfully stored in borrowed_books.txt\n\n");
    }

    // --- Question 2: Binary File Student Records ---
    printf("=== Q2: Student Examination Results (Binary File) ===\n");
    FILE *bin_fp = fopen("results.dat", "wb+");
    if (bin_fp != NULL) {
        struct Student s1 = {"John Doe", "CIT/0001/2024", 85};
        struct Student s2 = {"Jane Smith", "CIT/0002/2024", 92};

        fwrite(&s1, sizeof(struct Student), 1, bin_fp);
        fwrite(&s2, sizeof(struct Student), 1, bin_fp);

        // Rewind and read back records
        rewind(bin_fp);
        struct Student temp;
        printf("Reading from binary file:\n");
        while (fread(&temp, sizeof(struct Student), 1, bin_fp) == 1) {
            printf("Name: %s | Reg No: %s | Marks: %d\n", temp.name, temp.reg_no, temp.total_marks);
        }
        fclose(bin_fp);
        printf("\n");
    }

    // --- Question 3: Sales Transactions Text File ---
    printf("=== Q3: Daily Sales Transactions ===\n");
    // Writing sample sales data for testing
    FILE *sales_fp = fopen("sales.txt", "w");
    if (sales_fp != NULL) {
        fprintf(sales_fp, "1500.50\n");
        fprintf(sales_fp, "2300.00\n");
        fprintf(sales_fp, "450.25\n");
        fclose(sales_fp);
    }

    // Reading and processing sales data
    sales_fp = fopen("sales.txt", "r");
    if (sales_fp != NULL) {
        float amount;
        float total_sales = 0.0;

        while (fscanf(sales_fp, "%f", &amount) == 1) {
            total_sales += amount;
        }
        fclose(sales_fp); // Ensuring file is properly closed after reading

        printf("Total daily sales calculated from file: KSh. %.2f\n", total_sales);
    }

    return 0;
}
